#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
enum Day {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum Month {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

class Date {
    private:
        Day weekday;
        Month month;
        int day;
        int year;

    public:
        // out streaam overloaded operator
        friend ostream& operator<< (ostream& out, const Date& date);

        // constructors
        Date();
        Date(Day w, Month m, int d, int y);
        // getters
        Day get_weekday() const;
        Month get_month() const;
        int get_day() const;
        int get_year() const;
        // setters
        void set_weekday(Day w);
        void set_month(Month m);
        void set_day(int d);
        void set_year(int y);

        Date get_curr_date();
        Day day_of_week(int d, int m, int y);
        Month num_to_month(int m);

}; 
#endif