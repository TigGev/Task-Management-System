#ifndef TASK_MANAGER
#define TASK_MANAGER
#include "user.h"

class TaskManager {
        std::vector<User*> m_users;
        std::vector<Task*> m_all_tasks;
    public:
        TaskManager() = default;
        ~TaskManager();
        TaskManager(const TaskManager& other) = delete;
        TaskManager(TaskManager&& other);

        void displayTask(int taskId) const;
        void addTaskForUser(int uId, Task* newTask);
        void registerUser(const std::string& userName, const std::string& password);
        // void addTask(args);
        void editTask(int taskId,
                       const std::string& title,
                        const std::string& description,
                         const std::string& deadline,
                          const std::string& category,
                           const Priority& priority);
        void removeTask(int uId, int taskId);
};

#endif