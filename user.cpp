#include "user.h"

int User::generalUserId = 0;

User::~User() {
    for (Task* task : tasks) {
        task->setUid(invalidUid);
    }
}

User::User(User&& other) noexcept : m_uid(other.m_uid),
                                     username(std::move(other.username)),
                                      password(std::move(other.password)),
                                       tasks(std::move(other.tasks)),
                                        isLogged(other.isLogged)
{}

// User& User::operator= (const User& other) {
    // 
// }

std::ostream& operator<< (std::ostream& output, const User& user) {
    output << "Username: " << user.username << "\n";
    output << "Tasks: ";
    for (Task* task : user.tasks) {
        output << task->getTaskId() << " ";
    }
    output << std::endl;
}


std::istream& operator>> (std::istream& input, User& user) {
    std::cout << "Enter a Username: ";
    input >> user.username;
    std::cout << std::endl;
    std::cout << "Enter a Password: ";
    input >> user.password;
    std::cout << std::endl;
    return input;
}


void User::addTask(Task* newTask) {
    
    tasks.push_back(newTask);
    newTask->setUid(m_uid); 
}

void User::deleteTask(int taskId) {
    for (auto task = tasks.begin(); task != tasks.end(); ++task) {
        if ((*task) -> getTaskId() == taskId) {
            tasks.erase(task);
            // std::cout << "Task deleted" << std::endl; 
            return;
        }
    }
    printTaskDontExist();
}

void User::userEditTask(int taskId,
                      const std::string& title,
                       const std::string& description,
                        const std::string& deadline,
                         const std::string& category,
                          const Priority& priority)
{ 
    for (Task* task : tasks) {
        if (task->getTaskId() == taskId) {
            task->editTask(title, description, deadline, category, priority); 
            return;
        }
    }
    printTaskDontExist();
}

void User::listTasks() const {
    for (Task* task : tasks) {
        task->display();
    }
}

Task* User::searchTask(int taskId) {
    for (Task* task : tasks) {
        
        if (task->getTaskId() == taskId) {
            return task;
        }
    }
    printTaskDontExist();
    return nullptr;
}