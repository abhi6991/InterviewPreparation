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



 struct compare  
 {  
   bool operator()(const pair<int,int> & l, const pair<int,int> & r)  
   {  
       return l.first > r.first;  
   }  
 }; 

void prims(vector<vector<pair<int,int> > > graph,vector<int> &key,vector<int> &pred,int s)
{

	priority_queue<pair<int,int>,vector<pair<int,int> >, compare >  pq;

	key[s]=0;
	int i;
	int n=graph.size();
	
	
	pq.push(make_pair(key[s],s));
	vector<int> visited(n,0);


	while(!pq.empty())
	{
		pair<int,int> p=pq.top();
		pq.pop();
		//visited[p.first]=1;

		int n=p.second;
		visited[n]=1;
		int w=p.first;

		//cout<<"n="<<n<<"w="<<w<<endl;

		for(i=0;i<graph[n].size();i++)
		{
			int u=graph[n][i].first;
			//cout<<"u="<<u<<"dist="<<graph[n][i].second<<endl;
			if(!visited[u] && key[u] > graph[n][i].second)
			{
				cout<<"u="<<u<<endl;				
				key[u]=graph[n][i].second;
				pq.push(make_pair(key[u],u));
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

    vector<vector<pair<int,int> > > graph(n);
    vector<int> key(n,INT_MAX);
    vector<int> pred(n,-1);

    int i;
    for(i=0;i<m;i++)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	//cout<<"x="<<x<<endl;
    	graph[x].push_back(make_pair(y,w));
    	graph[y].push_back(make_pair(x,w));
    }

    int s;
    cin>>s;
    //cout<<"here"<<endl;
    prims(graph,key,pred,s);	

    
    cout<<"keys:"<<endl;
    for(i=0;i<n;i++)
    	cout<<key[i]<<" ";

	return 0;
} 