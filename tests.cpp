#include "mainwindow.h"
#include<QFile>
bool is_phone_number_valid(QString phone_number)
{
    for (QChar i : phone_number)
        if(!i.isDigit())
            return false;
    return true;
}

bool is_name_valid(QString first_name)
{
    for (QChar i : first_name)
        if(!i.isLetter())
            return false;
    return true;
}

bool is_lastname_valid(QString last_name)
{
    for (QChar i : last_name)
        if(!i.isLetter())
            return false;
    return true;
}
void tests()
{
    assert(is_phone_number_valid("1234567890"));
    assert(is_name_valid("Данил"));
    assert(is_name_valid("Danil"));
    assert(is_lastname_valid("Скуратов"));
    assert(is_lastname_valid("Skuratov"));
}
