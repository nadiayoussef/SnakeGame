#include "Reservation.hpp"
#include <iostream>
using namespace std;

Reservation::Reservation(ReservationType ty, User* u, Court* c, Time* t, Date* d) {

    this->type = ty;

    int four = (rand() % 10) * 1000;
    int three = (rand() % 10) * 100;
    int two = (rand() % 10) * 10;
    int one = (rand() % 10);
    int id = four + three + two + one;
    this->res_id = id;

    this->reserver = u;
    this->court = c;
    // this->time = t1;
    // this->date = d1;
    this->time = t;
    this->date = d;
}

Reservation::Reservation() {
    this->type = RESERVATION;
    
    // Random id
    int four = (rand() % 10) * 1000;
    int three = (rand() % 10) * 100;
    int two = (rand() % 10) * 10;
    int one = (rand() % 10);
    int id = four + three + two + one;
    this->res_id = id;

    this->reserver = new User();
    this->added_reserver = new User();
    this->court = new Court();
    this->time = new Time();
    this->date = new Date();
}



 ofstream& operator<<(ofstream& ofs, Reservation r){

        ofs << r.get_res_type() <<endl;

        ofs << r.get_reserver()<<endl;

        ofs << r.get_added_reserver() <<endl;

        ofs << r.get_court() <<endl;

        ofs << r.get_time() <<endl;

        ofs << r.get_date() <<endl;

        return ofs;

}

ifstream& operator>>(ifstream& ifs, Reservation& r){

    User* u;
    string username = "";
    string restype = "";
    Court* c;
    int court = 0;
    int time = 0;
    int hour1 = 0;
    int hour2 = 0;
    int min1 = 0;
    int min2 = 0;
    ifs >> restype>> username >> court>> time;
    u->set_username(username);
    r.set_reserver(u);
    c->set_court_num(court);
    r.set_court(c);
    hour1 = time /1000 %10;
    hour2 = time /100 %10;
    min1 = time / 10 % 10;
    min2 = time % 10;
    hour1 = hour1*10 +hour2;
    min1 = min1*10 + min2;
    Time* t = new Time(hour1,min1);
    r.set_time(t);
    return ifs;
}


ReservationType Reservation::get_res_type() {
    return this->type;
}

User* Reservation::get_reserver() {
     return this->reserver;
 }

 User* Reservation::get_added_reserver() {
     return this->added_reserver;
 }

Court* Reservation::get_court() {
    return this->court;
}

Time* Reservation::get_time() {
    return this->time;
}

Date* Reservation::get_date() {
    return this->date;
    
}

int Reservation::get_res_id() {
    return this->res_id;
}

void Reservation::set_res_type(ReservationType t) {
    this->type = t;
}

 void Reservation::set_reserver(User* r) {
     this->reserver = r;
 }

void Reservation::set_court(Court* c) {
    this->court = c;
   
}

void Reservation::set_time(Time* t) {
    this->time = t;
}

void Reservation::set_date(Date* d) {
    this->date = d;
}

 void Reservation::join_reservation(User* r) {
     this->added_reserver = r;
    
 }

bool Reservation::valid_reservation() {
    
    Time *res_time = this->get_time();
    int hour = res_time->get_hour();
    if(hour < 6) { // checks if the reservation time is between 12am and 6am
        return false;
    }

    ReservationType res_type = this->get_res_type();
    if(res_type == OPEN_PLAY) {
        if(hour < 18 || hour > 21) {
            return false;
        }
    }

    // check if there is already a reservation at this time
    // if so, return false
    Court* res_court = this->get_court();
    vector<Reservation> reses = res_court->get_reserved_hours();
    int size = reses.size();
    for(int i = 0; i < size; i++) {
        Reservation res = reses[i];
        Time* t = res.get_time();
        if(t == res_time) {
            return false;
        }
    }

    Date *res_date = this->get_date();
    int res_day = res_date->get_day();
    Date curr_date = curr_date.get_curr_date();
    int curr_day = curr_date.get_day();
    if((res_day - curr_day) > 7) { // checks if the reservation is within the next week (7 days)
        return false;
    }

    // check that this user does not have more than two reservations already this week
    // if so, return false
    User* user = this->get_reserver();
    if(user->get_sum() >= 2){
        return false;
    }

    return true;
}
