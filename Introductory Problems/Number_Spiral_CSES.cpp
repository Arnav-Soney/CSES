#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef pair<int,int> pii;
int main(){
    fast_io;
    ll t, x, y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        lli z;
        if(x==y){
            cout<<x*x-x+1<<endl;
        }
        else if(x>y){    
            z = x*x;
            if(x%2==0) cout<<z-y+1<<endl;
            else cout<<(x-1)*(x-1)+y<<endl;
        }
        else{
            z = y*y;
            if(y%2!=0) cout<<z-x+1<<endl;
            else cout<<(y-1)*(y-1)+x<<endl;        
        }
    }
    return 0;
}