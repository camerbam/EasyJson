
#include "EasyJson/JsonObject.hpp"

JsonObject::JsonObject() : JsonValue() {}

JsonValue& JsonObject::operator[](const std::string& key)
{
  return m_values[key];
}
