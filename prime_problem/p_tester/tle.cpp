#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout << "Hello waiter" << std::endl;
    std::chrono::seconds dura( 5);
    std::this_thread::sleep_for( dura );
    std::cout << "Waited 5s\n";
}
