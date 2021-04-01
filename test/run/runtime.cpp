#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("runtime");


    auto const c = suite.test("construct", [](auto) {
        felspar::runtime_error{"Error message"};
        felspar::runtime_error{std::string{"Error message"}};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::runtime_error{"An error message"};
        }).throws(felspar::runtime_error{"An error message"});
        check([]() {
            throw felspar::runtime_error{"An error message"};
        }).throws(std::runtime_error{"An error message"});
    });


}
