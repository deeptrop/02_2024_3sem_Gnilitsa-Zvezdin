#include <iostream>
#include <cmath>
bool is_prime(int num) {
    if (num<=1) { return false;}

    for (int i=2; i<=sqrt(num); i++)
    { 
        if (num%i == 0)
            return false;
    }
    return true;
}
int main() 
    {
        int num;
        std:: cin >> num;
        // выделяем память для массива 
        int *primes = new int[num]; // n - количесвто элементов в массиве 
        int count = 0; //счетчик простых чисел 
        for (int i=2; i<num; i++)
        { 
            if (is_prime(i) == true)
            {
                primes[count] == i;
                count++;
                std::cout << i << " ";
            }
            else {
            }
            
        }
        for (int i=0; i < count; i++)
        {   
            std::cout << primes[i] << " " ;
            
            
        }  
        delete[] primes;  // Освобождаем память, выделенную для массива
    }