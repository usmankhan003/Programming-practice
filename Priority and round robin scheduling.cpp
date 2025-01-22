#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Task {
    string taskName;
    string taskId;
    int timeDuration;
    int priority; // Priority field
    Task* next;

    Task(string taskName, string taskId, int timeDuration, int priority)
        : taskName(taskName), taskId(taskId), timeDuration(timeDuration), priority(priority), next(nullptr) {}
};

void addTask(Task*& head, string taskName, string taskId, int timeDuration) {
    int priority = 0;  // Set default priority if you don't want to ask for it
    Task* newTask = new Task(taskName, taskId, timeDuration, priority);

    if (head == nullptr) {
        head = newTask;
    } else {
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
        Task *highestPriorityTask = head, *prev = nullptr, *highestPrev = nullptr;

        // Find the task with the highest priority
        for (Task* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->priority > highestPriorityTask->priority) {
                highestPriorityTask = temp;
                highestPrev = prev;
            }
            prev = temp;
        }

        cout << "Processing Task: " << highestPriorityTask->taskName
             << " (Task ID: " << highestPriorityTask->taskId
             << ", Time Duration: " << highestPriorityTask->timeDuration << " ms"
             << ", Priority: " << highestPriorityTask->priority << ")" << endl;

        highestPriorityTask->timeDuration -= 10;
        if (highestPriorityTask->timeDuration <= 0) {
            cout << "Task " << highestPriorityTask->taskName << " completed." << endl;

            // Remove the completed task
            if (highestPrev == nullptr) { // If the highest priority task is the head
                head = highestPriorityTask->next;
            } else {
                highestPrev->next = highestPriorityTask->next;
            }
            delete highestPriorityTask;
        }
    }
    cout << "All tasks executed completely." << endl;
}

void fifo(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    cout << "\nProcessing Tasks (FIFO):\n";
    while (head != nullptr) {
        cout << "Processing Task: " << head->taskName
             << " (Task ID: " << head->taskId
             << ", Time Duration: " << head->timeDuration << " ms)" << endl;

        head->timeDuration -= 10;
        if (head->timeDuration <= 0) {
            cout << "Task " << head->taskName << " completed." << endl;
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
    cout << "All tasks executed completely." << endl;
}

void lifo(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    stack<Task*> taskStack;
    Task* temp = head;
    while (temp != nullptr) {
        taskStack.push(temp);
        temp = temp->next;
    }

    cout << "\nProcessing Tasks (LIFO):\n";
    while (!taskStack.empty()) {
        Task* currentTask = taskStack.top();
        taskStack.pop();

        cout << "Processing Task: " << currentTask->taskName
             << " (Task ID: " << currentTask->taskId
             << ", Time Duration: " << currentTask->timeDuration << " ms)" << endl;

        currentTask->timeDuration -= 10;
        if (currentTask->timeDuration <= 0) {
            cout << "Task " << currentTask->taskName << " completed." << endl;
            delete currentTask;
        }
    }

    head = nullptr;
    cout << "All tasks executed completely." << endl;
}

void sjf(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    cout << "\nProcessing Tasks (SJF):\n";
    while (head != nullptr) {
        Task *shortest = head, *prev = nullptr, *shortestPrev = nullptr;
        for (Task* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->timeDuration < shortest->timeDuration) {
                shortest = temp;
                shortestPrev = prev;
            }
            prev = temp;
        }

        cout << "Processing Task: " << shortest->taskName
             << " (Task ID: " << shortest->taskId
             << ", Time Duration: " << shortest->timeDuration << " ms)" << endl;

        shortest->timeDuration -= 10;
        if (shortest->timeDuration <= 0) {
            cout << "Task " << shortest->taskName << " completed." << endl;
            if (shortestPrev == nullptr) {
                head = shortest->next;
            } else {
                shortestPrev->next = shortest->next;
            }
            delete shortest;
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
            delete currentTask;
        }
    }
    head = nullptr;
    cout << "All tasks executed completely." << endl;
}

int main() {
    Task* head = nullptr;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. FIFO Scheduling" << endl;
        cout << "4. LIFO Scheduling" << endl;
        cout << "5. SJF Scheduling" << endl;
        cout << "6. Priority Scheduling" << endl;
        cout << "7. Round Robin Scheduling" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskName, taskId;
                int timeDuration;
                char addMore;

                do {
                    cout << "Enter Task Name: ";
                    cin.ignore();
                    getline(cin, taskName);

                    cout << "Enter Task ID: ";
                    getline(cin, taskId);

                    cout << "Enter Time Duration (in milliseconds): ";
                    cin >> timeDuration;

                    // Don't ask for priority here
                    addTask(head, taskName, taskId, timeDuration);
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
                fifo(head);
                break;

            case 4:
                lifo(head);
                break;

            case 5:
                sjf(head);
                break;

            case 6:
                priorityScheduling(head);
                break;

            case 7:
                roundRobin(head);
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
