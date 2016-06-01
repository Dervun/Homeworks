#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setEnabledButtons(false);
    connect(ui->actionSave_As, &QAction::triggered,
            this, &MainWindow::saveQuote);
    connect(&bash, &Bash::quotesLoaded,    /// По окончании загрузки цитат отобразить следующую, то есть первую.
            this, &MainWindow::nextQuote);
    connect(ui->rateUpButton, &QPushButton::clicked,
            this, &MainWindow::rateUp);
    connect(ui->rateDownButton, &QPushButton::clicked,
            this, &MainWindow::rateDown);
    connect(ui->bayanButton, &QPushButton::clicked,
            this, &MainWindow::bayan);
    connect(ui->nextButton, &QPushButton::clicked,
            this, &MainWindow::nextQuote);
    connect(ui->previosButton, &QPushButton::clicked,
            this, &MainWindow::previosQuote);
    connect(ui->refreshButton, &QPushButton::clicked,
            this, &MainWindow::refresh);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setEnabledButtons(bool state)
{
    ui->bayanButton->setEnabled(state);
    ui->rateDownButton->setEnabled(state);
    ui->rateUpButton->setEnabled(state);
    ui->nextButton->setEnabled(state);
    ui->previosButton->setEnabled(state);
    ui->refreshButton->setEnabled(state);
}

void MainWindow::setRateButtonsDisabled()
{
    ui->bayanButton->setEnabled(false);
    ui->rateDownButton->setEnabled(false);
    ui->rateUpButton->setEnabled(false);
}

void MainWindow::fillContent(QString quote)
{
    ui->ContentText->setText(quote);      /// Заполняем поле новой цитатой
    refreshCurrentQuote(quote);
    ui->ratingDisplayingLabel->setText(QString::number(bash.getCurrentRating()));  /// Выставляем соответствующий рейтинг
    this->setWindowTitle(bash.getId() + " quote");  /// В заголовок окна ставим номер цитаты
    refreshCurrentNumberOfQuote(bash.getId());
    setEnabledButtons(true);  /// Включаем кнопки, чтобы можно было пользоваться программой
}

void MainWindow::refreshCurrentNumberOfQuote(const QString &string)
{
    currentNumberOfQuote.clear();
    currentNumberOfQuote = string;
}

void MainWindow::refreshCurrentQuote(const QString &string)
{
    currentQuote.clear();
    currentQuote = string;
}

void MainWindow::rateUp()
{
    bash.rateUp();  /// Повышаем рейтинг
    ui->ratingDisplayingLabel->setText(QString::number(ui->ratingDisplayingLabel->text().toInt() + 1)); /// Увеличиваем счётчик рейтинга на экране на 1
    setRateButtonsDisabled();  /// Выключаем кнопки изменения рейтинга, потому что их больше нет смысла нажимать.
}

void MainWindow::rateDown()
{
    bash.rateDown(); /// Понижаем рейтинг
    ui->ratingDisplayingLabel->setText(QString::number(ui->ratingDisplayingLabel->text().toInt() - 1)); /// Уменьшаем счётчик рейтинга на экране на 1
    setRateButtonsDisabled(); /// Выключаем кнопки изменения рейтинга, потому что их больше нет смысла нажимать.
}

void MainWindow::bayan()
{
    bash.bayan();
    setRateButtonsDisabled(); /// Выключаем кнопки изменения рейтинга, потому что их больше нет смысла нажимать.
}

void MainWindow::nextQuote()
{
    fillContent(bash.getNextQuote()); /// Загружаем следующую цитату, заполняем соответствующую информацию
}

void MainWindow::previosQuote()
{
    fillContent(bash.getPreviosQuote()); /// Загружаем предыдущую цитату, заполняем соответствующую информацию
}

void MainWindow::refresh()
{
    setEnabledButtons(false);  /// Выключаем кнопки на время обновления информации
    ui->ContentText->setText("Please wait.\nLoading relevant quotations from bash.im");  /// Просим пользователя подождать, пока загрузятся цитаты
    bash.refreshQuotes();
}

void MainWindow::saveQuote()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Bash.im - Save As", currentNumberOfQuote + " quote", "Text Files (*.txt);;All Files (*.*)");
    QFile file(fileName);
    if (file.open(QFile::WriteOnly))
    {
        QTextStream out(&file);
        out << currentNumberOfQuote << "\n" << currentQuote;
        file.close();
    }
}

