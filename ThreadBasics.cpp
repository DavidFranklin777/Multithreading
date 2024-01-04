// Threads basic concept

#include <iostream>
#include <thread>

using namespace std;

void threadFunction(int threadNumber)
{
	cout << "Hello from thread: " << threadNumber << endl;

}

int main()
{
	// Creating two threads
	// Prototype: t1(func, params...)
	thread t1(threadFunction, 1);
	thread t2(threadFunction, 2);
	
	cout << "Hello from main thread" << endl;
	
	
	// Wait for both threads to finish
	
	t1.join();
	t2.join();
	
	return 0;
	
}


/* Note that the output can arrive in any order
Hello from thread 1!
Hello from thread 2!
Hello from the main thread!

OR

Hello from the main thread!
Hello from thread 1!
Hello from thread 2!

OR

Hello from thread Hello from the main thread!1
Hello from thread 2!!

*/