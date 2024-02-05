#include "Language.h"
std::string LangFactory::CurrentThemeId;
std::string LangFactory::CurrentSysId;
std::map<std::string, std::shared_ptr<Language>> LangFactory::InstancesMap;

Language::Language(const std::string& Id, std::string Lang, std::string File)
{
	FileStream = new FileReader(File);
	auto [result, data] = FileStream->ReadContent();
	if (!result) {
		// 失败处理
	}
	Json = json::parse(data);
	IdName = Id;
	LangName = Lang;
	FilePath = File;
}
Language::~Language()
{
	if (FileStream) delete FileStream;
}

const std::string Language::GetIdName() const
{
	return IdName;
}
// 语言没事一般不改用不着
bool Language::WriteJsonData()
{
	return false;
}

const std::string Language::GetFilePath() const
{
	return FilePath;
}

const std::string Language::GetLangName() const
{
	return LangName;
}

std::shared_ptr<Language> LangFactory::GetThemeInstance(const std::string& ThemeName, const std::string& LangName)
{
	std::string IdName = "Theme-" + ThemeName + "-" + LangName;
	CurrentThemeId = IdName;
	std::string FilePath = ".\\Theme\\" + ThemeName + "\\Language\\" + LangName + ".json";
	auto it = InstancesMap.find(IdName);
	if (it == InstancesMap.end()) {
		auto instance = std::make_shared<Language>(IdName, LangName, FilePath);
		InstancesMap[IdName] = instance;
		return instance;
	}
	else {
		return it->second;
	}
}

std::shared_ptr<Language> LangFactory::GetSysInstance(const std::string& LangName)
{
	std::string IdName = "Sys-" + LangName;
	CurrentSysId = IdName;
	std::string FilePath = ".\\Language\\" + LangName + ".json";
	auto it = InstancesMap.find(IdName);
	if (it == InstancesMap.end()) {
		auto instance = std::make_shared<Language>(IdName, LangName, FilePath);
		InstancesMap[IdName] = instance;
		return instance;
	}
	else {
		return it->second;
	}
}

std::shared_ptr<Language> LangFactory::GetCurrentSysInstance()
{
	auto it = InstancesMap.find(CurrentSysId);
	if (it == InstancesMap.end()) {
		return nullptr;
	}
	else {
		return it->second;
	}
}

std::shared_ptr<Language> LangFactory::GetCurrentThemeInstance()
{
	auto it = InstancesMap.find(CurrentThemeId);
	if (it == InstancesMap.end()) {
		return nullptr;
	}
	else {
		return it->second;
	}
}
