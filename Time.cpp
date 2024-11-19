#include "Time.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

// default constructor
 Time::Time() {
     this->hour = 0;
     this->minute = 0;
}

 Time::Time(int h, int m) {
    if(h >=0 && h < 24) {
        this->hour = h;
    }
    else {
        throw std::invalid_argument( "not valid hour" );
    }
    if(m >=0 && m < 60){
        this->minute = m;
    }
    else {
        throw std::invalid_argument( "not valid minute" );
    }
}

int Time::get_hour() const{
    return this->hour;
}

int Time::get_minute() const{
    return this->minute;
}

void Time::set_hour(int h) {
    this->hour = h;
}

void Time::set_minute(int m) {
    this->minute = m;
}

// char* Time::get_curr_time() {
//     // current date and time on this system
//    time_t curr = time(0);
//    // convert to readable char
//    char* date_time = ctime(&curr);

//    return date_time;
// }

Time Time::get_curr_time() {

    Time curr_time;
    time_t curr = time(0);
    string date_time = ctime(&curr);


    int hour = 0;
    hour = (int)date_time[11] - 48;
    hour = hour * 10;
    hour += ((int)date_time[12] - 48);
    curr_time.set_hour(hour);

    int minute;
    minute = ((int)date_time[14] - 48);
    minute = minute * 10;
    minute += ((int)date_time[15] - 48);
    curr_time.set_minute(minute);

    return curr_time;
}

ostream& operator<< (ostream& out, const Time& time) {
    out << time.get_hour();
    out << ":";
    if(time.get_minute() < 10) {
        out << "0";
    }
    out << time.get_minute();
    return out;
}

bool operator== (const Time& t1, const Time& t2)
{
    return (t1.get_hour() == t2.get_hour()) && (t1.get_minute() == t2.get_minute());
}