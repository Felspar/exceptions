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
                std::source_location loc = std::source_location::current())
        : source_annotation<std::system_error>{loc, ec, annotate(loc)} {}
        system_error(
                std::error_code ec,
                std::string m,
                std::source_location loc = std::source_location::current())
        : source_annotation<std::system_error>{
                  loc, ec, annotate(std::move(m), loc)} {}
        system_error(
                int const ev,
                std::error_category const &ecat,
                std::source_location loc = std::source_location::current())
        : source_annotation<std::system_error>{
                  loc, ev, std::cref(ecat), annotate(loc)} {}
        system_error(
                int const ev,
                std::error_category const &ecat,
                std::string m,
                std::source_location loc = std::source_location::current())
        : source_annotation<std::system_error>{
                  loc, ev, std::cref(ecat), annotate(std::move(m), loc)} {}
    };


}
