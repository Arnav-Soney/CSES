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
    string s;
    cin>>s;
    ll n = s.size(),ans=1,res=0;
    for(int i=0 ; i<n-1 ; i++){
        if(s[i]==s[i+1]) ans++;
        else{
            res = max(res,ans);
            ans = 1;
        }
    }
    res = max(res,ans);
    cout<<res<<endl;
    return 0;
}