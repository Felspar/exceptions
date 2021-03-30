#include <felspar/test.hpp>
#include <felspar/exceptions.hpp>
#include <iostream>
#include <vector>


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


    template<typename V>
    V const &at(
            std::vector<V> const &v,
            std::size_t const pos,
            felspar::source_location loc = felspar::source_location::current()) {
        if (pos >= v.size()) {
            throw felspar::overflow_error{
                    "Requested index beyond vector bound", pos, v.size(),
                    std::move(loc)};
        } else {
            return v[pos];
        }
    }
    auto const a = suite.test("at", [](auto check) {
        auto const loc = felspar::source_location::current();
        auto eptr = check([&]() {
                        std::vector<int> v;
                        at(v, 3, loc);
                    })
                            .throws(std::overflow_error{
                                    "Requested index beyond vector bound"});
        try {
            std::rethrow_exception(eptr);
        } catch (felspar::overflow_error<std::size_t> const &e) {
            check(e.thrown_from().line()) == loc.line();
        }
    });


}
