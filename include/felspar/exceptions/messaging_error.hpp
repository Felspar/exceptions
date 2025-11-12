#pragma once


#include <felspar/exceptions/source_annotation.hpp>
#include <stdexcept>


namespace felspar::exceptions {


    template<typename E>
    class messaging_error : public source_annotation<E> {
      public:
        messaging_error(
                std::string m,
                std::source_location loc = std::source_location::current())
        : source_annotation<E>{
                  loc, source_annotation<E>::annotate(std::move(m), loc)} {}
    };


}
