#include <iostream>
#include <vector>

using std::vector;

vector<int> get_number_of_inversions(vector<int> &a, size_t left, size_t right, long long &inversionsNum);
vector<int> mergeAndCount(vector<int> left, vector<int> right, long long &inversions);
void print(vector<int> v);


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long number = 0;
  vector<int> b(a.size());
  b = get_number_of_inversions(a, 0, a.size(), number);
  std::cout << number<< '\n' ;
}

void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}

vector<int> get_number_of_inversions(vector<int> &a, size_t left, size_t right, long long &inversionsNum) {
  if (right <= left + 1)
      return a;
  else
  {
      size_t ave = (a.size()+1) / 2;
      vector<int> m,n, result;
      for (int i = 0; i < ave; i++)
        {
          m.push_back(a[i]);
        }
      for (int i = ave; i < a.size(); i++)
        {
          n.push_back(a[i]);
        }
      long long inv1=0,inv2=0,inv3=0;
      m = get_number_of_inversions(m, 0, ave, inv1);
      n = get_number_of_inversions(n, ave,a.size(),inv2);
      result = mergeAndCount(m, n, inv3);
      inversionsNum = inversionsNum + inv1 + inv2 + inv3;
      return result;
  }
}

// mergeAndCount is checked
vector<int> mergeAndCount(vector<int> left, vector<int> right, long long &inversions)
{
    vector<int> finalMerge;
    while (left.size()>0 && right.size()>0)
    {
        if (left.front()<=right.front())
        {
            // same as finalMerge.push_back(left[0])
            finalMerge.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            finalMerge.push_back(right.front());
            // count only happens when a number from right side is put in the sorted array
            // how many left in left when that happen => how many bigger number exist
            inversions = inversions + left.size();
            right.erase(right.begin());
        }
    }
    if (left.size()==0)
    {
        for (int i=0;i<right.size();i++)
        {
            finalMerge.push_back(right[i]);
        }
        right.clear();
    }
    else
    {
        for (int i=0;i<left.size();i++)
        {
            finalMerge.push_back(left[i]);
            // when right.size=0, all numbers on the left side that are left are big ones, need to be counted as inversions
        }
        left.clear();
    }
    return finalMerge;
}
