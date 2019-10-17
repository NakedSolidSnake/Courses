#include "sysinfowidget.h"

#include <QVBoxLayout>

using namespace QtCharts;

SysInfoWidget::SysInfoWidget(QWidget *parent,
                             int startDelayMs,
                             int updateSeriesDelayMs) :
    QWidget(parent),
    mChartView(this)
{
    mResfreshTimer.setInterval(updateSeriesDelayMs);
    connect(&mResfreshTimer,
            &QTimer::timeout,
            this,
            &SysInfoWidget::updateSeries);

    QTimer::singleShot(startDelayMs,
                       [this]{
        mResfreshTimer.start();
    });

    mChartView.setRenderHint(QPainter::Antialiasing);
    mChartView.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&mChartView);
    setLayout(layout);
}

QChartView& SysInfoWidget::chartView()
{
    return mChartView;
}


