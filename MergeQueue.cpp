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

      void put(int x)

        { link t = tail;

          tail = new node(x);

          if (head == 0)

               head = tail;

          else t->next = tail;

        }

      int get()

        { 
        if(head==NULL)
        	return -1;
        else
        {
        int v = head->item; 
		link t = head->next;
		delete head; head = t; 
		return v;	
		}
		 
		}
          
    void dequeue()
    {
			link t;
	 if(head == NULL)
    {
        cout<<"empty queue\n";
    }
    else
    {
        t = head;
        head = head->next;
        delete(t);
	
	}
}
     void peekAll()

       { /* implement this part */
       		link temp = head;
       if(temp==NULL)
       {
       	cout<<"The queue is empty"<<endl;
       	return;
	   }
       	
       while(temp!=tail->next)
       {
       	cout<<temp->item<<" ";
       	temp=temp->next;
	   }

       }

int countElements()
{ /* implement this part */
       link temp = head;
       int count=0;
       while(temp!=tail->next)
       {
       	count++;
       	temp=temp->next;
	   }
	return count;	
       }

void mergeQueueWithoutQ3(QUEUE q1,QUEUE q2)
{
       link temp1 = q1.head;
       link temp2= q2.head;
    
		   	while(temp1!=tail->next) // add the contents to the empty destination queue
       	{
       		q2.put(temp1->item);
       		temp1=temp1->next;
	   	}
	   	
	cout<<"Contents of Queue 1::"<<endl;	
	   	q1.peekAll();
	   	cout<<endl;
	cout<<"Contents of Queue 2::"<<endl;	
	   	q2.peekAll();	   
       
}

void copyQueue(QUEUE q1,QUEUE q2)
{
	link temp1 = q1.head;
    link temp2= q2.head;
	 if(temp2==NULL)
      {
	    while(temp1!=tail->next) // add the contents to the empty destination queue
       	{
       	
       		q2.put(temp1->item);
       		temp1=temp1->next;
	   	}
	}
	  else
	  {
	  	// removing the contents from the queue 2
	  	
      int e = q2.get();
      do
      {
      	e = q2.get();
	  }while(e!=-1);
	   
	   while(temp1!=tail->next) // add the contents to the empty destination queue
       	{
       		q2.put(temp1->item);
       		temp1=temp1->next;
	   	}
	   }
	   
	cout<<"Contents of Queue 1::"<<endl;	
	   	q1.peekAll();
	   	cout<<endl;
	cout<<"Contents of Queue 2::"<<endl;	
	   	q2.peekAll();	   
       
}


void moveQueue(QUEUE q1,QUEUE q2)
{
	link temp1 = q1.head;
    link temp2= q2.head;
    int e,e1,e2;

	   
	if(temp2==NULL) // move contents from q1 to q2
      {
      do
      {
      	e = q1.get(); // get returns -1 when the queue is empty
      	q2.put(e);
	  }while(e!=-1);
	   
	}
	  else
	  {
	  	// removing the contents from the queue 2
	  	
      do
      {
      	e = q2.get();
	  }while(e!=-1);
	   
	   // move contents from q1 to q2
	   
      do
      {
      	e1 = q1.get();
      	q2.put(e1);
	  }while(e1!=-1);
	}
	   
 
	cout<<"Contents of Queue 1::"<<endl;	
	   	q1.peekAll();
	   	cout<<endl;
	cout<<"Contents of Queue 2::"<<endl;	
	   	q2.peekAll();	   
       
}



  void mergeQueue(QUEUE q1,QUEUE q2)

       { /* implement this part */
       QUEUE q3(0);
       link temp1 = q1.head;
       link temp2= q2.head;
       link temp3 = q3.head;
       while(temp1!=tail->next)
       {
       q3.put(temp1->item);
       	temp1=temp1->next;
	   }
	   
	   while(temp2!=tail->next)
       {
       	q3.put(temp2->item);
       	temp2=temp2->next;
	   }
		q3.peekAll();

       }
  };
  
  
  int main()
  {
  	QUEUE q1(0),q2(0),q3(0);
  	int element,element1;
 	cout<<"Enter elements for queue 1::"<<endl;
  	while(element!=-1)
  	{
	  cin>>element;
	  if(element!=-1)
	  {
	  	q1.put(element);
	  }
  	 	 
	}
	
	cout<<"Peeking the Queue1"<<endl;
	q1.peekAll();
	cout<<endl;	
	cout<<"Enter elements for queue 2::"<<endl;
  	while(element1!=-1)
  	{
	  cin>>element1;
	  if(element1!=-1)
	  {
	  	q2.put(element1);
	  }
  	 	 
	}
	
/**	cout<<"Peeking the Queue2"<<endl;
	q2.peekAll();
	cout<<endl;
	
	cout<<"Count of elements in q1 ::"<<q1.countElements()<<endl;
	cout<<"Count of elements in q2 ::"<<q2.countElements()<<endl;
	cout<<"After merging :"<<endl;
	q1.mergeQueueWithoutQ3(q1,q2);
	q1.mergeQueue(q1,q2);
    cout<<"Copying from one queue"<<endl;
   q1.copyQueue(q1,q2);
 q1.moveQueue(q1,q2);
    cout<<endl;
    cout<<"After copy";
    */
	

  }
