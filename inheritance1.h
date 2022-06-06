#include<iostream>
#include<string>
using namespace std;

enum Discipline {ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE};
enum Classification {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class Person
{
protected:
string name;
public:
Person() { setName(""); }
Person(const string& pName) { setName(pName); }
void setName(const string& pName) { name = pName; }
string getName() const { return name; }
};

class Faculty :public Person
{
private:
Discipline department;
public:
// Constructor
Faculty(const string& fname, Discipline d)
{
// Access the protected base class member
name = fname;
department = d;
}
  
// Other member functions
void setDepartment(Discipline d) { department = d; }
Discipline getDepartment() const { return department; }
};

class Student : public Person
{
private:
Discipline major;
Faculty *advisor;
public:
// Constructor
Student(const string& sname, Discipline d, Faculty *adv){
// Access the protected member name
name = sname;

// Access the other members
major = d;
advisor = adv;
}

void setMajor(Discipline d) { major = d; }
Discipline getMajor() const { return major; }
  
void setAdvisor(Faculty *p) { advisor = p; }
Faculty *getAdvisor() { return advisor; }
};