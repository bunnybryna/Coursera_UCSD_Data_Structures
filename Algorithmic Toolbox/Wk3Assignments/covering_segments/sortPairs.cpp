#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int> > circles;

int main()
{
int n,s,d;
cout << "insert the size of the vector " << endl;
cin >> n;
cout << "insert the size and the dots of each circle" << endl;
for (int i=0;i<n;i++)
{
    cin >> s >> d;
    circles.push_back(make_pair(s,d));
}
sort(circles.begin(),circles.end());

for (int i=0;i<n;i++)
{
    cout << circles[i].first << " " << circles[i].second;
    cout << endl;
}
return 0;

}
