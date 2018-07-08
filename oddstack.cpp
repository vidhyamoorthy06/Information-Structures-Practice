#include <iostream>

using namespace std;


class STACK
{
    private:
    struct node
	{ 
		int item; 
		node* next;
		node(int x, node* t)
		{
		 item = x; next = t; 
		}

    };
    
	typedef node *link;
    link head;

    public:
    STACK()
    { 
		head = 0; 
	}
	
	void print()
	{
		link it = head;
		if(it==	NULL)
		cout<<"   "<<endl;
		else
		{
			cout<<"STACK :: ";
		while(it!=NULL)
      	{
      		cout<<it->item<<" ";
			  it = it->next;	
		}
		cout<<endl;
		}
		
	}
    
	int empty() const
    { 
		return head == 0; 
	}
    
	void push(int x)
    { 
		head = new node(x, head); 
	}


    int pop()
	{ 
		int v = head->item; 
		link t = head->next;
		delete head; 
		head = t; 
		return v; 
	}
	
	
	int Odds(STACK s)
	{
		int count=0;
		while(!s.empty())
		{
			int e = s.pop();
			if(e%2 != 0)
				count++;
		}
		
		return count;
	}

  }; // end of class STACK
  
  
  int main()
  {
  	STACK s; 
  	int element;
 	cout<<"Enter elements::"<<endl;
  	while(element!=-1)
  	{
	  cin>>element;
	  if(element!=-1)
	  {
	  	s.push(element);
  	  	s.print();
	  }
  	 	 
	}
	
	int count = s.Odds(s);
	cout<<"Odd Count is "<<count<<endl;
	

  }
