#include "user.h"

int User::generalUserId = 0;

User::User(User&& other) noexcept : m_uid(other.m_uid),
                                     username(std::move(other.username)),
                                      password(std::move(other.password)),
                                       tasks(std::move(other.tasks)),
                                        isLogged(other.isLogged)
{}

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