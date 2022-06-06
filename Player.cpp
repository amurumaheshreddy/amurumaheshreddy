#include <iostream> //writing #include statements
#include <iomanip>
#include <cstring>
using namespace std;
class Player //naming class
{
public: //defining what is public
Player() //first constructor, takes no argument
{
setName("none"); //initializing name to null string
number = 0; //initializing integer data numbers to 0
goals = 0;
assists = 0;
}
//this one parameter constructor takes the number and asks the user to enter the other inputs
Player(int initialNumber) {
char newName[50];
int g, assist;
cout << "\nWhat is the player number " << initialNumber << " name? ";
cin.getline(newName, 50);
cout << "How many goals have been scored? ";
cin >> g;
cout << "How many assists have been earned? ";
cin >> assist;
setPlayer(newName, initialNumber, g, assist);
}
Player(const char * n, int nm, int g, int a) //second constructor, takes four arguments
{
setName(n); //initializing data members using passed in arguments
number = nm;
goals = g;
assists = a;
}
void printPlayer() {
cout << "\n" << name << "\t #" << number << endl;
cout << "Goals: " << goals << "\t Assists: " << assists << "\t Points: " << (goals + assists) << endl; //displaying information
}
void setNumber(int newNumber) {
number = newNumber; //assigning passed argument to the number data member
}
void changeGoals(int goalsScored) {
if (goalsScored < 0) //if passed in number of goals is less than 0
{
cout << endl << "\nError in changeGoals. The # of goals scored cannot be negative" << endl; //displaying error message
return;
}
goals += goalsScored; //incrementing the goals data member by the passed in number of goals if passed in number of goals is greater than or equal to 0
}
void changeAssists(int assistsEarned) {
if (assistsEarned < 0) //if passed in number of assists is less than 0
{
cout << "\nError in changeAssists. The # of assists earned cannot be negative" << endl << endl; //displaying error message
return;
}
assists += assistsEarned; //incrementing the assists data member by the passed in number of assists if passed in number of assists is greater than or equal to 0
}
//this method sets the goals of player
void setGoals(int newGoals) {
//if the newGoals is negative display the error message else assign it to goals
if (newGoals < 0)
cout << "\nError in setGoals: The # of goals scored cannot be negative";
else
goals = newGoals;
}
//this method sets the assists of player
void setAssists(int newAssists) {
//if the newAssists is negative display the error message else assign it to assists
if (newAssists < 0)
cout << "\nError in setAssists: The # of assists scored cannot be negative";
else
assists = newAssists;
}
//this method sets the player's name,number,goals and assists to current player object
void setPlayer(const char newName[], int newNumber, int newGoals, int newAssists) {
setName(newName);
setNumber(newNumber);
setGoals(newGoals);
setAssists(newAssists);
}
//this method returns the name of player
char * getName() {
return name;
}
//this method sets the name with newname if it is not empty
void setName(const char * newname) {
if (strcmp(newname, "") == 0)
cout << "\nError in setName: The new name cannot be empty";
else
strcpy(name, newname);
}
int getNumber() {
return number;
}
int getGoals() {
return goals;
}
int getAssists() {
return assists;
}
private: //defining what is private
//data members for the class
char name[50];
int number;
int goals;
int assists;
};
int main() {
//creating 6 Player objects, first number is sweater number, second number is goals scored, third number is assists
Player p1("Ted E.Bear", 52, 15, 13);
Player p2; //will use default constructor
Player p3("Patrick Kane", 88, 23, 60);
Player p4("Alex DeBrincat", 12, 39, 28);
Player p5("Calvin de Haan", 44, 4, 4);
Player p6("Dylan Strome", 17, 20, 23);
cout << "\nThe first player object" << endl; //announcing first player object
p1.printPlayer(); //displaying player information for first player
p1.setPlayer("", 52, -18, -42);
p1.setPlayer("Ted E.Bear", 52, 15, 13);
p1.printPlayer();
cout << "\nThe second player object" << endl; //announcing second player object
p2.printPlayer(); //displaying player info for second player with default constructor
p2.setPlayer("Seth Jones", 4, 5, 44);
p2.printPlayer(); //displaying player info for second player with changed values
cout << "\nThe third player object" << endl; //announcing third player object
p3.printPlayer(); //displaying player info for second player
p3.changeGoals(-8); //changing number of goals
p3.changeAssists(-2); //changing number of assists
p3.printPlayer(); //displaying player info a second time
p3.changeGoals(1); //increasing number of goals by 1
p3.changeAssists(2); //increasing number of assists by 2
p3.printPlayer(); //displaying player info a third time
cout << "\nThe fourth player object" << endl; //announcing fourth player object
p4.printPlayer(); //displaying player info
p4.changeAssists(3); //increasing number of assists by three
p4.printPlayer(); //displaying player info again
cout << "\nThe fifth player object" << endl; //announcing fifth player object
cout << p5.getName() << " wears sweater number " << p5.getNumber() << " and has scored " << p5.getGoals() << " goals " << endl; //displaying only player's name along with sweater number and number of goals scored
cout << "\nThe sixth player object" << endl; //announcing sixth player object
cout << "Player number " << p6.getNumber() << " has earned " << p6.getAssists() << " assists"; //displaying only player's name along with the number of assists earned
cout << "\nThe seventh Player object";
Player p7(19);
p7.printPlayer();
}