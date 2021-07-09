#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("runtime");


    auto const c = suite.test("construct", []() {
        felspar::stdexcept::runtime_error{"Error message"};
        felspar::stdexcept::runtime_error{std::string{"Error message"}};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::stdexcept::runtime_error{"An error message"};
        }).throws(felspar::stdexcept::runtime_error{"An error message"});
        check([]() {
            throw felspar::stdexcept::runtime_error{"An error message"};
        }).throws(std::runtime_error{"An error message"});
    });


}
