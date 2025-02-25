#include "taskManager.h"


TaskManager::TaskManager(TaskManager&& other) : m_users(std::move(other.m_users)),
                                                 m_all_tasks(std::move(other.m_all_tasks))
{}

TaskManager& TaskManager::operator+= (const TaskManager& rhs) {
    m_users.insert(m_users.end(), rhs.m_users.begin(), rhs.m_users.end());
    m_all_tasks.insert(m_all_tasks.end(), rhs.m_all_tasks.begin(), rhs.m_all_tasks.end());
    return *this;
}

void TaskManager::displayTask(int taskId) const {
    for (Task* task : m_all_tasks) {
        if (task->getTaskId() == taskId) {
            std::cout << "yes" << std::endl;
            task->display();
            return;
        }
    }
    printTaskDontExist();
}

void TaskManager::addTaskForUser(int uId, Task* newTask) {
    m_all_tasks.push_back(newTask); //adding task in all tasks list
    for (User* user : m_users) {
        if (user->getUserId() == uId) {;
            user->addTask(newTask);
        }
    }
}

void TaskManager::registerUser(const std::string& userName, const std::string& password) {
    User* newUser = new User{userName, password};
    m_users.push_back(newUser);
}

void TaskManager::editTask(int taskId,
               const std::string& title,
                const std::string& description,
                 const std::string& deadline,
                  const std::string& category,
                   const Priority& priority) {
    for (Task* task : m_all_tasks) {
        if (task->getTaskId() == taskId) {
            task->editTask(title, description, deadline, category, priority);
        }
    }
}

void TaskManager::removeTask(int uId, int taskId) {
    for (User* user : m_users) {
        if (user->getUserId() == uId) {
            user->deleteTask(taskId);
        }
    }
    for (auto task = m_all_tasks.begin(); task != m_all_tasks.end(); task++) {
        if ((*task)->getTaskId() == taskId) {
            m_all_tasks.erase(task);
            delete *task;
            return;
        }
    }
}
