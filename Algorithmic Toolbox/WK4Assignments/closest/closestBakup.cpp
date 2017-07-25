#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <limits>

using namespace std;
/*
using std::vector;
using std::string;
using std::pair;
using std::min;*/

struct Point
{
	int x;
	int y;
};


void printMap(map<int,int> m);
double minimal_distance(vector<int> x, vector<int> y);
int divideSideMini(vector<Point> p, int n);
bool compareX(Point p1, Point p2);
double findMini(vector<Point> left,vector<Point>right);
double distancePtoP(Point p1, Point p2);
double distanceMin(vector<Point> p, int n);

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}

double minimal_distance(vector<int> x, vector<int> y) {
  cout << " x size is " << x.size();
  vector<Point> pv;
  for (int i=0;i<x.size();i++)
  {
	  pv.push_back(Point());
	  (pv[i]).x = x[i];
	  (pv[i]).y = y[i];
	  cout << (pv[i]).x << " "<<(pv[i]).y << endl;
  }
  //
  sort(pv.begin(),pv.end(),compareX);
  cout << "After sort " << endl;
  n = pv.size();
  for (int i=0;i<n;i++)
  {
	  cout << (pv[i]).x << " "<<(pv[i]).y << endl;
  }
  divideSideMini(pv,n);


  return 0.;
}


int divideSideMini(vector<Point> p, int n)
{
	if (n<=2)
		return distanceMin(p,n);
	int middle = (p.size()+1)/2;
	vector<Point>left,right;
	cout << "Left is " << endl;
	for (int i=0;i<middle;i++)
	{
		left.push_back(p[i]);
		cout << left[i].x <<" "<< left[i].y << endl;
	}
	cout << "Left is " << endl;
	for (int i=middle;i<p.size();i++)
	{
		right.push_back(p[i]);
		cout << right[i-middle].x <<" "<< right[i-middle].y << endl;
	}
	double dl = divideSideMini(left, middle);
	double dr = divideSideMini(right,middle);
	double dmini = min(dl,dr);

	return 0;
}

double findMini(vector<Point> left,vector<Point> right)
{
	if ((left.size()==1 )&& (right.size()==0))
		return ;
	else if ((left.size()==2 )&& (right.size()==2))
		return min(distancePtoP(left[0],left[1]),distancePtoP(right[0],right[1]));
	else 
	{
		vector<Point>l,r;
		cout << "L is " << endl;
		for (int i=0;i<middle;i++)
		{
			left.push_back(p[i]);
			cout << left[i].x <<" "<< left[i].y << endl;
		}
		cout << "Left is " << endl;
		for (int i=middle;i<p.size();i++)
		{
			right.push_back(p[i]);
			cout << right[i-middle].x <<" "<< right[i-middle].y << endl;
		}
	
	}
		
}

bool compareX(Point p1, Point p2)
{
	if (p1.x < p2.x)
		return true;
	else
		return false;
}

double distancePtoP(Point p1, Point p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

double distanceMin(vector<Point> p, int n)
{
	if n=1
		return 0.0;
	if n=2
		return distancePtoP(p[0],p[1]);
	double min = numeric_limits<int>::max();
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			if(distancePtoP(p[i],p[j])<min;
				min = distancePtoP(p[i],p[j]);
		}
	return min;
}	