#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DisplayContact();
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct person_t {QString first_name;
                 QString last_name;
                 QString  phone_number;};

bool MainWindow::is_phone_number_valid(QString phone_number)
{
    for (QChar i : phone_number)
        if(!i.isDigit())
            return false;
    return true;
}

bool MainWindow::is_name_valid(QString first_name)
{
    for (QChar i : first_name)
        if(!i.isLetter())
            return false;
    return true;
}

bool MainWindow::is_lastname_valid(QString last_name)
{
    for (QChar i : last_name)
        if(!i.isLetter())
            return false;
    return true;
}
void MainWindow::tests()
{
    QFile file("db.txt");
    assert(is_phone_number_valid("1234567890"));
    assert(is_name_valid("Данил"));
    assert(is_name_valid("Danil"));
    assert(is_lastname_valid("Скуратов"));
    assert(is_lastname_valid("Skuratov"));
}
void MainWindow::SaveContact(const person_t &person)
{
    QFile file("db.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        // Преобразование данных типа person_t в формат, который QDataStream может записать
        out << person.first_name << "\t"  << person.last_name << "\t" << person.phone_number << "\n";
        file.close();
        update();
    } else {
        qDebug() << "Failed to open file for writing";
    }
}

void MainWindow::DisplayContact()
{
    QFile file("db.txt");
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            QString text;
            while (!in.atEnd()) {
                QString line = in.readLine();
                text += line + "\n";
            }
            file.close();

            ui->textEdit->setText(text); // Предполагается, что у вас есть указатель на QTextEdit с именем textEdit
        } else {
            qDebug() << "Failed to open file for reading";
        }
}


void MainWindow::on_writeContact_clicked()
{
    QString fn = ui->lineEdit->text();
    QString ln = ui->lineEdit_2->text();
    QString tl = ui->lineEdit_3->text();
    if (!is_phone_number_valid(tl) || tl == "")
        ui->label_4->setText("Номер неправильный!");
    else if (!is_name_valid(fn) || fn == "")
        ui->label_4->setText("Неправильное имя!");
    else if (!is_lastname_valid(ln) || ln == "")
        ui->label_4->setText("Неправильная фамилия!");
    else
    {
        ui->label_4->setText("");
        person_t person;
        person.first_name = fn;
        person.last_name = ln;
        person.phone_number = tl;
        SaveContact(person);
        DisplayContact();
    }
}

