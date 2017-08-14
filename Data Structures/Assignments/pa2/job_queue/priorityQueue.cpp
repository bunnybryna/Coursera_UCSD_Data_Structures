
#include <iostream>
#include <queue>

class CompareDist
{
public:
	bool operator()(std::pair<int, int> n1, std::pair<int, int> n2)
	{
		if (n1.first!=n2.first)
            return n1.first>n2.first;
		else
            return n1.second>n2.second;
	}
};

int main()
{
	// use std priority_queue to implement min heap
	std::priority_queue<int, std::vector<int>, std::greater<int> > mypq;
	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);

	std::cout << "Popping out elements: ";
	while(!mypq.empty())
	{
		std::cout << ' '<< mypq.top();
		mypq.pop();
	}
	std::cout << '\n';

	std::priority_queue<std::pair <int, int>, std::vector<std::pair<int, int> >, CompareDist> pairQueue;
	pairQueue.push(std::make_pair(10,20));
	pairQueue.push(std::make_pair(10,30));
	pairQueue.push(std::make_pair(20,20));
	std::cout << "Popping out elements: ";
	while(!pairQueue.empty())
	{
		std::cout << " "<< pairQueue.top().first << "and" << pairQueue.top().second ;
		pairQueue.pop();
	}
	std::cout << '\n';
	return 0;
}
