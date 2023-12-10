include(FetchContent)

FetchContent_Declare(
        felspar-test
        GIT_REPOSITORY https://github.com/Felspar/test.git
        GIT_TAG main
        GIT_SHALLOW true
    )
FetchContent_MakeAvailable(felspar-test)
