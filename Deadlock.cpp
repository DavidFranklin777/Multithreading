/* In this example, we demonstrate how a deadlock occurs

   As you see, thread 1 and 2 execute func1 and 2 respectively.
   When both threads are being run, each of them gets locked under mtx1 and 2 respectively
   Now, then one of the threads encounter a second mutex lock, it cannot lock it because the other thread would have been locked
   
   Example: Lets say thread 1 gets locked with mtx1, meanwhile thread 2 at the same time gets locked with mtx2.
   Now when thread 2 tries to execute mtx2.lock(), it waits for thread 2 to unlock it.
   But thread 2 is waiting to lock mtx1, but it cannot proceed further unless thread 2 unlocks mtx1. And this waiting period goes on forever
   
   
   To solve this, we simply use mutexs in the same order for both functions. i.e mtx1.lock()-> mtx2.lock() in both func1 and func2
   What this does it, only one of the threads would lock mtx1 at first, and the other thread waits for it to unlock. Once a thread unlocks it, then the second thread can lock it.
*/



#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sharedVariable = 0; // Shared resource
mutex mtx1, mtx2; // mutex for synchronization

void func1()
{
	mtx1.lock();
	cout << "mtx1 locked thread1" << endl;
	this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work to ensure deadlock
	mtx2.lock();
	cout << "mtx2 locked thread2" << endl;
	mtx2.unlock();
	mtx1.unlock();
}


void func2()
{
	mtx2.lock();
	cout << "mtx2 locked thread2" << endl;
	this_thread::sleep_for(chrono::milliseconds(100));
	mtx1.lock();
	mtx1.unlock();
	mtx2.unlock();
}


int main()
{
	thread t1(func1);
	thread t2(func2);
	
	t1.join();
	t2.join();
	
}

