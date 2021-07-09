#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("length_error");


    auto const c = suite.test("construct", []() {
        felspar::stdexcept::length_error{"Error message"};
        felspar::stdexcept::length_error{std::string{"Error message"}};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::stdexcept::length_error{"An error message"};
        }).throws(felspar::stdexcept::length_error{"An error message"});
        check([]() {
            throw felspar::stdexcept::length_error{"An error message"};
        }).throws(std::length_error{"An error message"});
    });


}
