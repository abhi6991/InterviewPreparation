#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define N 100005
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define wl(n) while(n--)
#define PB push_back
#define MP make_pair
#define P(x) printf("%d\n",x)
#define fl(i,n) for(i=0;i<n;i++)
#define fil(i,a,n) for(i=a;i<n;i++)
#define rev(i,a,n) for(i=n-1;i>=a;i--)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int graph[n][n],dist[n][n],pred[n][n];

    int i,j,k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		int temp;
    		cin>>temp;
    		if(temp==-1)
    			temp=INT_MAX;
    		graph[i][j]=temp;	
    	}
    	
    }

    memset(pred,-1,sizeof(pred));

    for(k=0;k<n;k++)
    {
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][k]+graph[k][j]<graph[i][j])
    			{
    				graph[i][j]=graph[i][k]+graph[k][j];
    				pred[i][j]=pred[k][j];
    			}
    		}	
    	}
    }


    cout<<"Distances"<<endl;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		cout<<graph[i][j]<<" ";
    	}
    	cout<<endl;
    }

	return 0;
} 