#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
	  //foo->bar is equivalent to (*foo).bar
	  // (*parent).children.push_back(this)
      parent->children.push_back(this);
    }
};


int main ()
{
	int n;
	std::cin >> n;

	std::vector<Node> nodes;
	nodes.resize(n);
	int rootIndex;
	for (int child_index = 0; child_index < n; child_index++) 
	{
		int parent_index;
		std::cin >> parent_index;
		if (parent_index >= 0)
			nodes[child_index].setParent(&nodes[parent_index]);
		else
		{
			rootIndex = child_index;
		}
	nodes[child_index].key = child_index;
	//std::cout << "child_index " << child_index << " parent_index " << parent_index << std::endl;
	}
	// just for testing purpose 
	//(nodes[0].parent).key is not correct
	// since parent is a NodePointer
	// to find a parent node 
	// std::cout << (nodes[0].parent)->key << std::endl;
	// to find the first child node 
	// std::cout << "The first child of 4 is " << ((nodes[4].children)[0])->key << std::endl;
	// std::cout << "rootIndex is " << rootIndex << std::endl;
	Node* m_Root = new Node();
	*m_Root = nodes[rootIndex];
	std::queue<Node*> q;
	q.push(m_Root);
	//std::cout << " second level first node is " << ((m_Root->children)[0])->key << std::endl;
	int height = 0;
	while(1)
	{
	    int countNode = q.size();
	    //std::cout << " q size is " << countNode;
		if (countNode == 0)
		{
			  std::cout <<" Final height is "<< height << std::endl;
			  break;
			  //return height;
		}
		height++;
	    while (countNode > 0)
		{
		    //std::cout << " height is "<< countNode << std::endl;
			Node* n = q.front();
			//std::cout << "Second lever after root is " <<((n->children)[0])->key << std::endl;
		    q.pop();
		    //iterate through vector use *p than index number
			// int s = (n->children).size();
			//std::cout << "now node size is " << s << std::endl;
			std::vector<Node*>::iterator p;
		    for (p = (n->children).begin();p!=(n->children).end();p++)
			{
				q.push(*p);
				//std::cout << (*p)->key <<" ";
			}
		    countNode--;
	    }
    }
  // std::cout << maxHeight << std::endl;
  return 0;

}
