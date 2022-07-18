#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define full(vec) vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
using namespace std;
void solve()
{
    string a,b;cin>>a>>b;
    ll n=a.size(),m=b.size();
    vector<vector<ll>> arr(n+1,vector<ll>(m+1));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) arr[i][j]=arr[i-1][j-1]+1;
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<arr[n][m]<<endl;
}
int main()
{
    fast;
    ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
