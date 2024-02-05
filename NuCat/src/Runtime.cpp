#include "RunTime.h"

Runtime* Runtime::instance = nullptr;

Runtime::Runtime()
{
	this->Set("Error", "Error");
}
bool Runtime::Set(std::string key, std::string value)
{
	cached[key] = value;
	return true;
}
std::tuple<bool, std::string>  Runtime::Get(std::string key)
{
	auto value = cached.find(key);
	if (value == cached.end()) {
		return std::make_tuple(false, "");
	}
	return std::make_tuple(true, value->second);
}
bool Runtime::Put(std::string key)
{
	cached.erase(key);
	return true;
}
Runtime* Runtime::GetInstance()
{
	if (instance == nullptr) {
		instance = new Runtime();
	}
	return instance;
}

std::string& Runtime::operator[](std::string key)
{

	auto value = cached.find(key);
	if (value == cached.end()) {
		return cached[key];
	}
	return value->second;
}
