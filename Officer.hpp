#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include "User.hpp"
using namespace std;

//class User;

class Officer : public User{
	public:
// constructor
	Officer();
 	Officer(string u, SkillType st);

	Reservation make_reservation();
	void modify_reservation(User user, int res_id);
};


#endif
