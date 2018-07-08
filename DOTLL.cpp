#include <iostream>
using namespace std;
//Declare Node 
struct Node{
    int value;
    int index;
    Node *next;
};
 
//Declare starting (Head) node 
struct Node *headA=NULL;
struct Node *headB=NULL;
struct Node *newNodeA; 
struct Node *newNodeB;

//Insert node at vector B start
void insertNodeB(int n){
	cout<<"Index : Value"<<endl;
	int input_value,input_index;
	for(int i=0; i<n;i++){
    newNodeB=new Node;
    //cout<<i+1<<"     :   ";
    cin>>input_index;
	cin>>input_value;
	//cout<<endl;
    newNodeB->value=input_value;
    newNodeB->index=input_index;
    newNodeB->next=headB;
    headB=newNodeB; 
  }
}

//Insert node at vector A
void insertNodeA(int n){
	cout<<"Index : Value"<<endl;
	int input_value,input_index;
	for(int i=0; i<n;i++){
    newNodeA=new Node;
    //cout<<i+1<<"     :   ";
	cin>>input_index;
	cin>>input_value;
	//cout<<endl;
    newNodeA->value=input_value;
    newNodeA->index=input_index;
    
    newNodeA->next=headA;
    headA=newNodeA; 
  }
}

void displayA(){
	cout<<"Index and Value of vector A "<<endl;
    if(headA==NULL){
        cout<<"A list is empty!"<<endl;
        return; 
    }
    struct Node *temp=headA;
    cout<<"Index : Value"<<endl;
    while(temp!=NULL){
    	cout<<temp->index<<"     :   ";
        cout<<temp->value<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
 
 
//Traverse/ display all nodes (print items)
void displayB(){
	cout<<"Index and Value of vector B "<<endl;
    if(headB==NULL){
        cout<<"B list is empty!"<<endl;
        return;
    }
    struct Node *temp=headB;
    cout<<"Index : Value"<<endl;
    while(temp!=NULL){
        cout<<temp->index<<"     :   ";
        cout<<temp->value<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

void dotProductAB(){
    int sum=0;
    struct Node *tempA=headB;
    struct Node *tempB=headA;
    while(tempA!=NULL&&tempB!=NULL){
		
	   if(tempA->index == tempB->index){	
        sum+=tempA->value*tempB->value;
        tempA=tempA->next;
        tempB=tempB->next;
       }else if(tempA->index<tempB->index){
      	tempA = tempA->next;
       }else{
            tempB = tempB->next;
       }
      
      
    }
    cout<<"Dot-product of vectors AB is:"<<sum;
    cout<<endl;
}

 
int main(){
    int n1,n2=0;
    cout<<"Enter the number of non zero values for vector A: ";
	cin>>n1;
    insertNodeA(n1);
    displayA();
    
    cout<<"Enter the number of non zero values for vector B: ";
	cin>>n2;
    insertNodeB(n2);
    displayB();
    
    dotProductAB();
    return 0;
}
