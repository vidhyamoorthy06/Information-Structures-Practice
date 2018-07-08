#include<iostream>

using namespace std;
class QUEUE

  {

    private:

      struct node

        { int item; node* next;

          node(int x)

            { item = x; next = 0; }

        };

      typedef node *link;

      link head, tail;

    public:

      QUEUE(int)

        { head = 0; }
        

      int empty() const

        { return head == 0; }
        
    link getHead()
    {
    	return head;
	}
    

      void put(int x)

        { link t = tail;

          tail = new node(x);

          if (head == 0)

               head = tail;

          else t->next = tail;

        }

      int get()

        { 
		int v = head->item; 
		link t = head->next;
          delete head; 
		  head = t; 
		   return v; 	 
	
	}
    

     void peekAll()

       { /* implement this part */
       if(head==NULL)
       cout<<"nothing to peek; queue is empty"<<endl;
       else
       {
       	link temp = head;
       while(temp!=tail->next)
       {
       	cout<<temp->item<<" ";
       	temp=temp->next;
	   }

	   }
       
       }

  };
  
  
  int main()
  {
  	QUEUE q(0); 
  	char dialogue;
  	int n;
  	do
  	{
  		cin>>dialogue;
  	switch(dialogue)
  	{
  		case 'P':
  			cin>>n;
  			q.put(n);
  		break;
  		
  		case 'G':
  			if(q.getHead()==NULL)
  			cout<<"nothing to get; queue is empty"<<endl;
  			else
  			cout<<q.get()<<endl;
  		break;
  		
  		case 'E':
  			if(q.empty()==1)
  				cout<<"empty"<<endl;
  			else
  				cout<<"not empty"<<endl;
  		break;
  		
  		case 'F':
  			q.peekAll();
  		break;
  				
	}

	}while(dialogue !='0');
  	
  }
