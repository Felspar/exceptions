if(TARGET felspar-check)
    add_test_run(felspar-check felspar-exceptions TESTS
            bad_alloc.cpp
            length_error.cpp
            overflow.cpp
            runtime.cpp
            system.cpp
            underflow.cpp
        )
endif()
