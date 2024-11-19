#include<iostream>
#include "Officer.hpp"
#include <stdexcept>
using namespace std;

// class Reservation;
#include "Reservation.hpp"


Officer::Officer() : User() {};

Officer::Officer(string u, SkillType st) : User(u) {
    this->set_skill_type(st);
}


Reservation Officer::make_reservation() {

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

    Date curr_date = curr_date.get_curr_date();
    int curr_day = curr_date.get_day();
    while((day - curr_day) < 2) { // checks if the reservation is within 2 days
        cout << "Error!\nYou must reserve time at least two days in advance.\nPlease input a new date (dd/mm/yyyy): ";
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

    char type;
    cout << "Is this a regular reservation (r) or open-play hours (o): ";
    cin >> type;
    cout << endl;

    while(type != 'r' && type != 'o') {
        cout << "Error!\nPlease enter either a 'r' for regular reservation or 'o' for open-play hours: ";
        cin >> type;
        cout << endl;
    }

    ReservationType res_type;
    if(type == 'r') {
        res_type = RESERVATION;
    }
    else if(type == 'o') {
        res_type == OPEN_PLAY;
    }
    else {
        throw std::invalid_argument("Not a valid reservation.  Please try again.");
    }

    // Reservation officer_res = Reservation(res_type, this, court, res_time, res_date);
    Reservation officer_res = Reservation();
    User* officer = dynamic_cast<User*>(this);
    officer_res = officer->make_reservation(&res_date, &res_time, &res_court);
    officer_res.set_res_type(res_type);

    if(officer_res.valid_reservation()) {
        return officer_res;
    }
    else {
        throw std::invalid_argument("Not a valid reservation.  Please try again.");
    }

}

void modify_reservation(User user, int res_id) {
    vector<int> user_res = user.get_reservation_list();
    bool owns = false;
    for(int& res_num : user_res) {
        if(res_num == res_id) { // checks that the given user owns reservation of the given reservation id
            owns = true;
        }
    }
    if(!owns) {
        throw invalid_argument("The user requesting modification does not own this reservation.  Please try again.");
    }


}







//  void reserve_coaches(Coach c, int res_id){
// //if(find(vec.begin(), vec.end(), elem) != vec.end()

// }
//  void reserve_members(Member m, int res_id){

// }
//  void cancel_any(User u,int res_id){


// }
