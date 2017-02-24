#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long mod1 = 0;
    long long mod2 = 1;
    long long i=2;
    // use a vector instead of array to save memory
    // especially when n is huge, fibModArray[] will use up a lot of memory
    std::vector<long long> fibModVec;
    fibModVec.push_back(mod1);
    fibModVec.push_back(mod2);
    while (i<n+1)
    {
        mod1 = (long long)(mod1+mod2)%m;
        fibModVec.push_back(mod1);
        mod2 = (long long)(mod1+mod2)%m;
        fibModVec.push_back(mod2);
        // to find the Pisano period
        // when never 0&1 occurs, a new cycle starts
        if ((mod1==0)&&(mod2==1))
        {
            break;

        }
        // need to consider 1&0  
        else if (mod2==0)
        {
            long long mod3 = (long long)(mod1+mod2)%m;
            if (mod3==1)
            {
                i++;
                break;
            }
        }
        i=i+2;
    }
    long long cycle = i;
    long long mod = (long long)n%cycle;
    return (fibModVec[mod]);
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
