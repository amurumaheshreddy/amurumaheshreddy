#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
  int num, a, b;
  fstream inputStream;
  ofstream outputStream;

  inputStream.open("input.txt"); //let's say input.txt holds the number 3
  inputStream >> num;
  inputStream.close();
  for (a = 1; a <= num; a++) 
    {
      outputStream.open("table" + std::to_string(a) + ".txt");

      for (b = 1; b <= 10; b++)
        {
      outputStream << a << " X "
               << b << " = "
               << a*b << endl;
        }
      outputStream.close();
    }                        

  return 0;
}