#pragma once


#include <felspar/exceptions/messaging_error.hpp>
#include <felspar/exceptions/overflow_error.hpp>
#include <felspar/exceptions/underflow_error.hpp>


namespace felspar {


    using exception = exceptions::source_annotation<std::exception>;
    using logic_error = exceptions::messaging_error<std::logic_error>;
    using runtime_error = exceptions::messaging_error<std::runtime_error>;


}
