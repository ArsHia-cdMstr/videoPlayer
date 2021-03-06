#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "color.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>
#include <QProgressBar>
#include <QBoxLayout>
#include <QGroupBox>
#include <QDialog>
#include <QFormLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionstop_triggered();

    void on_actionpause_triggered();

    void on_actionplay_triggered();

    void on_actionopen_triggered();

    void on_actionfullscreen_triggered();

    void on_soundButton_clicked();

    void on_soundSlider_valueChanged(int value);

    void on_colorButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_actionpast_triggered();

    void on_actionnext_triggered();

    void on_playlistN_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QMediaPlayer* player;
    QVideoWidget* vw;
    bool muted = false ;
    color* colorWindow ;

    QUrl filenames [100] ;
    int lastIndex = 0 ;

};
#endif // MAINWINDOW_H
