#include <bits/stdc++.h>

using namespace std;

int col[60];
int d1[60];
int d2[60];
int q[60];

void nqueen(int at, int n) //at=present position
{
        if(at == n+1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                if(j==q[i])cout<<" * ";
                else cout<<" _ ";
            }

            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        return;
        }

        for(int i=1; i<=n; i++){
            if(col[i] == 1 || d1[i+at] == 1 || d2[i-at+n]==1) continue; //i+at, i-at+n== addition of position pointer
            q[at] = i;
            col[i] = 1;
            d1[i+at] = 1;
            d2[i-at+n]=1;
            nqueen(at+1,n);

            col[i]=0;
            d1[i+at]=0;
            d2[i-at+n]=0;
        }
}


int main()
{
    int n;
    cin>>n;
    nqueen(1,n);
}
