// all possible subset problem
//using bit manipulation

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	
	cout<<"Enter the size of the array\n";
	cin>>N;
	
	char* Array = new char[N];
	
	for(int i=0;i<N;i++)
		cin>>Array[i];
		
	cout<<"Al possible subsets are\n";
	
	for(int i=0;i<(1<<N);i++)
	{
		cout<<"{";
		for(int j=0;j<N;j++)
		{
			if(i&(1<<j))
				cout<<Array[j]<<" ";
		}
		cout<<"}\n";
	}
	
	return 0;
	}
