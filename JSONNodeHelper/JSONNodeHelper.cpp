#include "JSONNodeHelper.h"
#include "JSONNode.h"

JSONNodeHelper::JSONNodeHelper(JSONNode jsonNode):m_jsonNode(jsonNode)
{
}

JSONNode JSONNodeHelper::findKey(JSONNode jsonNode, std::string key)
{
    JSONNode returnNode;
    for (JSONNode::const_iterator i = jsonNode.begin(); i != jsonNode.end(); i++){
        if (i->name() == key){
            returnNode = *i;
        }
    }
    // TODO: throw exception if the key is not found
    return returnNode;
}

JSONNode JSONNodeHelper::operator[] (const std::string& key)
{
    return JSONNodeHelper::findKey(m_jsonNode, key);   
}
