#include "Coach.hpp"
#include "Reservation.hpp"
#include <iostream>
#include <string.h>
#include <stdexcept>
using namespace std;

Coach::Coach() : User() {};

Coach::Coach(string u) : User() {
    this->set_skill_type(PRO);
}


//need to check that it is not saturday and two days in advance
Reservation Coach::make_reservation() {

    int day = 0;
    int month = 0;
    int year = 0;


    string date;
    cout << "Making a reservation...please enter reservation information:" << endl;
    cout << "Enter the date in dd/mm/yyyy format: ";
    cin >> date;
    cout << endl;

    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));

    Date res_date;
    Day weekday = res_date.day_of_week(day, month, year);
    Month mon = res_date.num_to_month(month);

    while(weekday == SATURDAY) { // checks if reservation is made on a saturday
        cout << "Error\nCoaches may not reserve time on Saturdays.\nPlease input a new date (dd/mm/yyyy): ";
        cin >> date;
        cout << endl;

        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));

        Day weekday = res_date.day_of_week(day, month, year);
        Month mon = res_date.num_to_month(month);
    }


        Date curr_date = curr_date.get_curr_date();
        int curr_day = curr_date.get_day();
        while((day - curr_day) < 2) { // checks if the reservation is within 2 days
            cout << "Error\nYou must reserve time at least two days in advance\nPlease input a new date (dd/mm/yyyy): ";
            cin >> date;
            cout << endl;

            day = stoi(date.substr(0, 2));
            month = stoi(date.substr(3, 2));
            year = stoi(date.substr(6, 4));

            Day weekday = res_date.day_of_week(day, month, year);
            Month mon = res_date.num_to_month(month);
        }

    // RESERVATION DATE
    res_date = Date(weekday, mon, day, year);

    int hour;
    int minute;
    string time;
    cout << "Reservation times can only start on the hour or half hour." << endl;
    cout << "Please enter your reservation's start time in hh:mm format: ";
    cin >> time;
    cout << endl;

    hour = stoi(time.substr(0, 2));
    minute = stoi(time.substr(3, 2));

    while(minute != 0 || minute != 30) {
        cout << "Error!\nReservation times can only start on the hour or half hour." << endl;
        cout << "Please enter your reservation's start time in hh:mm format: ";
        cin >> time;
        cout << endl;

        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
    }

    // RESERVATION TIME
    Time res_time = Time(hour, minute);

    string court_num;
    cout << "Please enter which court you would like to reserve (1, 2, or 3): ";
    cin >> court_num;
    cout << endl;

    string c = "Court " + court_num;
    Court res_court =  Court(); // COME BACK TO EDIT COURT CLASS

    // Reservation coach_res = Reservation(LESSON, this, court, res_time, res_date);
    Reservation coach_res = Reservation();
    User* coach = dynamic_cast<User*>(this);
    coach_res = coach->make_reservation(&res_date, &res_time, &res_court);
    coach_res.set_res_type(LESSON);

    if(coach_res.valid_reservation()) {
        return coach_res;
    }
    else {
        throw std::invalid_argument("Not a valid reservation.  Please try again.");
    }
}