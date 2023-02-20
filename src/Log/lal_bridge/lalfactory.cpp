#include "./lalfactory.hpp"

namespace cp
{
    namespace lal
    {
        std::shared_ptr<ILogger> LALFactory::createLogger(cp::lal::ILogger::LogSeverity logLevel) const
        {
            // create and return a shared_ptr to a Parser object
            return std::make_shared<Logger>(logLevel);
        }
    }
}