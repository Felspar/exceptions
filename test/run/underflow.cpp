#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>


namespace {


    auto const suite = felspar::testsuite("underflow");


    auto const c = suite.test("construct", []() {
        felspar::stdexcept::underflow_error{
                "Some text", felspar::source_location::current()};
        felspar::stdexcept::underflow_error{
                "Some text", 4.5, 6.0, felspar::source_location::current()};
    });


    auto const v = suite.test("void", [](auto check) {
        check([]() {
            throw felspar::stdexcept::underflow_error{
                    std::string{"Some error"}};
        }).throws(felspar::stdexcept::underflow_error{"Some error"});
        check([]() { throw felspar::stdexcept::underflow_error{"Some error"}; })
                .throws(felspar::stdexcept::underflow_error{
                        std::string{"Some error"}});
    });


    auto const i = suite.test("int", [](auto check) {
        check([]() {
            throw felspar::stdexcept::underflow_error{
                    std::string{"Too small"}, 3};
        }).throws(felspar::stdexcept::underflow_error<int>{"Too small"});
        check([]() {
            throw felspar::stdexcept::underflow_error{
                    std::string{"Too few items"}, 4, 6};
        }).throws(felspar::stdexcept::underflow_error<int>{"Too few items"});
    });


}
