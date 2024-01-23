#include "config.h"
#include <qsettings.h>
#include "data_manager.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qfont.h>

Config::Config()
{
	QSettings settings("./configs/intelligent.ini", QSettings::IniFormat);

	settings.beginGroup("HttpPlatform");
	QString host = settings.value("host").toString();
	int port     = settings.value("port").toInt();
	dataManager.httpPlatformConfig.host = host.toStdString();
	dataManager.httpPlatformConfig.port = port;
	settings.endGroup();
	
	//加载字体
	QFont font(":/pfm.ttf");
	qApp->setFont(font);

	//加载界面UI
	QFile file(":/defaultskin.qss");
	file.open(QIODevice::ReadOnly);
	qApp->setStyleSheet(file.readAll());
}

Config::~Config()
{
}
