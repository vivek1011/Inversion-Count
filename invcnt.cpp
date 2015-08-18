// Inversion count using merge sort in an array.
// number of pairs of (i , j) such that i<j and a[i]>a[j] 
// Spoj problem link - http://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = a; i<b; i++)
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
typedef pair<ll,ll> ppl;
ll a[200010];
ll merge(ll lo, ll mid,ll hi)
{
	ll cnt =0 ; 
	int n1 = mid -lo+1;
	int n2 =hi - mid; 
	int L[200010] , R[200010];
	for(int i =0 ; i<n1; i++)
		L[i] = a[i+lo];
	for(int i =0 ; i<n2;i++)
		R[i] = a[i+mid+1];
	int i =0 , j =0 , k =lo ;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			a[k++] = L[i++];
		else
		{
			a[k++] = R[j++];
			cnt+= mid+1 - (lo+i);
		}
	}
	while(i<n1)
	a[k++] = L[i++];
	while(j<n2)
	a[k++] = R[j++];
	return cnt ; 
}
ll mergesort(int lo , int hi )
{
	ll invcnt =0 ; 
	if(lo<hi)
	{
		int mid = (lo+hi)/2;
		invcnt = mergesort( lo , mid );
		invcnt+= mergesort(mid+1, hi);
		invcnt+= merge(lo , mid, hi );
	}
	return invcnt ; 
}
int main()
{
	int t , i, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		fl(i, 0 , n) cin>>a[i];
		ll ans = mergesort(0 , n-1) ;
		cout<<ans<<endl;
	}
	return 0;
} 
