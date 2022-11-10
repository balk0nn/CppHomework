#include<iostream>
#include<cmath>
#include <experimental/random>

using namespace std;

//Рассчитывает площадь трапеции(Задача 1)
float area(float b1, float b2, float h) {
    return ((b1 + b2) / 2) * h;
}

//Рассчитывает площадь круга(Задача 2)
float circlearea(float r) {
    return M_PI * r * r;
}

//Рассчитывает длину окружности(Задача 2)
float circumference(float r) {
    return 2 * M_PI * r;
}

//Вычисляет площадь прямоугольного треугольника(Задача 3)
float trianglearea(float a, float b) {
    return a * b / 2;
}

//Вычисляет гипотенузу(Задача 3)
float hypothenuse(float a, float b) {
    return sqrt(a * a + b * b);
}

//Считает сумму цифр числа(Задача 3)
int sumofdigits(int a) {
    int sum = 0;
    //Прибавляем к sum последнюю цифру и отбрасываем ее, пока число не занулится
    while (a != 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

//Возвращает полярный радиус(Задача 5)
float radius(float x, float y) {
    return hypothenuse(x, y);
}

//Возвращает полярный угол(азимут)(Задача 5)
float azimut(float x, float y) {
    float angle;
    //Отдельно обрабатывается каждый случай знаков координат
    if (x == 0) {
        if (y == 0) {
            angle = 0;
        }
        if (y > 0) {
            angle = 3 * M_PI / 2;
        } else {
            angle = M_PI / 2;
        }
    }
    if (x < 0) {
        angle = atan(y / x) + M_PI;
    } else {
        angle = atan(y / x);
    }
    return angle;
}

//Возращает абсциссу точки на основании полярных координат(Задача 6)
float absciss(float r, float fi) {
    return r * cos(fi);
}

//Возращает ординату точки на основании полярных координат(Задача 6)
float ordinate(float r, float fi) {
    return r * sin(fi);
}

//Возвращает больший корень квадратного уравнения(Задача 7)
float biggerRoot(float a, float b, float c) {
    //Дискриминант квадратного уравнения
    float d = b * b - 4 * a * c;
    return (-b + sqrt(d)) / (2 * a);
}

//Возвращает меньший корень квадратного уравнения(Задача 7)
float smallerRoot(float a, float b, float c) {
    //Дискриминант квадратного уравнения
    float d = b * b - 4 * a * c;
    return (-b - sqrt(d)) / (2 * a);
}

//Выводит корни квадратного уравнения
void printRoots(float a, float b, float c) {
    float d = b * b - 4 * a * c;
    if (d > 0) {
        cout << " The roots of this quadratic equation are" << smallerRoot(a, b, c) << " and " << biggerRoot(a, b, c)
             << "\n";
    }
    if (d == 0) {
        cout << "This quadratic only has a single real solution, which is " << smallerRoot(a, b, c) << "\n";
    }
    if (d < 0) {
        cout << "This quadratic has no real roots\n";
    }
}

//Возвращает число полных прошедших часов к k-ой секунде суток(Задача 9)
int hours(int k) {
    if (k > 86399) {
        k /= 86400;
    }
    return k / 3600;
}

//Возвращает число полных прошедших минут к k-ой секунде суток(Задача 9)
int minutes(int k) {
    if (k > 86399) {
        k /= 86400;
    }
    return (k - hours(k) * 3600) / 60;
}

//Определяет является ли треугольник равнобедренным(Задача 10)
bool isIsosceles(float a, float b, float c) {
    //Сначала необходимо проверить может ли существовать треугольник с такими сторонами
    if ((a < b + c) and (b < a + c) and (c < a + b)) {
        //Затем уже проверить равенство любых 2-х сторон
        if ((a == b) or (b == c) or (a == c)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//Если стоимость > 1000, скидываем 10 %(Задача 11)
float getPrice(float n) {
    if (n > 1000) {
        return 0.9 * n;
    } else {
        return n;
    }
}

//Выясняем стоит ли индивиду с данными ростом и весом худеть или набирать вес и выводим нужный совет(Задача 12)
void advice(int height, int weight) {
    int a = height - weight;
    if (a == 100) {
        cout << "You shouldn't change your weight \n";
    } else if (a > 100) {
        cout << "You should gain some weight \n";
    } else {
        cout << "You should lose some weight \n";
    }
}

//Пусть одна секунда разговора стоит 1 денежную единцу
//Рассчитаем стоимость разговора с учетом скидки в выходные(Задача 14)
int fee(int time, int day) {
    //На случай если поступит число больше семи
    if (day > 7) {
        day %= 7;
    }
    if (day < 6) {
        return time;
    } else {
        return time * 0.8;
    }
}

//Выводим информацию о названии месяца и времени года по номеру месяца
void monthInfo(int n) {
    //Сначала обрабатываем случаи когда номер месяца не входит в отрезок [1; 12]
    if (n < 1) {
        n = 12 - abs(n) % 12;
    }
    if (n > 12) {
        n %= 12;
    }
    //Затем выводим нужное сообщение в зависимости от номера месяца
    switch (n) {
        case 1:
            cout << "January, Winter\n";
            break;
        case 2:
            cout << "February, Winter\n";
            break;
        case 3:
            cout << "March, Spring\n";
            break;
        case 4:
            cout << "April, Spring\n";
            break;
        case 5:
            cout << "May, Spring\n";
            break;
        case 6:
            cout << "June, Summer\n";
            break;
        case 7:
            cout << "July, Summer\n";
            break;
        case 8:
            cout << "August, Summer\n";
            break;
        case 9:
            cout << "September, Fall\n";
            break;
        case 10:
            cout << "October, Fall\n";
            break;
        case 11:
            cout << "November, Fall\n";
            break;
        case 12:
            cout << "December, Winter\n";
            break;
    }
}

//Проверка на "Счастливость числа"(Задача 16)
bool isHappy(int a) {
    int b = a % 1000;
    a /= 1000;
    return sumofdigits(a) == sumofdigits(b);
}

//Правильная форма слова копейка(Задача 17)
string kopeika(int n) {
    if (11 <= n and n <= 20) {
        return "Kopeek\n";
    }
    if (2 <= n % 10 and n % 10 <= 4) {
        return "Kopeyki\n";
    }
    if ((n % 10 == 1) and (n != 11)) {
        return "Kopeyka\n";
    } else {
        return "Kopeek\n";
    }
}

//Определяем, является ли число палиндромом(Задача 18)
bool isPalindrome(long n) {
    int a = 0;
    long b = n;
    //Разворачиваем число n
    while (b != 0) {
        a = a * 10 + b % 10;
        b /= 10;
    }
    //Если n и его отражение равны, то n - палиндром
    return a == n;
}

//Возвращает произведение цифр числа(Для задачи 19)
int productOfDigits(int a) {
    int product = 1;
    while (a != 0) {
        product *= a % 10;
        a /= 10;
    }
    return product;
}

//Определяем является ли произведение цифр числа а больше числа b
bool isProductOfDigitsBigger(int a, int b) {
    return productOfDigits(a) > b;
}

//Выясняем кратна ли сумма цифр числа семи
bool isDivisibleBySeven(int n) {
    return sumofdigits(n) % 7 == 0;
}

//Можно ли поместить прямоугольник со сторонами a, b в прямоугольник со сторонами c, d
bool canItFitIn(float a, float b, float c, float d) {
    return ((min(a, b) < min(c, d)) and (max(a, b) < max(c, d)));
}

//Получим медиану треугольника к стороне MainSide
float getMedian(float MainSide, float b, float c) {
    return sqrt(2 * b * b + 2 * c * c - MainSide * MainSide) / 2;
}

/*
Здесь находится цикл, позволяющий решать задачу по введенному номеру, в конце цикла пользователю
предлагается снова ввести номер задачи, которую он хочет решить, либо 0, чтобы закончить
*/
int main() {
    int k(34);
    cout << "Enter the number of the task you want to solve(1 - 20)\n"
            "Enter any other number to leave\n";
    cin >> k;
    while (1 <= k and k <= 20) {
        switch (k) {
            case 1:
                float b1, b2, h;
                cout << "Enter the first base of the trapezoid\n";
                cin >> b1;
                cout << "Enter the second base of the trapezoid\n";
                cin >> b2;
                cout << "Enter the height of the trapezoid\n";
                cin >> h;
                cout << "The area of the trapezoid is " << area(b1, b2, h) << "\n";
                break;
            case 2:
                float r;
                cout << "Enter the readius of the circle \n";
                cin >> r;
                cout << "The circumference is " << circumference(r) << "\n";
                cout << "The area of the circle is " << circlearea(r) << "\n";
                break;
            case 3:
                float a, b;
                cout << "Enter the first cathetus\n";
                cin >> a;
                cout << "Enter the second cathetus\n";
                cin >> b;
                cout << "The lenght of the hypothenuse is " << hypothenuse(a, b) << "\n";
                cout << "The area of the triangle is " << trianglearea(a, b) << "\n";
                break;
            case 4:
                int n;
                cout << "Enter an integer number \n";
                cin >> n;
                cout << "The sum of this number's digits is " << sumofdigits(n) << "\n";
                break;
            case 5:
                float x, y;
                cout << "Enter the 'x' coordinate \n";
                cin >> x;
                cout << "Enter the 'y'coordinate \n";
                cin >> y;
                cout << "In polar coordinates this vector would be (" << radius(x, y) << ", " << azimut(x, y) << ")\n";
                break;
            case 6:
                float r1, fi;
                cout << "Enter the radius \n";
                cin >> r1;
                cout << "Enter the azimut \n";
                cin >> fi;
                cout << "In cartesian coordinates this vector would look like (" << absciss(r1, fi) << ", "
                     << ordinate(r1, fi) << "\n";
                break;
            case 7:
                float a2, b4, c1;
                cout << "Enter the coefficient in front of 'x^2' (Must be nonzero) \n";
                cin >> a2;
                cout << "Enter the coefficient in front of 'x' \n";
                cin >> b4;
                cout << "Enter the free coefficient \n";
                cin >> c1;
                printRoots(a2, b4, c1);
                break;
            case 8:
                float d1, f1, e1, d12, d13, f12, f13, e12, e13;
                cout << "Enter the sides of the triangle separated by a space \n";
                cin >> d1 >> f1 >> e1;
                //Находим все медианы исходного треугольника
                d12 = getMedian(d1, f1, e1);
                f12 = getMedian(f1, d1, e1);
                e12 = getMedian(e1, d1, f1);
                //Затем находим все медианы нового треугольника
                d13 = getMedian(d12, f12, e12);
                f13 = getMedian(f12, d12, e12);
                e13 = getMedian(e12, d12, f12);
                cout << "Medians of the triangle made of medians of the given triangle are: " << d13 << ", " <<
                     f13 << ", " << e13 << "\n";
                break;
            case 9:
                int k1;
                cout << "What second of the day it is ? \n";
                cin >> k1;
                cout << "Your loacal time is " << hours(k1) << ":" << minutes(k1) << "\n";
                break;
            case 10:
                float a3, b5, c2;
                cout << "Enter the sides of the triangle separated by a space \n";
                cin >> a3 >> b5 >> c2;
                (isIsosceles(a3, b5, c2)) ? cout << "This triangle is Isosceles \n" : cout
                        << "This triangle is NOT Isosceles\n";
                break;
            case 11:
                float n1;
                cout << "Enter the total cost of your purchase \n";
                cin >> n1;
                cout << "The final cost of your purchase is " << getPrice(n1) << "\n";
                break;
            case 12:
                int height, weight;
                cout << "Enter your height \n";
                cin >> height;
                cout << "Enter your weight \n";
                cin >> weight;
                advice(height, weight);
                break;
            case 13: {
                int rand1 = experimental::randint(1, 9), rand2 = experimental::randint(1, 9);
                int answer;
                int product = rand1 * rand2;
                cout << "What does " << rand1 << "*" << rand2 << " equal to? \n";
                cin >> answer;
                (product == answer) ? cout << "Correct\n" : cout << "Incorrect\n";
                break;
            }
            case 14:
                int time, day;
                cout << "Enter the amount of time you spent in a phone call\n";
                cin >> time;
                cout << "Enter the day of the week this call was made\n"
                        "(The number 1 - 7)\n";
                cin >> day;
                cout << "The call costs you " << fee(time, day) << "\n";
                break;
            case 15:
                int month;
                cout << "Enter the number of the month \n";
                cin >> month;
                monthInfo(month);
                break;
            case 16:
                int n3;
                cout << "Enter the number you want to check for it's luck \n";
                cin >> n3;
                (isHappy(n3)) ? cout << "This number is 'Lucky'\n" : cout << "This number is nothing special...\n";
                break;
            case 17:
                int kopeyka;
                cout << "Enter the number from 1 to 99\n";
                cin >> kopeyka;
                cout << "U vas " << kopeyka << " " << kopeika(kopeyka) + "\n";
                break;
            case 18:
                long n2;
                cout << "Enter an integer number \n";
                cin >> n2;
                (isPalindrome(n)) ? cout << n2 << " is a Palindrome\n" : cout << n2 << " is not a Palindrome\n";
                break;
            case 19:
                int num1, num2;
                cout << "Enter two numbers separated by a space\n";
                cin >> num1 >> num2;
                (productOfDigits(num1) > num2) ? cout << "Product of digits of " << num1 << " is bigger than " << num2
                                                      << "\n"
                                               : cout << "Product of digits of " << num1 << " is not bigger than "
                                                      << num2 << "\n";
                (isDivisibleBySeven(num1)) ? cout << "Sum of digits of " << num1 << " is divisible by 7\n"
                                           : cout << "Sum of digits of " << num2 << " is not divisible by 7\n";
                break;
            case 20:
                float a1, b3, c, d;
                cout << "Enter the sides of the first rectangle separated by a space\n";
                cin >> a1 >> b3;
                cout << "Enter the sides of the second rectangle separated by a space\n";
                cin >> c >> d;
                (canItFitIn(a1, b3, c, d)) ? cout << "The first rectangle can fit in the second rectangle\n"
                                           : cout << "The first rectangle can't fit in the second rectangle\n";
                break;
        }
        cout << "Enter the number of the task you want to solve(1 - 20)\n"
                "Enter any other number to leave\n";
        cin >> k;
    }
    return 0;
}