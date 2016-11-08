#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
   steady_clock::time_point t1 = steady_clock::now();

   duration<int, ratio<60*60*24> > one_day(1);

   system_clock::time_point today = system_clock::now();
   system_clock::time_point tomorrow = today + one_day;

   std::time_t tt;

   tt = system_clock::to_time_t (today);
   cout << "Today is: " << ctime(&tt);

   tt = system_clock::to_time_t (tomorrow);
   cout << "Tomorrow will be: " << ctime(&tt);

   steady_clock::time_point t2 = steady_clock::now();

   duration<double> time_span = duration_cast<duration<double> > (t2 - t1);

   cout << "This program ran in: " << time_span.count() << " seconds.\n";
   return 0;
}
