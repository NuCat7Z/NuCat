#pragma once
#include <iostream>
#include <string>
#include "json.hpp"
#include "FileReader.h"
class Setting
{
public:
	std::optional<json::value> Json;
	FileReader* FileStream;
	static Setting* instance;
	std::string GetTheme();
	std::string GetLanguage(std::string Default);
	json::value operator[](std::string key);
	Setting();
	~Setting();
	static Setting* GetInstance();
private:

};
