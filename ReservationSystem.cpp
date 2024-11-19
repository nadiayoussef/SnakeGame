#include <iostream>
#include "User.hpp"
#include "Member.hpp"
#include "Coach.hpp"
#include "Officer.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Display.hpp"
#include "Reservation.hpp"
#include <cstdlib>
#include <cstdio>
#include <ncurses.h>
#include <ctime>
#include <string>
#include <vector>
using namespace std;


void booking() {
    cout << "test" << endl;
    int time;
    int date;
    Court *court;
    // make_reservation(time, date, court);

}


void printBorder(){
const int borderWidth = 100;
const int borderHeight = 74;

//printing top border
std::cout << std::string(borderWidth, '-') << std::endl;

int i = 0;
int c =0;
int hour =6;
int min =0;
int count =1;

//Printing Court header
    while (i < borderWidth-2)
    {
if(i==15 && c==0){
cout<<"Court 1";
}
if(i==35 && c==0){
cout<<"Court 2";

}
if(i==55 && c==0){
cout<<"Court 3";
c=1;
}
cout<< " ";
i++;
}

i=0;
std::cout << endl<<string(borderWidth, '-') << std::endl;
 
//Printing sides
while (i < borderHeight - 2)
    {

//printing hours
    if (i%2 == 0){
	cout<<"|";
if(hour<10){
cout<<" ";
}

cout<<hour<< ":"<<min<< 0<<"|";

if(count%2 == 0){
hour++;
min=0;
}
if(count%2 !=0){
if(min==0){
min=3;
}
else{min =0;}
}

cout<<string(borderWidth - 7, ' ') << "|"<<endl;
count++;
 }      

else{ std::cout << "| " << std::string(borderWidth - 2, ' ') << "|"<<endl;}
        i++;
	
 }

//printing bottom border
std::cout << std::string(borderWidth, '-') << std::endl;
}

int main() {

Coach c1 = Coach("enk");
vector<Reservation> vector_of_reservations;

//getting amount of users from last time program was run
int user_count =0;
ifstream in("user_count.txt");
in>>user_count;
in.close();

// ifstream rin("reservation_data.txt");
// while(!rin.eof()) {
//     Reservation r;
//     rin >> r;
//     vector_of_reservations.push_back(r);
// }
// rin.close();

ifstream ifs("user_data.txt");
vector<User> vector_of_users;
for (int x =0; x<(user_count*3); x++){
User u;
ifs>> u;
vector_of_users.push_back(u);
}
ifs.close();

//user prompt
string user_name = "";
//vector<User> vector_of_users;
vector_of_users.push_back(c1);
string user_type = "";
bool found_flag = false;
char user_action=' ';
User curr_user;
cout<< "Hi! Welcome to the Pickleball Facility Scheduler! If you already have an account please enter your username. If your username is not already in our system, the username you enter will be added to our database: " <<endl;
cin>>user_name;

for(int x =0; x<vector_of_users.size(); x++){

	if (vector_of_users[x].get_username() == user_name){
	cout<< "Username found, signing you into your account"<<endl;
	found_flag =true;
	curr_user= vector_of_users[x];
}
}
if(found_flag==false){
cout<< "Enter whether you are a coach, officer, or member"<<endl;
cin>>user_type;
if (user_type == "coach"){
Coach c;
c.set_username(user_name);
vector_of_users.push_back(c);
curr_user =c;
}
else if (user_type == "officer"){
Officer o;
o.set_username(user_name);
vector_of_users.push_back(o);
curr_user =o;
}
else {
Member m;
m.set_username(user_name);
vector_of_users.push_back(m);
curr_user =m;
}

cout<< "Account created, signing you in."<<endl;

}
ofstream ofs("user_data.txt", ios::trunc);
for(int x =0; x<vector_of_users.size(); x++){
ofs<<vector_of_users[x];
}
ofs.close();
ofstream out("user_count.txt");
out<<vector_of_users.size();
out.close();

ofstream outfile("res_count.txt");
outfile << vector_of_reservations.size();
outfile.close();

ofstream outr("reservation_data.txt", ios::trunc);
for(int x = 0; x < vector_of_reservations.size(); x++) {
    outr << vector_of_reservations[x];
}
outr.close();


while(user_action != 'x')
{
cout<<"You have the following options: make a reservation, join a reservation, cancel a reservation, check the current schedule or exit the program. Enter 'm' for make, 'j' for join, 'c' for cancel, 's' for schedule, or 'x' for exit: "<<endl;
cin>>user_action;

if( user_action == 'm'){
//curr_user.make_reservation();

}

else if( user_action == 'j'){
//curr_user.join_reservation();

}
else if( user_action == 'c'){
//curr_user.cancel_reservation();
}

else if( user_action == 's'){
printBorder();
}

else if( user_action == 'x'){
break;
}

cout<< "Taking you back to the home screen"<<endl<<endl;


}

    booking();

    return(0);
}
