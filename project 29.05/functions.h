//
//  functions.h
//  project 29.05
//
//  Created by Лиза on 08.05.2025.
//
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
