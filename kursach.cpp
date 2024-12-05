#include <iostream>
#include <windows.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <bitset>
using namespace std;
using namespace chrono;

// лаба1
void replacing_bit_divisibility_by_2(int& number) {
    cout << "ИДЗ(замена битов исходя из их четности):";
    cout << endl;
    unsigned int mask = 1 << (sizeof(int) * 8) - 1;
    if (number >= 0) {
        for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
            if (i % 2 != 0) {
                number |= (1 << i);
            };
            mask >>= 1;
        };

    }
    else {
        for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
            putchar((i % 2 == 0) ? '0' : ((number & mask) ? '1' : '0'));
            if (i % 2 == 0) {
                number &= (~(1 << i));
            };
            mask >>= 1;
        };
    };
    cout << endl;
    cout << number << endl;
}
void display_menu_for_laba1() {
    cout << "Выберите действие: " << endl;
    cout << "1) Сколько памяти (в байтах)отводится под различные типы данных со спецификаторами и без:int, short int, long int, float, double, long double, char и bool." << endl;
    cout << "2) Вывести на экран двоичное представление в памяти (все разряды) целого числа." << endl;
    cout << "3) Вывести на экран двоичное представление в памяти (все разряды) типа float." << endl;
    cout << "4) Вывести на экран двоичное представление в памяти (все разряды) типа double." << endl;
    cout << "5) Возвращаемся к лабам." << endl;
}

