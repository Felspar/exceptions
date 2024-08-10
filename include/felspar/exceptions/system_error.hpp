#pragma once


#include <felspar/exceptions/source_annotation.hpp>
#include <functional>
#include <system_error>


namespace felspar::stdexcept {


    class system_error :
    public exceptions::source_annotation<std::system_error> {
      public:
        system_error(
                std::error_code ec,
                source_location loc = source_location::current())
        : source_annotation<std::system_error>{loc, ec, annotate(loc)} {}
        system_error(
                std::error_code ec,
                std::string m,
                source_location loc = source_location::current())
        : source_annotation<std::system_error>{
                  loc, ec, annotate(std::move(m), loc)} {}
        system_error(
                int const ev,
                std::error_category const &ecat,
                source_location loc = source_location::current())
        : source_annotation<std::system_error>{
                  loc, ev, std::cref(ecat), annotate(loc)} {}
        system_error(
                int const ev,
                std::error_category const &ecat,
                std::string m,
                source_location loc = source_location::current())
        : source_annotation<std::system_error>{
                  loc, ev, std::cref(ecat), annotate(std::move(m), loc)} {}
    };


}
