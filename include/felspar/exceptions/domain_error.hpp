#pragma once


#include <felspar/exceptions/messaging_error.hpp>


namespace felspar::stdexcept {


    using domain_error = exceptions::messaging_error<std::domain_error>;


}
