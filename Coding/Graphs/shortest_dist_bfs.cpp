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

void bfs(vector<vector<int> > graph,vector<int> &visited,vector<int> &pred,vector<int> &dist, vector<int> color,int x)
{
	visited[x]=1;
	queue<int> qu;
	qu.push(x);
	dist[x]=0;
	color[x]=0;
	while(!qu.empty())
	{
		int n=qu.front();
		qu.pop();
		cout<<"visited "<<n<<endl;
		int i;
		for(i=0;i<graph[n].size();i++)
		{
			int u=graph[n][i];
			if(!visited[u])
			{
				//cout<<"here u="<<u<<endl;
				dist[u]=dist[n]+1;
				visited[u]=1;
				pred[u]=n;
				color[u]=1;
				//push into the queue
				qu.push(u);
			}	
		}

		color[n]=2;
	}

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n);
 	vector<int> visited(n,0);
 	vector<int> pred(n,-1);
 	vector<int> dist(n,INT_MAX);
 	vector<int> color(n,0);

 	int i;
 	for(i=0;i<m;i++)
 	{
 		int x,y;
 		cin>>x>>y;
 		graph[x].push_back(y);
 		graph[y].push_back(x);
 	}

 	int s;
 	cin>>s;
 	bfs(graph,visited,pred,dist,s);


 	//print distance from source to all

 	cout<<"Distances:"<<endl;
 	for(i=0;i<n;i++)
 	{
 		cout<<dist[i]<<" ";
 	}

	return 0;
} 