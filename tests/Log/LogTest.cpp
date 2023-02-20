#include <LoggerTest.hpp>

TEST_GROUP(LoggerTestOnNormalMode)
{
    Logger* logger;

    void setup() { logger = new Logger(LogSeverity::kNormal); }

    void teardown() { delete logger; }
};

TEST(LoggerTestOnNormalMode, LogError)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", LogSeverity::kError);
    std::cout.rdbuf(old_buffer);

    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnNormalMode, LogDebug)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") != 0);
}

TEST(LoggerTestOnNormalMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") != 0);
}

TEST(LoggerTestOnNormalMode, LogInfo)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") != 0);
}

TEST(LoggerTestOnNormalMode, LogNormal)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A message", LogSeverity::kNormal);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A message\n") == 0);
}

TEST_GROUP(LoggerTestOnDebugMode)
{
    Logger* logger;

    void setup() { logger = new Logger(LogSeverity::kDebug); }

    void teardown() { delete logger; }
};

TEST(LoggerTestOnDebugMode, LogError)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogDebug)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogInfo)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") == 0);
}

TEST(LoggerTestOnDebugMode, LogNormal)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A message.", LogSeverity::kNormal);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A message.\n") == 0);
}

TEST_GROUP(LoggerTestOnErrorMode)
{
    Logger* logger;

    void setup() { logger = new Logger(LogSeverity::kError); }

    void teardown() { delete logger; }
};

TEST(LoggerTestOnErrorMode, LogError)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnErrorMode, LogDebug)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message", LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message\n") != 0);
}

TEST(LoggerTestOnErrorMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") != 0);
}

TEST(LoggerTestOnErrorMode, LogInfo)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare("An info message.\n") != 0);
}

TEST(LoggerTestOnErrorMode, LogNormal)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A message.", LogSeverity::kNormal);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A message.\n") != 0);
}

TEST_GROUP(LoggerTestOnVerboseMode)
{
    Logger* logger;

    void setup() { logger = new Logger(LogSeverity::kVerbose); }

    void teardown() { delete logger; }
};

TEST(LoggerTestOnVerboseMode, LogError)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnVerboseMode, LogDebug)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") != 0);
}

TEST(LoggerTestOnVerboseMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A verbose message.", LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A verbose message.\n") == 0);
}

TEST(LoggerTestOnVerboseMode, LogInfo)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message", LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message\n") == 0);
}

TEST(LoggerTestOnVerboseMode, LogNormal)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A message.", LogSeverity::kNormal);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A message.\n") == 0);
}

TEST_GROUP(LoggerTestOnInfoMode)
{
    Logger* logger;

    void setup() { logger = new Logger(LogSeverity::kInfo); }

    void teardown() { delete logger; }
};

TEST(LoggerTestOnInfoMode, LogError)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An error has occurred.", LogSeverity::kError);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An error has occurred.\n") == 0);
}

TEST(LoggerTestOnInfoMode, LogDebug)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A debug message.", LogSeverity::kDebug);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A debug message.\n") != 0);
}

TEST(LoggerTestOnInfoMode, LogVerbose)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", LogSeverity::kVerbose);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") != 0);
}

TEST(LoggerTestOnInfoMode, LogInfo)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("An info message.", LogSeverity::kInfo);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " An info message.\n") == 0);
}

TEST(LoggerTestOnInfoMode, LogNormal)
{
    std::stringstream output;
    std::streambuf* old_buffer = std::cout.rdbuf(output.rdbuf());

    logger->log("A message.", LogSeverity::kNormal);
    std::cout.rdbuf(old_buffer);
    CHECK(static_cast<std::string>(output.str().c_str()).compare(getActualDate() + " A message.\n") == 0);
}
