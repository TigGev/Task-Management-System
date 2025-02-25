#include "taskManager.h"
#include <iostream>

int main() {
    TaskManager manager;

    manager.registerUser("Alice", "pass123");
    manager.registerUser("Bob", "secure456");

    Task* task1 = new Task("Buy groceries", "Milk, eggs, bread", "26-02-2025", "personal", Priority::Medium);
    Task* task2 = new Task("Complete project", "Finish C++ project for school", "01-03-2025", "study", Priority::High);

    manager.addTaskForUser(0, task1);
    manager.addTaskForUser(1, task2);

    std::cout << "\nTasks after addition:" << std::endl;
    manager.displayTask(0);
    manager.displayTask(1);

    manager.editTask(0, "Go shopping", "Buy electronics", "27-02-2025", "personal", Priority::High);
    std::cout << "\nTasks after editing:" << std::endl;
    manager.displayTask(0);

    manager.removeTask(1, 1);
    std::cout << "\nTasks after deletion:" << std::endl;
    manager.displayTask(1);

    return 0;
}
