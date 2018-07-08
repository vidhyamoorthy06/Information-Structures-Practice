#include <iostream>

using namespace std;

int main()
{
	int values[20][30];
	for (int i=0; i<20; i++){
     for(int j=0; j<30; j++){
values[i][j]=0;
values[i][j++]=1;
}
}

	for (int i=0; i<20; i++){
     for(int j=0; j<30; j++){
cout<<(values[i][j]);
}
}

}
