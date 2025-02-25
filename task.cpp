#include "task.h"

int Task::generalTaskId = 0;

// ctor with parameters
Task::Task(const std::string& title,
            const std::string& description,
             const std::string& deadline,
              const std::string& category,
               const Priority& priority) :
        m_taskId(generalTaskId++),
         m_uId(-1),
          m_title(title),
           m_description(description),
            m_deadline(deadline),
             m_category(category),
              m_priority(priority)
{}

Task::Task(const Task& other) :
    m_taskId(other.m_taskId),
     m_uId(other.m_uId),
      m_title(other.m_title),
       m_description(other.m_description),
        m_deadline(other.m_deadline),
         m_category(other.m_category),
          m_priority(other.m_priority),
           m_status(other.m_status)
{}

Task::Task(Task&& other) noexcept :
    m_taskId(other.m_taskId),
     m_uId(other.m_uId),
      m_title(std::move(other.m_title)),
       m_description(std::move(other.m_description)),
        m_deadline(std::move(other.m_deadline)),
         m_category(std::move(other.m_category)),
          m_priority(std::move(other.m_priority)), 
           m_status(std::move(other.m_status)) 
{}

void Task::editTask(const std::string& newTitle,
                     const std::string& newDescription,
                      const std::string& newDeadline,
                       const std::string& newCategory,
                        const Priority& newPriority) {
    m_title = newTitle;
    m_description = newDescription;
    m_deadline = newDeadline;
    m_category = newCategory;
    m_priority = newPriority;
}

void Task::setStatus(const Status& status) {
    m_status = status;
}


void Task::display() const {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Task ID: " << m_taskId << "\n"
              << "User ID: " << m_uId << "\n"
              << "Title: " << m_title << "\n"
              << "Description: " << m_description << "\n"
              << "Deadline: " << m_deadline << "\n"
              << "Category: " << m_category << "\n"
              << "Priority: ";
              switch (m_priority) {
                case Priority::Low: std::cout << "Low" << std::endl;
                case Priority::Medium: std::cout << "Medium" << std::endl;
                case Priority::High: std::cout << "High" << std::endl;
              }
              std::cout << "Status: ";
              switch (m_status) {
                case Status::NotStarted: std::cout << "Not started" << std::endl;
                case Status::InProgress: std::cout << "In progress" << std::endl;
                case Status::Completed: std::cout << "Completed" << std::endl;
              }
    std::cout << "-----------------------------------------" << std::endl;
}

void Task::setPriority(const Priority& priority) {
    m_priority = priority;
}

int Task::getTaskId() const {return m_taskId;};

