#ifndef ERRORLEVEL_H
#define ERRORLEVEL_H

#include <QObject>

class ErrorLevel : public QObject
{
    Q_OBJECT
public:
    explicit ErrorLevel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ERRORLEVEL_H