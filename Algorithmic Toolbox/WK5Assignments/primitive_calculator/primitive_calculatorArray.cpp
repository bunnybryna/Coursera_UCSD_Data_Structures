#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n);
vector<int> optimal_sequenceDP(int n);
int find_smallest(int num1, int num2, int num3);

int main() {
  int n, size;
  std::cin >> n;
  vector<int> sequence = optimal_sequenceDP(n);
  /*std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }*/
  return 0;
}


vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

//We should create an array, in which the index is the number of operations,
//and the value for each index is the max value we can achieve using the given operations.
vector<int> optimal_sequenceDP(int n) {
  vector<int> sequence;
  int operations[n+1];
  int num;
  for (int i=0;i<=n;i++)
  {
	 if (i==0 || i==1)
		operations[i]=0;
	 else if (i==2 || i==3)
		operations[i]=1;
     else
	 {
        {if (i % 3 == 0 && i % 2 == 0)
            num = find_smallest(operations[i/3],operations[i/2],operations[i-1])+1;
		else if (i % 3 == 0)
			num = min(operations[i/3],operations[i-1])+1;
		else if (i % 2 == 0)
			num = min(operations[i/2],operations[i-1])+1;
		else
			num = operations[i-1]+1;
        }
	     operations[i]=num;
	 }
  }
  cout << " The list is :" << endl;
  for (int i=0;i<=n;i++)
	  cout << operations[i] << " ";
    // using vectors
	/*
  vector<int> operations;
  int num;
  for (int i=0;i<=n;i++)
  {
	 if (i==0 || i==1)
		num = 0;
	 else if (i==2 || i==3)
		num = 1;
     else
	 {
		if (i % 3 == 0 && i % 2 == 0)
            num = find_smallest(operations[i/3],operations[i/2],operations[i-1])+1;
		else if (i % 3 == 0)
			num = min(operations[i/3],operations[i-1])+1;
		else if (i % 2 == 0)
			num = min(operations[i/2],operations[i-1])+1;
		else
			num = operations[i-1]+1;   
	 }	
	operations.push_back(num);*/
return sequence;
}

int find_smallest(int num1, int num2, int num3)
{
	return min(min(num1, num2),num3);
}
