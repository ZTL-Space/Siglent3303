#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::loadSettings() {

    QSettings settings; // default constructor, uses QApplications settings for path and file name

    double voltage_ch1 = settings.value("voltage_ch1", 5).toDouble();
    double current_ch1 = settings.value("current_ch1", 0.1).toDouble();
    double voltage_ch2 = settings.value("voltage_ch2", 5).toDouble();
    double current_ch2 = settings.value("current_ch2", 0.1).toDouble();

    ui->voltage_ch1->setValue( voltage_ch1 );
    ui->current_ch1->setValue( current_ch1 );
    ui->voltage_ch2->setValue( voltage_ch2 );
    ui->current_ch2->setValue( current_ch2 );
}


void MainWindow::saveSettings() {

    QSettings settings; // default constructor, uses QApplications settings for path and file name

    double voltage_ch1 = ui->voltage_ch1->value();
    double current_ch1 = ui->current_ch1->value();
    double voltage_ch2 = ui->voltage_ch2->value();
    double current_ch2 = ui->current_ch2->value();

    settings.setValue("voltage_ch1", voltage_ch1);
    settings.setValue("current_ch1", current_ch1);
    settings.setValue("voltage_ch2", voltage_ch2);
    settings.setValue("current_ch2", current_ch2);
}
