#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main()
{
	list<string> mylist= {"bryna","Hello","World"};
	mylist.push_front("dear");
	mylist.push_front("Hey");

	std::cout << "mylist contains:";
	for (string& x: mylist) std::cout << ' ' << x;
	std::cout << '\n';

	vector< list<string> > elems(3);
	elems[0].push_front("Bryna");
	elems[0].push_front("Zhao");
	//elems[2].push_front("haha");
	// std::cout << "2 has size of " << elems[2].size() << std::endl;
	// for (int i=0;i<3;i++)
	// {
		// for (string& x: elems[i]) std::cout << ' ' << x;
	// }
	for (string& x: elems[2]) std::cout << ' ' << x;
    std::cout << "\n";


	return 0;
}
