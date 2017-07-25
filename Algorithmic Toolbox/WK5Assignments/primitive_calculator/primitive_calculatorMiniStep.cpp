#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> optimal_sequence(int n);
vector<int> optimal_sequenceDP(int n);
int mini_step(int n);
int min(int num1, int num2, int num3);


int main() {
  int n, size;
  cin >> n;
  cout << "mini_step is " << mini_step(n);
  vector<int> sequence = optimal_sequenceDP(n);
  //std::cout << sequence.size() - 1 << std::endl;
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

//We should create an array, in which the index is the number of operations,
//and the value for each index is the max value we can achieve using the given operations.
vector<int> optimal_sequenceDP(int n) {
  vector<int> sequenceVector;
  if (n == 1)
  {
	reverse(sequenceVector.begin(), sequenceVector.end());
    for (size_t i = 0; i < sequenceVector.size(); ++i) {
    std::cout << sequenceVector[i] << "is  ";}
	return sequenceVector;
  }
  else
  {
  //map<int, int> operations;
  //map[n] = mini_step(n);
  vector<int> sequence;
  {
  if (n%3==0 && n%2==0)
    sequence = optimal_sequenceDP(min(mini_step(n/3),mini_step(n/2),mini_step(n-1)));
  else if (n%3==0 && n%2 !=0)
    sequence = optimal_sequenceDP(min(mini_step(n/3),mini_step(n-1)));
  else if (n%3!=0 && n%2 == 0)
    sequence = optimal_sequenceDP(min(mini_step(n/2),mini_step(n-1)));
  else 
	sequence = optimal_sequenceDP(n-1);
  }
  sequence.push_back(n);
  return sequence;
  }

/*  if ((n % 3 == 0) && (n % 2 == 0))
  {
	find_smallest(operations[n/3],operations[n/2],opeations[n-1]);
	return sequence.push_back(n);
  }
  else if ((n % 3 != 0) &&(n % 2 == 0))
  {
	min(operations[n/2],opeations[n-1]);
  }
  else if ((n % 3 == 0) &&(n % 2 != 0))
  {
	int num1, num3;
    cout << " %3 " << endl;
	num1 = optimal_sequenceDP(n/3,sequenceVector);
	num3 = optimal_sequenceDP(n-1,sequenceVector);
	if (num1<num3)
		return num1;
	else
		return num3;
  }
  else
  {
    cout << " n-1 " << endl;
	return optimal_sequenceDP(n-1,sequenceVector)+1;
  }*/
}

int mini_step(int n)
{
	if (n== 1)
		return 0;
	else
	{
		int num1, num2, num3;
		{
		if ( n%3 == 0)
			num3 = mini_step(n/3);
		else if (n%2 == 0)
			num2 = mini_step(n/2);
		else
			num1 = mini_step(n-1);
		}
	return 1+ min(num1, num2, num3);
    }
}


int min(int num1, int num2, int num3)
{
	return min(min(num1, num2), num3);
}
