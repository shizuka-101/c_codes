#include<iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    vector<int> harry_coins(N);
    stack<int> monk_coins;
    
    for(int i=0;i<N;i++)
    {
        cin>>harry_coins[i];
        
    }
    
    int Q,X;
    cin>>Q>>X;
    
    int index = 0;
    int sum = 0;
    int num_of_coins = 0;
    
     if(sum==X)
        {
            cout<<num_of_coins;
         }
    
    for(int i=0;i<Q;i++)
    {
        
        if(sum==X)
        {
            cout<<num_of_coins;
            break;
        }
        
        string str;
        
        string harry = "Harry";
        string rem = "Remove";
        
        cin>>str;
        
        if(str == harry)
        {
						
            monk_coins.push(harry_coins[index]);
            index+=1;
            ++num_of_coins;
            sum+=monk_coins.top();
            
            //cout<<sum<<"\n";
        }
        else
        if(str == rem)
        {
            sum-=monk_coins.top();
            --num_of_coins;
            monk_coins.pop();
            
            //cout<<sum<<"\n";
        }
        
        if(sum==X)
        {
            cout<<num_of_coins;
            break;
        }
        
        
    }
    
    if(sum!=X)
    {
        cout<<"-1";
    }
    
}
