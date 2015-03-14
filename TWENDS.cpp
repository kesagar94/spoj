#include<iostream>
using namespace std;

int max(int a[],int chk[][1000],int f,int l)
{

	int q,w,v;
	if(f>l)
	{
		return 0;
	}
	if(chk[f][l]!=0)
		return chk[f][l];
	int s1,s2;
	if(a[f+1]>=a[l])
	{
		q=f+2;
		w=l;
		v=a[f+1];
	}
	else
	{
		q=f+1;
		w=l-1;
		v=a[l];
	}
	s1=a[f]-v+max(a,chk,q,w);

	if(a[f]>=a[l-1])
	{
		q=f+1;
		w=l-1;
		v=a[f];
	}
	else
	{
		q=f;
		w=l-2;
		v=a[l-1];
	}
	s2=a[l]-v+max(a,chk,q,w);
	//cout<<f<<" "<<l<<" "<<s1<<" "<<s2<<endl;
	if(s1>s2)
	{
		chk[f][l]=s1;
	}
	else
		chk[f][l]=s2;
	return chk[f][l];
}

int main()
{
	//freopen("input.txt","r",stdin());
	int n,i;
	int a[1001];
	cin>>n;
	int m=0;
	while(n!=0)
	{
		m++;
		int chk[1000][1000] = {0};
		for(i=0;i<n;i++)
			cin>>a[i];
		int p = max(a,chk,0,n-1);
		cout<<"In game "<<m<<", the greedy strategy might lose by as many as "<<p<<" points.\n";
		cin>>n;
	}

	return 0;
}