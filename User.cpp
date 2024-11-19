#include "User.hpp"
#include <fstream>
#include "Reservation.hpp"
#include <iostream>
using namespace std;


User::User() {
        this->username = "";
        this->weekly_sum = 0;
        this->skill_type = C;
}

User::User(string u) {
    this->username = u;
    this->weekly_sum = 0;
    this->skill_type = C;
}

string User::get_username() {
    return this->username;
}

int User::get_sum() {
    return this->weekly_sum;
}

SkillType User::get_skill_type() {
    return this->skill_type;
}

vector<int> User::get_reservation_list() {
    return this->reservation_list;
}


void User::set_username(string un) {
     this->username = un;
}

void User::set_sum(int num_res) {
     this->weekly_sum = num_res;
}

void User::set_skill_type(SkillType st) {
    this->skill_type = st;
}

void User::set_reservation_list(vector<int> res_list) {
    this->reservation_list = res_list;
}


void User::add_reservation(int res_id) {
    this->reservation_list.push_back(res_id);
}



void User::view_sched() {
}



 ofstream& operator<<(ofstream& ofs, User u){
	ofs << u.get_username() <<endl;
	ofs << u.get_sum()<<endl;
	ofs << u.get_skill_type() <<endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, User& u){
    string un ="";
    int ws = 0;
    //SkilltType???	
    ifs >> un >> ws;
    u.set_username(un);
    return ifs;
}

Reservation User::make_reservation(Date* date, Time* time, Court* court) {
    Reservation res = Reservation();
//generate resid?
    res.set_reserver(this);
    res.set_court(court);
    res.set_time(time);
    res.set_date(date);
    this->add_reservation(res.get_res_id());
    return res;
}