int main_of_laba1() {
    setlocale(0, "");
    int i, part, j;
    int int_num;
    unsigned int mask = 1 << (sizeof(int) * 8) - 1;
    union {
        float float_num;
        int float_to_int;
    };
    unsigned int mask_float = 1 << (sizeof(int) * 8) - 1;
    union {
        double double_num;
        unsigned int double_divided_on_two_parts[2];
    };
    unsigned int mask_double = 1 << ((sizeof(int) * 8) - 1);
    while (true) {
        display_menu_for_laba1();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> i;
        switch (i) {
        case 1:
            //1) Сколько памяти (в байтах)отводится под различные типы данных со спецификаторами и без:
    // int, short int, long int, float, double, long double, char и bool.
            cout << "Тип данных int - " << sizeof(int) << "байта" << endl;
            cout << "Тип данных short int - " << sizeof(short int) << "байта" << endl;
            cout << "Тип данных long int - " << sizeof(long int) << "байта" << endl;
            cout << "Тип данных float - " << sizeof(float) << "байта" << endl;
            cout << "Тип данных double - " << sizeof(double) << "байта" << endl;
            cout << "Тип данных long double - " << sizeof(long double) << "байта" << endl;
            cout << "Тип данных char - " << sizeof(char) << "байта" << endl;
            cout << "Тип данных bool - " << sizeof(bool) << "байта" << endl;
            break;
        case 2:
            //2) Вывести на экран двоичное представление в памяти (все разряды) целого числа.
            cout << "Введите число типа int: ";
            cin >> int_num;
            cout << "двоичное представление в памяти(все разряды) целого числа: " << endl;

            for (i = 0; i <= sizeof(int) * 8 - 1; ++i) {
                putchar(int_num & mask ? '1' : '0');
                mask >>= 1;
                if (i == 0 || i % 8 == 7) {
                    putchar(' ');
                }
            };
            cout << endl;
            replacing_bit_divisibility_by_2(int_num);//ИДЗ
            cout << endl;
            cout << int_num;
            cout << endl;
            mask = 1 << (sizeof(int) * 8) - 1;
            for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
                putchar(int_num & mask ? '1' : '0');
                mask >>= 1;
                if (i == 0 || i % 8 == 7) {
                    putchar(' ');
                }
            };
            cout << endl;
            break;
        case 3:
            //3) Вывести на экран двоичное представление в памяти (все разряды) типа float.

            cout << "Введите число типа float: ";
            cin >> float_num;
            cout << "двоичное представление в памяти (все разряды) типа float" << endl;
            for (i = 0; i <= (sizeof(int) * 8) - 1; ++i) {
                putchar(float_to_int & mask_float ? '1' : '0');
                mask_float >>= 1;
                if (i == 0 || i == 8 || i == 12) { // Знак (1 бит) и Экспонента (8 бит)
                    putchar(' ');
                }
            }
             cout << endl;
             break;
        case 4:
            //4) Вывести на экран двоичное представление в памяти (все разряды) типа double.
            cout << "Введите число типа double: ";

            cin >> double_num;
            cout << "двоичное представление в памяти (все разряды) типа double: ";
            cout << endl;
            for (part = 1; part >= 0; --part) {
                for (j = 0; j <= (sizeof(int) * 8 - 1); ++j) {
                    putchar(double_divided_on_two_parts[part] & mask_double ? '1' : '0');
                    mask_double >>= 1;
                };
                mask_double = 1 << ((sizeof(int) * 8) - 1);

            };
            break;
        case 5:
            cout << "Возвращаемся к выбору лабы!!!" << endl;
            return 0;

        default:
            cout << "Некорректный номер задания" << endl;
            break;
        }
        cout << "Задание выполнено. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}
//лаба2
void idz_for_laba2(int arr[], int N) {
    int value_to_decrease;
    int counter_even = 0;
    int counter_odd = 0;
    int start_val = 1;
    int end_val = 9;
    srand(time(0));
    cout << "Введите значение для уменьшения четных элементов ";
    cin >> value_to_decrease;
    cout << "Выводим четные элементы, уменьшенные в процессе ";
    int random_value = (rand() % (end_val - start_val + 1) + start_val);
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // уменьшение на заданное значение
            arr[i] = arr[i] - value_to_decrease;
            cout << arr[i] << ' ';
            // умножение четного на рандомное значение
            arr[i] = arr[i] * random_value;
            if (arr[i] % 2 == 0) {
                counter_even += 1;
            }
        }
        else if (i % 2 != 0 and arr[i] % 2 != 0) {
            counter_odd += 1;
        };
    };
    cout << endl;
    cout << "Выводим массив с четными элементами, умноженными на значение " << random_value << " : ";
    for (int i = 0; i < (N / 2); i++) {
        cout << arr[i] << " ";
    };
    cout << endl;
    cout << "Количество четных элементов имеющих четные значения: " << counter_even << endl;
    cout << "Количество нечетных элементов имеющих нечетные значения: " << counter_odd << endl;
    for (int i = 1; i < 10; i++) {
        int counter_del = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] % i == 0) {
                counter_del += 1;
            }
        };
        cout << "Количество чисел делящихся на " << i << " равно " << counter_del << endl;
    };
};
void shaker_sort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
    nanoseconds result;
    start_time = steady_clock::now();
    for (int a = 0; a < n / 2; a++) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
    end_time = steady_clock::now();
    result = duration_cast<nanoseconds>(end_time - start_time);
    cout << result.count() << " наносекунд - время сортировки с помощью shaker sort" << endl;

}
void bubble_sort(int arr[], int N) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
    nanoseconds result;
    start = steady_clock::now();
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < N - 1 - j; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            };
        };
    };
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << " наносекунд - время сортировки с помощью bubble sort" << endl;
}
void insert_sort(int arr[], int n) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
    nanoseconds result;
    start = steady_clock::now();
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Сдвигаем элементы массива, которые больше key, на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    };
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << " наносекунд - время сортировки с помощью insert sort" << endl;
}
void quick_sort(int arr[], int end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quick_sort(arr, l, begin);
    if (f < end) quick_sort(arr, end, f);
}
void comb_sort(int arr[], int N) {
    int swap;
    float k = 1.247, S = N - 1;
    int count = 0;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
    nanoseconds result;
    start_time = steady_clock::now();
    while (S >= 1)
    {
        for (int i = 0; i + S < N; i++)
        {
            if (arr[i] > arr[int(i + S)])
            {
                swap = arr[int(i + S)];
                arr[int(i + S)] = arr[i];
                arr[i] = swap;
            }
        }
        S /= k;
    }

    while (true)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = swap;
            }
            else count++;
        }
        if (count == N - 1)
            break;
        else
            count = 0;
    }
    end_time = steady_clock::now();
    result = duration_cast<nanoseconds>(end_time - start_time);
    cout << result.count() << " наносекунд - время сортировки с помощью comb sort" << endl;
}
void from_small_to_big_2(int arr[], int N) {
    shaker_sort(arr, N);
    insert_sort(arr, N);
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
    nanoseconds result;
    start_time = steady_clock::now();
    quick_sort(arr, N - 1, 0);
    end_time = steady_clock::now();
    result = duration_cast<nanoseconds>(end_time - start_time);
    cout << result.count() << " наносекунд - время сортировки с помощью quick sort" << endl;
    comb_sort(arr, N);
    bubble_sort(arr, N);
    cout << "Отсортированный массив: ";
    for (int a = 0; a < N; a++) {
        cout << arr[a] << ' ';
    };
    cout << endl;
};

