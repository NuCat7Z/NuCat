#include "Util.h"
#include "Setting.h"
#include "RunTime.h"
#include "Language.h"
#include "Log.h"
#ifdef _WIN_PLATFORM_
#include <Windows.h>
int  wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
#else
int main(int argc, char** argv) {
#endif
	// Init 初始化程序语言 注册基础服务
	std::string locale = Util::GetLangLocale();
	if (Setting::GetInstance()->GetLanguage("").compare("") != 0)
	{
		locale.clear();
		locale = Setting::GetInstance()->GetLanguage("");
	}
	((*Runtime::GetInstance())["LocaleName"]) = locale;
	LangFactory::GetSysInstance(locale);
	Log::SetLogLevel((int)((*Setting::GetInstance())["LogLevel"]));
	if (!Util::CheckWebviewEnvironment()) {
		// 视图环境检测识别
		// 不同环境需要不同处理 当前只支持Win
	}
	// 检查7z环境 并加载命名空间
	// 解析命令行 进入事件处理
	return 0;
}
