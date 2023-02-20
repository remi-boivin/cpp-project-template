#ifndef LAL_FACTORY
#define LAL_FACTORY

#include <memory>
#include "../../lal/ifactory.hpp"
#include "../include/logger.hpp"

namespace cp
{
    namespace lal
    {
        class LALFactory : public lal::IFactory
        {
        public:
            std::shared_ptr<lal::ILogger> createLogger(cp::lal::ILogger::LogSeverity logLevel) const override;

        private:
            mutable std::weak_ptr<lal::ILogger> m_loggerRef;
        };

    }
}

#endif // LAL_FACTORY
