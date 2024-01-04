/* Synchronization in multithreading is a mechanism to ensure that two or more concurrent threads do not simultaneously access shared resources in a way that leads to inconsistent or corrupt data. Let's illustrate synchronization with a simple C++ example using a mutex:

The final value should be 15. Because at a given time, only one thread can access this function, it incremements the sharedResource value and exits, since its a global variable
It does not get reset, so when the second thread executes it, it resumes from the previously incrememnted value.
*/



#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sharedVariable = 0; // Shared resource
mutex mtx; // mutex for synchronization

void accessSharedResource(const int& increment)
{
	mtx.lock();
	sharedResource+= increment;
	mtx.unlock();
}


int main()
{
	thread t1(accessSharedResource, 5);
	thread t2(accessSharedResource, 10);
	
	t1.join();
	t2.join();
	
	cout << "The final value of shared resource is " sharedVariable << endl;
}

