#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;



class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  // make result vector class attribute
  // so each member function has access to it
  vector <int> result;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    // remember to clear the vector
    result.clear();
    in_orderRe(0);
	return result;
  }
 // pass index instead of node here
  void in_orderRe(int index){
	if (left[index] != -1)
		in_orderRe(left[index]);
    // since node will be push to result here
	result.push_back(key[index]);
	if (right[index] != -1)
		in_orderRe(right[index]);
	}

  vector <int> pre_order() {
    result.clear();
    pre_orderRe(0);
    return result;
  }

  void pre_orderRe(int index){
    result.push_back(key[index]);
    if (left[index] != -1)
        pre_orderRe(left[index]);
    if (right[index] != -1)
        pre_orderRe(right[index]);
  }
  vector <int> post_order() {
    result.clear();
    post_orderRe(0);
    return result;
  }

  void post_orderRe(int index){
    if( left[index] != -1)
      post_orderRe(left[index]);
    if (right[index] != -1)
      post_orderRe(right[index]);
    result.push_back(key[index]);
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

