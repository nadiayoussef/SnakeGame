#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include "User.hpp"

//class User;

class Member : public User{
public:
	Member();
	Member(string u, SkillType st);

	Reservation make_reservation();


	void message_officer (string message);
};
#endif
