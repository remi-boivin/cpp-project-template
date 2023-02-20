#include "../include/date.hpp"

std::string getActualDate()
{
    auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream actualDate;

    actualDate << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return actualDate.str();
}