#pragma once
#include <iostream>
#include <string>
namespace Util {
	std::string GetLangLocale();
	std::string StringtoLowerCase(const std::string& input);
	bool CheckWebviewEnvironment();
}