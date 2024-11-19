#include "Member.hpp"
#include <stdexcept>
#include "Reservation.hpp"
Member::Member() : User() {};

Member::Member(string u, SkillType st) : User(u) {
    this->set_skill_type(st);
}


Reservation Member::make_reservation() {

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

    // Reservation member_res = Reservation(RESERVATION, this, court, res_time, res_date);
    Reservation member_res = Reservation();
    User* member = dynamic_cast<User*>(this);
    member_res = member->make_reservation(&res_date, &res_time, &res_court);
    member_res.set_res_type(RESERVATION);

    if(member_res.valid_reservation()) {
        return member_res;
    }
    else {
        throw std::invalid_argument("Not a valid reservation.  Please try again.");
    }

}
