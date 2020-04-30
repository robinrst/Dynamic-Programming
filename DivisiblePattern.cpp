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
#define          N (int)1e4+5
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

int n,m,k,q;
string s , t;
int dp[N][2520]; // dp[i][j] -> denote number of numbers having remainder j till ith index
vi v;


vi Z(string s , int n)  // z[i] btata h ki i se leke aage tk kitne length ki string match kr rhi h prefix se
{
	int l = 0 , r = 0;
	vi z(n,0);

	fo(i,1,n)
	{
		if( i <= r ) z[i] = min( z[i - l] , r - i + 1 ); // ya th z[i] jo h vh usi z-box m hoga ya phr or character match kr rhe honge
		while( i + z[i] < n and s[z[i]] == s[i + z[i]] ) z[i]++; // explicit matching krna

		if( i + z[i] - 1 > r ) //  agr z[i] ki length r se jada ho jae th r ko update kr do
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int makeAns( int i = 0, int now = 1)
{
	if( i == n ) return ( now == 0 );

	int& ans = dp[i][now];
	if( ~ans ) return ans;

	ans = 0;
	ans = makeAns(i+1, ( now * v[i] )%2520 );
	ans = ( ans%mod + makeAns(i+1 , now )%mod )%mod;

	return ans;
}

void go()
{
	cin >> t >> s;
	m = (int)t.size();
	n = (int)s.size();

	string now = t + '$' + s;
	auto z = Z(now , n + m + 1);

	for( int i = m + 1; i <= n + m; i++)
	{
		if( z[i] == m ) 
		{
			v.pb(i-m);
		}
	}

	n = (int)v.size();
	memset( dp , -1 , sizeof dp );

	int ans = makeAns();

	cout << ans << endl;



	// int nn = (int)v.size();

	// for( int i = 1; i < (1LL<<nn); i++)
	// {
	// 	int now = 1;
	// 	for( int j = 0; j < nn; j++)
	// 	{
	// 		if( i&(1LL<<j) ) now *= v[j];
	// 	}
		
	// 	bool ok = 0;
	// 	fo(j,1,10)
	// 	{
	// 		if( now%j )
	// 		{
	// 			ok = 1;
	// 			break;
	// 		}
	// 	}

	// 	if( !ok ) bug(now);
	// }

}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}

 