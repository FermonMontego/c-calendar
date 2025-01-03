#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int selectTab(int* tab, int** currentTab);
int printCurrentTab(char* currentTab);
int printCurrentTabValues(int currentTab);

int selectedYears = -1;
int selectedMonth = -1;

char* formatWeekLabel(int week);

int printYears();
int printMonths();
int printDays();

int range_years = 1000;
int current_year;

enum Tabs {
    YEARS = 0,
    MONTHS = 1,
    DAYS = 2,
};

int months[12];

int weeks[7] = {
    0, 1, 2, 3, 4, 5, 6
};

int main()
{
    current_year = get_current_year();

    months[0] = 31;
    months[1] = (current_year % 4 == 0 && current_year % 100 != 0) || (current_year % 400 == 0) ? 29 : 28;
    months[2] = 31;
    months[3] = 30;
    months[4] = 31;
    months[5] = 30;
    months[6] = 31;
    months[7] = 31;
    months[8] = 30;
    months[9] = 31;
    months[10] = 30;
    months[11] = 31;

    int currentTabDefault = YEARS;
    int* currentTab = &currentTabDefault;

    printCurrentTabValues(*currentTab);

    return 0;
}

int selectTab(int* tab, int** currentTab) {
    *currentTab = tab;

    return 0;
}

int printCurrentTabValues(int currentTab) {

    switch(currentTab) {
        case YEARS:
            return printYears();
            break;
        case MONTHS:
            return printMonths();
            break;
        case DAYS:
            return printDays();
            break;
    }

    return 0;
}

int printYears() {
    int start = current_year - range_years;
    int end = current_year;

    for(int i = start; i <= end; i++) {
        printf("%d ", i);
    }

    while(1) {
        printf("\n\nChoose year: ");
        scanf("%d", &selectedYears);

        if(selectedYears < start || selectedYears > end) {
            printf("Selected years not exist in list\n\n");
            selectedYears = -1;

            continue;
        }

        break;
    }

    printCurrentTabValues(MONTHS);

    return 0;
}

int printMonths() {
    for(int i = 0; i < sizeof(months) / sizeof(int); i++) {
        printf("%d ", i + 1);
    }

    while(1) {
        printf("\n");
        printf("Choose month: ");

        scanf("%d", &selectedMonth);

        if(selectedMonth < 1 || selectedMonth > 12) {
            printf("Selected month is not correct\n");
            selectedMonth = -1;
            continue;
        }

        break;
    }

    printCurrentTabValues(DAYS);

    return 0;
}

int printDays() {

    int dayOfWeekIndex = getDayOfWeek(selectedYears, selectedMonth, 1);
    int lineBreakCount = 0;

    for(int i = 0; i < sizeof(weeks) / sizeof(int); i++) {
        printf("%s\t", formatWeekLabel(i));
    }

    printf("\n\n");

    for(int startDayOfWeek = 0; startDayOfWeek < (dayOfWeekIndex == 0 ? 6 : dayOfWeekIndex - 1); startDayOfWeek++) {
        printf(" \t");
        lineBreakCount++;
    }

    for(int k = dayOfWeekIndex; k < months[selectedMonth - 1] + dayOfWeekIndex; k++) {
        printf(" %d\t", k + 1 - dayOfWeekIndex);

        lineBreakCount++;

        if(lineBreakCount % 7 == 0) {
            printf("\n");
            lineBreakCount = 0;
        };
    }

    return 0;
}

char* formatWeekLabel(int week) {
    switch(week) {
        case 0: return "Mon.";
        case 1: return "Tue.";
        case 2: return "Wed.";
        case 3: return "Thu.";
        case 4: return "Fri.";
        case 5: return "Sat.";
        case 6: return "Sun.";
        default: return "Mon.";
    }

    return 0;
}
