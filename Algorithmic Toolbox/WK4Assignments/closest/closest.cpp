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

double minimal_distance(vector<int> x, vector<int> y);
double divideSideMini(vector<Point> p, int n);
double distancePtoP(Point p1, Point p2);
double distanceMin(vector<Point> p, int n);
bool compareX(Point p1, Point p2);
bool compareY(Point p1, Point p2);

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
  if (x.size() == 1)
	  return 0.0;
  vector<Point> pv;
  for (int i=0;i<x.size();i++)
  {
	  pv.push_back(Point());
	  (pv[i]).x = x[i];
	  (pv[i]).y = y[i];
	  //cout << (pv[i]).x << " "<<(pv[i]).y << endl;
  }
  sort(pv.begin(),pv.end(),compareX);
  int n = pv.size();
  /*cout << "After sort " << endl;
  for (int i=0;i<n;i++)
  {
	  cout << (pv[i]).x << " "<<(pv[i]).y << endl;
  }*/
  int middle = (n+1)/2;
  Point mdPoint = pv[middle];
  double dSide = divideSideMini(pv,n);
  if (dSide == 0.0)
	  return 0.0;
  //cout << "Ond side mini is " << dSide;
  vector<Point> strip;
  for (int i=0;i< n;i++)
  {
	  if ((abs(pv[i].x - mdPoint.x))< dSide)
		  strip.push_back(pv[i]);
		  //cout << "strip inludes " << pv[i].x << " " << pv[i].y << endl;
  }
  sort(strip.begin(),strip.end(),compareY);
  /*cout << "After sorted" << endl;
  for (int i=0;i< strip.size();i++)
  {
      cout << strip[i].x << " " << strip[i].y << endl;
  }*/
  double dNow = dSide;
  // have to use two for loops
  // can't just compare strip[i] and strip[i+1]=> only sort by y
  // minimal distance can happen between i and i+2,3,4,...
  for (int i=0;i<strip.size();i++)
  {
	  for (int j=i+1;j<strip.size();j++)
	  {
		if (abs((strip[j].y-strip[i].y)) < dNow)
		{
			dNow = distancePtoP(strip[i],strip[j]);
			//cout << " dNow is " << dNow << endl;
		}	
	  }
  }
  return dNow;
}

// recursive function to find one side minimal distance
double divideSideMini(vector<Point> p, int n)
{
	if (n<=3)
		return distanceMin(p,n);
	int middle = (n+1)/2;
	vector<Point>left,right;
	//cout << "Left is " << endl;
	for (int i=0;i<middle;i++)
	{
		left.push_back(p[i]);
		//cout << left[i].x <<" "<< left[i].y << endl;
	}
	//cout << "Right is " << endl;
	for (int i=middle;i<p.size();i++)
	{
		right.push_back(p[i]);
		//cout << right[i-middle].x <<" "<< right[i-middle].y << endl;
	}
	double dl = divideSideMini(left, middle);
	double dr = divideSideMini(right,n-middle);
	double dmini = min(dl,dr);
	if (dmini == 0.0)
		return 0.0;
	return dmini;
}

double distanceMin(vector<Point> p, int n)
{
	if (n==2)
		return distancePtoP(p[0],p[1]);
	double min = numeric_limits<int>::max();
	for (int i=0;i<n;i++)
	{	
		for (int j=i+1;j<n;j++)
		{
			if(distancePtoP(p[i],p[j])<min)
				min = distancePtoP(p[i],p[j]);
			if (min == 0.0)
				return 0.0;
		}
	}	
	return min;
}


double distancePtoP(Point p1, Point p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

bool compareX(Point p1, Point p2)
{
	if (p1.x < p2.x)
		return true;
    else if (p1.x == p2.x)
        return (p1.y < p2.y);
	else
		return false;
}

bool compareY(Point p1, Point p2)
{
	if (p1.y < p2.y)
		return true;
	else
		return false;
}
