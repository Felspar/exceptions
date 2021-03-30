# Felspar exceptions

**Annotated exceptions for C++ 20**

These exceptions allow for capture of source location information (typically the throw site). Some exceptions may also capture other information.


To use add the `felspar-exceptions` and `felspar-test` libraries to your project and include the utility header:

```cpp
#include <felspar/exception.hpp>
```

Individual exceptions also have their own headers.

For all of the exception types an extra source location can be explicitly provided to customise the captured source location:

```cpp
template<typename V>
V const &at(std::vector<V> const &v, std::size_t const pos,
        felspar::source_location loc = felspar::source_location::current()) {
    if (pos >= v.size()) {
        throw felspar::overflow_error{"Requested index beyond vector bound",
                pos, v.size(), std::move(loc)};
    } else {
        return v[pos];
    }
}
```

The source location will be now be reported as the call site of the `at` function rather than where the exception is thrown.


## `felspar::overflow_error` and `felspar::underflow_error`

```cpp
#include <felspar/exception.hpp> // convenience header
#include <felspar/exceptions/overflow_error.hpp> // specific header
#include <felspar/exceptions/underflow_error.hpp> // specific header
```

Mirrors the standard library types but includes source location together with value information. They can also be used as a drop in replacement for `std::overflow_error` and `std::underflow_error` and can be caught as such, where it will only add the source location information to the `what()` string.

```cpp
throw felspar::overflow_error{"Too large", 3};
```

Might be reported as:

    Too large
    ../../test/run/overflow.cpp:26:0
    Value is 3

Where an overflow is used to report a value that is too large, the limit value can also be given:

```cpp
throw felspar::overflow_error{"Wrong number of wheels", 5, 4};
```

The report will look like:

    Wrong number of wheels
    ../../test/run/overflow.cpp:25:0
    Limit 4 and value is 5

Similarly with `felspar::underflow_error`:


```cpp
throw felspar::underflow_error{"Too small", 3};
```

As:

    Too small
    ../../exceptions/test/run/underflow.cpp:29:0
    Value is 3

And:

```cpp
throw felspar::overflow_error{"Too few items", 4, 6};
```

As:

    Too few items
    ../../exceptions/test/run/underflow.cpp:32:0
    Limit 6 and value is 4
