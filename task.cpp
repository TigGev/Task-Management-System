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


Task& Task::operator= (const Task& rhs) {
    if (this == &rhs) {
        return *this;
    }
    m_taskId = rhs.m_taskId;
    m_uId = rhs.m_uId;
    m_title = rhs.m_title;
    m_description = rhs.m_description;
    m_deadline = rhs.m_deadline;
    m_category = rhs.m_category;
    m_priority = rhs.m_priority;
    m_status = rhs.m_status;
    return *this;
}

Task& Task::operator= (Task&& rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }
    m_taskId = rhs.m_taskId;
    m_uId = rhs.m_uId;
    m_title = std::move(rhs.m_title);
    m_description = std::move(rhs.m_description);
    m_deadline = std::move(rhs.m_deadline);
    m_category = std::move(rhs.m_category);
    m_priority = std::move(rhs.m_priority);
    m_status = std::move(rhs.m_status);
    return *this;
}


bool Task::operator== (const Task& rhs) {
    return m_taskId == rhs.m_taskId;
}

bool Task::operator!= (const Task& rhs) {
    return !(*this==rhs);
}

bool Task::operator> (const Task& rhs) {
    return this->m_priority > rhs.m_priority;
}

bool Task::operator< (const Task& rhs) {
    return this->m_priority < rhs.m_priority;
}

Task& Task::operator++() {
    if (m_status != Status::Completed) {
        m_status = static_cast<Status>(static_cast<int>(m_status) + 1);
    }
    return *this;
}

const Task Task::operator++(int n) {
    Task tmp(*this);
    ++(*this);
    return tmp;
}

Task& Task::operator--() {
    if (m_status != Status::NotStarted) {
        m_status = static_cast<Status>(static_cast<int>(m_status) - 1);
    }
    return *this;
}

const Task Task::operator--(int) {
    Task tmp(*this);
    --(*this);
    return tmp;
}

std::ostream& operator<< (std::ostream& os, const Task& task) {
    os << "-----------------------------------------" << std::endl;
    os << "Task ID: " << task.m_taskId << "\n"
              << "User ID: " << task.m_uId << "\n"
              << "Title: " << task.m_title << "\n"
              << "Description: " << task.m_description << "\n"
              << "Deadline: " << task.m_deadline << "\n"
              << "Category: " << task.m_category << "\n"
              << "Priority: ";
              switch (task.m_priority) {
                case Priority::Low: os << "Low" << std::endl;
                case Priority::Medium: os << "Medium" << std::endl;
                case Priority::High: os << "High" << std::endl;
              }
              std::cout << "Status: ";
              switch (task.m_status) {
                case Status::NotStarted: os << "Not started" << std::endl; break;
                case Status::InProgress: os << "In progress" << std::endl; break;
                case Status::Completed: os << "Completed" << std::endl; break;
              }
    os << "-----------------------------------------" << std::endl;
    return os;
}


std::istream& operator>> (std::istream& is, Task& task) {
    std::cout << "Title: ";
    is >> task.m_title;
    std::cout << std::endl;
    std::cout << "Description: ";
    is >> task.m_description;
    std::cout << std::endl;
    std::cout << "Deadline: ";
    is >> task.m_deadline;
    std::cout << std::endl;
    std::cout << "Category: ";
    is >> task.m_category;
    std::cout << std::endl;
    int inp = 0;
    do {
        std::cout << "Select priority: (1 - Low, 2 - Medium or 3 - High)" << std::endl;
        is >> inp;
        switch (inp)
        {
        case 1: task.m_priority = Priority::Low; break;
        case 2: task.m_priority = Priority::Medium; break;
        case 3: task.m_priority = Priority::High; break;
        default: std::cout << "Please enter the number between 1 - 3" << std::endl; break;
        }
    } while (inp > 0 && inp < 4);
    inp = 0;
    do {
        std::cout << "Select status: (1 - Not started, 2 - In progress or 3 - Completed)" << std::endl;
        is >> inp;
        switch (inp)
        {
        case 1: task.m_status = Status::NotStarted; break;
        case 2: task.m_status = Status::InProgress; break;
        case 3: task.m_status = Status::Completed; break;
        default: std::cout << "Please enter the number between 1 - 3" << std::endl; break;
        }
    } while (inp > 0 && inp < 4);
    return is;
}


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

