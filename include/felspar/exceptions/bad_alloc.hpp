#pragma once


#include <felspar/exceptions/source_annotation.hpp>


namespace felspar::stdexcept {


    class bad_alloc : public exceptions::source_annotation<std::bad_alloc> {
        std::string msg;

      public:
        explicit bad_alloc(source_location loc = source_location::current())
        : source_annotation<std::bad_alloc>{loc},
          msg{annotate("felspar::stdexcept::bad_alloc", loc)} {}
        explicit bad_alloc(
                std::string m, source_location loc = source_location::current())
        : source_annotation<std::bad_alloc>{loc},
          msg{annotate(std::move(m), loc)} {}

        char const *what() const noexcept { return msg.c_str(); }
    };


}
