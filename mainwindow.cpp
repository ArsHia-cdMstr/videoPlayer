#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoWidget.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new VideoWidget(this);
    player->setVideoOutput(vw);
    ui->display->addWidget(vw);

    connect(player ,&QMediaPlayer::durationChanged ,ui->durationSlider ,&QSlider::setMaximum);
    connect(player ,&QMediaPlayer::positionChanged ,ui->durationSlider ,&QSlider::setValue);
    connect(ui->durationSlider ,&QSlider::sliderMoved ,player ,&QMediaPlayer::setPosition);
    ui->durationSlider->setRange(0,player->duration()/1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionstop_triggered()
{
    player->stop();
}


void MainWindow::on_actionpause_triggered()
{
    player->pause();
}


void MainWindow::on_actionplay_triggered()
{
    player->play();
}


void MainWindow::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open a file", "" , "video file(*.*)");
    on_actionstop_triggered();

    player->setMedia(QUrl::fromLocalFile(fileName));
    on_actionplay_triggered();

}


void MainWindow::on_actionfullscreen_triggered()
{
    vw->setFullScreen(true);
}
