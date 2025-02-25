#ifndef USER_H
#define USER_H
#include "task.h"

inline void printTaskDontExist() {std::cout << "---- Such a task does not exist. ----" << std::endl;}

class User {
        static int generalUserId;
        int m_uid;
        std::string username;
        std::string password;
        std::vector<Task*> tasks;
        bool isLogged;
    public:
        User(std::string name, std::string pass) :
                    m_uid(generalUserId++),
                     username(name),
                      password(pass) {};
        ~User() = default;
        User(const User&) = delete;
        User(User&& other) noexcept;
        void addTask(Task* newTask);
        void deleteTask(int taskId);
        void userEditTask(int taskId,
                        const std::string& title,
                         const std::string& description,
                          const std::string& deadline,
                           const std::string& category,
                            const Priority& priority);
        void listTasks() const;
        Task* searchTask(int taskId);
        void login() {isLogged = true;};
        void logiut() {isLogged = false;}; 
        int getUserId() {return m_uid;};
};


#endif