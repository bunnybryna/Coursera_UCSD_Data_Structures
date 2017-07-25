#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::string a="393";
    for (int i=0;i<a.length();i++)
    {
        std::cout << a[i] << std::endl;
    }
    // a.length+1
    int digit[3];
    std::string buffer;
    for (int i=0;i<=2;i++)
    {
        buffer = a[i];
        int value = atoi(buffer.c_str());
        digit[i]=value;
        std::cout << digit[i] << std::endl;
    }
    return 0;
}
