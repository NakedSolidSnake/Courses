#ifndef CPPWORKER_H
#define CPPWORKER_H

#include <QObject>

class CppWorker : public QObject
{
    Q_OBJECT
public:
    explicit CppWorker(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CPPWORKER_H