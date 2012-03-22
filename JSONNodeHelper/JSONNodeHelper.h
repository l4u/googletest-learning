#ifndef JSON_NODE_HELPER_H
#define JSON_NODE_HELPER_H

#include "JSONNode.h"
class JSONNodeHelper
{
public:
    JSONNodeHelper(JSONNode jsonNode);
    static JSONNode findKey(JSONNode jsonNode, std::string key);
    JSONNode operator[](const std::string& key);
private:
    JSONNode m_jsonNode;
};
#endif
