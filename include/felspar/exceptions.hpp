#pragma once


#include <felspar/exceptions/bad_alloc.hpp>
#include <felspar/exceptions/messaging_error.hpp>
#include <felspar/exceptions/overflow_error.hpp>
#include <felspar/exceptions/system_error.hpp>
#include <felspar/exceptions/underflow_error.hpp>


namespace felspar::stdexcept {


    using exception = exceptions::source_annotation<std::exception>;

    using length_error = exceptions::messaging_error<std::length_error>;
    using logic_error = exceptions::messaging_error<std::logic_error>;
    using runtime_error = exceptions::messaging_error<std::runtime_error>;


}
