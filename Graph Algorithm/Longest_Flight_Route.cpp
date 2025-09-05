#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define i32 int32_t
#define i64 int_fast64_t
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repv(i,a,b) for(int i = a; i >=b; i--)
#define mod 1000000007
#define inf (1LL<<60)
const ll mod1 = 998244353ll;
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vbl vector<bool>
#define vvbl vector<vector<bool>>
#define mkp make_pair
#define vpll vector<pair<long long, long long>>
#define vpi vector<pair<int, int>>
#define dsort(a) sort(all(a), greater<ll>())
#define read(a, n) for(int_fast64_t i=0 ; i<n ; i++) cin >> a[i]
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define maxof(...) max({__VA_ARGS__})
#define minof(...) min({__VA_ARGS__})
#ifdef Arnav
#include <iostream>
#define debug(x) \
    std::cerr << #x << " = " << (x) << std::endl;
#else
#define debug(x)
#endif
#define sumv(arr) accumulate(all(arr), 0LL)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*-----------------------------------------------------------------------------------------------------------------------*/

void dfs(ll node,vector<ll>&vis,vector<vector<ll>>&g,stack<ll>&s){
    vis[node]=1;
    for(auto child:g[node]){
        if(vis[child]==0){
            dfs(child,vis,g,s);
        }
    }
    s.push(node);
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;

    ll n,m;cin>>n>>m;
    vector<vector<ll>>g(n+1) ;
    vector<ll>vis(n+1,0);
    stack<ll>s;
    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    vector<ll>dis(n+1,-1e9);
    vector<ll>par(n+1,0);

    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,vis,g,s);
        }
    }
    if(s.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dis[1]=0;
    while(!s.empty()){
        ll node=s.top();
        s.pop();
        for(auto child:g[node]){
            if(dis[node]!=-1e9&&dis[child]<dis[node]+1){
                dis[child]=dis[node]+1;
                par[child]=node;
            }
        }
    }
    if(dis[n]==-1e9){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<ll>path;
        path.push_back(n);
        while(n!=1){
            n=par[n];
            path.push_back(n);
        }
        cout<<path.size()<<endl;
        for(ll i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}