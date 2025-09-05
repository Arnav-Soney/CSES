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
    ll n;
    cin >> n;
    vector<ll> a(n-1);
    for(int i=0;i<n-1;i++) cin>>a[i];
    vector<bool> arr(n,false);
    for(int i=0;i<n-1;i++) arr[a[i]-1] = true;
    for(int i=0;i<n;i++){
        if(arr[i]==false){
            cout<<i+1;
            break;
        }
    }
    return 0;
}