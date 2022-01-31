#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoWidget.h"
#include "color.h"
#include <QPushButton>
#include <QStyle>


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

    ui->soundButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->soundSlider->setRange(0 , 100);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete colorWindow;
    delete player;
    delete vw;
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

    ui->playlist->addItem(fileName);

    player->setMedia(QUrl::fromLocalFile(fileName));
    on_actionplay_triggered();

}


void MainWindow::on_actionfullscreen_triggered()
{
    vw->setFullScreen(true);
}


void MainWindow::on_soundButton_clicked()
{
    if (muted)
    {
        player->setMuted(!muted);
        ui->soundButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    }else{
        player->setMuted(!muted);
        ui->soundButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
    }

    muted = !muted;
}


void MainWindow::on_soundSlider_valueChanged(int value)
{
     player->setVolume(value);
}





void MainWindow::on_colorButton_clicked()
{
    colorWindow = new color(this);
    colorWindow->transfer(vw);
    colorWindow->show();
}


void MainWindow::on_playlist_currentIndexChanged(const QString &arg1)
{
    player->setMedia(QUrl::fromLocalFile(arg1));
    on_actionplay_triggered();
}

