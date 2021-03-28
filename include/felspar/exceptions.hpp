#pragma once


#include <exception>
#include <felspar/exceptions/source_annotation.hpp>


namespace felspar {


    using exception = exceptions::source_annotation<std::exception>;


}