void max_min_elems_of_arr_3(int arr[], int not_sort[], int N) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
    nanoseconds result;
    start = steady_clock::now();
    // несортированный массив
    int min = not_sort[0];
    int max = not_sort[0];
    for (int i = 1; i < N; i++) {
        if (not_sort[i] < min) {
            min = not_sort[i];
        }
        if (not_sort[i] > max) {
            max = not_sort[i];
        }

    };
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ С НЕСОРТИРОВАННЫМ МАССИВОМ" << endl;
    cout << "Максимальный и минимальный элементы для неотсортированного массива: " << min << ' ' << max << endl;
    // для отсортированного массива
    start = steady_clock::now();
    min = arr[0];
    max = arr[N - 1];
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ С СОРТИРОВАННЫМ МАССИВОМ" << endl;
    cout << "Максимальный и минимальный элементы для отсортированного массива: " << min << ' ' << max << endl;

};

void median_of_arr_4(int arr[], int N) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
    nanoseconds result;
    int srednee_znachenie = (arr[0] + arr[N - 1]) / 2;
    cout << "среднее от min и max " << srednee_znachenie << endl;
    int counter = 0;
    cout << "Под каким номером есть такое же число как среднее: ";
    start = steady_clock::now();
    for (int i = 0; i < N && arr[i] <= srednee_znachenie; i++) {
        if (arr[i] == srednee_znachenie) {
            cout << i << endl;
            counter += 1;
        }

    };
    end = steady_clock::now();

    if (counter == 0) {
        cout << "нет таких элементов массива" << endl;
    }
    else {
        cout << "Всего найдено чисел: " << counter << endl;
    };
    result = duration_cast<nanoseconds>(end - start);
    cout << "Нахождение заданных элементов заняло: " << result.count() << " наносекунд" << endl;
}


void smaller_num_counter_5(int arr[], int N) {
    int num;
    int count = 0;
    cout << "ВВЕДИТЕ ЧИСЛО: ";
    cin >> num;
    for (int i = 0; i < N && arr[i] < num; i++, count++);
    cout << endl;
    cout << "КОЛИЧЕСТВО ЧИСЕЛ МЕНЬШЕ ЧЕМ " << num << " РАВНО " << count << endl;
};

void bigger_num_counter_6(int arr[], int N) {
    int num;
    int count = 0;
    cout << "ВВЕДИТЕ ЧИСЛО: ";
    cin >> num;
    for (int i = N - 1; i >= 0 && arr[i] > num; i--, count++) {};
    cout << endl;
    cout << "КОЛИЧЕСТВО ЧИСЕЛ БОЛЬШЕ ЧЕМ " << num << " РАВНО " << count << endl;
};

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        return binarySearch(arr, value, mid + 1, end);
    }
    return -1;
};

void find_number_in_arr_7(int arr[], int N) {
    int num;
    int num_in_arr = 0;
    cout << "ВВЕДИТЕ ЧИСЛО ДЛЯ ЗАДАНИЯ 7: ";
    cin >> num;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
    nanoseconds result;
    cout << "Полным перебором: ";
    // полный перебор
    start = steady_clock::now();
    for (int a = 0; a < N; a++) {
        if (num == arr[a]) {
            num_in_arr = 1;
            break;
        }
    };
    end = steady_clock::now();
    if (num_in_arr == 1) {
        cout << "Введенное число есть в массиве!" << endl;
    }
    else {
        cout << "Введенного числа нет в массиве!" << endl;
    }
    result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ ОБЫЧНЫМ ПЕРЕБОРОМ" << endl;
    cout << "Бинарным поиском: ";
    start = steady_clock::now();
    // бинарный поиск
    int answer = binarySearch(arr, num, 0, N - 1);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    if (answer == -1) {
        cout << "Введенного числа нет в массиве!" << endl;
    }
    else {
        cout << "Введенное число есть в массиве!" << endl;
    }
    cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ БИНАРНЫМ ПОИСКОМ" << endl;

};

void change_elems_of_arr_8(int arr[], int N) {
    int elem_index_1;
    int elem_index_2;
    cout << "Введи индексы, которые хочешь поменять в массиве:";
    cin >> elem_index_1;
    cout << endl;
    cin >> elem_index_2;
    swap(arr[elem_index_1], arr[elem_index_2]);
    cout << "МАССИВ С ИЗМЕННЕННЫМИ ЗНАЧЕНИЯМИ " << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    };
    cout << endl;
};


