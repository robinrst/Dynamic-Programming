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
vi c[N];
int w[N] ,dp[101][N]; // dp[i][j] -> maximum weight we can get by taking i colors with j capacity

void go()
{
	cin >> n >> m >> k;

	fo(i,1,n+1) cin >> w[i];
	fo(i,1,n+1)
	{
		int x;
		cin >> x;
		c[x].pb(w[i]);
	}

	memset( dp , -1 , sizeof dp );

	fo(i,1,m+1)
	{
		fo(j,1,k+1)
		{
			if( i == 1 )
			{
				for( auto x : c[i] )
				{
					if( j - x >= 0 ) dp[i][j] = max( dp[i][j] , x ); // filled 1st color as per capacity i.e j
				}
				continue;
			}
			for( auto x : c[i] )
			{
				if( j - x > 0 and ~dp[i-1][j-x] ) // here j - x > 0 and not ( j - x ) >= 0  , because you have to choose every color
													// and second condition is because if you can choose ith color and you should also have 
													// answer for remaining capacity in previous color i.e dp[i-1][j - x];
				{
					dp[i][j] = max( dp[i][j] , x + dp[i-1][j-x] );
				}
			}
		}
	}

	if( ~dp[m][k] ) cout << ( k - dp[m][k] ) << endl;
	else cout << dp[m][k] << endl;
}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}

 