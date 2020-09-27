#ifndef INCLUDE_JSON_OBJECT
#define INCLUDE_JSON_OBJECT

#include <map>
#include <string>

#include "JsonValue.hpp"

class JsonObject : private JsonValue
{
public:
  JsonObject();

  JsonObject(const JsonObject&) = delete;
  JsonObject& operator=(const JsonObject&) = delete;

  JsonValue& operator[](const std::string& key);

private:
  std::map<std::string, JsonValue> m_values;
};

#endif
