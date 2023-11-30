#include <iostream>
#include <string>

// Base class Task
class Task {
protected:
    std::string taskName;
    std::string taskDescription;

public:
    Task(const std::string& name, const std::string& description)
        : taskName(name), taskDescription(description) {}

    void describeTask() {
        std::cout << "Task: " << taskName << std::endl;
        std::cout << "Description: " << taskDescription << std::endl;
    }
};

// Derived class AssignedTask
class AssignedTask : public Task {
private:
    std::string assignee;

public:
    AssignedTask(const std::string& name, const std::string& description, const std::string& assignee)
        : Task(name, description), assignee(assignee) {}

    void assignTask(const std::string& newAssignee) {
        assignee = newAssignee;
        std::cout << "Task reassigned to " << assignee << "." << std::endl;
    }
};

// Derived class TaskInProgress
class TaskInProgress : public Task {
private:
    int progressPercent;

public:
    TaskInProgress(const std::string& name, const std::string& description)
        : Task(name, description), progressPercent(0) {}

    void updateProgress(int percent) {
        progressPercent = percent;
        std::cout << "Task progress updated to " << progressPercent << "%." << std::endl;
    }
};

// Derived class CompletedTask
class CompletedTask : public Task {
public:
    CompletedTask(const std::string& name, const std::string& description)
        : Task(name, description) {}

    void markAsComplete() {
        std::cout << "Task marked as completed." << std::endl;
    }
};

int main() {
    AssignedTask task1("Web Development", "Create landing page", "Alice");
    task1.describeTask();
    task1.assignTask("Bob");

    TaskInProgress task2("App Development", "Implement new features");
    task2.describeTask();
    task2.updateProgress(75);

    CompletedTask task3("Testing", "Perform security testing");
    task3.describeTask();
    task3.markAsComplete();

    return 0;
}
