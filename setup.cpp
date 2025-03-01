#include "setup.h"
#include "ui_setup.h"
#include <QSettings>
#include <QDir>


Setup::Setup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Setup)
{
    ui->setupUi(this);
}

Setup::~Setup()
{
    saveSettings();
    delete ui;
}



void Setup::loadSettings() {

    QSettings settings; // default constructor, uses QApplications settings for path and file name

    QString ip_address = settings.value("setup/ip_address", "").toString();
    QString ip_portnumber = settings.value("setup/ip_portnumber", "5025").toString();
    bool useNetworking = settings.value("setup/useNetworking", 0).toBool();

    QString serial_device = settings.value("setup/serial_device", "").toString();
    QString serial_speed = settings.value("setup/serial_speed", "115200").toString();
    bool useSerial = settings.value("setup/useSerial", 0).toBool();

    //useNetworking and useSerial are mutally exclusive, check that they not both enabled. If so, set networking as enabled, serial as disabled
    if (useNetworking && useSerial) {
            useNetworking = true;
            useSerial = false;
        };

    ui->ip_adress->setText(ip_address);
    ui->ip_portnumber->setText( ip_portnumber );
    ui->use_connection_network->setChecked( useNetworking );

    ui->serial_device->addItems( getSortedListofSerialPorts() );
    ui->serial_speed->setText( serial_speed );
    ui->use_connection_serial->setChecked( useSerial );

}


void Setup::saveSettings() {

    QSettings settings; // default constructor, uses QApplications settings for path and file name

    QString ip_address = ui->ip_adress->text();
    int ip_portnumber = ui->ip_portnumber->text().toInt();
    bool useNetworking = ui->use_connection_network->isChecked();

    QString serial_device = ui->serial_device->currentText();
    int serial_speed = ui->serial_speed->text().toInt();
    bool useSerial = ui->use_connection_serial->isChecked();

    settings.setValue("setup/ip_address", ip_address);
    settings.setValue("setup/ip_portnumber", ip_portnumber);
    settings.setValue("setup/useNetworking", useNetworking);

    settings.setValue("setup/serial_device", serial_device);
    settings.setValue("setup/serial_speed", serial_speed);
    settings.setValue("setup/useSerial", useSerial);

}

QStringList Setup::getSortedListofSerialPorts() {
    // Linux specific, I dont care about win, ios etc.

    QDir d("/dev/serial/by-id/");
    QFileInfoList files = d.entryInfoList(QDir::Files | QDir::NoDot | QDir::NoDotDot);

    static QStringList list;

    for (int i=0; i < files.size(); i++) {
        if (files[i].isSymbolicLink()) {
            list.append( files[i].symLinkTarget() );
        }
    }

    list.sort();
    return list;
}




