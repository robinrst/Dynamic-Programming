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
pii a[N];
int dp[N][2];  // 1 -> ways to make odd sum till ith index
			  // 0 -> ways to make even sum till ith index

void go()
{
	cin >> n;

	int ans = 0;

	memset( dp , 0 , sizeof dp );
	
	dp[0][1] = 0; // base case for odd sum 
	dp[0][0] = 1; // base case for even sum 

	fo(i,1,n+1)
	{
		int x , y;
		cin >> x >> y;

		x &= 1;
		y &= 1;

		if( x and y ) // both odd
		{
			dp[i][1] = ( dp[i-1][0] * 2 )%mod; // to make odd sum we need total ways to make even sum since ( odd + even -> odd) and we have 2 odd here
			dp[i][0] = ( dp[i-1][1] * 2 )%mod; // // to make even sum we need total ways to make odd sum since ( odd + odd -> even) and we have 2 odd here
		}
		else if( !x and !y ) // both even
		{
			dp[i][1] = ( dp[i-1][1] * 2 )%mod; // to make odd sum we need total ways to make odd sum since ( odd + even -> odd)  and we have 2 even here
			dp[i][0] = ( dp[i-1][0] * 2 )%mod; // to make even sum we need total ways to make even sum since ( even + even -> even)  and we have 2 even here
		}
		else // one odd and one even
		{
			dp[i][1] = ( dp[i-1][0] + dp[i-1][1] )%mod; // to have odd sum now we can make it by taking previous ways to make odd sum and now 1 even and vice versa.
			dp[i][0] = ( dp[i-1][1] + dp[i-1][0] )%mod; // to have even sum now we can make it by taking previous ways to make even sum and now 1 even and vice versa.
		}
	}

	cout << dp[n][1]%mod << endl; // print number of ways to make odd sum
}

int32_t main()
{
	FAST;     
	int t=1; 
	cin>>t;
	test(t) go();
}

 