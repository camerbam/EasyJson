
#include "EasyJson/JsonArray.hpp"

JsonArray::JsonArray() : JsonValue() {}

JsonValue& JsonArray::operator[](const std::size_t& key)
{
  return m_values[key];
}
