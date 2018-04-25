#include "SysInfo.h"

#include <QtGlobal>

#ifdef Q_OS_WIN

#elif defined(Q_OS_MAC)
    #include "SysInfoMacImpl.h"
#elif defined(Q_OS_LINUX)

#endif

SysInfo& SysInfo::instance()
{
    #ifdef Q_OS_WIN

    #elif defined(Q_OS_MAC)
        static SysInfoMacImpl singleton;
    #elif defined(Q_OS_LINUX)

    #endif

    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}
