#include <ctime>
#include <chrono>
#include <iostream>
using namespace std;

#include <stdio.h>
#include <time.h>

int main()
{
   time_t current_time;
   struct tm local_time;
   time(&current_time);
   localtime_s(&local_time, &current_time);

   string timeDisplay;
   int Year = local_time.tm_year + 1900;
   int Month = local_time.tm_mon + 1;
   int Day = local_time.tm_mday;

   int Hour = local_time.tm_hour - 12;
   int Min = local_time.tm_min;
   int Sec = local_time.tm_sec;

   if (Hour >= 12)
       timeDisplay = "AM";
   else if (Hour < 12)
       timeDisplay = "PM";

   cout << Hour << ":" << Min << " " << timeDisplay;
   cout << "\n";
   cout << Month << "/" << Day << "/" << Year;

   return 0;
}

