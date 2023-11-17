#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using runtime_error = exceptions::messaging_error<std::runtime_error>;


}
