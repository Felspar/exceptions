#pragma once


#include <stdexcept>
#include <felspar/exceptions/source_annotation.hpp>


namespace felspar {


    /// Annotated mathematical overflow exception. Includes value and maximum
    /// annotations in addition to throw source location
    template<typename V>
    class overflow_error :
    public exceptions::source_annotation<std::overflow_error> {
        V v;

      public:
        overflow_error(
                std::string const &m,
                V v = {},
                source_location loc = source_location::current())
        : v{v},
          source_annotation<std::overflow_error>{loc, annotate(m, loc, v)} {}
        explicit overflow_error(
                char const *m,
                V v = {},
                source_location loc = source_location::current())
        : v{v},
          source_annotation<std::overflow_error>{loc, annotate(m, loc, v)} {}

      protected:
        static std::string annotate(std::string m, source_location loc, V v) {
            return source_annotation<std::overflow_error>::annotate(
                           std::move(m), loc)
                    + "\nValue is " + std::to_string(v);
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


}
