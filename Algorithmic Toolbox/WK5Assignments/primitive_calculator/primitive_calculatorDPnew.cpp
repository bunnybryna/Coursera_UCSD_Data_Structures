#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> optimal_sequence(int n);
vector<int> optimal_sequenceDP(int n);
int min(int num1, int num2, int num3);

int main() {
  int n, size;
  cin >> n;
  vector<int> sequence = optimal_sequenceDP(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
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

vector<int> optimal_sequenceDP(int n) {
  if (n == 1)
  {
	vector<int> sequence;
    sequence.push_back(1);	
	return sequence;
  }
  else
  {
	  vector<int> operations(n+1);
	  vector<int> precedures(n+1);
	  operations[1]=0;
	  precedures[1]=0;
	  for (int i=2;i<= n; i++)
	  {
		  operations[i] = operations[i-1]+1;
		  precedures[i] = i-1;
		  if (i%3==0 && i%2 ==0)
		  {
			if(operations[i/3] == min(operations[i-1],operations[i/3],operations[i/2]))
			{
				operations[i] = operations[i/3]+1;
				precedures[i] = i/3;
			}
			else if(operations[i/2] == min(operations[i-1],operations[i/3],operations[i/2]))
			{
				operations[i] = operations[i/2]+1;
				precedures[i] = i/2;
			} 
		  }		  
		  else if (i%3==0)
		  {
			if(operations[i/3] < operations[i-1])
			{
				operations[i] = operations[i/3]+1;
				precedures[i] = i/3;
			}
		  }
		  else if (i%2==0)
		  {
			if(operations[i/2] < operations[i-1])
			{
				operations[i] = operations[i/2]+1;
				precedures[i] = i/2;
			}
		  }
	  }
/*	  cout << "operations are " << endl;
      for (int i=1;i<=n;i++)
		  cout << operations[i] << " ";
	  cout << endl << "precedures are " << endl;
	  for (int i=1;i<=n;i++)
		  cout << precedures[i] << " ";
	  cout << "precedures[2] is " << precedures[2] << endl;*/
	  vector<int> sequence;
	  int i=n;
	  while (i != 1)
	  {
		  sequence.push_back(i);
		  i = precedures[i];
	  }
	  // adding 1 to the sequence
	  sequence.push_back(1);
	  reverse(sequence.begin(), sequence.end());
	  /*cout << endl << "sequence are " << endl;
	  for (int i=0;i<sequence.size();i++)
		  cout << sequence[i] << " ";*/
	  return sequence;
  }
}

int min(int num1, int num2, int num3)
{
	return min(min(num1, num2), num3);
}
