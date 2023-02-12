#include <Log/logger.hpp>
#include <Date/date.hpp>

Logger::Logger(LogSeverity logLevel)
    : m_logLevel(logLevel)
{
}

void Logger::log(const std::string &message, LogSeverity severity)
{
    if (severity >= m_logLevel)
        std::cout << getActualDate() << " " << message << std::endl;
}

void Logger::set(LogSeverity logLevel) {
    m_logLevel = logLevel;
}

LogSeverity Logger::get() {
    return m_logLevel;
}