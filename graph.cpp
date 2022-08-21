#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define i2n (ll i=0;i<n;i++)
#define j2n (ll j=0;j<n;j++)
#define n2i (ll i=n-1;i>=0;j--)
#define n2j (ll j=n-1;j>=0;j--)
#define full(vec) vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
using namespace std;
void solve()
{
	cout<<"enter the number of nodes"<<endl;
	ll n;cin>>n;
	cout<<"Enter the number of edges"<<endl;
	ll e;cin>>e;
	ll cost[n+1][n+1];
	vector<vector<ll>> g(n+1);
	vector<int> dis(n+1,INT_MAX);
	cout<<"Enter two adjacent nodes and their cost"<<endl;
	for(ll i=0;i<e;i++)
	{
		ll x,y,w;cin>>x>>y>>w;
		g[x].pb(y);
		g[y].pb(x);
		cost[x][y]=w;
		cost[y][x]=w;
	}
	cout<<"enter source and destination"<<endl;
	ll src,dest;cin>>src>>dest;
	dis[src]=0;
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,src});
	while(!pq.empty())
	{
		pair<ll,ll> temp=pq.top();
		pq.pop();
		ll u=temp.second;
		ll c=temp.first;
		c=c*(-1);
		for(ll i=0;i<g[u].size();i++)
		{
			ll v=g[u][i];
			if(dis[v]>c+cost[u][v])
			{
				dis[v]=c+cost[u][v];
				pq.push({dis[v]*-1,v});
			}
		}
	}
	cout<<dis[dest]<<endl;
}
int main()
{   
    fast;
    ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
