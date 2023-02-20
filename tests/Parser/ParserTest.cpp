#include <parserTest.hpp>

TEST_GROUP(ParseArgsTestGroup){
    void setup(){}

    void teardown(){}};

TEST(ParseArgsTestGroup, VerboseFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-v"};
    int verbose = 0;
    const std::vector<std::string> args = {"-v"};

    parse_args(argc, argv, args, verbose);
    CHECK_EQUAL(1, verbose);
}

TEST(ParseArgsTestGroup, DebugFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-v"};
    int verbose = 0;
    const std::vector<std::string> args = {"-v", "-d", "-e"};

    parse_args(argc, argv, args, verbose);
    CHECK_EQUAL(1, verbose);
}

TEST(ParseArgsTestGroup, InvalidFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-x"};
    int verbose = 0;
    const std::vector<std::string> args = {"-v"};
 
    CHECK_THROWS(std::runtime_error, parse_args(argc, argv, args, verbose));
}