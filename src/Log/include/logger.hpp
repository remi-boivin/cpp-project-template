#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include "../../lal/ilogger.hpp"

// namespace cp
// {
    // namespace logger
    // {
    class Logger : public cp::lal::ILogger
    {
    public:
        Logger(cp::lal::ILogger::LogSeverity logLevel);

        void log(const std::string &message, cp::lal::ILogger::LogSeverity severity) const override;
        void set(cp::lal::ILogger::LogSeverity logLevel) override;
        cp::lal::ILogger::LogSeverity get() const override;

    private:
        cp::lal::ILogger::LogSeverity m_logLevel;
    };

    // }
// }

#endif // LOGGER_HPP