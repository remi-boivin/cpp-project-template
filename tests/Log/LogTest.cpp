#include "./include/LoggerTest.hpp"

std::shared_ptr<cp::lal::ILogger> logger;

TEST_GROUP(LoggerTestOnInfoMode)
{
    void setup()
    {
        std::unique_ptr<cp::lal::IFactory> loggerFactory = std::make_unique<cp::lal::LALFactory>();
        logger = loggerFactory->createLogger(cp::lal::ILogger::LogSeverity::kInfo);
    }

    void teardown()
    {
        logger.reset();
    }
};

TEST(LoggerTestOnInfoMode, LogError)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", cp::lal::ILogger::LogSeverity::kError);
    std::cout.rdbuf(old_buffer);

    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnInfoMode, LogDebug)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", cp::lal::ILogger::LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") != 0);
}

TEST(LoggerTestOnInfoMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", cp::lal::ILogger::LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") != 0);
}

TEST(LoggerTestOnInfoMode, LogInfo)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", cp::lal::ILogger::LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") == 0);
}

TEST_GROUP(LoggerTestOnDebugMode){
    void setup(){
        std::unique_ptr<cp::lal::IFactory> loggerFactory = std::make_unique<cp::lal::LALFactory>();
logger = loggerFactory->createLogger(cp::lal::ILogger::LogSeverity::kDebug);
}

void teardown() { logger.reset(); }
}
;

TEST(LoggerTestOnDebugMode, LogError)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", cp::lal::ILogger::LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogDebug)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", cp::lal::ILogger::LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", cp::lal::ILogger::LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogInfo)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", cp::lal::ILogger::LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") == 0);
}

TEST_GROUP(LoggerTestOnErrorMode){
    void setup(){
        std::unique_ptr<cp::lal::IFactory> loggerFactory = std::make_unique<cp::lal::LALFactory>();
logger = loggerFactory->createLogger(cp::lal::ILogger::LogSeverity::kError);
}

void teardown() { logger.reset(); }
}
;

TEST(LoggerTestOnErrorMode, LogError)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", cp::lal::ILogger::LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnErrorMode, LogDebug)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message", cp::lal::ILogger::LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message\n") != 0);
}

TEST(LoggerTestOnErrorMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", cp::lal::ILogger::LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") != 0);
}

TEST(LoggerTestOnErrorMode, LogInfo)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", cp::lal::ILogger::LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare("An info message.\n") != 0);
}

TEST_GROUP(LoggerTestOnVerboseMode){
    void setup(){std::unique_ptr<cp::lal::IFactory> loggerFactory = std::make_unique<cp::lal::LALFactory>();
logger = loggerFactory->createLogger(cp::lal::ILogger::LogSeverity::kVerbose);
}

void teardown() { logger.reset(); }
}
;

TEST(LoggerTestOnVerboseMode, LogError)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", cp::lal::ILogger::LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnVerboseMode, LogDebug)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", cp::lal::ILogger::LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") != 0);
}

TEST(LoggerTestOnVerboseMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", cp::lal::ILogger::LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") == 0);
}

TEST(LoggerTestOnVerboseMode, LogInfo)
{
    std::stringstream output;
    std::streambuf *old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message", cp::lal::ILogger::LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message\n") == 0);
}