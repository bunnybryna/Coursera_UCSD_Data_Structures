#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right);
vector<int> mergeAndCount(vector<int> left, vector<int> right, long long &inversions);
void print(vector<int> v);


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  /*for (size_t i = 0; i < b.size(); i++) {
    std::cin >> b[i];
  }
  long long number = 0;
  c = mergeAndCount(a,b,number);
  print(c);
  std::cout << number << std::endl;*/
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  std::cout << "After sorted it's";
  for (size_t i = 0; i < b.size(); i++) {
    std::cout << b[i];
  }
}

void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1)
      return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  vector<int> c,d;
  for (int i = 0; i < ave; i++)
    {
      c.push_back(a[i]);
    }
  for (int i = ave; i < a.size(); i++)
    {
      d.push_back(a[i]);
    }
  std::cout << "c is ";
  print(c);
  std::cout << "d is ";
  print(d);
  number_of_inversions += get_number_of_inversions(c, b, left, ave);
  vector<int> b1,b2;
  std::cout << "a,b,left,ave-" << std::endl;
  print(b);
  b1 = b;
  number_of_inversions += get_number_of_inversions(d, b, ave, right);
  std::cout << "a,b,ave,right-" << std::endl;
  print(b);
  b2 = b;
  std::cout << "c is ";
  print(c);
  std::cout << "d is ";
  print(d);
  //b = mergeAndCount(b1,b2,number_of_inversions);
  print(b);
  return number_of_inversions;
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
        inversions = inversions + left.size();
        left.clear();
    }
    std::cout << "Now inversions are " <<inversions<< std::endl;
    return finalMerge;
}
