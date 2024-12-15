# fmt.hpp

`fmt.hpp` is a lightweight C++ header-only library that provides a simple function for formatting strings, similar to the `sprintf` function in C.

## Features

- Header-only library
- Portable across different platforms (Windows, Linux, macOS)
- Uses the `__attribute__((format(printf, fmt, args)))` attribute for format string checking on non-Windows platforms

## Usage

To use `fmt.hpp`, simply include it in your C++ project:

```cpp
#include "fmt.hpp"
```

## Example

```cpp
#include <cstdio>
#include "fmt.hpp"

int main() {
    std::string formatted_string = fmt("Hello, %s! You have %d new messages.", "world", 5);
    printf("%s\n", formatted_string.c_str());
    return 0;
}
```

