#pragma once


#include <felspar/exceptions/source_annotation.hpp>
#include <optional>
#include <stdexcept>


namespace felspar::stdexcept {


    /// Annotated mathematical overflow exception. Includes value and maximum
    /// annotations in addition to throw source location
    template<typename V>
    class overflow_error :
    public exceptions::source_annotation<std::overflow_error> {
        V v;
        std::optional<V> mx;

      public:
        explicit overflow_error(
                std::string m,
                V v = {},
                std::optional<V> mx = {},
                source_location loc = source_location::current())
        : source_annotation<
                std::overflow_error>{loc, annotate(std::move(m), loc, v, mx)},
          v{v},
          mx{mx} {}
        overflow_error(std::string m, V v, source_location loc)
        : source_annotation<
                std::overflow_error>{loc, annotate(std::move(m), loc, v, {})},
          v{v},
          mx{} {}

      protected:
        static std::string annotate(
                std::string m, source_location loc, V v, std::optional<V> mx) {
            if (mx) {
                return source_annotation<std::overflow_error>::annotate(
                               std::move(m), loc)
                        + "\nLimit " + std::to_string(*mx) + " and value is "
                        + std::to_string(v);
            } else {
                return source_annotation<std::overflow_error>::annotate(
                               std::move(m), loc)
                        + "\nValue is " + std::to_string(v);
            }
        }
    };

    template<>
    class overflow_error<void> :
    public exceptions::source_annotation<std::overflow_error> {
      public:
        /// Standard constructors
        explicit overflow_error(
                std::string m, source_location loc = source_location::current())
        : source_annotation<std::overflow_error>{
                loc, annotate(std::move(m), loc)} {}
    };


    overflow_error(std::string const &)->overflow_error<void>;
    overflow_error(std::string const &, source_location)->overflow_error<void>;
    template<typename V, typename... Args>
    overflow_error(std::string const &, V, Args...) -> overflow_error<V>;


}
