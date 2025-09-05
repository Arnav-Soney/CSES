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

vll segTree;

void BuildTree(ll i,ll l,ll r,vector<ll>& nums){
    if(l==r){
        segTree[i] = nums[l];
        return;
    }
    ll mid = l+(r-l)/2;
    BuildTree(2*i+1, l, mid, nums);
    BuildTree(2*i+2, mid+1, r, nums);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

ll Query(ll start,ll end,ll i,ll l,ll r){
    if(l>end || r<start) return 0;
    if(l>=start && r<=end) return segTree[i];
    ll mid = l+(r-l)/2;
    return (Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r));
}

int main(){
    fast_io;
    ll n,q; 
    cin >> n >> q;
    vll nums(n);
    fr(0,n) cin>>nums[i];
    segTree.resize(4*n);
    BuildTree(0,0,n-1,nums);
    fr(0,q){
        int a,b;
        cin>> a >> b;
        cout<<Query(a-1,b-1,0,0,n-1)<<endl;
    }
    return 0;
}