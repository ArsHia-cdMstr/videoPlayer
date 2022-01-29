#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
//    vw->setGeometry(10,10,600,200);

    player->setVideoOutput(vw);
    this->setCentralWidget(vw);


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

