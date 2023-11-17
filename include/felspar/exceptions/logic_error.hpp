#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using logic_error = exceptions::messaging_error<std::logic_error>;


}
