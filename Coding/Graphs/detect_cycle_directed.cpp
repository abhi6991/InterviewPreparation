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


//detect cycle directed
bool dfs(vector<vector<int> > graph,vector<int> &visited,vector<int> &pred,vector<int> &color,int x)
{
	//cout<<"visited val:"<<visited[x]<<endl;
	visited[x]=1;
	color[x]=1;
	//cout<<"visited :"<<x<<endl;

	int i;
	for(i=0;i<graph[x].size();i++)
	{
		int u=graph[x][i];
		//cout<<"u="<<u<<endl;
		if(!visited[u] && dfs(graph,visited,pred,color,u))
		{
			//cout<<"here cycle x="<<x<<"u="<<u<<endl;
			return true;
		}
		else if(color[u]==1){
			///cout<<"cycle x="<<x<<"u="<<u<<endl;
			return true;
		}

	}

	color[x]=2;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;

    vector<vector<int> > graph(n);
    vector<int> visited(n,0);
    vector<int> pred(n,-1);
    vector<int> color(n,0);

    ll i;
    cout<<"m="<<m<<endl;
    for(i=0;i<m;i++)
    {
    	ll x,y;
    	cin>>x>>y;

    	graph[x].push_back(y);
    	//graph[y].push_back(x);

    }

    ll s;
    cin>>s;
    if(dfs(graph,visited,pred,color,s))
    {
    	cout<<"Cycle detected"<<endl;
    }


	return 0;
} 