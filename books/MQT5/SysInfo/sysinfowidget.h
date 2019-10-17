#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr,
                           int startDelayMs = 500,
                           int updateSeriesDelayMs = 500);

signals:

public slots:

protected:
    QtCharts::QChartView& chartView();

protected slots:
    virtual void updateSeries() = 0;

private:
    QTimer mResfreshTimer;
    QtCharts::QChartView mChartView;
};

#endif // SYSINFOWIDGET_H
