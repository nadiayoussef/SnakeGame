#include <iostream>
#include "Court.hpp"
using namespace std;

Court::Court() {
        this->court_num = 0;
        vector<Reservation> res_h;
        this->reserved_hours = res_h;
}
Court::Court(int cn, vector<Reservation> res_h) {
        this->court_num = cn;
        this->reserved_hours = res_h;
}

int Court::get_court_num() {
        return this->court_num;

}

vector<Reservation> Court::get_reserved_hours() {
        return this->reserved_hours;
}

void Court::set_court_num(int cn) {
        this->court_num = cn;
}

void Court::set_reserved_hours(vector<Reservation> res_h) {
        this->reserved_hours = res_h;
}

void Court::add_reservation(Reservation r) {
        this->reserved_hours.push_back(r);
}
