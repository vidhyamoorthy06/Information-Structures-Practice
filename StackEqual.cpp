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

    int peek()
    {
    	if(head!=NULL)
		return head->item;
		else
		return 0;
    }

    int pop()
	{ 
		int v = head->item; 
		link t = head->next;
		delete head; 
		head = t; 
		return v; 
	}
	
    void flush()
    {
      	link it = head;
      	cout<<"STACK"<<endl;
      	while(it!=NULL)
      	{
      		cout<<it->item<<endl;
			  it = it->next;	
		}
		
		cout<<"Emptying stack"<<endl;
		
		while(head!=NULL)
      	{
      		link t = head;
      		delete t;
			  head = head->next;	
		}
		
		if(head==NULL)
			print(); //empty line if stack is empty
		else
			cout<<"cannot empty stack!!"<<endl;
          /* implement this part */

    }
    
    int equal(STACK s1,STACK s2)
    {
    	while(!s1.empty()&& !s2.empty())
    	{
    		if(s1.pop()!=s2.pop())
    		return 0;  	
		}
			return(s1.empty()&&s2.empty());
	}
	

  };
  
  
  int main()
  {
  	
  	STACK s1,s2,s3; 
  	int element, elementb;
 	cout<<"Enter elements for s1::"<<endl;
  	while(element!=-1)
  	{
	  cin>>element;
	  if(element!=-1)
	  {
	  	s1.push(element);
  	  	s1.print();
	  }
  	 	 
	}
	
	cout<<"Enter elements for s2::"<<endl;
  	while(elementb!=-1)
  	{
	  cin>>elementb;
	  if(elementb!=-1)
	  {
	  	s2.push(elementb);
  	  	s2.print();
	  }
  	 	  
	}
	
	 cout<<endl;
  	 	 cout<<s3.equal(s1,s2);
}




