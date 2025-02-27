#ifndef USER_H
#define USER_H
#include "task.h"

inline void printTaskDontExist() {std::cout << "---- Such a task does not exist. ----" << std::endl;}
const int invalidUid = -1;

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
        ~User();
        User(const User&) = delete;
        User(User&& other) noexcept;
        // User& operator= (const User& other);
        friend std::ostream& operator<< (std::ostream& output, const User& user);
        friend std::istream& operator>> (std::istream& input, User& user);
        operator bool() const {return isLogged;};
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