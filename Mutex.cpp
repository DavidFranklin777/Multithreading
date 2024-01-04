/* In this example, we use mutex to make sure only one thread is accessing the function at a time
 The output will be 2000
 If we remove the mutex object, we dont see the output of 2000 necessarily, this is because of race condition
 Where two threads try to modify the variable at a same time and both tend to incrememnt it lets say from 100 to 101, where as it should have been 100->101->102
 Thus we end up with a value less than 2000
*/



#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sharedVariable = 0; // Shared resource
mutex mtx; // mutex for synchronization

void increment()
{
	for (int i=0; i<1000; i++)
	{
		mtx.lock();           // lock the mutex
		++sharedVariable;
		mtx.unlock();		  // unlocking
	}
}


int main()
{
	thread t1(increment);
	thread t2(increment);
	
	t1.join();
	t2.join();
	
	cout << "The final value of shared variable is " sharedVariable << endl;
}

