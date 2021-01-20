#include "thread"
#include "chrono"
#include <iostream>

using namespace std;

void timer1(int seconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}

void timer2(int seconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}

void thread_function() {
  cout << "Thread: " << std::this_thread::get_id() << " started\n";
  timer1(5);
  cout << "Thread: " << std::this_thread::get_id() << " ended\n";

}

void thread_function2() {
  cout << "Thread: " << std::this_thread::get_id() << " started\n";
  timer2(10);
  cout << "Thread: " << std::this_thread::get_id() << " ended\n";

}

int main() {
   cout << "Main Thread: " << std::this_thread::get_id() << " Started\n";
   std::thread t(&thread_function);
   std::thread g(&thread_function2);
   cout << "Main Thread: " << std::this_thread::get_id() << " Started\n";
   t.join();
   g.join();
   cout << "Main Thread: " << std::this_thread::get_id() << " Ended\n";
}