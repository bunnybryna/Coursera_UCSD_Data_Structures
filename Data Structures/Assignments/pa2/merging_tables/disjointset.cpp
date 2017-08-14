#include <iostream>
using namespace std;

class DisjointSet
{
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public:
	void makeSet(vector<int> universe)
	{
		for (int i: universe)
		{
			parent[i]=i;
			rank[i]=0;
		}	
	}
	int Find(int k)
	{
		if (parent[k]!= k)
			// path compression
			parent[k]= Find(parent[k])
			
		return parent[k];
	}
	void Union(int a, int b)
	{
		int x = Find(a);
		int y = Find(b);
		if (x==y)
			return ;
		if (rank[x] > rank[y])
			parent[y] = x;
		else if (rank[x]<rank[y])
			parent[x] = y;
		else 
		{
			parent[x] = y;
			rank[y]++
		}
	}
};

void printSets(vector<int> universe, DisjointSet &ds)
{
	for (int i: universe)
		cout << ds.Find(i) << " ";
		cout << endl;
}

int main()
{
	vector<int> universe = {1,2,3,4,5};
	DisjointSet ds;
	ds.makeSet(universe);
	printSets(universe, ds);
	ds.Union(4,3);
	printSets(universe, ds);
	ds.Union(2,1);
	printSets(universe, ds);
	ds.Union(1,3);
	printSets(universe, ds);

	return 0;
}
