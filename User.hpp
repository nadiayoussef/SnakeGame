#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <fstream>
// #include "Reservation.hpp"
using namespace std;
#include "Date.hpp"


enum SkillType {PRO, A, B, C};

class Reservation;
class Court;
// class Date;
class Time;


// User class
class User{
private:
        string username;
        int weekly_sum = 0;
	SkillType skill_type;
	vector<int> reservation_list;
public:
        // constructors
        User();
        User(string name);

        // getters
        string get_username();
        int get_sum();
        SkillType get_skill_type();
        vector<int> get_reservation_list();

        // setters
        void set_username(string un);
        void set_sum(int num_res); 
        void set_skill_type(SkillType st);
        void set_reservation_list(vector<int> res_list);

        void add_reservation(int res_id);

	friend ofstream & operator<<(ofstream& ofs,User u);
	friend ifstream& operator>>(ifstream& ifs, User& u);
          

        Reservation make_reservation(Date* date, Time* time, Court* court);        

        void view_sched();
};
#endif
