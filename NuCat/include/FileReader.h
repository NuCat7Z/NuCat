#pragma once
#include <string>
#include <tuple>
#include <iostream>
class FileReader {
public:
    FileReader(std::string_view Path);
    ~FileReader() = default;
    std::tuple<bool,std::string> ReadContent();
    bool WriteContent(std::string_view Content);
    bool AppendContent(std::string_view Content);
    bool CleanContent();
private:
    std::string file;
};
// FileReader 输出 输入均使用utf8编码 每次操作均重新打开文件 应当不频繁多次操作该类方法