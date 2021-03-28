add_library(felspar-exception-headers-tests STATIC EXCLUDE_FROM_ALL
        exceptions.cpp
        source_annotation.cpp
    )
target_link_libraries(felspar-exception-headers-tests felspar-exceptions)

if(TARGET check)
    add_dependencies(check felspar-exception-headers-tests)
endif()

