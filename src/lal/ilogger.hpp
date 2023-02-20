#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>
#include <vector>
// #include "../Log/include/logger.hpp"

namespace cp
{
    namespace lal
    {
        class ILogger
        {
        public:
            enum class LogSeverity
            {
                kDebug,
                kVerbose,
                kInfo,
                kError,
            };

            virtual void log(const std::string &message, LogSeverity severity) const = 0;
            virtual void set(LogSeverity logLevel) = 0;
            virtual LogSeverity get() const = 0;
        };
    }
}
#endif // IPARSER_HPP