#include <iostream>
#include <vector>

using std::vector;

vector<int> mergeSort(vector<int> &a, int start, int end);
vector<int> merge(vector<int> left, vector<int> right);
/*
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}*/

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> final=mergeSort(a,0,a.size());
  for (size_t i = 0; i < final.size(); i++) {
    std::cout << final[i];
  }
}

vector<int> mergeSort(vector<int> &a, int start, int end)
{
    if (end <= start+1)
    {
        return a;
    }
    else
    {
        vector<int> b,c,result;
        int ave = (a.size()+1)/2;
        for (int i = 0; i < ave; i++) 
        {
          b.push_back(a[i]);
        }
        for (int i = ave; i < a.size(); i++) 
        {
          c.push_back(a[i]);
        } 
        b = mergeSort(b, 0, ave);
        c = mergeSort(c, ave, a.size());
        result = merge(b,c);
        return result;
    }
}

vector<int> merge(vector<int> left, vector<int> right)
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
        }
        left.clear();
    }
    return finalMerge;
}
