#include "../includes/my.hpp"

auto main(int argc, char **argv) -> int
{
    const std::vector<std::string> args = {"-v", "-d"};
    std::vector<std::string> parsedArgs = {};
    // Logger logger{static_cast<cp::lal::ILogger::LogSeverity>(loggerLevel)};
    std::unique_ptr<cp::iparser::IFactory> parserFactory = std::make_unique<cp::parser::PALFactory>();
    std::shared_ptr<cp::iparser::IParser> parser = parserFactory->createParser(args);
    std::unique_ptr<cp::lal::IFactory> loggerFactory = std::make_unique<cp::lal::LALFactory>();
    std::shared_ptr<cp::lal::ILogger> logger = loggerFactory->createLogger(cp::lal::ILogger::LogSeverity::kInfo);

    try
    {
        parser->args(argc, argv);
        for (const auto &arg : parser->get())
        {
            if (arg == "-v")
                logger->set(cp::lal::ILogger::LogSeverity::kVerbose);
            else if (arg == "-d")
                logger->set(cp::lal::ILogger::LogSeverity::kDebug);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // delete parser;
    logger->log("This is a project's template !", cp::lal::ILogger::LogSeverity::kDebug);

    return 0;
}
