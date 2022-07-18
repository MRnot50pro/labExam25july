#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define i2n (ll i=0;i<n;i++)
#define j2n (ll j=0;j<n;j++)
#define n2i (ll i=n-1;i>=0;j--)
#define n2j (ll j=n-1;j>=0;j--)
#define full(vec) vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 10000000001

typedef long long ll;
using namespace std;
ll row[100],col[100];
ll dp[100][100];
ll mcm(ll beg,ll end)
{
	ll ret=inf;
	if(beg>=end) return 0;
	if(dp[beg][end]!=-1) return dp[beg][end];
	for(ll mid=beg;mid<end;mid++)
	{
		ll c_l=mcm(beg,mid);
		ll c_r=mcm(mid+1,end);
		ll o_l=row[beg]*col[mid]*col[end];
		ll all=c_l+c_r+o_l;
		ret=min(ret,all);
	}
	return dp[beg][end]=ret;
}
void solve()
{
	ll n;cin>>n;
	for i2n cin>>row[i]>>col[i];
	memset(dp,-1,sizeof(dp));
	cout<<mcm(0,n-1)<<endl;
}
int main()
{   
    fast;
    //ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
