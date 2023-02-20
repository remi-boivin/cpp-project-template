#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>

enum class LogSeverity {
    kDebug,
    kVerbose,
    kInfo,
    kNormal,
    kError,
};

class Logger {
public:
    Logger(LogSeverity logLevel);

    void log(const std::string& message, LogSeverity severity);

private:
    LogSeverity m_logLevel;
};

#endif // LOGGER_HPP