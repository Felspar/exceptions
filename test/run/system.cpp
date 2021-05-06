#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("system");


    auto const c = suite.test("construct", []() {
        felspar::source_location loc = felspar::source_location::current();
        felspar::system_error{std::error_code{}, loc};
        felspar::system_error{std::error_code{}, "What ho!"};
        felspar::system_error{0, std::system_category()};
        felspar::system_error{0, std::system_category(), "What no!"};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::system_error{std::error_code{}, "Message"};
        }).throws(felspar::system_error{std::error_code{}, "Message"});
        check([]() {
            throw felspar::system_error{std::error_code{}, "Message"};
        }).throws(std::system_error{std::error_code{}, "Message"});
    });


}
