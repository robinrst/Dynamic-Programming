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
vi adj[N];
int a[N] , dp[N][2]; // dp[i][0] -> maximum sum not taking ith 
					// dp[i][1] -> maximum sum taking ith

void go()
{
	cin >> n;

	fo(i,1,n+1) cin >> a[i];

	sort( a + 1 , a + 1 + n ); // so that next element will always greater or previous + 1

	dp[1][1] = a[1]; // taken 1st
	dp[1][0] = 0; // not taken

	int pre = a[1];

	fo(i,2,n+1)
	{
		if( a[i] == pre ) // same as previous
		{
			dp[i][1] = dp[i-1][1] + a[i]; // previoud taken + now taken
			dp[i][0] = dp[i-1][0]; // not taken as of previous
		}
		else if( a[i] == pre + 1 )
		{
			dp[i][1] = dp[i-1][0] + a[i]; // if taking this one then now sum will be previous not taken + now a[i]
			dp[i][0] = max( dp[i-1][0] , dp[i-1][1] ); // if not taking this one , update not taking till now as maximum of not taking of previous and taking of previous
		}
		else
		{
			dp[i][1] = max( dp[i-1][1] + a[i] , dp[i-1][0] + a[i] ); // here element is greater than previous + 1 -> can make answer with both maximum sum of previously taken and not taken
			dp[i][0] = max( dp[i-1][0] , dp[i-1][1] );//// if not taking this one , update not taking till now as maximum of not taking of previous and taking of previous
		}

		pre = a[i];
	}

	int ans = max( dp[n][0] , dp[n][1] ); // maximum of taking last or not

	cout << ans << endl;
}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}

 