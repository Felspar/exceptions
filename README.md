# Felspar exceptions

**Annotated exceptions for C++ 20**

These exceptions allow for capture of source location information (typically the throw site). Some exceptions may also capture other information.


To use add the `felspar-exceptions` and `felspar-test` libraries to your project and include the utility header:

```cpp
#include <felspar/exception.hpp>
```


## `felspar::overflow_error`

Mirrors the standard library type but includes source location together with value information.

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
    Required less than (or equal to) 4 and got 5
