#include <my.hpp>

auto main() -> int
{
    Logger logger { LogSeverity::kNormal };
    logger.log("This is a project's template !", LogSeverity::kNormal);

    return 0;
}