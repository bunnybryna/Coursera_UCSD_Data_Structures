#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
    int digit1=0;
    int digit2=1;
    int i=2;
    while (i<n+1)
    {
        int digit3;
        digit3=(digit1+digit2)%10;
        digit1=digit3;
        digit2=(digit2+digit3)%10;
        //std::cout <<"now d1 is " << digit1 << " d2 is " << digit2 << "\n";
        i=i+2;
    }
    if (n%2==0)
        return digit1;
    else
        return digit2;
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit_fast(n);
    //std::cout << c << '\n';
    std::cout << d << "\n";
    }
