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

ll solve(ll base, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp%2==1){
            res = (res*base)%mod;
        }
        base = (base*base)%mod;
        exp = exp/2;
    }
    return res;
}

int main(){
    fast_io;
    ll n;
    cin >> n;
    cout<< solve(2,n)<<endl;
    return 0;
}