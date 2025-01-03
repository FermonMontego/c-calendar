#include "utils.h"
#include <stdio.h>
#include <time.h>

int getDayOfWeek(int year, int month, int day) {
    int a;
    int y;
    int m;
    int R;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return R % 7;
}

char* getDayOfWeekByIndex(int week) {
    char* daysOfWeek[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    return daysOfWeek[week];
}

int get_current_year() {
    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);

    return now->tm_year + 1900;
}
