#include "staffwidget.h"
#include <QDebug>
#include <QJsonObject>

StaffWidget::StaffWidget(QWidget *parent) : QObject(parent) {
    m_isLoaded = false;
    m_isFreePlay = false;
    m_octave = 4;
    mapStringsToNotes();

    // WebEngine requires QWidget parent, WebChannel requires QObject parent
    QWebChannel* channel = new QWebChannel(this);
    channel->registerObject("cppBridge", this);

    m_webView = new QWebEngineView(parent);
    m_webView->page()->setWebChannel(channel);
    m_webView->setUrl(QUrl("qrc:/web/index.html"));
    m_webView->show();
}

QWebEngineView* StaffWidget::getWebView() {
    return m_webView;
}

void StaffWidget::jsGetNote(const QJsonObject &data) {
    if(data["pitch"].isUndefined() || data["pitch"].isNull()) {
        return;
    }

    // Receiving the first note from the js-side implies the webpage is completely loaded
    if(!m_isLoaded) {
        m_isLoaded = true;
    }

    int octave = data["octave"].toInt();
    if (octave > m_octave) {
        emit octaveUp();
    }
    if(octave < m_octave) {
        emit octaveDown();
    }
    m_octave = octave;

    m_currentNote = m_stringToNote[data["pitch"].toString()];
    emit highlightNote(m_currentNote);
}

void StaffWidget::loadSong(QString songName) {
    if(!m_isLoaded) {
        return;
    }

    // Run file loading in a callback to ensure load overlay is displayed first, due to how Qt multithreads
    // the webengine. QVariant is required for the callback.
    m_webView->page()->runJavaScript("symphony.showOverlay(true, 'load')", [&, songName] (const QVariant) {
        QFile file(":/res/musicxml/" + songName + ".musicxml");

        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(nullptr, "Error loading music score", file.errorString());
        }

        QTextStream in(&file);
        QString score = in.readAll();

        file.close();
        emit jsLoadXml(score);
    });
}

void StaffWidget::validateNote(Note note) {
    if (!m_isLoaded || m_isFreePlay) {
        return;
    }

    if(note == m_currentNote && m_isLoaded) {
        emit noteValidated();
        nextNote();
    }
}

    void StaffWidget::nextNote() {
    if(m_isLoaded) {
        m_webView->page()->runJavaScript("symphony.gotoNextNote()");
    }
}

void StaffWidget::mapStringsToNotes() {
    m_stringToNote.emplace("A", Note::ANatural);
    m_stringToNote.emplace("B", Note::BNatural);
    m_stringToNote.emplace("C", Note::CNatural);
    m_stringToNote.emplace("D", Note::DNatural);
    m_stringToNote.emplace("E", Note::ENatural);
    m_stringToNote.emplace("F", Note::FNatural);
    m_stringToNote.emplace("G", Note::GNatural);
    m_stringToNote.emplace("A#", Note::ASharp);
    m_stringToNote.emplace("Bb", Note::ASharp);
    m_stringToNote.emplace("C#", Note::CSharp);
    m_stringToNote.emplace("Db", Note::CSharp);
    m_stringToNote.emplace("D#", Note::DSharp);
    m_stringToNote.emplace("Eb", Note::DSharp);
    m_stringToNote.emplace("F#", Note::FSharp);
    m_stringToNote.emplace("Gb", Note::FSharp);
    m_stringToNote.emplace("G#", Note::GSharp);
    m_stringToNote.emplace("Ab", Note::GSharp);
}

void StaffWidget::hideStaff(bool toggle){
    if (!m_isLoaded) {
        return;
    }

    m_isFreePlay = toggle;

    if (toggle) {
        m_webView->page()->runJavaScript("symphony.showOverlay(true, 'freeplay')");
    } else {
        m_webView->page()->runJavaScript("symphony.showOverlay(false, 'freeplay')");
        emit highlightNote(m_currentNote);
    }
}

// Called after song is completely parsed, allows freeplay mode to be selected again
void StaffWidget::jsFinishSongLoad() {
    emit songLoaded();
}
