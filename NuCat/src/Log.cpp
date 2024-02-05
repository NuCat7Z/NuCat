#include "Log.h"
#include "FileReader.h"

std::function<bool(std::string, Log::Level, std::string)> HandlerFunction = Log::DefaultHandler;

int Log::CurrentLogLevel = 2; //WARN以上
std::string GetCurrentDate() {
	const auto now = std::chrono::system_clock::now();
	const auto time_zone = std::chrono::current_zone();
	const auto local_time = time_zone->to_local(now);
	const auto time_point = std::chrono::time_point_cast<std::chrono::days>(local_time);
	const auto year_month_day = std::chrono::year_month_day{ time_point };
	return std::format("{:%Y-%m-%d}", year_month_day);
}
std::string GetCurrentDateTime() {
	const auto now = std::chrono::system_clock::now();
	const auto time_zone = std::chrono::current_zone();
	const auto local_time = time_zone->to_local(now);
	const auto time_point = std::chrono::floor<std::chrono::seconds>(local_time);
	const auto year_month_day = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(time_point) };
	const auto time_of_day = std::chrono::hh_mm_ss{ time_point - std::chrono::floor<std::chrono::days>(time_point) };
	std::ostringstream oss;
	oss << std::format("{:%Y-%m-%d}", year_month_day) << ' '
		<< std::setw(2) << std::setfill('0') << time_of_day.hours().count() << ':'
		<< std::setw(2) << std::setfill('0') << time_of_day.minutes().count() << ':'
		<< std::setw(2) << std::setfill('0') << time_of_day.seconds().count();

	return oss.str();
}
std::string GetCurrentTimestamp() {
	const auto now = std::chrono::system_clock::now();
	const auto duration = now.time_since_epoch();
	const auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

	return std::format("{}", millis);
}
void Log::SetLogLevel(int LogLevel)
{
	Log::CurrentLogLevel = LogLevel;
}
void Log::DeleteAll() {
	// 清除所有日志 直接清空整个日志目录
}
void Log::SetOutHandler(std::function<bool(std::string, Log::Level, std::string)> callback) {
	HandlerFunction = callback;
	// 设置日志拦截 通过注册回调函数
}
bool Log::Logging(std::string content, Level ErrorLevel)
{
	if (static_cast<int>(ErrorLevel) < Level::LOG_DEBUG || static_cast<int>(ErrorLevel) > Level::LOG_EXIT) {
		return false;
	}
	// 过滤无效等级日志
	if (static_cast<int>(ErrorLevel) < Log::CurrentLogLevel) {
		return false;
	}
	// 过滤低等级日志
	char* LogLevel[] = { (char*)u8"DEBUG", (char*)u8"INFO", (char*)u8"WARN", (char*)u8"ERROR", (char*)u8"EXIT" };
	std::string LogLevelStr = LogLevel[static_cast<int>(ErrorLevel)];
	return HandlerFunction(content, ErrorLevel, LogLevelStr);
}
bool Log::DefaultHandler(std::string Content, Level ErrorLevel, std::string LogLevelStr)
{
	std::string CurrentDate = GetCurrentDate();
	std::string path = ".\\Log\\" + CurrentDate + ".txt";
	std::string RealContent;
	std::string  CurrentTimestamp = GetCurrentDateTime();
	RealContent.append((char*)u8"[");
	RealContent.append(CurrentTimestamp);
	RealContent.append((char*)u8"] ");
	RealContent.append((char*)u8"[");
	RealContent.append(LogLevelStr);
	RealContent.append((char*)u8"] ");
	RealContent.append(Content);
	RealContent.append("\n");
	FileReader(path).WriteContent(RealContent);
	return true;
}
// 用于阻止日志
bool Log::BlankHandler(std::string Content, Level ErrorLevel, std::string LogLevelStr)
{
	return true;
}
