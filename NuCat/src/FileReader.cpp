#include "FileReader.h"
#include <fstream>
#include <functional>
FileReader::FileReader(std::string_view Path)
{
	file = Path;
	std::fstream FileStream(file, std::ios::in | std::ios::out | std::ios::app);
	FileStream.close();
}
std::tuple<bool, std::string> FileReader::ReadContent()
{
	std::fstream FileStream(file, std::ios::in | std::ios::binary);
	FileStream.ignore((std::numeric_limits<std::streamsize>::max)());
	FileStream.clear(); // EOF
	FileStream.seekg(0, std::ios_base::beg);
	if (!FileStream.is_open()) return std::make_tuple(false, std::string(""));
	// 获取文件大小
	std::streampos FileStreamSize = FileStream.gcount();
	char* Ret = new char[int(FileStreamSize) + 1];
	// 分配缓冲区
	FileStream.read(Ret, FileStreamSize);
	Ret[FileStreamSize] = '\0';
	std::string Content = Ret;
	delete[] Ret;
	FileStream.close();
	return std::make_tuple(true, Content);
}
bool FileReader::WriteContent(std::string_view Content)
{
	std::fstream FileStream(file, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!FileStream.is_open()) {
		return false;
	}
	FileStream << Content;
	FileStream.close();
	return true;
}
bool FileReader::AppendContent(std::string_view Content)
{
	std::fstream FileStream(file, std::ios::out | std::ios::app | std::ios::binary);
	if (!FileStream.is_open()) {
		return false;
	}
	FileStream << Content;
	FileStream.close();
	return true;
}
bool FileReader::CleanContent()
{
	std::fstream FileStream(file, std::ios::out | std::ios::trunc);
	FileStream.close();
	return true;
}
