#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <typeinfo>

#include "Time.hpp"
#include "Date.hpp"
#include "Court.hpp"
#include "User.hpp"

enum ReservationType {RESERVATION, LESSON, OPEN_PLAY};


class Reservation{
    private:
        ReservationType type;
	int res_id;
        User* reserver;
        User* added_reserver;
        Court* court;
        Time* time;
        Date* date;

    public:
        // constructor
        Reservation(ReservationType ty, User* u, Court* c, Time* t, Date* d);
        Reservation();
        void Reservation_helper(vector<float> params, User* u);
	// getters
        ReservationType get_res_type();
        User* get_reserver();
        User* get_added_reserver();
        Court* get_court();
        Time* get_time();
        Date* get_date();
        int get_res_id();

        // setters
        void set_res_type(ReservationType t);
        void set_reserver(User* r);
        void set_court(Court* c);
        void set_time(Time* t);
        void set_date(Date* d);

        void join_reservation(User* r);
        bool valid_reservation();

	friend ofstream & operator<<(ofstream & ofs, Reservation r);
        friend ifstream & operator>>(ifstream & ifs, Reservation& r);
};
#endif