int main_of_laba2()
{
    setlocale(0, "");
    // 1)Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.
    const int N = 100;
    unsigned identificator;
    int Array[N];
    int not_sorted_array[N];
    unsigned int start_val = -99;
    int end_val = 99;
    srand(time(0));
    cout << "Сгенерированный массив: " << endl;
    for (int i = 0; i < N; i++) {
        Array[i] = rand() % (end_val - start_val + 1) + start_val;
        not_sorted_array[i] = Array[i];
        cout << Array[i] << ' ';
    };
    cout << endl;
    cout << "Доступные задания: " << endl;
    cout << "1. Сгенерировать массив заново" << endl;
    cout << "2. Сортировка от меньшего к большему" << endl;
    cout << "3. Поиск минимального и максимального значений" << endl;
    cout << "4. Расчет и поиск среднего значения max и min" << endl;
    cout << "5. Элементы массива меньше заданного числа" << endl;
    cout << "6. Элементы массива больше заданного числа" << endl;
    cout << "7. Найти число в массиве" << endl;
    cout << "8. Поменять элементы с заданными индексами местами" << endl;
    cout << "9. ИДЗ 5" << endl;
    cout << "10. Возвращаемся к выбору лаб" << endl;
    while (true) {
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        if (!(cin >> identificator)) {
            cin.clear();
            continue;
        }

        switch (identificator) {
        case 1:
            cout << "Новый массив" << endl;
            for (int i = 0; i < N; i++) {
                Array[i] = rand() % (end_val - start_val + 1) + start_val;
                not_sorted_array[i] = Array[i];
                cout << Array[i] << ' ';
            }
            cout << endl;
            break;

        case 2:
            cout << "Сортировка от меньшего к большему" << endl;
            from_small_to_big_2(Array, N);
            break;

        case 3:
            max_min_elems_of_arr_3(Array, not_sorted_array, N);
            break;

        case 4:
            median_of_arr_4(Array, N);
            break;

        case 5:
            smaller_num_counter_5(Array, N);
            break;

        case 6:
            bigger_num_counter_6(Array, N);
            break;

        case 7:
            find_number_in_arr_7(Array, N);
            break;

        case 8:
            change_elems_of_arr_8(Array, N);
            break;
        case 9:
            idz_for_laba2(Array, N);
            break;
        case 10:
            cout << "Возвращаемся к выбору лабы!!" << endl;
            return 0;
        default:
            cout << "Некорректный номер задания" << endl;
            break;
        }
    }
}
// лаба 3
void print_matrix(int* matrix, int N) {
    int* end = matrix + (N * N) - 1;
    for (int* i = matrix; i <= end; ++i) {
        if ((i - matrix) % N == 0) {
            cout << "\n";
        }
        cout << *i << " ";
    }
}
void print_Matrix(int* matrix, int n, int helper) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            destCoord.X = j * 4 + 50;
            destCoord.Y = i + helper;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(matrix + i * n + j) << " ";
        }
        cout << endl;
    }
}
void idz_for_3() {
    int N;
    cout << "Введите число для ИДЗ(от 2 до 10)" << endl;
    cin >> N;
    int* matrix1 = new int[N * N];
    int* matrix2 = new int[N * N];
    int* matrix3 = new int[N * N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix1 + i * N + j) = rand() % (N * N) + 1;
            *(matrix2 + i * N + j) = rand() % (N * N) + 1;
            *(matrix3 + i * N + j) = 1;
        }
    }
    cout << "Первая матрица" << endl;
    print_Matrix(matrix1, N, 0);
    cout << "Вторая матрица" << endl;
    print_Matrix(matrix2, N, N + 1);
    cout << endl;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            int* num = matrix3 + i + top * N;
            *num = *(matrix1 + i + top * N) + *(matrix2 + i + top * N);
            print_Matrix(matrix3, N, N + 12);
            Sleep(50);
        }
        top++;
    }
    print_Matrix(matrix3, N, N + 12);
}
void shaker_sort_for_3(int* matrix, int N) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int* i = matrix + 1, *end = matrix + N * N - 1; i <= end; i++) {
            if (*(i - 1) > *i) {
                int temp = *(i - 1);
                *(i - 1) = *i;
                *i = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        for (int* i = matrix + N * N - 2; i >= matrix; i--) {
            if (*(i - 1) > *i) {
                int temp = *(i - 1);
                *(i - 1) = *i;
                *i = temp;
                swapped = true;
            }
        }
    }
}
void comb_sort_for_3(int* matrix, int N) {
    float k = 1.247;
    int S = N * N;
    bool swapped = true;

    while (S > 1 || swapped) {
        if (S > 1) {
            S /= k;
        }
        swapped = false;

        for (int i = 0; i + S < N * N; i++) {
            if (*(matrix + i) > *(matrix + i + S)) {
                swap(*(matrix + i), *(matrix + i + S));
                swapped = true;
            }
        }
    }
}
void quick_sort_for_3(int* matrix, int* begin, int* end) {
    int* f = begin;
    int* l = end;
    int mid = *(begin + (end - begin) / 2);

    while (f <= l) {
        while (*f < mid) f++;
        while (*l > mid) l--;

        if (f <= l) {
            swap(*f, *l);
            f++;
            l--;
        }
    }
    if (begin < l) quick_sort_for_3(matrix, begin, l);
    if (f < end) quick_sort_for_3(matrix, f, end);
}
void insert_sort_for_3(int* matrix, int N) {
    for (int i = 1; i < N * N; i++) {
        int key = *(matrix + i);
        int j = i - 1;
        while (j >= 0 && *(matrix + j) > key) {
            *(matrix + j + 1) = *(matrix + j);
            j--;
        }
        *(matrix + j + 1) = key;
    }
}
void fill_snake(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; i++) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(400);
        }
        left++;

        for (int i = bottom; i >= top; i--) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(400);
        }
        left++;
    }
}
void fill_spiral(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(matrix + top * n + i) = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(100);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            *(matrix + i * n + right) = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(100);
        }
        right--;


        for (int i = right; i >= left; i--) {
            *(matrix + bottom * n + i) = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(100);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            *(matrix + i * n + left) = rand() % (n * n) + 1;
            print_Matrix(matrix, n, 0);
            Sleep(100);
        }
        left++;
    }
    print_Matrix(matrix, n, 0);
}
void swap_quarters_a(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + i * N + j + middle) = *(temp + i * N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i + middle) * N + j) = *(temp + i * N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + i * N + (j - middle)) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j) = *(temp + i * N + j);
            }
        }
    }
    print_Matrix(matrix, N, N + 10);
}
void swap_quarters_b(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + (i + middle) * N + j + middle) = *(temp + i * N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i + middle) * N + j - middle) = *(temp + i * N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + (i - middle) * N + j - middle) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j + middle) = *(temp + i * N + j);
            }
        }
    }
    print_Matrix(matrix, N, N + 10);
}
void swap_quarters_c(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle) {
                *(matrix + (i + middle) * N + j) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j) = *(temp + i * N + j);
            }
        }
    }
    print_Matrix(matrix, N, N + 10);
}

