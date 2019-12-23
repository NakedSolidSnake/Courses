#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sendInt(int val);
    void sendDouble(double val);

public slots:
    void cppSlot();
};

#endif // CPPCLASS_H
