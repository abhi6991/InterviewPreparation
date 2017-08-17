#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define N 100005
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define wl(n) while(n--)
#define PB push_back
#define p pair<int,int>
#define MP make_pair
#define P(x) printf("%d\n",x)
#define fl(i,n) for(i=0;i<n;i++)
#define fil(i,a,n) for(i=a;i<n;i++)
#define rev(i,a,n) for(i=n-1;i>=a;i--)

void bellman(vector<pair<pair<ll,ll> ,ll> > edges, vector<int> &pred,vector<int> &dist,int s)
{
	int i,j;
	int n=dist.size();
	int e=edges.size();
	dist[s]=0;

	for(i=1;i<=n;i++)
	{
		for(j=0;j<e;j++)
		{

			int u,v,w;
			//cout<<"u="<<u<<"v="<<v<<"w="<<w<<endl;
			u=edges[j].first.first;
			v=edges[j].first.second;
			w=edges[j].second;

			if(dist[v]>dist[u]+w)
			{
				if(i==n)
				{
					cout<<"Negative Cycle Detected"<<endl;
					return;
				}

				dist[v]=dist[u]+w;
			}
		}
	}

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair< pair<ll,ll>, ll > > edges;

    int i;
    for(i=0;i<m;i++)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	edges.PB(make_pair(make_pair(x,y),w));
    }

    vector<int> dist(n,INT_MAX),pred(n,-1);

    int s;
    cin>>s;
    bellman(edges,pred,dist,s);

    cout<<"Distances:"<<endl;
    for(i=0;i<n;i++)
    	cout<<dist[i]<<" ";


	return 0;
} 