void swap_quarters_d(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < middle) {
                *(matrix + i * N + j + middle) = *(temp + i * N + j);
            }
            else {
                *(matrix + i * N + j - middle) = *(temp + i * N + j);
            }
        }
    }
    print_Matrix(matrix, N, N + 10);
}
void enlarge_each_element(int* matrix, int N) {
    int enlarge_num;

    cout << "Введите число, которое нужно прибавить: ";
    cin >> enlarge_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) += enlarge_num;
        }
    }
    print_Matrix(matrix, N, N + 10);
}
void reduce_each_element(int* matrix, int N) {
    int reduce_num;

    cout << "Введите число, которое нужно отнять: ";
    cin >> reduce_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) -= reduce_num;
        }
    }
    print_Matrix(matrix, N, N + 10);
}
void divide_each_element(int* matrix, int N) {
    int divide_num;

    cout << "Введите число, на которое нужно разделить: ";
    cin >> divide_num;
    if (divide_num == 0) {
        cout << "Деление на ноль!" << endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) /= divide_num;
        }
    }
    print_Matrix(matrix, N, N + 10);
}

void multiply_each_element(int* matrix, int N) {
    int multiply_num;

    cout << "Введите число, на которое нужно умножить: ";
    cin >> multiply_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) *= multiply_num;
        }
    }
    print_Matrix(matrix, N, N + 10);
}

