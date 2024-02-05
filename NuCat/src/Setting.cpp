#include "Setting.h"
Setting* Setting::instance = nullptr;
std::string Setting::GetTheme()
{
	json::value& JsonRoot= *Json;
	std::string ThemeName = JsonRoot.get("Theme","default");
	return ThemeName;
}
std::string Setting::GetLanguage(std::string Default)
{
	json::value& JsonRoot = *Json;
	std::string ThemeName = JsonRoot.get("Language", "");
	return ThemeName;
}

json::value Setting::operator[](std::string key)
{
	return (*Json)[key];
}
Setting::Setting()
{
	FileStream = new FileReader(".\\Config\\Setting.json");
	auto [result, data] = FileStream->ReadContent();
	if (!result) {
		// 失败处理
	}
	Json = json::parse(data);
}

Setting::~Setting()
{
}

Setting* Setting::GetInstance()
{
	if (instance == nullptr) {
		instance = new Setting();
	}
	return instance;
}
