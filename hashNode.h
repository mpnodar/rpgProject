#pragma once
#include <string>
#include <vector>
class hashNode
{
private:
	std::string Key;
	std::vector<std::string> Data;
public:
	hashNode(std::string key, std::vector<std::string> data);
	std::string getKey();
	std::vector<std::string> getData();
	void setKey(std::string key);
	void setData(std::vector<std::string> data);
};

