#include "Date.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
using namespace std;

// default constructor
Date::Date() {
    this->weekday = SUNDAY;
    this->month = JANUARY;
    this->day = 1;
    this->year = 2000;
}

Date::Date(Day w, Month m, int d, int y) {
    this->weekday = w;
    this->month = m;
    if(d > 0 && d < 32) {
        this->day = d;
    }
    else {
        throw std::invalid_argument("Invalid date.");
    }
    
    this->year = y;
}

Day Date::get_weekday() const{
    return this->weekday;
}

Month Date::get_month() const{
    return this->month;
}

int Date::get_day() const{
    return this->day;
}

int Date::get_year() const{
    return this->year;
}

void Date::set_weekday(Day w) {
    this->weekday = w;
}

void Date::set_month(Month m) {
    this->month = m;
}

void Date::set_day(int d) {
    this->day = d;
}

void Date::set_year(int y) {
    this->year = y;
}

Date Date::get_curr_date() {
    Date curr_date;
    time_t curr = time(0);
    string date_time = ctime(&curr);

    string weekday;
    for(int w = 0; w < 3; w++) {
        weekday += date_time[w];
    }

    if(weekday == "Sun") {
        curr_date.set_weekday(SUNDAY);
    }
    else if(weekday == "Mon") {
        curr_date.set_weekday(MONDAY);
    }
    else if(weekday == "Tue") {
        curr_date.set_weekday(TUESDAY);
    }
    else if(weekday == "Wed") {
        curr_date.set_weekday(WEDNESDAY);
    }
    else if(weekday == "Thu") {
        curr_date.set_weekday(THURSDAY);
    }
    else if(weekday == "Fri") {
        curr_date.set_weekday(FRIDAY);
    }
    else if(weekday == "Sat") {
        curr_date.set_weekday(SATURDAY);
    }


    string month;
    for(int m = 4; m < 7; m++) {
        month += date_time[m];
    }

    if(month  == "Jan") {
        curr_date.set_month(JANUARY);
    }
    else if(month == "Feb") {
        curr_date.set_month(FEBRUARY);
    }
    else if(month == "Mar") {
        curr_date.set_month(MARCH);
    }
    else if(month == "Apr") {
        curr_date.set_month(APRIL);
    }
    else if(month == "May") {
        curr_date.set_month(MAY);
    }
    else if(month == "Jun") {
        curr_date.set_month(JUNE);
    }
    else if(month == "Jul") {
        curr_date.set_month(JULY);
    }
    else if(month == "Aug") {
        curr_date.set_month(AUGUST);
    }
    else if(month == "Sep") {
        curr_date.set_month(SEPTEMBER);
    }
    else if(month == "Oct") {
        curr_date.set_month(OCTOBER);
    }
    else if(month == "Nov") {
        curr_date.set_month(NOVEMBER);
    }
    else if(month == "Dec") {
        curr_date.set_month(DECEMBER);
    }

    int day = 0;
    day = (int)date_time[8] - 48;
    day = day * 10;
    day += ((int)date_time[9] - 48);
    curr_date.set_day(day);

    int year;
    year = ((int)date_time[20] - 48) * 1000;
    year += ((int)date_time[21] - 48) * 100;
    year += ((int)date_time[22] - 48) * 10;
    year += ((int)date_time[23] - 48);
    curr_date.set_year(year);

    return curr_date;
    
}


ostream& operator<< (ostream& out, const Date& date) {
    switch(date.get_weekday()) {
        case SUNDAY:
            out << "Sunday";
            break;
        case MONDAY:
            out << "Monday";
            break;
        case TUESDAY:
            out << "Tuesday";
            break;
        case WEDNESDAY:
            out << "Wednesday";
            break;
        case THURSDAY:
            out << "Thursday";
            break;
        case FRIDAY:
            out << "Friday";
            break;
        case SATURDAY:
            out << "Saturday";
            break;
        default:
            out << "No day given";
            break;
    };

    out << ", ";

    switch(date.get_month()) {
        case JANUARY:
            out << "January";
            break;
        case FEBRUARY:
            out << "February";
            break;
        case MARCH:
            out << "March";
            break;
        case APRIL:
            out << "April";
            break;
        case MAY:
            out << "May";
            break;
        case JUNE:
            out << "June";
            break;
        case JULY:
            out << "July";
            break;
        case AUGUST:
            out << "August";
            break;
        case SEPTEMBER:
            out << "September";
            break;
        case OCTOBER:
            out << "October";
            break;
        case NOVEMBER:
            out << "November";
            break;
        case DECEMBER:
            out << "December";
            break;
        default:
            out << "No month given";
            break;
    };

    out << " ";

    if(date.get_day() < 10) {
        out << "0";
    }
    
    out << date.get_day() << ", " << date.get_year();

    out << endl;

    return out;
}


Day Date::day_of_week(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int day = ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;

    switch(day) {
        case 0:
            return SUNDAY;
            break;
        case 1:
            return MONDAY;
            break;
        case 2:
            return TUESDAY;
            break;
        case 3:
            return WEDNESDAY;
            break;
        case 4:
            return THURSDAY;
            break;
        case 5:
            return FRIDAY;
            break;
        case 6:
            return SATURDAY;
            break;
    }
}

Month Date::num_to_month(int m) {
    switch(m) {
        case 1:
            return JANUARY;
            break;
        case 2:
            return FEBRUARY;
            break;
        case 3:
            return MARCH;
            break;
        case 4:
            return APRIL;
            break;
        case 5:
            return MAY;
            break;
        case 6:
            return JUNE;
            break;
        case 7:
            return JULY;
            break;
        case 8:
            return AUGUST;
            break;
        case 9:
            return SEPTEMBER;
            break;
        case 10:
            return OCTOBER;
            break;
        case 11:
            return NOVEMBER;
            break;
        case 12:
            return DECEMBER;
            break;
        default:
            throw std::invalid_argument("Not a valid month of the year.");
            break;
    }
}