#include <iostream>
#include <windows.h>
using namespace std;

void Print_tasks(string tasks[], int task_counter) {
    cout << "Task To Do: " << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < task_counter; i++) {
        cout << "Task " << i << " : " << tasks[i] << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

int main() {
    system("color d");
    string task[10] = {""};

    // Counter variable to keep track of the number of tasks
    int task_counter = 0;

    int option = -1;

    while (option != 0) {
        // Display menu
        cout << "<---------TO DO LIST --------->" << endl;
        cout << "1. To Add new Task." << endl;
        cout << "2. To View Task." << endl;
        cout << "3. Delete The Task." << endl;
        cout << "Terminate The Program. (press '0')" << endl;

        cout << "Enter your choice => ";
        cin >> option;

        switch (option) {
            case 1: {
                if (task_counter >= 10) {
                    cout << "<-------TASK LIST IS FULL------->" << endl;
                } else {
                    cout << "Enter A New Task: ";
                    cin.ignore();
                    getline(cin, task[task_counter++]);
                }
                break;
            }
            case 2: {
                system("cls");  // Clear console (may not work in some environments)
                Print_tasks(task, task_counter);
                break;
            }
            case 3: {
                system("cls");  // Clear console (may not work in some environments)
                Print_tasks(task, task_counter);
                int del_task = 0;
                cout << "Enter a task to delete=> ";
                cin >> del_task;

                if (del_task < 0 || del_task >= task_counter) {
                    cout << "It is an ERROR !! Please enter a valid Task." << endl;
                    break;
                }

                for (int i = del_task; i < task_counter - 1; i++) {
                    task[i] = task[i + 1];
                }
                task_counter--;
                break;
            }
            case 0: {
                cout << "Terminating the program--- ----- -------" << endl;
                break;
            }
            default:
                cout << "You Have Entered An invalid Value." << endl;
        }
    }

    return 0;
}