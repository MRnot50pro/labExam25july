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
ll prc[1000],w[1000];
ll n,cap;
ll dp[1000][1000];
ll knapsack(ll pos,ll rem_cap)
{
	if(pos>=n) return 0;
	if(dp[pos][rem_cap]!=-1) return dp[pos][rem_cap];
	ll ans=knapsack(pos+1,rem_cap);
	if(rem_cap>=w[pos])
		ans=max(ans,knapsack(pos+1,rem_cap-w[pos])+prc[pos]);
	dp[pos][rem_cap]=ans;
	return dp[pos][rem_cap];
}
void solve()
{
	cin>>n>>cap;
	for(ll i=0;i<n;i++) cin>>w[i]>>prc[i];
	memset(dp,-1,sizeof(dp));
	cout<<knapsack(0,cap)<<endl;
}
int main()
{   
    fast;
    ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
