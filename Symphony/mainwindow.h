#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "irrKlang.h"
#include <unordered_map>
#include "notes.h"
#include "staffwidget.h"
#include "appcontroller.h"
#include "ik_vec3d.h"
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <QPushButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::map<Note, std::pair<std::string, QPushButton*>> m_noteToButton;
    irrklang::ISoundEngine* m_soundEngine;
    StaffWidget* m_staff;
    int m_octave;
    bool m_isLoadingSong; // Prevents switching to freeplay while loading a song
    bool m_isFreePlayMode;
    QAction* m_guidedPlay;
    QAction* m_freePlay;

    //helper functions
    void mapNotesToButtons();
    void resetOctave();

signals:
    void updateVisualizer(Note);
    void notePressed(Note);
    void songLoad(QString);
    void hideStaff(bool);

public slots:
    void highlightKey(Note);
    void volumeSet(int volume);
    void octaveDown();
    void octaveUp();
    void toggleFreeMode();
    void toggleGuidedMode();
    void playNote(Note);
    void finishSongLoad();
    void helpButton();
};
#endif // MAINWINDOW_H
