# Felspar Exceptions

**Annotated exceptions for C++**

[![Documentation](https://badgen.net/static/docs/felspar.com)](https://felspar.com/exceptions/)
[![GitHub](https://badgen.net/badge/Github/felspar-exceptions/green?icon=github)](https://github.com/Felspar/exceptions)
[![License](https://badgen.net/github/license/Felspar/exceptions)](https://github.com/Felspar/exceptions/blob/main/LICENSE_1_0.txt)
[![Discord](https://badgen.net/badge/icon/discord?icon=discord&label)](https://discord.gg/tKSabUa52v)

**felspar-exceptions** is a library that provides exceptions types that capture source location information (typically the throw site). Some exceptions may also capture other information


## Using the library

The library is designed to be easy to use from CMake projects. To use it add it in your source tree somewhere and then use `add_subdirectory` to include it in your project. The library also requires the use of some other libraries which can get by using an `include`. So if you have the library in a folder called `felspar-exceptions`, you can add the following to your `CMakeLists.txt`:

```cmake
add_subdirectory(felspar-exceptions)
include(felspar-coro/requirements.cmake)
```

To make use of the library add `felspar-exceptions` in your `target_link_libraries` directive.

```cmake
target_link_libraries(your-app otherlib1 otherlib2 felspar-exceptions)
```

If you want to build the tests then add `felspar-check` as a target before the `add_subdirectory` and then add `felspar-check` to the targets you build.

```cmake
add_custom_target(felspar-check)
add_subdirectory(felspar-exceptions)
```


## Basic usage

To use add the `felspar-exceptions` and `felspar-test` libraries to your project and include the utility header:

```cpp
#include <felspar/exception.hpp>
```

For all of the exception types an extra source location can be explicitly provided to customise the captured source location:

```cpp
template<typename V> inline
V const &at(std::vector<V> const &v, std::size_t const pos,
        felspar::source_location const &loc = felspar::source_location::current()) {
    if (pos >= v.size()) {
        throw felspar::stdexcept::overflow_error{
                "Requested index beyond vector bound",
                pos, v.size(), loc};
    } else {
        return v[pos];
    }
}
```

The source location will be now be reported as the call site of the `at` function rather than where the exception is thrown.

All wrappers for `std::` exceptions are in the `felspar::stdexcept::` namespace.


## `felspar::stdexcept::length_error`, `felspar::stdexcept::logic_error`, `felspar::stdexcept::runtime_error` and `felspar::stdexcept::system_error`

```cpp
#include <felspar/exceptions.hpp>
```

Mirrors the standard library types and includes source location information. They can still be caught as their standard types, `std::length_error` or `std::logic_error` or `std::runtime_error` or `std::system_error`, and the source location will be in the `what()` string.

```cpp
throw felspar::stdexcept::runtime_error{"An error message"};
```

Might be reported as:

    An error message
    ../../exceptions/test/run/runtime.cpp:19:19


## `felspar::stdexcept::overflow_error` and `felspar::stdexcept::underflow_error`

```cpp
#include <felspar/exception.hpp> // convenience header
#include <felspar/exceptions/overflow_error.hpp> // specific header
#include <felspar/exceptions/underflow_error.hpp> // specific header
```

Mirrors the standard library types but includes source location together with value information. They can also be used as a drop in replacement for `std::overflow_error` and `std::underflow_error` and can be caught as such, where it will only add the source location information to the `what()` string.

```cpp
throw felspar::stdexcept::overflow_error{"Too large", 3};
```

Might be reported as:

    Too large
    ../../test/run/overflow.cpp:26:0
    Value is 3

Where an overflow is used to report a value that is too large, the limit value can also be given:

```cpp
throw felspar::stdexcept::overflow_error{"Wrong number of wheels", 5, 4};
```

The report will look like:

    Wrong number of wheels
    ../../test/run/overflow.cpp:25:0
    Limit 4 and value is 5

Similarly with `felspar::stdexcept::underflow_error`:

```cpp
throw felspar::stdexcept::underflow_error{"Too small", 3};
```

As:

    Too small
    ../../exceptions/test/run/underflow.cpp:29:0
    Value is 3

And:

```cpp
throw felspar::stdexcept::overflow_error{"Too few items", 4, 6};
```

As:

    Too few items
    ../../exceptions/test/run/underflow.cpp:32:0
    Limit 6 and value is 4


## `felspar::stdexcept::bad_alloc`

```cpp
#include <felspar/exception.hpp> // convenience header
#include <felspar/exceptions/bad_alloc.hpp> // specific header
```

This standard version of this exception takes no arguments, but the throw location is still captured by `felspar::stdexcept::bad_alloc`.

Throwing the exception normally:

```cpp
throw felspar::stdexcept::bad_alloc{};
```

Results in:

    felspar::stdexcept::bad_alloc
    ../../test/run/bad_alloc.cpp:23:0

The exception is also extended to take an optional error message:

```cpp
throw felspar::stdexcept::bad_alloc{"Allocation error message"};
```

Results in:

    Allocation error message
    ../../test/run/bad_alloc.cpp:14:0
