#pragma once


#include <felspar/exceptions/source_annotation.hpp>
#include <optional>
#include <stdexcept>


namespace felspar {


    /// Annotated mathematical overflow exception. Includes value and maximum
    /// annotations in addition to throw source location
    template<typename V>
    class overflow_error :
    public exceptions::source_annotation<std::overflow_error> {
        V v;
        std::optional<V> mx;

      public:
        explicit overflow_error(
                std::string const &m,
                V v = {},
                std::optional<V> mx = {},
                source_location loc = source_location::current())
        : v{v},
          mx{mx},
          source_annotation<std::overflow_error>{loc, annotate(m, loc, v, mx)} {
        }
        explicit overflow_error(
                char const *m,
                V v = {},
                std::optional<V> mx = {},
                source_location loc = source_location::current())
        : v{v},
          mx{mx},
          source_annotation<std::overflow_error>{loc, annotate(m, loc, v, mx)} {
        }

      protected:
        static std::string annotate(
                std::string m, source_location loc, V v, std::optional<V> mx) {
            if (mx) {
                return source_annotation<std::overflow_error>::annotate(
                               std::move(m), loc)
                        + "\nRequired less than (or equal to) "
                        + std::to_string(*mx) + " and got " + std::to_string(v);
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
                std::string const &m,
                source_location loc = source_location::current())
        : source_annotation<std::overflow_error>{loc, annotate(m, loc)} {}
        explicit overflow_error(
                char const *m, source_location loc = source_location::current())
        : source_annotation<std::overflow_error>{loc, annotate(m, loc)} {}
    };


    overflow_error(std::string const &)->overflow_error<void>;
    overflow_error(char const *)->overflow_error<void>;
    template<typename V>
    overflow_error(std::string const &, V) -> overflow_error<V>;
    template<typename V>
    overflow_error(char const *, V) -> overflow_error<V>;
    template<typename V>
    overflow_error(std::string const &, V, V) -> overflow_error<V>;
    template<typename V>
    overflow_error(char const *, V, V) -> overflow_error<V>;


}
