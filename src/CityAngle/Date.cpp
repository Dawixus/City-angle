#include "Date.h"
#include <ctime>

std::tuple<int, int, int> Date::getDay() {
        std::time_t t = std::time(nullptr);
        std::tm* date = std::localtime(&t);
        int day = date->tm_mday;
        int month = date->tm_mon + 1;
        int year = date->tm_year + EPOCH_START;
        return {day, month, year};
    }