void display_menu_for_laba3() {
    cout << "\nДоступные задания:" << endl;
    cout << "1. Задание 1. Заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до N*N согласно схемам" << endl;
    cout << "2. Задание 2. Получение новой матрицы, из матрицы п. 1, переставляя ее блоки в соответствии со схемами" << endl;
    cout << "3. Задание 3. Используя арифметику указателей, сортирует элементы любой сортировкой из списка ниже" << endl;
    cout << "4. Задание 4. Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число" << endl;
    cout << "5. Задание 5. ИДЗ" << endl;
    cout << "6. Задание 6. Вернемся к выбору лабы." << endl;
}
void start(int* matrix, int N) {
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            *(matrix + i * N + j) = 1;
        }
    }
}
int main_of_laba3() {
    setlocale(0, "");
    srand(time(NULL));
    int N, identificator, num1, num2, num3, num4;
    cout << "Введите размер матрицы (6, 8, 10): ";
    cin >> N;
    int* matrix = new int[N * N];

    while (true) {
        display_menu_for_laba3();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> identificator;
        system("cls");  // Для Windows
        switch (identificator) {
        case 1:
            start(matrix, N);
            cout << "1. Массив спиралью" << endl;
            cout << "2. Массив змейкой" << endl;
            cin >> num1;
            switch (num1) {
            case 1:
                fill_spiral(matrix, N);
                break;
            case 2:
                fill_snake(matrix, N);
                break;
            }
            break;
        case 2:
            print_Matrix(matrix, N, 0);
            cout << "Меняем четверти" << endl;
            cout << "1. по часовой стрелке" << endl;
            cout << "2. по диагонали " << endl;
            cout << "3. сверху вниз" << endl;
            cout << "4. справа налево" << endl;
            cin >> num2;
            cout << "Измененная матрица" << endl;
            switch (num2) {
            case 1:
                swap_quarters_a(matrix, N);
                break;
            case 2:
                swap_quarters_b(matrix, N);
                break;
            case 3:
                swap_quarters_c(matrix, N);
                break;
            case 4:
                swap_quarters_d(matrix, N);
                break;
            }
            break;
        case 3:
            print_Matrix(matrix, N, 0);
            cout << "Введите сортировку:" << endl;
            cout << "1. Shaker sort" << endl;
            cout << "2. Comb sort" << endl;
            cout << "3. Insert sort" << endl;
            cout << "4. Quick sort" << endl;

            cin >> num3;
            switch (num3) {
            case 1:
                shaker_sort_for_3(matrix, N);
                print_Matrix(matrix, N, N + 10);
                break;
            case 2:
                comb_sort_for_3(matrix, N);
                print_Matrix(matrix, N, N + 10);
                break;
            case 3:
                insert_sort_for_3(matrix, N);
                print_Matrix(matrix, N, N + 10);
                break;
            case 4:
                quick_sort_for_3(matrix, matrix, matrix + N * N - 1);
                print_Matrix(matrix, N, N + 10);
                break;
            }
            cout << "Измененная матрица" << endl;
            break;
        case 4:
            print_Matrix(matrix, N, 0);
            cout << "Введите номер операции с элементами массива:" << endl;
            cout << "1. Увеличить элементы массива" << endl;
            cout << "2. Уменьшить элементы массива " << endl;
            cout << "3. Умножить элементы массива" << endl;
            cout << "4. Разделить элементы массива" << endl;
            cout << "Измененная матрица" << endl;
            cin >> num4;
            switch (num4) {
            case 1:
                enlarge_each_element(matrix, N);
                break;
            case 2:
                reduce_each_element(matrix, N);
                break;
            case 3:
                multiply_each_element(matrix, N);
                break;
            case 4:
                divide_each_element(matrix, N);
                break;
            }
            break;
        case 5:
            cout << "ИДЗ" << endl;
            idz_for_3();
            break;

        case 6:
            cout << "Обратно к выбору лабы!!" << endl;
            return 0;

        default:
            cout << "Некорректный номер задания." << endl;
            break;
        }
        cout << "Задание выполнено. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}
// 4 лаба
unsigned my_str_len(char* S)
{
    unsigned L = 0;
    while (S[L])
        ++L;
    return L;
}
void keyboard_input(char* text, int N) {
    cin.getline(text, N, '.');
    int len_of_sequence = my_str_len(text);
    for (int j = 0; j < len_of_sequence; j++) {
        text[j] = text[j + 1];
    }
    --len_of_sequence;
    cin.sync();

}

void input_from_file(char* text) {
    ifstream File;
    File.open("text.txt");
    if (!File.is_open()) {
        cout << "" << endl;
    }
    File.read((char*)text, sizeof(text));
    File.close();
}
void print_result(char* text, int N) {
    for (int i = 0; i < N; ++i)
        cout << text[i];
    cout << endl;
}

void delete_space(char* text, int N) {
    for (int i = 0; i < N; ++i) {
        if (text[i] == ' ' and text[i + 1] == ' ') {
            while (text[i + 1] == ' ') {
                for (int j = i + 1; j < N; j++) {
                    text[j] = text[j + 1];
                }
                --N;
            }

        }
    }
}
void delete_punctuation(char* text, int N) {
    for (int i = 0; i < N; ++i) {
        if (ispunct(text[i]) and ispunct(text[i + 1])) {
            if (text[i] == '.' and text[i + 1] == '.' and text[i + 2] == '.' and not ispunct(text[i + 3])) {
                i += 3;
            }
            else {
                while (ispunct(text[i + 1])) {
                    for (int j = i + 1; j < N; j++) {
                        text[j] = text[j + 1];
                    }
                    --N;
                }
            }
        }
    }

}
void make_lower(char* text, int N) {
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            text[i] = toupper(text[i]);
        }
        else if (text[i - 1] == ' ' and isalpha(text[i])) {
            text[i] = toupper(text[i]);
        }
        else {
            text[i] = tolower(text[i]);
        }
    }
}
void correctLetterCase(char* text) {
    for (int i = 0; i < my_str_len(text); i++) {
        if (isalpha(text[i]) && (i == 0 || text[i - 1] == ' ')) {
            text[i] = toupper(text[i]);
        }
        else {
            text[i] = tolower(text[i]);
        }
    }
}
void how_many_symbols_in_word(char* text, int N) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (text[i] != ' ' && text[i] != '\0') {
            cout << text[i];
            counter += 1;
        }
        else {
            cout << " - " << counter << endl;
            counter = 0;
        }
    }
}
int linear_search(char* text, char pattern[], int N) {
    int pattern_len = my_str_len(pattern);
    for (int i = 0; i <= N - pattern_len; ++i) {
        int j;
        for (j = 0; j <= pattern_len; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern_len) {
            return i;
        }
    }
    return -1;
}
void prepare_table(const char* pattern, int pattern_len, int table[256]) {
    for (int i = 0; i < 256; i++) {
        table[i] = pattern_len;
    }
    for (int i = 0; i < pattern_len - 1; i++) {
        table[(unsigned char)pattern[i]] = pattern_len - i - 1;
    }
}
int Boyer_Moore_algorithm(char* text, char pattern[], int N, int* table) {
    int pattern_len = my_str_len(pattern);
    int text_len = my_str_len(text);
    prepare_table(pattern, pattern_len, table);
    int j, k;

    int i = pattern_len - 1;
    while (i < text_len) {
        int j = pattern_len - 1;
        int k = i;

        while (j >= 0 && k >= 0 && text[k] == pattern[j]) {
            k--;
            j--;
        }

        if (j < 0) {
            return k + 1;
        }
        i += table[(unsigned char)text[i]];
    }

    return -1;
}
int organize_words(char* text, char words[][10]) {
    int i = 0, word_len = 0, count = 0;
    while (text[i] != '\0' && count < 50) {
        if (text[i] == ' ' || text[i + 1] == '\0') {
            if (word_len > 0) {
                words[count][word_len] = '\0';
                count++;
                word_len = 0;
            }
        }
        else {
            words[count][word_len] = text[i];
            word_len++;
        }
        i++;
    }
    return count;
}
void swap_words(char words[][10], int j) {
    char temp[10];
    int k = 0;
    while (words[j][k] != '\0' && k < 10) {
        temp[k] = words[j][k];
        k++;
    }
    temp[k] = '\0';
    k = 0;
    while (words[j - 1][k] != '\0' && k < 10) {
        words[j][k] = words[j - 1][k];
        k++;
    }
    words[j][k] = '\0';
    k = 0;
    while (temp[k] != '\0' && k < 10) {
        words[j - 1][k] = temp[k];
        k++;
    }
    words[j - 1][k] = '\0';
}
void sort_alphabetically(char words[][10], int count) {
    int c = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = count - 1; j > i; j--) {
            if (words[j][0] < words[j - 1][0]) {
                swap_words(words, j);
            }
            else if (words[j][0] == words[j - 1][0]) {
                while (words[j][c] == words[j - 1][c]) {
                    c++;
                }
                if (words[j][c] < words[j - 1][c]) {
                    swap_words(words, j);
                }

            }
        }
    }
}
void display_menu_of_laba4() {
    cout << "Выберите действие:" << endl;
    cout << "1. Выберите откуда брать последовательность." << endl;
    cout << "2. Необходимо отредактировать входной текст." << endl;
    cout << "3. Вывести на экран слова последовательности в алфавитном порядке." << endl;
    cout << "4. Вывести на экран количество символов в каждом слове исходной последовательности." << endl;
    cout << "5. Необходимо найти все подстроки, которую введёт пользователь в имеющейся строке." << endl;
    cout << "6. Алгоритм Бойера-Мура" << endl;
    cout << "7. Возвращаемся в основное меню." << endl;
}

