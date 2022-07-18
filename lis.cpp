#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define i2n (ll i=0;i<n;i++)
#define vec vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
using namespace std;
void solve()
{
    ll n=8;
    vi v(n);
    for i2n cin>>v[i];
//    ll pos=lower_bound(v.begin(),v.end(),4)-v.begin();
//    cout<<pos<<endl;
    vi lis;
    for i2n
    {
        int temp=v[i];
        ll pos=lower_bound(lis.begin(),lis.end(),temp)-lis.begin();
        if(pos==lis.size()) lis.pb(temp);
        else lis[pos]=temp;
    }
    cout<<lis.size()<<endl;
}
int main()
{
    fast;
    //ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
