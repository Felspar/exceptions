#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("length_error");


    auto const c = suite.test("construct", []() {
        felspar::length_error{"Error message"};
        felspar::length_error{std::string{"Error message"}};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::length_error{"An error message"};
        }).throws(felspar::length_error{"An error message"});
        check([]() {
            throw felspar::length_error{"An error message"};
        }).throws(std::length_error{"An error message"});
    });


}