int main_of_laba4()
{
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int identificator, num1, num2, n, len_of_sequence, result, count, index;
    const int N = 600;
    char sequence[N] = { ' ' }, pattern[30], pattern1[30], words[50][10];
    int table[256];
    while (true) {
        display_menu_of_laba4();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> identificator;
        switch (identificator) {
        case 1:
            cout << "Выберите ввод:" << endl;
            cout << "1. С клавиатуры." << endl;
            cout << "2. Из файла." << endl;
            cin >> num1;
            cout << endl;
            switch (num1) {
            case 1:
                keyboard_input(sequence, N);
                sequence[my_str_len(sequence)] = ' ';
                sequence[my_str_len(sequence) + 1] = '\0';
                break;
            case 2:
                const char* filePath = "C:/laba4/ladna.txt";
                ifstream file(filePath, ios::in);
                if (!file.is_open()) {
                    cout << "Файл не открывается!!!!! \n";
                    return -1;
                }
                file.read((char*)sequence, sizeof(sequence));
                file.close();
                break;
            }
            cout << my_str_len(sequence) << endl;
            print_result(sequence, my_str_len(sequence));
            break;
        case 2:
            cout << "Измененный текст, очищенный от пробелов, знаков препинания и неправильного регистра" << endl;
            delete_space(sequence, my_str_len(sequence));
            delete_punctuation(sequence, my_str_len(sequence));
            make_lower(sequence, my_str_len(sequence));
            cout << my_str_len(sequence) << endl;
            print_result(sequence, my_str_len(sequence));
            break;
        case 3:
            cout << "Отсортированные по алфавиту слова:" << endl;
            count = organize_words(sequence, words);
            sort_alphabetically(words, count);
            for (int i = 0; i < count; i++) {
                cout << words[i] << " ";
            }
            break;
        case 4:
            cout << "Вывести на экран количество символов в каждом слове исходной последовательности." << endl;
            how_many_symbols_in_word(sequence, my_str_len(sequence));
            break;
        case 5:
            system("cls");
            cout << "Введите слово для линейного поиска" << endl;
            cin.clear();
            cin.sync();
            keyboard_input(pattern, my_str_len(pattern));
            result = linear_search(sequence, pattern, my_str_len(sequence));
            if (result == -1) {
                cout << "Нет таких слов в последовательности" << endl;
            }
            else {
                cout << "Есть такая подстрока,начиная с индекса " << result << endl;
            }
            break;
        case 6:
            system("cls");
            cout << "Введите слово для поиска" << endl;
            cin.clear();
            cin.sync();
            keyboard_input(pattern1, my_str_len(pattern1));
            index = Boyer_Moore_algorithm(sequence, pattern1, my_str_len(sequence), table);
            if (index != -1) {
                cout << "Первое вхождение найдено на индексе: " << index << endl;
            }
            else {
                cout << "Шаблон не найден." << endl;
            }
            break;
        case 7:
            cout << "Возвращаемся в основное меню!" << endl;
            return 0;

        default:
            cout << "Некорректный номер задания." << endl;
            break;
        }
        cout << "Задание выполнено. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}
void display_1_menu() {
    cout << "Введите действие: " << endl;
    cout << "1. 1 лаба" << endl;
    cout << "2. 2 лаба" << endl;
    cout << "3. 3 лаба" << endl;
    cout << "4. 4 лаба" << endl;
}
int main() {
    int i;
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        display_1_menu();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> i;
        switch (i) {
        case 1:
            system("cls");
            main_of_laba1();
            break;
        case 2:
            system("cls");
            main_of_laba2();
            break;
        case 3:
            system("cls");
            main_of_laba3();
            break;
        case 4:
            system("cls");
            main_of_laba4();
            break;
        case 5:
            cout << "Выход!" << endl;
            return 0;

        default:
            cout << "Некорректный номер работы." << endl;
            break;
        }
        cout << "Работа выполнена. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;

}