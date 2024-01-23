#ifndef CONFIG_H
#define CONFIG_H

#include "util.h"

#define config Config::instance()

class Config
{
public:
	Singleton(Config);
	~Config();
private:
	Config();
};











#endif // !CONFIG_H
