#include "thread"
#include "chrono"
#include <iostream>

using namespace std;

void sleepnow(int seconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));

}

void thread_function() {
  cout << "Thread: " << std::this_thread::get_id() << " started\n";
  sleepnow(5);
  cout << "Thread: " << std::this_thread::get_id() << " ended\n";

}

int main() {
   cout << "Main Thread: " << std::this_thread::get_id() << " Started\n";
   std::thread t(&thread_function);
}