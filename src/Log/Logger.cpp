#include <Log/logger.hpp>

Logger::Logger(LogSeverity logLevel)
    : m_logLevel(logLevel)
{
}

void Logger::log(const std::string& message, LogSeverity severity)
{
    if (severity >= m_logLevel) {
        std::cout << message << std::endl;
    }
}
