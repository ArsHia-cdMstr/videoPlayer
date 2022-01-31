#include "color.h"
#include "ui_color.h"

color::color(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::color)
{
    ui->setupUi(this);
}

color::~color()
{
    delete ui;
}

void color::transfer( QVideoWidget* v)
{
    vw = v;

    connect(ui->Bslider, &QSlider::sliderMoved, vw, &QVideoWidget::setBrightness);
    connect(vw, &QVideoWidget::brightnessChanged, ui->Bslider, &QSlider::setValue);

    connect(ui->Cslider, &QSlider::sliderMoved, vw, &QVideoWidget::setContrast);
    connect(vw, &QVideoWidget::contrastChanged, ui->Cslider, &QSlider::setValue);

    connect(ui->Hslider, &QSlider::sliderMoved, vw, &QVideoWidget::setHue);
    connect(vw, &QVideoWidget::hueChanged, ui->Hslider, &QSlider::setValue);

    connect(ui->Sslider, &QSlider::sliderMoved, vw, &QVideoWidget::setSaturation);
    connect(vw, &QVideoWidget::saturationChanged, ui->Sslider, &QSlider::setValue);

}




void color::on_resetButton_clicked()
{
    ui->Bslider->setValue(0);
    vw->setBrightness(0);
    ui->Cslider->setValue(0);
    vw->setContrast(0);
    ui->Hslider->setValue(0);
    vw->setHue(0);
    ui->Sslider->setValue(0);
    vw->setSaturation(0);
}

