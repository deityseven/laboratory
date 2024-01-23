#ifndef DATAMANAGER_H
#define DATAMANAGER_H

//system library

//c library

//c++ library

//QT library
#include <qvector.h>
#include <qstring.h>
#include <qqueue.h>
#include <qmap.h>
#include <qmutex.h>
#include <qreadwritelock.h>

//other
#include "util.h"
#include "common.h"


/**
	保存本程序所有数据 ,这是个单例类 ,全局可用
*/

#define dataManager DataManager::instance()

class DataManager
{
	Singleton(DataManager);
public:

private:
	DataManager() {}
};

#endif // DATAMANAGER_H
