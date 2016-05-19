#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->verticalSlider, &QSlider::valueChanged,
            ui->progressBar, &QProgressBar::setValue); ///< Значение слайдера меняется -> задаётся новое значение у прогрессбара.
}

MainWindow::~MainWindow()
{
    delete ui;
}
