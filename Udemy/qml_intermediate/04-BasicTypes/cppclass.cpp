#include "cppclass.h"

CppClass::CppClass(QObject *parent) : QObject(parent)
{

}

void CppClass::cppSlot()
{
    emit sendInt(123);
}
