/* In this example, we demonstrate how an atomic variable works
   This is similar to mutex, atomic variables ensure that they are not interfered with other threads before being completely executed by the a thread
   For example, if one thread is changing its value, it ensures that the other thread does not interfere with it, just like mutex guards
   
   The output of this is 2000. If we remove the atomic variable and replace it with a regular one, you will see a value that is less than 2000

*/



#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> counter(0);  // Atomic counter

void increment()
{
	for (int i=0; i<1000; i++)
	{
		counter++;  // Atomic increment
	}
	
}



int main()
{
	thread t1(increment);
	thread t2(increment);
	
	t1.join();
	t2.join();
	
	cout << "The final value of counter is " << counter << endl;
	
	return 0;
	
}

