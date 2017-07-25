#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right);
std::map<int,int> get_majority(vector<int> &a);
int majority(std::map<int,int>m);

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << "Final result is " <<(get_majority_element(a, 0, a.size()-1)) << '\n';
}



int get_majority_element(vector<int> &a, int left, int right) {
  vector<int> aLeft, aRight;
  int mid;
  if (a.size()%2==0)
  {
    mid = a.size()/2;
  }
  else
  {
    mid = (a.size()+1)/2;
  }

  for (int i=0;i<mid;i++)
  {
        aLeft.push_back(a[i]);
  }
  for (int i=mid;i<a.size();i++)
  {
        aRight.push_back(a[i]);
  }
  std::map<int,int> countLeft, countRight;
  countLeft = get_majority(aLeft);
  countRight = get_majority(aRight);
  int leftMJ = majority(countLeft);
  int rightMJ = majority(countRight);
  std::cout << "leftMJ is " << leftMJ << "rightMJ" << rightMJ << std::endl;
  if ((leftMJ == 0) && (rightMJ == 0))
  {
      return 0;
  }
  else
  {
    int left, right;
    left = countLeft[leftMJ] + countRight[leftMJ];
    right = countLeft[rightMJ] + countRight[rightMJ];
    if (left > a.size()/2)
    {
        return 1;
    }
    else if(right > a.size()/2)
    {
        return 1;
    }
    else
        return 0;
  }
}

std::map<int,int> get_majority(vector<int> &a)
{
    std::map<int,int> countElement;
    for (size_t i=0;i<a.size();i++)
    {
        if (countElement.find(a[i]) == countElement.end())
        {
            countElement[a[i]]= 1;
        }
        else
        {
            countElement[a[i]]=countElement[a[i]]+1;
        }
    }
    for (std::map<int,int>::iterator it=countElement.begin();it != countElement.end();it++)
    {
         std::cout <<  it->first << "=>" << it->second << std::endl;
    }
    return countElement;
}

int majority(std::map<int,int>m)
{
    for (std::map<int,int>::iterator it=m.begin();it != m.end();it++)
    {
        if ((it->second) > m.size()/2)
        {
            return (it->first);
        }
    }
    return 0;

}
