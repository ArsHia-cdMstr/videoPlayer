#ifndef COLOR_H
#define COLOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class color;
}

class color : public QMainWindow
{
    Q_OBJECT

public:
    explicit color(QWidget *parent = nullptr);
    ~color();

    void transfer(QMediaPlayer* , QVideoWidget*);

private slots:



    void on_resetButton_clicked();

private:
    Ui::color *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
};

#endif // COLOR_H
