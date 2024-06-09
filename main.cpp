#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//1. Предусмотреть вывод информации о выбранной ветви вычислений.
void task1(){
    double x, y, f, b;
    int k;
    cout << "Vvedite x: "; cin >> x;
    cout << "Vvedite y: "; cin >> y;
    cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 – exp(x): "; cin >> k;

    switch(k)
    {
        case 1: f=sinh(x); break;
        case 2: f=pow(x,2); break;
        case 3: f=exp(x); break;
        default: f=sinh(x);
    }

    if (y > 2 * x){
        b = tan(x) + pow(f, 2);
    } else if(y < 2 * x){
        b = pow(fabs(f + y), 3);
    } else{
        b  = pow(x, 1 / 3) * sin(x);
    }

    cout<<"RESULT = : " << b << endl;
}

//2. Даны два целых числа: D (день) и M (месяц), определяющие правильную дату
//невисокосного года. Вывести значения D и M для даты, следующей за указанной.
void task2(){
    int day, month;

    cout<< "Enter day: "; cin >> day;
    cout<< "Enter month: "; cin >> month;

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        if (day <= 31 && day >= 1) {
            if (day == 31) {
                day = 1;
                if (month != 12) {
                    month++;
                } else {
                    month = 1;
                }
            } else {
                day++;
            }
        } else{
            cout << "Wrong day: " << day << endl;
            return;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day <= 30 && day >= 1){
            if (day == 30){
                day = 1;
                month++;
            } else{
                day++;
            }
        } else{
            cout << "Wrong day: " << day << endl;
            return;
        }
    } else if (month == 2){
        if (day <= 28 && day >= 1) {

            if (day == 28) {
                day = 1;
                month++;
            } else {
                day++;
            }
        } else{
            cout << "Wrong day: " << day << endl;
            return;
        }
    } else{
        cout << "Enter wrong month: " << month << endl;
        return;
    }
    cout << "Day = " << day;
    cout << " Month = " << month;

}

//3. Вывести на экран таблицу значений функции Y(x) и ее разложения в ряд S(x) для x,
//изменяющегося от a до b с шагом h = (b – a)/10.
void task3(){
    double a = 0.1, b = 1.0 ,h,x,y,s,k;
    int n = 8,i;
    x=a;
    h=(b-a)/10;
    while (x<=b)
    {
        s = 0;
        k=1;
        y= 2 * (pow(cos(x),2) - 1);
        for (i=1; i<=n; i++)
        {
            k*=2*i;
            s += pow(-1,i)*(pow(2 * x, 2 * i)) / k;
        }
        cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
        x += h;
    }
}

//4. Дано целое число N (> 0). Используя операции деления нацело и взятия остатка от
//деления, найти количество и сумму его цифр.
void task4(){
    int n, sum = 0, count = 0;
    cout << "Enter integer: "; cin >> n;
    if (n <= 0) return;
    while(n >= 1){
        sum += n % 10;
        count++;
        n= (n - n % 10) / 10;

    }
    cout << "Sum of numbers: " << sum << endl;
    cout << "Count of numbers: " << count << endl;
}

//Дано целое число N (> 0). Найти произведение 1.1 · 1.2 · 1.3 · … (N сомножителей).
void task5(){
    int n;
    double a = 1.1, sum = a;
    cout << "Enter integer: "; cin >> n;
    if (n <= 0) return;
    for (int i = 0; i < n; ++i) {
        a += 0.1;
        sum *= a;
    }
    cout << "RESULT: " << sum << endl;
}

int main() {
    task1();
//    task2();
//    task3();
//    task4();
//    task5();
    return 0;
}


