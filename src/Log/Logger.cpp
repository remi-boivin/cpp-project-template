#include "./include/logger.hpp"

Logger::Logger(cp::lal::ILogger::LogSeverity logLevel)
    : m_logLevel(logLevel)
{
}

void Logger::log(const std::string &message, cp::lal::ILogger::LogSeverity severity) const
{
    if (severity >= this->m_logLevel)
        std::cout << getActualDate() << " " << message << std::endl;
}

void Logger::set(cp::lal::ILogger::LogSeverity logLevel)
{
    this->m_logLevel = logLevel;
}

cp::lal::ILogger::LogSeverity Logger::get() const
{
    return this->m_logLevel;
}