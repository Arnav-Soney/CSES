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
    ll n,moves=0,mx=INT_MIN;
    cin >> n;
    vector<ll> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];
    for(int i=0 ; i<n ; i++){
        mx = max(v[i],mx);
        if(v[i]<mx){
            moves += (mx-v[i]);
        }
    }
    cout<<moves;
    return 0;
}