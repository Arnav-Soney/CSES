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
#define vi vector<int_fast64_t>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vbl vector<bool>
#define vvbl vector<vector<bool>>
#define mkp make_pair
#define vpll vector<pair<long long, long long>>
#define vpi vector<pair<int, int>>
#define dsort sort(all(a), greater<ll>())
#define read(a, n) for(int_fast64_t i=0 ; i<n ; i++) cin >> a[i]
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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

vll segTree, nums;
ll n, q;
void BuildTree(int i,int l,int r,vll& nums){
    if(l==r){
        segTree[i] = nums[l];
        return;
    }
    int mid = l+(r-l)/2;
    BuildTree(2*i+1, l, mid, nums);
    BuildTree(2*i+2, mid+1, r, nums);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void UpdatePoint(int index,int val,int i,int l,int r){
    if(l==r){
        segTree[i] = val;
        return;
    }
    int mid = l+(r-l)/2;
    if(index<=mid) UpdatePoint(index,val,2*i+1,l,mid);
    else UpdatePoint(index,val,2*i+2,mid+1,r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void update(int index, int val) {
    UpdatePoint(index,val,0,0,n-1);
}

ll Query(int start,int end,int i,int l,int r){
    if(l>end || r<start) return 0;
    if(l>=start && r<=end) return segTree[i];
    int mid = l+(r-l)/2;
    return (Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r));
}

ll sumRange(int left, int right) {
    return Query(left,right,0,0,n-1);
}

int32_t main(){
    fast_io;
    cin >> n >> q;
    nums.resize(n);
    segTree.resize(4*n);
    read(nums, n);
    BuildTree(0, 0, n-1, nums);
    rep(i, 0, q){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            x--;
            update(x, y);
        }
        else{
            x--;
            y--;
            cout << sumRange(x, y) << '\n';
        }
    }
    return 0;
}