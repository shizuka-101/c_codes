//inversion count 

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector< pair<int,int> >count_inversions( int *a, int end)
{
	vector< pair<int,int> > ci;
	
	for(int i=0;i<end;i++)
		for(int j=i+1;j<end;j++)
		{
			if(a[i]>a[j])
			ci.push_back(make_pair(a[i],a[j]));
		}
	return ci;
}


//Using merge sort
int merge(int *a, int *t, int l, int m, int r)
{
	int i,j,k,inv_cnt=0;
	
	i=l;
	j=m+1;
	k=l;
	
	while((i<=m)&&(j<=r))
	{
		if(a[i]<=a[j])
		{
			t[k++]=a[i++];
		}
		else
		{
			t[k++]=a[j++];
			inv_cnt = (m-i)+1;
		}
	}
	
	while(i<=m)
	{
		t[k++]=a[i++];
	}
	while(j<=r)
		t[k++]=a[j++];
	
	while(l<k)
	{
		a[l++]=t[l++];
	}
	
	return inv_cnt;
}

int MS(int *A, int *t, int beg, int end)
{
	int mid, inv_cnt=0;
	
	if(beg<end)
	{
		mid = (beg+end)/2;
		
		inv_cnt+= MS(A,t,beg,mid);		
		inv_cnt+=MS(A,t,mid+1,end);
		
		inv_cnt+=merge(A,t,beg,mid,end);
	}
	
	return inv_cnt;
}

int MergeSort(int *a, int size)
{
	int *temp =  new int[size];
	
	return MS(a,temp,0,size-1);
}

int main()
{
	int n;
	cin>>n;
	
	int* a= new int[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"Total inversion pairs"<<MergeSort(a,n);
	/*vector< pair<int,int> > inversion_pair;
	
	inversion_pair = count_inversions(a,n);
		
	for(int i=0;i<inversion_pair.size();i++)
	{
		cout<<inversion_pair[i].first<<" "<<inversion_pair[i].second<<"\n";
	}*/
	
	return 0;
}
