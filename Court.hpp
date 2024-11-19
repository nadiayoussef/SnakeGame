#ifndef COURT_H
#define COURT_H
#include <iostream>
#include "Reservation.hpp"
#include <vector>
using namespace std;

class Reservation;

class Court{
private:
        int court_num;
        vector<Reservation> reserved_hours;

public:
        // constructor
        Court();
        Court(int cn, vector<Reservation> res_h);

        // getters
        int get_court_num();
        vector<Reservation> get_reserved_hours();

        // setters
        void set_court_num(int cn);
        void set_reserved_hours(vector<Reservation>);

        void add_reservation(Reservation r);

};
#endif
