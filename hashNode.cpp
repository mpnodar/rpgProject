#include "hashNode.h"

hashNode::hashNode(std::string key, std::vector<std::string> data)
{
    Key = key;
    Data = data;
}

std::string hashNode::getKey()
{
    return Key;
}

std::vector<std::string> hashNode::getData()
{
    return Data;
}

void hashNode::setKey(std::string key)
{
    Key = key;
}

void hashNode::setData(std::vector<std::string> data)
{
    Data = data;
}
