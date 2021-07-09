#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("system");


    auto const c = suite.test("construct", []() {
        felspar::source_location loc = felspar::source_location::current();
        felspar::stdexcept::system_error{std::error_code{}, loc};
        felspar::stdexcept::system_error{std::error_code{}, "What ho!"};
        felspar::stdexcept::system_error{0, std::system_category()};
        felspar::stdexcept::system_error{0, std::system_category(), "What no!"};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::stdexcept::system_error{
                    std::error_code{}, "Message\n"};
        })
                .throws(felspar::stdexcept::system_error{
                        std::error_code{}, "Message\n"});
        check([]() {
            throw felspar::stdexcept::system_error{
                    std::error_code{}, "Message\n"};
        }).throws(std::system_error{std::error_code{}, "Message\n"});
    });


}
