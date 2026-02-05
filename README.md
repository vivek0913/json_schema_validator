# json_schema_validator
**JSON Schema Validator** (Modern C++)

A lightweight and educational JSON Schema validator written in modern C++.

**Features** (Current)

1. Validates JSON data against a simplified JSON Schema
2. Supports core types:
    1. object
    2. array
    3. string
    4. integer
    5. boolean
    6. null

3. Recursive schema-based validation
4. Clean internal representation using std::variant
5. Command-line interface for easy usage


**Tech Stack**
1. C++20
2. nlohmann/json (parsing only)
3. CMake
4. Clang / GCC compatible

**Usage**
```
json_validator schema.json data.json
```

**Example**
>schema.json
```
{
  "type": "object",
  "required": ["users"],
  "properties": {
    "users": {
      "type": "array",
      "items": {
        "type": "object",
        "required": ["name", "age"],
        "properties": {
          "name": { "type": "string" },
          "age":  { "type": "integer" }
        }
      }
    }
  }
}

```
>data.json
```
{
  "users": [
    { "name": "Alice", "age": 30 },
    { "name": "Bob",   "age": 25 }
  ]
}

```
**Example Output**
```
JSON is valid
```
or
```
JSON is invalid
```

**Design Goals**
1. Strong type safety
2. Minimal dependencies
3. Clear separation between parsing, validation, and CLI
4. Easy to extend with additional schema rules

**Future Work**
1. Detailed validation error reporting
2. Additional schema keywords (minimum, enum, etc.)
3. Unit tests
4. Performance optimizations
