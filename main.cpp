#include <iostream>
#include <vector>
#include <string>

struct Task {
    int id;
    std::string description;
    bool completed;

    // This constructor is optional if  using uniform initialization
    Task(int id, std::string description, bool completed) : id(id), description(description), completed(completed) {}


 
};


class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string& description) {
        int newId = tasks.empty() ? 1 : tasks.back().id + 1;
        tasks.push_back({newId, description, false});
    }

    void displayTasks(bool onlyUncompleted = false) const {
        for (const auto& task : tasks) {
            if (!onlyUncompleted || !task.completed) {
                std::cout << task.id << ": " << task.description << (task.completed ? " (Completed)" : "") << std::endl;
            }
        }
    }

    void removeTask(int id) {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
            return task.id == id;
        }), tasks.end());
    }

    void editTask(int id, const std::string& newDescription) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.description = newDescription;
                break;
            }
        }
    }

    void markTaskDone(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                break;
            }
        }
    }
};

int main() {
    ToDoList myList;
    std::string input;
    int choice, id;

    while (true) {
        std::cout << "1. Add 2. Display All 3. Remove 4. Exit 5. Edit 6. Mark Done 7. Display Uncompleted: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Task: ";
                getline(std::cin, input);
                myList.addTask(input);
                break;
            case 2:
                myList.displayTasks();
                break;
            case 3:
                std::cout << "Remove ID: ";
                std::cin >> id;
                myList.removeTask(id);
                break;
            case 4:
                return 0;
            case 5:
                std::cout << "Edit ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "New Desc: ";
                getline(std::cin, input);
                myList.editTask(id, input);
                break;
            case 6:
                std::cout << "Done ID: ";
                std::cin >> id;
                myList.markTaskDone(id);
                break;
            case 7:
                myList.displayTasks(true);
                break;
        }
    }
}
