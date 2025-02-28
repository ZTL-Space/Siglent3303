#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void loadSettings();
    void saveSettings();

private slots:
    void setVoltage_ch1(double val);
    void setCurrent_ch1(double val);
    void setVoltage_ch2(double val);
    void setCurrent_ch2(double val);


};
#endif // MAINWINDOW_H
