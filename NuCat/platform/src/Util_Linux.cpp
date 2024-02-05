#include "Util.h"

std::string Util::GetLangLocale()
{
	std::string LocaleName = std::getenv("LANG");
	size_t pos = LocaleName.find(".");
	std::string part;
	if (pos != std::string::npos) {
		return  Util::StringtoLowerCase(LocaleName.substr(0, pos));
	}
	return "zh-cn";
}
bool Util::CheckWebviewEnvironment()
{
	return true;
}
