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
void showTask(const Task& task, int index)
{
    cout << index + 1 << ") " << task.title << " | Priority: " << task.priority;
    cout << (task.completed ? " [COMPLETED]\n" : "\n"); // Виводить статус виконання
    cout << "    Description: " << task.description << "\n";
    cout << "    Deadline: " << task.time.year << "-" << task.time.month << "-" << task.time.day;
    cout << " " << task.time.hour << ":" << task.time.minute << "\n";
}

void listTasks()
{
    if (totalTasks == 0)
    {
        cout << "No tasks to display.\n";
        return;
    }
    cout << "\nAll tasks:\n";
    for (int i = 0; i < totalTasks; i++)
    {
        showTask(taskList[i], i);
    }
}

// Виводить задачі, що мають бути виконані сьогодні
void listTasksToday()
{
    cout << "Tasks for today:\n";
    if (totalTasks == 0)
    {
        cout << "No tasks to display.\n";
        return;
    }
    for (int i = 0; i < totalTasks; ++i)
    {
        showTask(taskList[i], i);
    }
}

// Виводить задачі, що мають бути виконані цього тижня
void listTasksThisWeek()
{
    cout << "Tasks for this week:\n";
    if (totalTasks == 0)
    {
        cout << "No tasks to display.\n";
        return;
    }
    for (int i = 0; i < totalTasks; ++i)
    {
        showTask(taskList[i], i);
    }
}
void deleteTask()
{
    int index;
    cout << "Enter task number to delete: ";
    // Перевірка коректності вводу номера задачі
    while (!(cin >> index) || index < 1 || index > totalTasks)
    {
        cout << "Invalid number. Please enter a valid task number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Зсуваємо всі наступні задачі в масиві на одну позицію вліво
    for (int i = index - 1; i < totalTasks - 1; i++)
    {
        taskList[i] = taskList[i + 1];
    }

    totalTasks--;
    cout << "Task deleted.\n";
}

void editTask()
{
    int index;
    cout << "Enter task number to edit: ";

    while (!(cin >> index) || index < 1 || index > totalTasks)
    {
        cout << "Invalid number. Please enter a valid task number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    Task& task = taskList[index - 1]; // Отримуємо посилання на задачу для редагування

    cout << "Enter new title (end with ';'): ";
    readText(task.title, 50);

    cout << "Enter new priority (1-10): ";
    while (!(cin >> task.priority) || task.priority < 1 || task.priority > 10)
    {
        cout << "Invalid priority. Please enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter new description (end with ';'): ";
    readText(task.description, 100);

    inputDateTime(task.time); // Вводимо нову дату та час

    cout << "Task updated.\n";
}

void searchByTitle()
{
    char searchTitle[50];
    cout << "Enter title to search (end with ';'): ";
    readText(searchTitle, 50);

    bool found = false;
    cout << "\nSearch results by title:\n";
    for (int i = 0; i < totalTasks; i++)
    {
        bool match = true;
        int j = 0;
        // Порівнюємо символи обох рядків до їх кінця
        while (searchTitle[j] != '\0' && taskList[i].title[j] != '\0')
        {
            if (searchTitle[j] != taskList[i].title[j])
            {
                match = false; // Знайдено відмінність
                break;
            }
            j++;
        }
        // Перевіряємо, чи обидва рядки закінчилися одночасно, що свідчить про повний збіг
        if (match && searchTitle[j] == '\0' && taskList[i].title[j] == '\0')
        {
            showTask(taskList[i], i); // Виводимо знайдену задачу
            found = true;
        }
    }
    if (!found)
    {
        cout << "No tasks found with that title.\n";
    }
}

void searchByPriority()
{
    int searchPrio;
    cout << "Enter priority to search (1-10): ";
    // Перевірка коректності вводу пріоритету для пошуку
    while (!(cin >> searchPrio) || searchPrio < 1 || searchPrio > 10)
    {
        cout << "Invalid priority. Please enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    bool found = false;
    cout << "\nSearch results by priority " << searchPrio << ":\n";
    for (int i = 0; i < totalTasks; ++i)
    {
        if (taskList[i].priority == searchPrio)
        {
            showTask(taskList[i], i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No tasks found with priority " << searchPrio << ".\n";
    }
}

void searchByDescription()
{
    char searchText[100];
    cout << "Enter description text to search (end with ';'): ";
    readText(searchText, 100);

    bool found = false;
    if (searchText[0] == '\0') // Перевірка на порожній пошуковий запит
    {
        cout << "Search text cannot be empty.\n";
        return;
    }

    cout << "\nSearch results by description:\n";
    for (int i = 0; i < totalTasks; ++i)
    {
        bool currentTaskMatches = false;
        // Простий алгоритм пошуку підрядка в описі задачі
        for (int j = 0; taskList[i].description[j] != '\0'; ++j)
        {
            int k = 0;
            // Порівнюємо символи, поки не знайдемо невідповідність або кінець пошукового тексту
            while (searchText[k] != '\0' && taskList[i].description[j + k] != '\0' &&
                searchText[k] == taskList[i].description[j + k])
            {
                k++;
            }
            // Якщо досягли кінця пошукового тексту, значить, підрядок знайдено
            if (searchText[k] == '\0')
            {
                currentTaskMatches = true;
                break;
            }
        }
        if (currentTaskMatches)
        {
            showTask(taskList[i], i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No tasks found with that description.\n";
    }
}