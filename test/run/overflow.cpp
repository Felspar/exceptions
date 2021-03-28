#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("overflow");


    auto const v = suite.test("void", [](auto check) {
        check([]() {
            throw felspar::overflow_error{std::string{"Some error"}};
        }).throws(felspar::overflow_error{"Some error"});
        check([]() {
            throw felspar::overflow_error{"Some error"};
        }).throws(felspar::overflow_error{std::string{"Some error"}});
    });


    auto const i = suite.test("int", [](auto check) {
        check([]() {
            throw felspar::overflow_error{std::string{"Some error"}, 3};
        }).throws(felspar::overflow_error<int>{"Some error"});
    });


}
