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
	
	link getHead()
	{
		return head;
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
		return head->item;
    }

    int pop()
	{ 
		int v;
		if(head==NULL)
			cout<<"nothing to pop off; stack is empty"<<endl;
		else
		{
			v = head->item; 
			link t = head->next;
			delete head; 
			head = t; 
		}
	
		return v; 
	}
	
     void flush()
    {
      	link it = head;
      	cout<<"STACK"<<endl;
      	while(it!=NULL)
      	{
      		cout<<it->item<<" ";
			  it = it->next;	
		}
		cout<<endl;
		
		cout<<"Emptying stack"<<endl;
		
		while(head!=NULL)
      	{
      		pop();
			  head = head->next;	
		}
		
		if(head==NULL)
			cout<<"stack is empty"<<endl;
		else
			cout<<"cannot empty stack!!"<<endl;
          /* implement this part */
    }


  };
  
  
  int main()
  {
  	STACK s; 
  	char dialogue;
  	int n;
  	do
  	{
  		cin>>dialogue;
  	switch(dialogue)
  	{
  		case 'P':
  			cin>>n;
  			s.push(n);
  			cout<<"Pushed "<<n<<endl;
  		break;
  		
  		case 'R':
  			cout<<"Popped "<<s.pop()<<endl;
  		break;
  		
  		case 'E':
  			if(s.getHead()==NULL)
  				cout<<"empty"<<endl;
  			else
  				cout<<"not empty"<<endl;
  		break;
  		
  		case 'F':
  			s.flush();
  			cout<<"flushed";
  		break;
  		
  		case 'K':
  			cout<<s.peek()<<endl;
  		break;
  				
	}

	}while(dialogue !='0');
  	
 	
  }//main
