#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <string>
#include "FileReader.h"
#include "json.hpp"

class Language
{
public:
	std::optional<json::value> Json;
	FileReader* FileStream;
	Language(const std::string& Id, std::string Lang, std::string File);
	~Language();
	const std::string GetFilePath() const;
	const std::string GetLangName() const;
	const std::string GetIdName() const;
	bool WriteJsonData();
private:
	std::string IdName;
	std::string LangName;
	std::string FilePath;
};

class LangFactory {
public:

	static std::shared_ptr<Language> GetThemeInstance(const std::string& ThemeName, const std::string& LangName);
	static std::shared_ptr<Language> GetSysInstance(const std::string& LangName);
	// 该方法不会创建实例 返回最新实例
	static std::shared_ptr<Language> GetCurrentSysInstance();
	// 该方法不会创建实例 返回最新实例
	static std::shared_ptr<Language> GetCurrentThemeInstance();
private:
	LangFactory() = default;
	static std::string CurrentThemeId;
	static std::string CurrentSysId;
	static std::map<std::string, std::shared_ptr<Language>> InstancesMap;
};
