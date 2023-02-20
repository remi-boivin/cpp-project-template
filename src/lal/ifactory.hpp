#ifndef LAL_IFACTORY_HPP
#define LAL_IFACTORY_HPP

#include <memory>
#include "./ilogger.hpp"

namespace cp
{
    namespace lal
    {
        class IFactory
        {
        public:
            virtual std::shared_ptr<ILogger> createLogger(ILogger::LogSeverity logLevel) const = 0;

        protected:
            template <typename Abstract, typename Concrete, typename... Args>
            std::shared_ptr<Abstract> create(std::weak_ptr<Abstract> &weakRef, Args &&...args) const
            {
                if (weakRef.expired())
                {
                    auto shared = std::shared_ptr<Abstract>(std::make_shared<Concrete>(std::forward<Args>(args)...));
                    weakRef = shared;
                    return shared;
                }
                return weakRef.lock();
            }
        };
    }
}

#endif // LAL_IFACTORY_HPP