#ifndef INCLUDE_JSON_ARRAY
#define INCLUDE_JSON_ARRAY

#include <vector>
#include <string>

#include "JsonValue.hpp"

class JsonArray : private JsonValue
{
public:
  JsonArray();

  JsonArray(const JsonArray&) = delete;
  JsonArray& operator=(const JsonArray&) = delete;

  JsonValue& operator[](const std::size_t& key);

private:
  std::vector<JsonValue> m_values;
};

#endif
