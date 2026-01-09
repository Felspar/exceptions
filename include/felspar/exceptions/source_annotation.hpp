#pragma once


#include <source_location>
#include <string>
#include <utility>


namespace felspar::exceptions {


    /// Capture the source annotation for this exception
    template<typename SC>
    class source_annotation : public SC {
        std::source_location loc;

      public:
        /// Return the throw site source code location information
        auto const &thrown_from() const { return loc; }

      protected:
        /// Used by sub-classes that need to pass arguments to the actual
        /// exception constructor. Note that we need to pass in the source
        /// location first.
        template<typename... Args>
        source_annotation(std::source_location loc, Args... args)
        : SC{std::forward<Args>(args)...}, loc{std::move(loc)} {}

        /// Used by sub-classes that take a user-define error message to include
        /// the source location information in the message
        static std::string annotate(std::string m, std::source_location loc) {
            m += "\n";
            return source_info(std::move(m), loc);
        }
        static std::string annotate(std::source_location loc) {
            return source_info({}, loc);
        }

      private:
        static std::string source_info(std::string m, std::source_location loc) {
            m += loc.file_name();
            m += ":";
            m += std::to_string(loc.line());
            m += ":";
            m += std::to_string(loc.column());
            m += ": Error, exception thrown";
            return m;
        }
    };


}
