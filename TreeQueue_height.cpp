#include<iostream>

using namespace std;

struct node
{
	   int item, ht; 
	   node *l, *r;
       node(int x)
	   {
	    item = x; l = 0; r = 0; ht=0;
	   }

};

 typedef node *link;
 link h=0;

class QUEUE

  {
    private:
  link *q; int N, head, tail;
public:
  QUEUE(int maxN)
  {
    q = new link[maxN + 1];
    N = maxN + 1;
    head = N;
    tail = 0;
  }
  int empty() const
  {
    return head % N == tail;
  }
  void put(link item)
  {
    q[tail++] = item; tail = tail % N;
  }
  link get()
  {
    head = head % N; return q[head++];
  }
};

link findnode(link h, int pitem)
{
  QUEUE q(100);
  q.put(h);
  while (!q.empty())
  {
    h = q.get();
    if (h->item == pitem) break;
    if (h->l != 0) q.put(h->l);
    if (h->r != 0) q.put(h->r);
  }
  if (h->item != pitem)
  {
    cout << "Not find node with item " << pitem << endl;
    return 0;
  }
  return h;
}

void traverse(link h)
{
  if (h == 0) return;
  QUEUE q(100);
  link t = 0;
  q.put(h);
  while (!q.empty())
  {
    t = q.get();
      cout << t->item << " ";
      if (t->l != 0) q.put(t->l);
      if (t->r != 0)  q.put(t->r);
  }
cout << endl;
}

void putLeft(int p, int c) // putting the node of value 'c' on the left of node of value 'p'
    {
		link t = findnode(h, p);
        if (t != 0)
        {
          if (t->l == 0)
          {
            t->l = new node(c);
            cout << "Node with item " << c << " has been added" << endl;
          }
          else
          {
            cout << "Error: Node with item " << p << " has had left node" << endl;
          }
	}
}
		
	void putRight(int p, int c)// putting the node of value 'c' on the right of node of value 'p'
	{
		link t = findnode(h, p);
        if (t != 0)
        {
          if (t->r == 0)
          {
            t->r = new node(c);
            cout << "Node with item " << c << " has been added" << endl;
          }
          else
          {
            cout << "Error: Node with item " << p << " has had left node" << endl;
          }
		}
	}


   
  void traverseSubtree(int i)
  {
  	link t = findnode(h, i);
        if (t != 0) 
        {
          cout << "level-order traversal of the asked subtree:";
          traverse(t);
          cout << endl;
		}
  }
  
  int height(link h)
{
	QUEUE q(100);
	q.put(h);
	h->ht=1;
	while(!q.empty())
	{
		h =q.get();
		int maxh = h->ht;
	if(h->l!=0)
	{
		q.put(h->l);
		h->l->ht = h->ht+ 1;
	}

	if(h->r!=0)
	{
		q.put(h->r);
		h->r->ht = h->ht+1;
	}
}
return h->ht;
}
 	
	

  
 int main()
  {
  	QUEUE q(0); //tree
  	char dialogue;
  	int root,parent,child,sub;
  	do
  	{
  		cin>>dialogue;
  	switch(dialogue)
  	{
  		case 'C': // Create the root node with item 'root'
  		
  		cin >>root;
        if (h == 0)
        {
          h = new node(root);
          cout << "Root node with item " << root << " has been created" << endl;
        }
        else
        {
          cout << "Error: Tree is not empty" << endl;
        }
  		break;
  		
  		case 'L': // create a node 'child' to the left of node 'parent'
  			cin>>parent>>child;
  			putLeft(parent,child);
  		break;
  		
  		case 'R': // create a node 'child' to the right of node 'parent'
  			cin>>parent>>child;
  			putRight(parent,child);
  		break;
  		
  		case 'P': //Print the height of tree in a level order traversal manner
			cout<<"The tree height is "<<height(h)<< " (using the level order traversal of the entire tree)"<<endl;
  		break;
  		
  		case 'S': //Print subtree of node 'p' in level order traversal manner 		
  			cin>>sub;
  			traverseSubtree(sub);
		break;
  			
	}

	}while(dialogue !='0');
  	
  }




  
  
  
