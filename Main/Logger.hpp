#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>

namespace Main {

#define DEBUG_LEVEL_ENABLED
#define INFO_LEVEL_ENABLED
#define WARN_LEVEL_ENABLED
#define ERROR_LEVEL_ENABLED
extern std::ofstream nullStream;

#ifdef DEBUG_LEVEL_ENABLED
    #define Log_debug std::clog << "Debug: "  << __FILE__ << " at line: " << __LINE__ << ": "
#else
    #define Log_debug nullStream
#endif

#ifdef INFO_LEVEL_ENABLED
    #define Log_info std::clog  << "Info: "  << __FILE__ << " at line: " << __LINE__ << ": "
#else
    #define Log_info nullStream
#endif

#ifdef WARN_LEVEL_ENABLED
    #define Log_warn std::clog  << "Warn: "  << __FILE__ << " at line: " << __LINE__ << ": "
#else
    #define Log_warn nullStream
#endif

#ifdef ERROR_LEVEL_ENABLED
    #define Log_error std::clog << "ERROR: "  << __FILE__ << " at line: " << __LINE__ << ": "
#else
    #define Log_error nullStream
#endif

}

#endif // LOGGER_H
