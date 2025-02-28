#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();

    // These lambda functions require QT5 and C++11 or newer, alternatively use QSignalMapper
    connect(ui->preset_ch1_voltage_3v3, &QAbstractButton::clicked, this, [this]{ setVoltage_ch1(3.3); });
    connect(ui->preset_ch1_voltage_5v0, &QAbstractButton::clicked, this, [this]{ setVoltage_ch1(5.0); });
    connect(ui->preset_ch1_voltage_12v0, &QAbstractButton::clicked, this, [this]{ setVoltage_ch1(12); });
    connect(ui->preset_ch1_voltage_13v8, &QAbstractButton::clicked, this, [this]{ setVoltage_ch1(13.8); });

    connect(ui->preset_ch2_voltage_3v3, &QAbstractButton::clicked, this, [this]{ setVoltage_ch2(3.3); });
    connect(ui->preset_ch2_voltage_5v0, &QAbstractButton::clicked, this, [this]{ setVoltage_ch2(5.0); });
    connect(ui->preset_ch2_voltage_12v0, &QAbstractButton::clicked, this, [this]{ setVoltage_ch2(12); });
    connect(ui->preset_ch2_voltage_13v8, &QAbstractButton::clicked, this, [this]{ setVoltage_ch2(13.8); });

    connect(ui->preset_ch1_current_0a1, &QAbstractButton::clicked, this, [this]{ setCurrent_ch1(0.1); });
    connect(ui->preset_ch1_current_0a5, &QAbstractButton::clicked, this, [this]{ setCurrent_ch1(0.2); });
    connect(ui->preset_ch1_current_1a0, &QAbstractButton::clicked, this, [this]{ setCurrent_ch1(1); });
    connect(ui->preset_ch1_current_2a0, &QAbstractButton::clicked, this, [this]{ setCurrent_ch1(2); });

    connect(ui->preset_ch2_current_0a1, &QAbstractButton::clicked, this, [this]{ setCurrent_ch2(0.1); });
    connect(ui->preset_ch2_current_0a5, &QAbstractButton::clicked, this, [this]{ setCurrent_ch2(0.2); });
    connect(ui->preset_ch2_current_1a0, &QAbstractButton::clicked, this, [this]{ setCurrent_ch2(1); });
    connect(ui->preset_ch2_current_2a0, &QAbstractButton::clicked, this, [this]{ setCurrent_ch2(2); });

    ui->statusbar->showMessage("Not connected");
    ui->menuConnect->setDisabled(1); // FIXME wrap in check if configured either network or USB serial

}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::setVoltage_ch1(double val) {
    ui->voltage_ch1->setValue(val);
    emit ui->voltage_ch1->valueChanged(val);
}

void MainWindow::setCurrent_ch1(double val) {
    ui->current_ch1->setValue(val);
    emit ui->current_ch1->valueChanged(val);
}


void MainWindow::setVoltage_ch2(double val) {
    ui->voltage_ch2->setValue(val);
    emit ui->voltage_ch2->valueChanged(val);
}

void MainWindow::setCurrent_ch2(double val) {
    ui->current_ch2->setValue(val);
    emit ui->current_ch2->valueChanged(val);
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



