#ifndef SYSINFOWINDOWIMPL_H
#define SYSINFOWINDOWIMPL_H

#include <QtGlobal>
#include <QVector>

#include "sysinfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowImpl : public SysInfo
{
public:
    SysInfoWindowImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;
    QVector<qulonglong> mCpuLoadLastValues;
 };

#endif // SYSINFOWINDOWIMPL_H
