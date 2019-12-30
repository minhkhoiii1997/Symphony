#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appcontroller.h"
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <QPushButton>
#include "irrKlang.h"
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Initialization
    AppController* app = new AppController(this);
    m_staff = new StaffWidget(this);
    m_soundEngine = irrklang::createIrrKlangDevice();
    m_octave = 4; // 4 is the middle C octave
    m_isLoadingSong = false;

    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->appLayout);
    mapNotesToButtons();

    // Set up images
    QImage speaker(":/icons/sound_icon.png");
    QPixmap speakerPixmap = QPixmap::fromImage(speaker.scaled(ui->speakerIcon->size()));
    ui->speakerIcon->setPixmap(speakerPixmap);

    // Replace placeholder staff with interactive widget
    QWebEngineView* webview = m_staff->getWebView();
    QSizePolicy sp = webview->sizePolicy();
    sp.setVerticalPolicy(QSizePolicy::Minimum);
    webview->setSizePolicy(sp);
    ui->appTopHalf->replaceWidget(ui->staff, webview);
    ui->staff->deleteLater();

    // Connections
    connect(this, &MainWindow::updateVisualizer,
            app, &AppController::visualizerUpdate);

    for(const auto& pair : m_noteToButton) {
        connect(pair.second.second, &QPushButton::pressed, m_staff, [&] () {
            emit notePressed(pair.first);
            emit updateVisualizer(pair.first);
        });
    }

    // Set up song select menu
    QMap<QString, QString> songs = {
        {"A9_Symphony_Demo", "Demo Song"},
        {"amazingGrace", "Amazing Grace"},
        {"C_Major_Warmup", "C Major Warmup"},
        {"jingleBellRock", "Jingle Bell Rock"},
        {"merryChristmas", "Merry Christmas"},
        {"G_Major_Warmup", "G Major Warmup"},
        {"Learn_Note_Values", "Learn Note Values"},
        {"Learn_Notes_I", "Learn Notes I"},
        {"Learn_Notes_II", "Learn Notes II"}
    };

    QMap<QString, QString> majScales = {
      {"C_Major_Scale", "C Major Scale"},

      {"D_Major_Scale", "D Major Scale"},

      {"Db_Major_Scale", "Db Major Scale"},

      {"E_Major_Scale", "E Major Scale"},

      {"Eb_Major_Scale", "Eb Major Scale"},

      {"G_Major_Scale", "G Major Scale"},

      {"Gb_Major_Scale", "Gb Major Scale"},

      {"F_Major_Scale", "F Major Scale"},

      {"A_Major_Scale", "A Major Scale"},

      {"Ab_Major_Scale", "Ab Major Scale"},

      {"B_Major_Scale", "B Major Scale"},

      {"Bb_Major_Scale", "Bb Major Scale"},

    };
     QMap<QString, QString> minScales = {
         {"C_Minor_Scale", "C Minor Scale"},
         {"D_Minor_Scale", "D Minor Scale"},
         {"Db_Minor_Scale", "Db Minor Scale"},
         {"E_Minor_Scale", "E Minor Scale"},
         {"Eb_Minor_Scale", "Eb Minor Scale"},
         {"G_Minor_Scale", "G Minor Scale"},
         {"Gb_Minor_Scale", "Gb Minor Scale"},
         {"F_Minor_Scale", "F Minor Scale"},
         {"A_Minor_Scale", "A Minor Scale"},
         {"Ab_Minor_Scale", "Ab Minor Scale"},
         {"B_Minor_Scale", "B Minor Scale"},
         {"Bb_Minor_Scale", "Bb Minor Scale"}

     };

    QMenu* learnSelect = ui->Learn_Select;
    QMenu* scaleSelect = ui->Learn_Select->addMenu("Scales");
    QMenu* minorSelect = scaleSelect->addMenu("Minor");
    QMenu* majorSelect = scaleSelect->addMenu("Major");
    QMenu* songSelect = ui->Learn_Select->addMenu("Songs");

    // Cannot use a range based for-loop due to how QMap is implemented
    QMap<QString, QString>::const_iterator iter = songs.begin();
    while (iter != songs.end()) {
        QAction* songName = new QAction(iter.value());
        QString internalSongName = iter.key(); // Must capture by copy to pass into lambda
        connect(songName, &QAction::triggered, m_staff, [&, internalSongName] () {
            m_isLoadingSong = true;
            m_freePlay->setDisabled(true);
            toggleGuidedMode();
            emit songLoad(internalSongName);
        });
        songSelect->addAction(songName);
        ++iter;
    }


    QMap<QString, QString>::const_iterator iter2 = majScales.begin();
    while (iter2 != majScales.end()) {
        QAction* scaleName = new QAction(iter2.value());
        QString internalSongName = iter2.key(); // Must capture by copy to pass into lambda
        connect(scaleName, &QAction::triggered, m_staff, [&, internalSongName] () {
            m_isLoadingSong = true;
            m_freePlay->setDisabled(true);
            toggleGuidedMode();
            emit songLoad(internalSongName);
        });
        majorSelect->addAction(scaleName);
        ++iter2;
    }
    QMap<QString, QString>::const_iterator iter3 = minScales.begin();
    while (iter3 != minScales.end()) {
        QAction* scaleName = new QAction(iter3.value());
        QString internalSongName = iter3.key(); // Must capture by copy to pass into lambda
        connect(scaleName, &QAction::triggered, m_staff, [&, internalSongName] () {
            m_isLoadingSong = true;
            m_freePlay->setDisabled(true);
            toggleGuidedMode();
            emit songLoad(internalSongName);
        });
        minorSelect->addAction(scaleName);
        ++iter3;
    }

    connect(app, &AppController::newHeight, this, [&] (int i, int body) {
        switch(body){
            case 0:
                ui->verticalSlider->setValue(i);
                break;
            case 1:
                ui->verticalSlider_2->setValue(i);
                break;
            case 2:
                ui->verticalSlider_3->setValue(i);
                break;
            case 3:
                ui->verticalSlider_4->setValue(i);
                break;
            case 4:
                ui->verticalSlider_5->setValue(i);
                break;
            case 5:
                ui->verticalSlider_6->setValue(i);
                break;
        }
    });

    QTimer::singleShot(30, app, &AppController::updateWorld);

    //play mode
    QMenu* playMode = ui->menuPlay_Mode;
    m_freePlay = new QAction(tr("Free Play"));
    m_freePlay->setCheckable(true);
    m_freePlay->setChecked(false);
    m_guidedPlay = new QAction(tr("Guided Play"));
    m_guidedPlay->setCheckable(true);
    m_guidedPlay->setChecked(true);
    m_isFreePlayMode = false;
    playMode->addAction(m_freePlay);
    playMode->addAction(m_guidedPlay);

    connect(this, &MainWindow::songLoad,
            m_staff, &StaffWidget::loadSong);

    connect(m_staff, &StaffWidget::songLoaded,
            this, &MainWindow::finishSongLoad);

    connect(m_staff, &StaffWidget::octaveUp,
            this, &MainWindow::octaveUp);

    connect(m_staff, &StaffWidget::octaveDown,
            this, &MainWindow::octaveDown);

    connect(m_freePlay, &QAction::triggered,
            this, &MainWindow::toggleFreeMode);

    connect(m_guidedPlay, &QAction::triggered,
            this, &MainWindow::toggleGuidedMode);

    connect(this, &MainWindow::notePressed,
            this, &MainWindow::playNote);

    connect(this, &MainWindow::hideStaff,
            m_staff, &StaffWidget::hideStaff);

    connect(this, &MainWindow::notePressed,
            m_staff, &StaffWidget::validateNote);

    connect(m_staff, &StaffWidget::highlightNote,
            this, &MainWindow::highlightKey);

    connect(ui->leftButton, &QPushButton::pressed,
            this, &MainWindow::octaveDown);

    connect(ui->rightButton, &QPushButton::pressed,
            this, &MainWindow::octaveUp);

    connect(ui->volumeSlider, &QAbstractSlider::valueChanged,
            this, &MainWindow::volumeSet);

    connect(ui->helpButton, &QPushButton::pressed,
            this, &MainWindow::helpButton);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::helpButton(){
    QMessageBox box;
    int index = 0;
    bool closed = false;
    QAbstractButton* pButtonNo = box.addButton(tr("Previous"), QMessageBox::HelpRole);
    QAbstractButton* pButtonYes = box.addButton(tr("Next!"), QMessageBox::ActionRole);
    QVector<QPixmap> map;
    QPixmap menuImage(":/helpButton/menuOptions.JPG"); map.insert(0, menuImage);
    QPixmap staffImage(":/helpButton/staff.JPG"); map.insert(1, staffImage);
    QPixmap keyboardImage(":/helpButton/the keyboard.JPG"); map.insert(2, keyboardImage);
    QPixmap octaveImage(":/helpButton/octave.JPG");  map.insert(3, octaveImage);
    QPixmap volumeImage(":/helpButton/volumeSlider.JPG"); map.insert(4, volumeImage);
    box.setIconPixmap(map[index]);
    box.exec();
    while(!closed){
        if (box.clickedButton() == pButtonYes) {
            if (index < 4){
                index++;
                qDebug() << "advance";
                box.setIconPixmap(map[index]);
                box.exec();
            }
            else if (index >= 4){
                closed = true;
            }
        }
        if (box.clickedButton() == pButtonNo){
            if (index > 0){
                index--;
                qDebug() << "previous";
                box.setIconPixmap(map[index]);
                box.exec();
            }
            else if(index <= 0){
                closed = true;
            }
        }
        if (closed){
            box.close();
        }
    }
}

