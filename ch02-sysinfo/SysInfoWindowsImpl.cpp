#include "SysInfoWindowsImpl.h"

#include <Windows.h>

SysInfoWindowsImpl::SysInfoWindowsImpl()
    : SysInfo()
    , mCpuLoadLastValues()
{

}

double SysInfoWindowsImpl::memoryUsed()
{
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memoryStatus);
    qulonglong memoryPhysicalUsed = memoryStatus.ullTotalPhys - memoryStatus.ullAvailPhys;

    return (double)memoryPhysicalUsed / (double)memoryStatus.ullTotalPhys * 100.0;
}

void SysInfoWindowsImpl::init()
{
    mCpuLoadLastValues = cpuRawData();
}

QVector<qulonglong> SysInfoWindowsImpl::cpuRawData()
{
    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    GetSystemTimes(&idleTime, &kernelTime, &userTime);

    QVector<qulonglong> rawData;

    rawData.append(convertFileTime(idleTime));
    rawData.append(convertFileTime(kernelTime));
    rawData.append(convertFileTime(userTime));

    return rawData;
}

qulonglong SysInfoWindowsImpl::convertFileTime(const FILETIME &filetime) const
{
    ULARGE_INTEGER laregeInteger;
    laregeInteger.LowPart = filetime.dwLowDateTime;
    laregeInteger.HighPart = filetime.dwHighDateTime;
    return laregeInteger.QuadPart;
}

double SysInfoWindowsImpl::cpuLoadAverage()
{
    QVector<qulonglong> firstSample = mCpuLoadLastValues;
    QVector<qulonglong> secondSample = cpuRawData();
    mCpuLoadLastValues = secondSample;

    qulonglong currentIdle = secondSample[0] - firstSample[0];
    qulonglong currentKernel = secondSample[1] - firstSample[1];
    qulonglong currentUser = secondSample[2] - firstSample[2];
    qulonglong currentSystem = currentKernel + currentUser;

    double percent = (currentSystem - currentIdle) * 100.0 / currentSystem;

    return qBound(0.0, percent, 100.0);
}


