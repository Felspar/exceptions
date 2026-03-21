#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using invalid_argument = exceptions::messaging_error<std::invalid_argument>;


}
