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

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q,x;
vi a;
int dp[101][501]; // dp[i][j] -> denotes ways to make current till ith index with sum as j 
				 // if we encounter a '(' , we add 1 to sum and if this ')' , then subtracat one , so if sum is negative no sequence is possible till
				 // that index so we try placing '(' at that index 

int makeAns( int i = 1 , int sum = 0)
{
	if( sum < 0 ) return 0;
	if( i == n + 1 ) return ( sum == 0 );

	int& ans = dp[i][sum];
	if( ~ans ) return ans;

	if( a[i] ) ans = makeAns(i+1 , sum + 1)%mod;
	else 
	{
		ans = makeAns( i+1 , sum - 1) + makeAns( i + 1 , sum + 1);
		ans %= mod;
	}

	return ans;
}
void go()
{
	cin >> n >> m;
	a.assign(2*n+1 , 0);
	fo(i,0,m) cin >> x , a[x] = 1;

	n *= 2;

	memset( dp , -1, sizeof dp );

	int ans = makeAns()%mod;
	cout << ans << endl;
}

int32_t main()
{
	FAST;     
	int t=1; 
	cin>>t;
	test(t) go();
}

 