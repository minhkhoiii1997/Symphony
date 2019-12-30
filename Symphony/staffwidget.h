#ifndef WEBCONTROLLER_H
#define WEBCONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <unordered_map>
#include "notes.h"

class StaffWidget : public QObject
{
    Q_OBJECT
public:
    explicit StaffWidget(QWidget *parent = nullptr);
    QWebEngineView* getWebView();

private:
    // Translates JavaScript strings to C++ Note enum
    std::map<QString, Note> m_stringToNote;
    Note m_currentNote;
    QWebChannel* m_channel;
    QWebEngineView* m_webView;
    bool m_isLoaded;
    bool m_isFreePlay;
    void mapStringsToNotes();
    int m_octave;

signals:
    void noteValidated();
    void highlightNote(Note);
    void songLoaded();
    void octaveUp();
    void octaveDown();
    QString jsLoadXml(QString xml);

public slots:
    void jsGetNote(const QJsonObject &datafromjs);
    void jsFinishSongLoad();
    void validateNote(Note);
    void nextNote();
    void loadSong(QString);
    void hideStaff(bool);
};

#endif // WEBCONTROLLER_H
