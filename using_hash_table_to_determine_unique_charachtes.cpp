//unique charachters in the string

#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
#include<string>
//#include<unorderd_map>
//
using namespace std;

int main()
{
	string str;
	map<char,int> charachters;
	
	cin>>str;
	
	int len = str.length();
	
	for(int i=0;i<len;i++)
	{
		charachters[str[i]]++;
		if(charachters[str[i]]>1)
			{
				cout <<"String contains duplicate charachters";
				return 0;
				}
		}
		cout<<"Unique charachters\n";
		return 0;	
	}
