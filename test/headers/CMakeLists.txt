if(TARGET felspar-check)
    add_library(felspar-exception-headers-tests STATIC EXCLUDE_FROM_ALL
            bad_alloc.cpp
            exceptions.cpp
            messaging_error.cpp
            overflow_error.cpp
            source_annotation.cpp
            system_error.cpp
            underflow_error.cpp
        )
    target_link_libraries(felspar-exception-headers-tests felspar-exceptions)

    add_dependencies(felspar-check felspar-exception-headers-tests)
endif()

