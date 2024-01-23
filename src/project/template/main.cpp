#include <QtWidgets/QApplication>

#include "config.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	config;

	return a.exec();
}

