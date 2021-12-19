#include <iostream>
using namespace std;

int meetingNumbers(int* array, int size_of_array, int number);
string toString(int number, int repeats)
{
    char figure;
    int degree, leftNumber, code;
    string str = "";
    for (int i = 0; i < repeats; i++)
    {
        leftNumber = number;
        degree = 0;
        while (leftNumber >= 10)
        {
            leftNumber /= 10;
            degree++;
        }
        code = leftNumber;
        number -= pow(10, degree) * leftNumber;
        figure = code + 48;
        str += figure;
    }
    return str;
}
string toString(int number)
{
    char figure;
    int code;
    string str = "";
    while (number > 0)
    {
        code = number % 10;
        number /= 10;
        figure = code + 48;
        str = figure + str;
    }
    return str;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int number_of_task;
    do
    {
        cout << "Введите номер задания(1-3; 0 - выход): " << endl;
        cin >> number_of_task;
        switch (number_of_task)
        {
        case 0: break;
        case 1:
        {
            string str;
            int number;
            cout << "Введите число\n";
            cin >> number;
            str = toString(abs(number));
            if (number < 0) str = '-' + str;
            cout << "Строка:\n" << str;
            return 0;
        }
        case 2:
        {
            cout << "Задание 2" << endl;
            string str;
            double number;
            int countOfRepeats;
            cout << "Введите число\n";
            cin >> number;
            cout << "Введите количество символов на вывод\n";
            cin >> countOfRepeats;
            int degree = 0, check = abs(number);
            while (check > 0)
            {
                if ((check < 100) and (check > 9) and (check % 10 == 0)) degree++;
                check /= 10;
                degree++;
            }
            if (countOfRepeats >= degree)
            {
                str = toString(number);
            }
            else str = toString(number, countOfRepeats);
            if (number < 0) str = '-' + toString(fabs(number), countOfRepeats);
            cout << "Строка:\n" << str;
            return 0;
        }
        
        case 3:
        {
            cout << "Задание 3" << endl;
            int size_of_array;
            int number;
            cout << "Введите размер массива : " << endl;
            cin >> size_of_array;
            cout << "Введите число : " << endl;
            cin >> number;
            int* array = new int[size_of_array];
            for (int i = 0; i < size_of_array; i++)
            {
                array[i] = rand() % 21 - 10;
                cout << array[i] << "\t";
            }
            cout << endl;
            meetingNumbers(array, size_of_array, number);
            break;
        }
        default: cout << "Задания с таким номером нету." << endl; break;
        }
    } while (number_of_task != 0);
    return 0;

}

int meetingNumbers(int* array, int size_of_array, int number)
{
    int counter = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        if (array[i] == number) counter++;
    }
    if (counter == 0) cout << "Нету встреч в массиве" << endl;
    else cout << "Количество встреч в массиве : " << counter << endl;
    return 0;
}