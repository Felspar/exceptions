#pragma once


#include <felspar/exceptions/source_annotation.hpp>
#include <optional>
#include <stdexcept>


namespace felspar {


    /// Annotated mathematical underflow exception. Includes value and minimum
    /// annotations in addition to throw source location
    template<typename V>
    class underflow_error :
    public exceptions::source_annotation<std::underflow_error> {
        V v;
        std::optional<V> mx;

      public:
        explicit underflow_error(
                std::string m,
                V v = {},
                std::optional<V> mx = {},
                source_location loc = source_location::current())
        : v{v},
          mx{mx},
          source_annotation<std::underflow_error>{
                  loc, annotate(std::move(m), loc, v, mx)} {}
        underflow_error(std::string m, V v, source_location loc)
        : v{v},
          mx{},
          source_annotation<std::underflow_error>{
                  loc, annotate(std::move(m), loc, v, {})} {}

      protected:
        static std::string annotate(
                std::string m, source_location loc, V v, std::optional<V> mx) {
            if (mx) {
                return source_annotation<std::underflow_error>::annotate(
                               std::move(m), loc)
                        + "\nLimit " + std::to_string(*mx) + " and value is "
                        + std::to_string(v);
            } else {
                return source_annotation<std::underflow_error>::annotate(
                               std::move(m), loc)
                        + "\nValue is " + std::to_string(v);
            }
        }
    };

    template<>
    class underflow_error<void> :
    public exceptions::source_annotation<std::underflow_error> {
      public:
        /// Standard constructors
        explicit underflow_error(
                std::string m, source_location loc = source_location::current())
        : source_annotation<std::underflow_error>{
                loc, annotate(std::move(m), loc)} {}
    };


    underflow_error(std::string const &)->underflow_error<void>;
    underflow_error(std::string const &, source_location)->underflow_error<void>;
    template<typename V, typename... Args>
    underflow_error(std::string const &, V, Args...) -> underflow_error<V>;


}
