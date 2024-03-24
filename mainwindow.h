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
//    bool is_phone_number_valid(QString phone_number);
//    bool is_name_valid(QString first_name);
//    bool is_lastname_valid(QString last_name);
    void DisplayContact();
//    void tests();
    struct person_t {QString first_name;
                     QString last_name;
                     QString  phone_number;};
    QList <person_t> buffer;

private slots:

    void SaveContact(const person_t &person);
    void on_writeContact_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
