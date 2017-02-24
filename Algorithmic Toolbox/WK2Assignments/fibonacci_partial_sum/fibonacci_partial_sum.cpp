#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
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

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    if (from == to)
    {
        int fNew = (int)((long long)(from%60));
        int digit = fibonacci60_lastDigit(fNew);
        return digit;
    }
    else
    {
        //S(t)-S(f-1)=F(t+2)-F(f+1)
        int fNew =(int)((long long)(from+1)%60);
        int tNew =(int)((long long)(to+2)%60);
        int fDigit = fibonacci60_lastDigit(fNew);
        int tDigit = fibonacci60_lastDigit(tNew);
        if (tDigit >= fDigit)
            return (tDigit-fDigit);
        else
            return (10+tDigit-fDigit);
    }

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << "\n";
    return 0;
}
