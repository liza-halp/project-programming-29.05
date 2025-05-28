#include "functions.h"
#include <iostream>
using namespace std;

// Максимальна кількість задач, яку може зберігати додаток
const int MAX_TASKS = 100;

// Структура для зберігання дати та часу виконання задачі
struct DateTime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// Структура, що описує одну задачу в списку
struct Task
{
    char title[50];
    int priority;
    char description[100];
    DateTime time;
    bool completed = false; // Статус задачі: true, якщо виконана, false - якщо ні
};

// Глобальний масив для зберігання всіх задач та їх кількості
Task taskList[MAX_TASKS];
int totalTasks = 0;

bool handleMenu(int choice)
{
    if (choice == 1)
    {
        addTask();
    }
    else if (choice == 2)
    {
        deleteTask();
    }
    else if (choice == 3)
    {
        editTask();
    }
    else if (choice == 4)
    {
        listTasks();
    }
    else if (choice == 5)
    {
        listTasksToday();
    }
    else if (choice == 6)
    {
        listTasksThisWeek();
    }
    else if (choice == 7)
    {
        listTasksThisMonth();
    }
    else if (choice == 8)
    {
        searchByTitle();
    }
    else if (choice == 9)
    {
        searchByPriority();
    }
    else if (choice == 10)
    {
        searchByDescription();
    }
    else if (choice == 11)
    {
        sortByPriority();
    }
    else if (choice == 12)
    {
        sortByDate();
    }
    else if (choice == 13)
    {
        completeTask();
    }
    else if (choice == 0)
    {
        cout << "Exiting program. Goodbye!\n";
        return false; // Повертаємо false, щоб завершити програму
    }
    else
    {
        cout << "Invalid choice. Please try again.\n";
    }
    return true; // Повертаємо true, щоб продовжити роботу програми
}

int main()
{
    menu();
    return 0;
}