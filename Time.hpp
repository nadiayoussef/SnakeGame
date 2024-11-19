#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
    private:
        int hour;
        int minute;

    public:
        // out streaam overloaded operator
        friend ostream& operator<< (ostream& out, const Time& time);
        // equality overloaded operator
        friend bool operator== (const Time& t1, const Time& t2);
        // constructors
        Time();
        Time(int h, int m);
        // getters
        int get_hour() const;
        int get_minute() const;
        // setters
        void set_hour(int h);
        void set_minute(int m);

        Time get_curr_time();
};


#endif