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
#define vi vector<int>
#define vll vector<long long>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef pair<int,int> pii;

ll t[1000001] = {0};

ll solve(ll n){
    t[0] = 1;
    for(ll i=1 ; i<n+1 ; i++){
        for(ll j=1 ; j<=6 ; j++){
            if(j > i) break;
            t[i] = (t[i] + t[i-j])%mod;
        }
    }
    return t[n];
}

int main(){
    fast_io;
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}