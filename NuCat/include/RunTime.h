#include <string>
#include <map>
#include <iostream>
#include <tuple>
class Runtime
{
public:
	Runtime();
	~Runtime() = default;
	bool Set(std::string key, std::string value);
	std::tuple<bool, std::string> Get(std::string key);
	bool Put(std::string key);
	static Runtime* GetInstance();
	std::string& operator[](std::string key);
private:
	static Runtime* instance;
	std::map<std::string, std::string> cached;
};