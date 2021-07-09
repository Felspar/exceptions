#include <felspar/test.hpp>
#include <felspar/exceptions/bad_alloc.hpp>


namespace {


    auto const suite = felspar::testsuite("bad_alloc");


    auto const c = suite.test("construct", []() {
        felspar::stdexcept::bad_alloc{};
        // felspar::stdexcept::bad_alloc{"Error message"};
        // felspar::stdexcept::bad_alloc{std::string{"Error message"}};
    });


    auto const t = suite.test("throw", [](auto check) {
        check([]() {
            throw felspar::stdexcept::bad_alloc{};
        }).throws(felspar::stdexcept::bad_alloc{});
        check([]() {
            throw felspar::stdexcept::bad_alloc{};
        }).template throws_type<std::bad_alloc>();
        // check([]() {
        //     throw felspar::stdexcept::bad_alloc{"An error message"};
        // }).throws(felspar::stdexcept::bad_alloc{"An error message"});
    });


}
