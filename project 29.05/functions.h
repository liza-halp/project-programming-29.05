void readText(char* text, int maxLength)
{
    int i = 0;
    char ch;
    // Очищаємо буфер вводу, щоб уникнути проблем з попереднім вводом (наприклад, символом '\n' після cin >> число)
    cin.ignore(1000, '\n');

    while (i < maxLength - 1) // Залишаємо місце для нульового термінатора
    {
        if (!cin.get(ch)) // Зчитуємо символ, включаючи пробіли
        {
            break; // Перериваємо, якщо стався збій при зчитуванні
        }
        if (ch == ';') // Якщо знайдено символ-роздільник, припиняємо зчитування
        {
            break;
        }
        text[i] = ch; // Записуємо символ в масив
        i++;
    }
    text[i] = '\0'; // Додаємо нульовий термінатор, щоб завершити C-рядок
}

void inputDateTime(DateTime& dt)
{
    cout << "Enter date and time (year month day hour minute): ";
    // Перевіряємо коректність вводу, поки користувач не введе числа
    while (!(cin >> dt.year >> dt.month >> dt.day >> dt.hour >> dt.minute))
    {
        cout << "Invalid input. Please enter numbers for year, month, day, hour, minute: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void addTask()
{
    if (totalTasks >= MAX_TASKS) // Перевірка на переповнення списку задач
    {
        cout << "Task list is full. Cannot add a new task.\n";
        return;
    }

    Task& task = taskList[totalTasks]; // Посилання на нову задачу в масиві

    cout << "Enter task title (end with ';'): ";
    readText(task.title, 50); // Зчитуємо назву задачі

    cout << "Enter priority (1-10): ";
    // Цикл для перевірки коректності вводу пріоритету
    while (!(cin >> task.priority) || task.priority < 1 || task.priority > 10)
    {
        cout << "Invalid priority. Please enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter task description (end with ';'): ";
    readText(task.description, 100); // Зчитуємо опис задачі

    inputDateTime(task.time);

    task.completed = false; // Нова задача завжди не виконана за замовчуванням

    totalTasks++; // Збільшуємо лічильник задач
    cout << "Task added.\n";
}

void completeTask()
{
    int index;
    cout << "Enter task number to mark as completed: ";

    while (!(cin >> index) || index < 1 || index > totalTasks)
    {
        cout << "Invalid number. Please enter a valid task number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    taskList[index - 1].completed = true; // Позначаємо задачу виконаною
    cout << "Task marked as completed.\n";
}