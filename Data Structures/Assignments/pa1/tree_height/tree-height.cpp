#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

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

int main_with_large_stack_space();


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

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
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
  }

  // Replace this code with a faster implementation
  // int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    // int height = 0;
    // for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      // height++;
    // maxHeight = std::max(maxHeight, height);
  // }
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
			  //std::cout <<" Final height is "<< height << std::endl;
			  std::cout << height << std::endl;
			  return height;
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
  return 0;
}