void MainWindow::highlightKey(Note n) {
    if(!m_isFreePlayMode) {
        for(const auto& pair : m_noteToButton) {
            pair.second.second->setStyleSheet("");
        }
        m_noteToButton[n].second->setStyleSheet("background-color: #e81123;");
    }
}

void MainWindow::playNote(Note n) {
        std::string note = "res/PianoKeys/" + m_noteToButton[n].first + std::to_string(m_octave) + ".wav";
        m_soundEngine->play2D(note.c_str());
}

void MainWindow::mapNotesToButtons() {
    m_noteToButton.emplace(Note::ANatural, std::pair<std::string, QPushButton*>("A", ui->aNaturalButton));
    m_noteToButton.emplace(Note::BNatural, std::pair<std::string, QPushButton*>("B", ui->bNaturalButton));
    m_noteToButton.emplace(Note::CNatural, std::pair<std::string, QPushButton*>("C", ui->cNaturalButton));
    m_noteToButton.emplace(Note::DNatural, std::pair<std::string, QPushButton*>("D", ui->dNaturalButton));
    m_noteToButton.emplace(Note::ENatural, std::pair<std::string, QPushButton*>("E", ui->eNaturalButton));
    m_noteToButton.emplace(Note::FNatural, std::pair<std::string, QPushButton*>("F", ui->fNaturalButton));
    m_noteToButton.emplace(Note::GNatural, std::pair<std::string, QPushButton*>("G", ui->gNaturalButton));
    m_noteToButton.emplace(Note::ASharp, std::pair<std::string, QPushButton*>("Bb", ui->aSharpButton));
    m_noteToButton.emplace(Note::CSharp, std::pair<std::string, QPushButton*>("Db", ui->cSharpButton));
    m_noteToButton.emplace(Note::DSharp, std::pair<std::string, QPushButton*>("Eb", ui->dSharpButton));
    m_noteToButton.emplace(Note::FSharp, std::pair<std::string, QPushButton*>("Gb", ui->fSharpButton));
    m_noteToButton.emplace(Note::GSharp, std::pair<std::string, QPushButton*>("Ab", ui->gSharpButton));
}

void MainWindow::volumeSet(int volume) {
    m_soundEngine->setSoundVolume(static_cast<float32>(volume/100.0f));
}

void MainWindow::octaveDown() {
    if(m_octave > 3) {
        m_octave--;
    }
}

void MainWindow::octaveUp() {
    if(m_octave < 6) {
        m_octave++;
    }
}

void MainWindow::resetOctave() {
    m_octave = 4;
}

void MainWindow::finishSongLoad () {
    m_isLoadingSong = false;
    m_freePlay->setDisabled(false);
}

void MainWindow::toggleFreeMode() {
    if (m_isLoadingSong) {
        return;
    }

    m_isFreePlayMode = true;
    m_freePlay->setChecked(m_isFreePlayMode);
    m_guidedPlay->setChecked(!m_isFreePlayMode);

    emit hideStaff(true);

    for(const auto& pair : m_noteToButton) {
        pair.second.second->setStyleSheet("");
    }

    resetOctave();
}

void MainWindow::toggleGuidedMode() {
    m_isFreePlayMode = false;
    m_freePlay->setChecked(m_isFreePlayMode);
    m_guidedPlay->setChecked(!m_isFreePlayMode);
    emit hideStaff(false);
}
