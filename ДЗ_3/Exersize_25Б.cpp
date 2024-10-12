#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//типы функции 
typedef int(*FuncPtr)(int, int);
int substr(int , int );
int sum(int , int );
int sum(int a, int b)
{
    return a+b;
}

int substr(int a, int b)
{
    return a-b;
}

int division(int a, int b)
{
    return a/b;
}

int multi(int a, int b)
{
    return a*b;
}

int power(int a, int b)
{
    int result=1;
    for (int i=0; i<b; i++)
    {
        result*=a;
    }
    return result;
}

int max_v(int a, int b)
{
    if (a<b) return b;
    else return a;
}

int min_v (int a, int b)
{
    if (a<b) return a;
    else return b;
}
//компаратор
bool compare(pair<int, FuncPtr> left, pair<int, FuncPtr> right)
{
    return left.first < right.first;
    
}

string get_name(FuncPtr f)
{
    if (f == sum)
        return "сумма";
    if (f == substr)
        return "разница";
    if (f == division)
        return "деление";
    if (f == multi)
        return "умножение";
    if (f == power)
        return "степень";
    if (f == max_v)
        return "макс значение";
    if (f == min_v)
        return "минимальное значение";
    else return "0";
}




int main()
{
    setlocale(LC_ALL, "Russian");
    int a; 
    int b;
    
    cout << "введите значение a и b через пробел" ;
    cin >> a >> b ;
    cout << a << " " << b ;
    
    FuncPtr NUMPY[7] = {min_v, max_v, power, multi, division, substr, sum}; // создание массива из указателей на функции
    
    vector<pair<int, FuncPtr>> results; // создание вектора 
    for (int i=0; i<7; i++ )
    {
        results.emplace_back(NUMPY[i](a,b),NUMPY[i]); // заполнение вектора 
    }
    
    sort(results.begin(), results.end(),compare); // сортировка вектора 
    for (const auto& res : results)
{
    cout << "\t" << get_name(res.second) << ": " << res.first << endl;
}
}
