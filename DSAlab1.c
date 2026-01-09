/*a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 7 days of a week.
 Each Element of the array is a structure having three fields. The first field is the name of the Day (A dynamically allocated String), 
 The second field is the date of the Day (A integer), the third field is the description of the activity for a particular day
  (A dynamically allocated String).
b) Write functions create(), read() and display(); to create the calendar, to read the data from the keyboard and to
 print weeks activity details report on screen.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calElement
{
    char *day;
    int date;
    char *activity;
};

struct calElement* create()
{
    struct calElement *calendar;
    calendar = (struct calElement *)malloc(sizeof(struct calElement) * 7);
    return calendar;
}

void read(struct calElement *calendar)
{
    char day[10];
    char activity[50];
    int i, date;

    for(i = 0; i < 7; i++)
    {
        printf("\nEnter the day: ");
        scanf("%s", day);

        calendar[i].day = (char *)malloc(strlen(day) + 1);
        strcpy(calendar[i].day, day);

        printf("Enter the date: ");
        scanf("%d", &date);
        calendar[i].date = date;

        printf("Enter description of the activity: ");
        scanf(" %[^\n]", activity); // " %[^\n]" :- Reads full sentence including spaces and Stops when Enter is pressed

        calendar[i].activity = (char *)malloc(strlen(activity) + 1);
        strcpy(calendar[i].activity, activity);
    }
}

void display(struct calElement *calendar)
{
    int i;
    printf("\n\nYour Calendar\n");
    printf("Day\t\tDate\t\tActivity");

    for(i = 0; i < 7; i++)
    {
        printf("\n%s\t\t%d\t\t%s",
               calendar[i].day,
               calendar[i].date,
               calendar[i].activity);
    }
}

int main()
{
    int i;
    struct calElement *calendar;

    calendar = create();
    read(calendar);
    display(calendar);

    // Free inner allocations
    for(i = 0; i < 7; i++)
    {
        free(calendar[i].day);
        free(calendar[i].activity);
    }

    free(calendar);
    return 0;
}

