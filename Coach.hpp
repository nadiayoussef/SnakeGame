#ifndef COACH_H
#define COACH_H
#include<iostream>
#include "User.hpp"
#include <vector>
class Coach : public User {
public:
	Coach();
	Coach(string u);

	Reservation make_reservation();

};
#endif
