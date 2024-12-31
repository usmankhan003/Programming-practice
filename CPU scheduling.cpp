#include <iostream>
#include <string>
using namespace std;

struct Task {
    string taskName;
    string taskId;
    int timeDuration;
    Task* next;

    Task(string taskName, string taskId, int timeDuration) 
        : taskName(taskName), 
          taskId(taskId), 
          timeDuration(timeDuration), 
          next(nullptr) {}
};

void addTask(Task*& head, string taskName, string taskId, int timeDuration) {
    Task* newTask = new Task(taskName, taskId, timeDuration);

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
             << ", Time Duration: " << temp->timeDuration 
             << " Millisecond" << endl;
        temp = temp->next;
    }
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
             << ", Time Duration: " << head->timeDuration 
             << " Millisecond)" << endl;

        if (head->timeDuration > 10) {
            head->timeDuration -= 10;
            cout << "Updated Time Duration: " << head->timeDuration << " Millisecond" << endl;
        } 
        else {
            cout << "Task " << head->taskName << " completed (Time Duration reach)." << endl;

            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }

    cout << "All tasks Executed Completely." << endl;
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
             << ", Time Duration: " << currentTask->timeDuration 
             << " Millisecond)" << endl;

        if (currentTask->timeDuration > 10) {
            currentTask->timeDuration -= 10;
            cout << "Updated Time Duration: " << currentTask->timeDuration << " Millisecond" << endl;
        } else {
            cout << "Task " << currentTask->taskName << " completed (Time Duration reached)." << endl;
        }

        delete currentTask;
    }

    head = nullptr; // All tasks have been processed
    cout << "All tasks Executed Completely." << endl;
}

void sjf(Task*& head) {
    if (head == nullptr) {
        cout << "No tasks to process!" << endl;
        return;
    }

    cout << "\nProcessing Tasks (SJF):\n";
    while (head != nullptr) {
        // Find the task with the shortest duration
        Task *shortest = head, *prev = nullptr, *shortestPrev = nullptr;
        for (Task* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->timeDuration < shortest->timeDuration) {
                shortest = temp;
                shortestPrev = prev;
            }
            prev = temp;
        }

        // Process the shortest task
        cout << "Processing Task: " << shortest->taskName 
             << " (Task ID: " << shortest->taskId 
             << ", Time Duration: " << shortest->timeDuration 
             << " Millisecond)" << endl;

        if (shortest->timeDuration > 10) {
            shortest->timeDuration -= 10;
            cout << "Updated Time Duration: " << shortest->timeDuration << " Millisecond" << endl;
        } 
        else {
            cout << "Task " << shortest->taskName << " completed (Time Duration reached)." << endl;

            // Remove the shortest task from the list
            if (shortestPrev == nullptr) {
                head = shortest->next; // Shortest is the head
            } else {
                shortestPrev->next = shortest->next;
            }
            delete shortest;
        }
    }

    cout << "All tasks Executed Completely." << endl;
}

int main() {
    Task* head = nullptr;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Add Tasks for (FIFO) First in First out" << endl;
        cout << "4. Add Tasks for (LIFO) Last in First out" << endl;
        cout << "5. Add Tasks for (SJF) Short Job First" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskName;
                string taskId;
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
                cout << " Program Ends Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
