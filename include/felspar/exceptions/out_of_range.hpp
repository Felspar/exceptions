#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using out_of_range = exceptions::messaging_error<std::out_of_range>;


}
