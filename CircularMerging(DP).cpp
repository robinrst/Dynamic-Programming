#include        "algorithm"
#include        "iostream"
#include        "numeric"
#include        "iomanip"
#include        "cstring"
#include        "math.h"
#include        "bitset"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

#include        "ext/pb_ds/assoc_container.hpp" // Common file
#include        "ext/pb_ds/tree_policy.hpp" // Including tree_order_statistics_node_update
#include        "ext/pb_ds/detail/standard_policies.hpp"

using namespace std;
using namespace __gnu_pbds;


#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          pb push_back
#define          N (int)500+5
#define          PI acos(-1.0)
// #define          int long long 
#define          vi vector<int>
#define          mod 1000000007
#define          ld long double
#define          eb emplace_back
#define          mii map<int,int>
#define          vpii vector<pii>
#define          pii pair<int,int>
#define          pq priority_queue
#define          BLOCK (int)sqrt(N)
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) x.rbegin(),x.rend()
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define 		 bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > 
OS ;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const long long  INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
vi a;
vector<long long > pre;
vector< vector<long long > > dp;

long long  sum(int l ,int r ) 
{
	if( l <= r )
	{
		if( l == 0 ) return pre[r];
		else return pre[r] - pre[l-1];
	}
	else
	{
		return pre[n-1] - pre[l-1] + pre[r];
	}
}

void go()
{
	cin >> n;
	a.resize(n);
	pre.resize(n);
	dp.assign(n , vector<long long> (n , INF) );

	fo(i,0,n) cin >> a[i] , pre[i] = ( i ? pre[i-1] + a[i] : a[i] );

	fo(i,0,n) dp[i][i] = 0;

	for( int gap = 1; gap < n; gap++)
	{
		for( int i = 0; i < n; i++)
		{
			int j = ( i + gap)%n;

			for( int k = i; k != j ; k = (k+1)%n )
			{
				long long  now = sum(i,k) + sum((k+1)%n, j);
				dp[i][j] = min( dp[i][j] , dp[i][k] + dp[(k+1)%n][j] + now );
			}
		}
	}

	long long  ans = INF;

	for( int i = 0; i < n; i++)
	{
		int j = (i + n - 1)%n;
		ans = min( ans , dp[i][j] );
	}
	cout << ans << endl;

}

int32_t main()
{
	FAST;     
	int t=1; 
	cin>>t;
	test(t) go();
}

