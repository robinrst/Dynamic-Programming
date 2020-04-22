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
#define          N (int)2e6+5
#define          PI acos(-1.0)
#define          int long long 
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
#define          allr(x) rbegin(x),rend(x)
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

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
int a[N] ,dp[N]; // dp[i] -> maximum sum of sequence till form upto ith index

void go()
{
	cin >> n >> k;

	fo(i,0,n) cin >> a[i] , dp[i] = a[i];

	int ans = 0;

	for( int i = k; i < n; i += k )
	{
		int mx1 = i - k , mx2 = -inf;
		for( int j = i - k + 1; j < i; j++)
		{
			if( dp[j] > dp[mx1] )
			{
				mx2 = mx1;
				mx1 = j;
			}
			else if( mx2 == -inf or dp[j] > dp[mx2] ) mx2 = j;
		}

		for(int j = i; j < i+k and j < n; j++)
		{
			if( a[j] < 0 ) dp[j] = dp[mx1];
			else if( j - mx1 != k ) dp[j] = dp[mx1] + a[j];
			else dp[j] = dp[mx2] + a[j];

			ans = max( ans , dp[j] );
		}
	}

	cout << ans << endl;	
}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}

