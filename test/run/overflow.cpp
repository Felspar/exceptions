#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("overflow");


    auto const c = suite.test("construct", [](auto check) {
        felspar::overflow_error{
                "Some text", felspar::source_location::current()};
        felspar::overflow_error{
                "Some text", 4.5, felspar::source_location::current()};
        felspar::overflow_error{
                "Some text", 4.5, 3.0, felspar::source_location::current()};
    });


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
        check([]() {
            throw felspar::overflow_error{
                    std::string{"Wrong number of wheels"}, 5, 4};
        }).throws(felspar::overflow_error<int>{"Wrong number of wheels"});
    });


}
