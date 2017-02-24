#include <iostream>
#include <vector>
#include <cmath>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci60_lastDigit(int n)
{
    std::vector<int> fib60Vec;
    int mod1 = 0;
    int mod2 = 1;
    fib60Vec.push_back(mod1);
    fib60Vec.push_back(mod2);
    int i=2;
    while (i<n+1)
    {
        mod1 = (mod1+mod2)%10;
        fib60Vec.push_back(mod1);
        mod2 = (mod1+mod2)%10;
        fib60Vec.push_back(mod2);
        i = i+2;
    }
    return fib60Vec[n];
}

int fibonacci_sum_fast(long long n)
{

    // fibonacci feature: the last digit cycles every 60 numbers
    long long nNew = (long long)(n+2)%60;
    //std::cout << "nNew is " << nNew << "\n";
    int nInt = (int)nNew;
    //Sn = F(n+2)-1
    int lDigit = fibonacci60_lastDigit(nInt) ;
    if ( lDigit>=1 )
        return lDigit-1;
    else
        return 9;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
