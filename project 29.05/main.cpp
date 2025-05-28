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