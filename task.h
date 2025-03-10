#ifndef TASK_H
#define TASK_H
#include <iostream>

enum class Priority {Low, Medium, High};
enum class Status {NotStarted, InProgress, Completed};


class Task {

        static int generalTaskId;
        int m_taskId;
        int m_uId;
        std::string m_title;
        std::string m_description;
        std::string m_deadline; // DD-MM-YYYY
        std::string m_category; // work, personal, study
        Priority m_priority;
        Status m_status {Status::NotStarted};

    public:
        Task() : m_taskId(generalTaskId++), m_uId(-1) {}; 
        ~Task() = default;
        Task( const std::string& title,
               const std::string& description,
                const std::string& deadline,
                 const std::string& category,
                  const Priority& priority);
        Task(const Task& other);
        Task(Task&& other) noexcept;
        Task& operator= (const Task& rhs);
        Task& operator= (Task&& rhs) noexcept;
        bool operator== (const Task& rhs);
        bool operator!= (const Task& rhs);
        bool operator> (const Task& rhs);
        bool operator< (const Task& rhs);
        Task& operator++();
        const Task operator++(int);
        Task& operator--();
        const Task operator--(int);
        friend std::ostream& operator<< (std::ostream&, const Task& task);
        friend std::istream& operator>> (std::istream&, Task& task);

        void editTask(const std::string& newTitle,
                       const std::string& newDescription,
                        const std::string& newDeadline,
                         const std::string& newCategory,
                          const Priority& newPriority);
        void setStatus(const Status& status);
        void display() const;
        void setPriority(const Priority& priority);
        int getTaskId() const;
        void setUid(int uId) {m_uId = uId;};
};
#endif