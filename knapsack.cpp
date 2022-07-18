#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define i2n (ll i=0;i<n;i++)
#define j2n (ll j=0;j<n;j++)
#define n2i (ll i=n-1;i>=0;j--)
#define n2j (ll j=n-1;j>=0;j--)
#define f(vec) vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
using namespace std;
void solve()
{
	ll n,cap;cin>>n>>cap;
	vector<pair<ll,ll>> v;
	for(ll i=0;i<n;i++) 
	{
		ll pdct,prc;cin>>pdct>>prc;
		v.push_back(make_pair(prc/pdct,pdct));
	}
	sort(f(v));
	ll ans=0;
	for(ll i=n-1;i>=0 && cap>0;i--)
	{
		ll tm=min(cap,v[i].second);
		cap-=tm;
		ans+=(tm*v[i].first);
	}
	cout<<ans<<endl;
}
int main()
{   
    fast;
    ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}