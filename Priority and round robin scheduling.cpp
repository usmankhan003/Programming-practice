#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Task {
    string taskName;
    string taskId;
    int timeDuration;
    int priority;
    Task* next;
    
    Task(string taskName, string taskId, int timeDuration, int priority)
        : taskName(taskName), taskId(taskId), timeDuration(timeDuration), priority(priority), next(nullptr) {}
};

void addTask(Task*& head, string taskName, string taskId, int timeDuration, int priority) 
{
    Task* newTask = new Task(taskName, taskId, timeDuration, priority);

    if (head == nullptr) {
        head = newTask;
    } 
    else {
        Task* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void displayTasks(Task* head) {
    if (head == nullptr) {
        cout << "No tasks to display!" << endl;
        return;
    }

    Task* temp = head;
    cout << "\nTask List:\n";
    while (temp != nullptr) {
        cout << "Task Name: " << temp->taskName
             << ", Task ID: " << temp->taskId
             << ", Time Duration: " << temp->timeDuration << " ms"
             << ", Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}

void priorityScheduling(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    cout << "\nProcessing Tasks (Priority Scheduling):\n";

    while (head != nullptr) {
        // Find the highest priority task
        Task* highest = head;
        Task* prev = nullptr;
        Task* highestPrev = nullptr;

        for (Task* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->priority > highest->priority) {
                highest = temp;
                highestPrev = prev;
            }
            prev = temp;
        }

        // Process the highest priority task
        cout << "Processing Task: " << highest->taskName
             << " (Task ID: " << highest->taskId
             << ", Time Duration: " << highest->timeDuration
             << " ms, Priority: " << highest->priority << ")" << endl;

        highest->timeDuration -= 10;
        highest->priority--;

        if (highest->timeDuration <= 0) {
            cout << "Task " << highest->taskName << " completed." << endl;

            // Remove the task from the list
            if (highestPrev == nullptr) {
                head = highest->next;
            } 
            else {
                highestPrev->next = highest->next;
            }
            delete highest;
        }
    }
    cout << "All tasks executed completely." << endl;
}

void roundRobin(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    queue<Task*> taskQueue;
    for (Task* temp = head; temp != nullptr; temp = temp->next) {
        taskQueue.push(temp);
    }

    cout << "\nProcessing Tasks (Round Robin):\n";
    while (!taskQueue.empty()) {
        Task* currentTask = taskQueue.front();
        taskQueue.pop();

        cout << "Processing Task: " << currentTask->taskName
             << " (Task ID: " << currentTask->taskId
             << ", Time Duration: " << currentTask->timeDuration << " ms)" << endl;

        currentTask->timeDuration -= 10;

        if (currentTask->timeDuration > 0) {
            taskQueue.push(currentTask);
        } else {
            cout << "Task " << currentTask->taskName << " completed." << endl;
        }
    }
    head = nullptr; // All tasks have been processed
    cout << "All tasks executed completely." << endl;
}

int main() {
    Task* head = nullptr;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Priority Scheduling" << endl;
        cout << "4. Round Robin Scheduling" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskName;
                string taskId;
                int timeDuration;
                int priority;
                char addMore;

                do {
                    cout << "Enter Task Name: ";
                    cin.ignore();
                    getline(cin, taskName);

                    cout << "Enter Task ID: ";
                    getline(cin, taskId);

                    cout << "Enter Time Duration (in milliseconds): ";
                    cin >> timeDuration;

                    cout << "Enter Priority: ";
                    cin >> priority;

                    addTask(head, taskName, taskId, timeDuration, priority);
                    cout << "Task added successfully!" << endl;

                    cout << "Do you want to add another task? (y/n): ";
                    cin >> addMore;
                } while (addMore == 'y' || addMore == 'Y');

                break;
            }

            case 2:
                displayTasks(head);
                break;

            case 3:
                priorityScheduling(head);
                break;

            case 4:
                roundRobin(head);
                break;

            case 5:
                cout << "Program Ends. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
