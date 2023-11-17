#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using length_error = exceptions::messaging_error<std::length_error>;


}
