#include <iostream>

#include "Task.h"
#include "TaskList.h"



int main(int argc, char const *argv[])
{


    todo::Task task1(todo::TaskId(1), "Title", "Description",
        std::chrono::system_clock::now(),
        std::chrono::system_clock::now() + std::chrono::hours(2),
        todo::TaskPriority::High);

    todo::Task task(todo::TaskId(2), "Buy Coffee", "Dont forget to buy coffee for Tomorrow",
        std::chrono::system_clock::now(),
        std::chrono::system_clock::now() + std::chrono::hours(1), todo::TaskPriority::Medium);


    std::cout << "Hello world" << std::endl;
    return 0;
}
