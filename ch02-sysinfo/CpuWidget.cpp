#include "CpuWidget.h"
#include "SysInfo.h"

#include <QDebug>

using namespace QtCharts;

CpuWidget::CpuWidget(QWidget *parent)
    : SysInfoWidget(parent)
    , mSeries(new QPieSeries(this))
{
    mSeries->setHoleSize(0.35);

    QChart *chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU average load");
}

void CpuWidget::updateSeries()
{
    double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();
    mSeries->clear();
    mSeries->append("Load", cpuLoadAverage);
    mSeries->append("Free", 100.0 - cpuLoadAverage);
}
