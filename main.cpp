#include "chrono"
#include "thread" 
void sleepNow(int seconds) 
{
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}

int main() 
{

  sleepNow(5);
};