#include "../includes/my.hpp"

auto main(int argc, char **argv) -> int
{
    int loggerLevel = static_cast<int>(LogSeverity::kNormal);
    const std::vector<std::string> args = {"-v", "-d"};
    std::vector<std::string> parsedArgs = {};
    Logger logger{static_cast<LogSeverity>(loggerLevel)};
    std::unique_ptr<cp::iparser::IFactory> parserFactory = std::make_unique<cp::parser::PALFactory>();
    std::shared_ptr<cp::iparser::IParser> parser = parserFactory->createParser(args); // pass the argument here

    try
    {
        parser->args(argc, argv, loggerLevel);
        for (const auto &arg : parser->get())
        {
            if (arg == "-v")
                logger.set(LogSeverity::kVerbose);
            else if (arg == "-d")
                logger.set(LogSeverity::kDebug);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // delete parser;
    logger.log("This is a project's template !", LogSeverity::kDebug);

    return 0;
}
