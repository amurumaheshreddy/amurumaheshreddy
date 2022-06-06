#include "Orchestra.h"
#include <iostream>
using namespace std;
int main()
{
       Orchestra orchestra(5);
       Musician m1("guitar",4);
       Musician m2("piano",2);
      Musician m3("flute",5);
       Musician m4("trumpet",6);
       Musician m5("cello",10);
       Musician m6("violin",5);
       cout<<"Add musicians in orchestra "<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m1)<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m2)<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m3)<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m4)<<endl;
     cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m5)<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<boolalpha<<orchestra.add_musician(m6)<<endl;
       cout<<orchestra.get_current_number_of_members()<<endl;
       cout<<endl;
      cout<<"piano in orchestra : "<<boolalpha<<orchestra.has_instrument("piano")<<endl;
       cout<<"violin in orchestra : "<<boolalpha<<orchestra.has_instrument("violin")<<endl;
       Musician *members = orchestra.get_members();
     cout<<"Musician's Instrument and their Experience in orchestra : "<<endl;
       for(int i=0;i<orchestra.get_current_number_of_members();i++)
             cout<<members[i].get_instrument()<<" "<<members[i].get_experience()<<endl;
   return 0;
}