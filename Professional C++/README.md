
# 第1章 C++和STL速成

### 1.2.1 指针和动态内存

**智能指针**

```cpp
Employee* anEmployee = new Employee;

auto anEmployee = std::make_unique<Employee>();

std::unique_ptr<Employee> aneEmployee(new Employee);
```

**类型推断**

```cpp
const string message = "Test";
const string& foo()
{
    return message;
}

auto f1 = foo();//string copy

const auto& f1 = foo();//explicit

decltype(foo()) f2 = foo();//duplicate

decltype(auto) f3 = foo();//C14

```

# 第2章 使用字符串

**std::string字面量**

```cpp
auto string1 = "Hello World";//const char *
auto string2 = "Hello World"s;//C14 std::string

```

**原始字符串字面量**

```cpp
string str = "Hello \"World\"!";
string str = R"(Hello "World"!)";

string str = R"-(The characters )" are embedded in this string)-";

```
