#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool is_phone_number_valid(std::string  phone_number);
    bool is_name_valid(std::string first_name, std::string last_name);
    void SaveContact();
    void DisplayContact();
    struct person_t {QString first_name;
                     QString last_name;
                     QString  phone_number;};
    QList <person_t> buffer;
private slots:
    void writeContact(const person_t &person);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
