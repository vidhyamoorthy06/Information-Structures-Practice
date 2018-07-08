#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class STACK 

  {

    private: char *s; int N;

    public:

		STACK(int maxN)
		{ 
			s = new char[maxN]; 
			N = 0; 
		}

		int empty() const
		{ 
			return N == 0; 
		}

		void push(char item)
		{
			s[N++] = item; 
		}

		char pop()
		{
			return s[--N]; 
		}
		
  };

int main()

  { 
	char o_tor[50]; // stack for storing operators
	char o_and[50]; // stack for storing operands
	while(1)
	{
		
	cout<<"Expression:??";
	cin >> o_tor;
	int N = strlen(o_tor);
	int j=0;
	STACK ops(N);// stack to save operators in precedence
	for (int i = 0; i < N; i++) // for loop for pushing the operands in second stack
	{

		if (o_tor[i] == ')')
		{
			o_and[j]=ops.pop();
			j++;
		}

		if ( (o_tor[i] == '+') || (o_tor[i] == '*') || (o_tor[i]=='^')) 
			ops.push(o_tor[i]);

		if ( (o_tor[i] >= '0') && (o_tor[i] <= '9') ) 
		{
			o_and[j]=o_tor[i];	j++;
		}
	} 

	for(int i=0;i<j;i++)  // displyaing operands only
		cout<<o_and[i]<<" ";
	cout<<endl;
// Performing the operations from Stack 
	int x,y,z; //operands for arithmetic
	N=j;
	STACK save(N);// stack to save results
	for ( int i = 0; i < N; i++)
	{
	if (o_and[i] == '+') 
	{
		x=save.pop()-48;
		y=save.pop()-48;
		save.push((x+y)%10+48);
	}	
	if (o_and[i] == '*') 
	{
		x=save.pop()-48;
		y=save.pop()-48;
		save.push((x*y)%10+48);
	}	

	if (o_and[i] == '^') 
	{
		x=save.pop()-48;
		y=save.pop()-48;
		z=1;
		for(int i=0;i<x;i++)
			z=z*y;

		save.push( (z%10)+48);
	}

	if ( ( o_and[i] >= '0') && (o_and[i] <= '9') ) 
		save.push(o_and[i]);

	}
	cout << save.pop() <<" in modulo 10" <<endl;
	cout<<endl;
}
}

