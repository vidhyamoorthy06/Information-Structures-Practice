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
        
        link getHead()
        {
        	return head;
		}
		
		link getTail()
		{
			return tail;
		}
		
		void setHead(link h)
		{
			head=h;
		}

      int empty() const

        { return head == 0; }

      void put(int x)

        { 
		link t = tail;

          tail = new node(x);

          if (head == 0)

               head = tail;

          else t->next = tail;

        }

      int get()

        { int v = head->item; 
		link t = head;
          head=head->next;
          delete t;
		   return v; }

    

     void peekAll()

       { /* implement this part */
       link temp = head;
       while(temp!=tail->next)
       {
       	cout<<temp->item<<" ";
       	temp=temp->next;
	   }

       }
       
       QUEUE append(QUEUE q1,QUEUE q2)
       {
       	while(q1.empty()!=0 && q2.empty()!=0)
       	{
       		q1.put(q2.get());
		  }
       	return q1;
	   }
	   
	   int moveCount(QUEUE q,QUEUE p)
	   {
	   	int count=0;
	   	link t = p.getHead();
	   	link tt = p.getTail();
	   	while(t!=tt->next)
	   	{
	   		q.put(p.get());
	   		count++;
	   		t=t->next;
		}
		return count;
	   }

  };
  
  
  int main()
  {
  	QUEUE q1(0);
  	QUEUE q2(0);
  	int element,e1;
 	cout<<"Enter elements for q1::"<<endl;
  	while(element!=-1)
  	{
	  cin>>element;
	  if(element!=-1)
	  {
	  	q1.put(element);
	  }
  	 	 
	}
	
	cout<<"Enter elements for q2::"<<endl;
  	while(e1!=-1)
  	{
	  cin>>e1;
	  if(e1!=-1)
	  {
	  	q2.put(e1);
	  }
}
	 // q1.append(q1,q2);
  	  cout<<"q1 ::"<<endl;
  	  q1.peekAll();
  	   cout<<"q2 ::"<<endl;
  	  q2.peekAll();
  	
  	   cout<<"count ::"<<endl;
  	  cout<< q1.moveCount(q1,q2)<<endl;
  	  // q1.append(q1,q2).peekAll();
	}
	
//	cout<<"Peeking the Queue"<<endl;
//	q.peekAll();
  
