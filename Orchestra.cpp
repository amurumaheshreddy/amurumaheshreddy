#include "Orchestra.h"

Orchestra::Orchestra() : max_size(0), curr_size(0) , members(NULL)

{}

Orchestra::Orchestra(int size) : max_size(size), curr_size(0)

{

       members = new Musician[size];

}

int Orchestra::get_current_number_of_members()

{

       return curr_size;

}

bool Orchestra:: has_instrument(std::string instrument)

{

       for(int i=0;i<curr_size;i++)

       {

             if(members[i].get_instrument() == instrument)

                    return true;

       }

       return false;

}

Musician* Orchestra::get_members()

{

       return members;

}

bool Orchestra::add_musician(Musician new_musician)

{

       if(curr_size < max_size)

       {

             members[curr_size] = new_musician;

             curr_size++;

             return true;

       }

       return false;

}

Orchestra::~Orchestra()

{

       if(members != NULL)

             delete [] members;

}

//end of Orchestra.cpp