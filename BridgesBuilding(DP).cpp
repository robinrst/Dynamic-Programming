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
#define          N (int)2e5+5
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
int dp[N];
pii a[N];


/*
We need to satisfy the condition between bridges 
Let B1 -> bridge and B2 -> bridge 2
and let assume that first point is xth bank of river
ans second point is yth bank of river
   B1    B2
   x1    x2 ..........
- ||-----||----------------
 ||	    || 			RIVER
|| ----||------------------
y1    y2 .........


So , condition will be
[   B1.x <= B2.x and B1.y <= B2.y ]

So for achieving this , we sort first set of points on the basis of yth
Now we have to just find the longest Increasing Sequence on xth points 
to satisfy the condition and  that will be number of bridges we can form
*/
void go()
{
	cin >> n;

	fo(i,1,n+1) cin >> a[i].f;
	fo(i,1,n+1) cin >> a[i].sc;

	sort( a + 1 , a + 1 + n , [&] ( pii x , pii y) -> bool
	{
		if( x.sc == y.sc ) return x.f < y.f;
		return x.sc < y.sc;
	});

	fo(i,1,n+1) dp[i] = 1;

	int ans = 0;

	fo(i,1,n+1)
	{
		for( int j = i-1; j >= 1; j--)
		{
			if( a[j].f <= a[i].f )
			{
				dp[i] = max( dp[i] , 1 + dp[j] );
			}
		}

		ans = max( ans , dp[i] );
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

 