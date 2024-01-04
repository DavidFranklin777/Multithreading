/* Note that the output can arrive in any order

Both threads are running concurrently Thread 
2 starts.
Thread 1 starts.
Thread 2 ends.
Thread 1 ends.
Both threads have finished.


The same code, if ran on a multi-core processor, can achieve parallelism

In parallelism scenario, the threads are actually executed at the same time
Each core can run a separate thread simultaneously

On single core system, it demonstrates concurrency

Key Points:
Concurrency: The threads appear to run in an overlapping manner but not necessarily at the same time.
Parallelism: The threads run at the same time, showing simultaneous execution.

*/



#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void threadFunction(int threadNumber)
{
	cout << "Thread " << threadNumber << " starts." << endl;
	
	// Simulate work by sleeping
	this_thread::sleep_for(chrono::seconds(1));
	
	cout << "Thread " << threadNumber << " ends." << endl;

}

int main()
{
	// Creating two threads
	// Prototype: t1(func, params...)
	thread t1(threadFunction, 1);
	thread t2(threadFunction, 2);
	
	cout << "Both threads are running concurrently " << endl;
	
	// Wait for both threads to finish
	t1.join();
	t2.join();
	
	cout << "Both threads have finished." << endl;
	
	return 0;
	
}


