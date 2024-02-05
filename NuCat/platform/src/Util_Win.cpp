#include "Util.h"
#include <Windows.h>
#include "WebView2.h"
std::string Utf16ToUtf8(const std::wstring& utf16) {
	int length = WideCharToMultiByte(CP_UTF8, 0, utf16.c_str(), -1, NULL, 0, NULL, NULL);
	std::string utf8(length, 0);
	WideCharToMultiByte(CP_UTF8, 0, utf16.c_str(), -1, &utf8[0], length, NULL, NULL);
	utf8.pop_back();
	return utf8;
}
std::wstring Utf8ToUtf16(const std::string& utf8) {
	int length = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
	std::wstring utf16(length, 0);
	MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &utf16[0], length);
	utf16.pop_back();
	return utf16;
}
std::string Util::GetLangLocale() {
	wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
	std::wstring test;
	int result = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);
	if (result > 0) {
		return Util::StringtoLowerCase(Utf16ToUtf8(localeName));
	}
	else {
		return "zh-cn";
	}
}
bool Util::CheckWebviewEnvironment()
{
	LPWSTR version_info;
	GetAvailableCoreWebView2BrowserVersionString(nullptr, &version_info);
	std::wstring VersionInfoU16(version_info);
	if (VersionInfoU16.compare(L"") == 0) return false;
	return true;
}
