#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool compare(char* src, char* dest, int len)
{
   while (len > 0)
   {
       if (*src != *dest)
           return false;
       src++;
       dest++;
       len--;
   }
   return true;
}

int len(char* src)
{
   int l = 0;
   while (*src != '\0')
   {
       ++l;
       ++src;
   }
   return l;
}

int main(int argc, char* argv[])
{
   ifstream file("dictionary.txt");
   const int Lines = 1000;
  
   char *c[Lines];

   for (int i = 0; i < Lines; ++i)
   {
       *(c + i) = new char[20];
       file >> *(c + i);
   }
   file.close();

   char buffer[20];
   cin >> buffer;

   for (int i = 0; i < Lines; ++i)
   {
       if (compare(*(c + i), buffer, len(*(c + i))))
       {
           cout << buffer << " is in the dictionary." << endl;
           return 0;
       }
   }

   cout << buffer << " is not in the dictionary." << endl;
   return 0;
}