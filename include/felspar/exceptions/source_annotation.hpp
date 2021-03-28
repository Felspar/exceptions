#pragma once


#include <felspar/test/source.hpp>
#include <utility>


namespace felspar::exceptions {


    /// Capture the source annotation for this exception
    template<typename SC>
    class source_annotation : public SC {
        felspar::source_location loc;

      public:
        source_annotation(auto l = source_location::current()) noexcept
        : loc{std::move(l)} {}

        auto const &thrown_from() const { return loc; }
    };


}
