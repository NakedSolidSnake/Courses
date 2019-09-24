#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QObject>

class CpuWidget : public QObject
{
    Q_OBJECT
public:
    explicit CpuWidget(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CPUWIDGET_H