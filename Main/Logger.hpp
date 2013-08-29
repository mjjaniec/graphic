#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

namespace Main {

bool DEBUG_LEVEL_ENABLED = true;
bool INFO_LEVEL_ENABLED = true;
bool WARN_LEVEL_ENABLED = true;
bool ERROR_LEVEL_ENABLED = true;

#define Log_debug std::clog << "Debug: "  << __FILE__ << " at line: " << __LINE__ << ": "
#define Log_info std::clog << "Info: "  << __FILE__ << " at line: " << __LINE__ << ": "
#define Log_warn std::clog << "Warn: "  << __FILE__ << " at line: " << __LINE__ << ": "
#define Log_error std::clog << "ERROR: "  << __FILE__ << " at line: " << __LINE__ << ": "
}

#endif // LOGGER_H
