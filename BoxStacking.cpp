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
#define          N (int)4e5+5
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
int dp[N]; // dp[i] -> maximum height sum in which ith box is on top

struct box
{
	int h , w , l;

}a[N];

bool can( int j , int i)
{
	return ( a[j].w > a[i].w  and a[j].l > a[i].l ); // check whether ith box can be placed over jth box
}

void go()
{
	cin >> n;
	int cn = 1;

	a[0].l = a[0].w = inf;
	a[0].h = 0;

	fo(i,0,n) 
	{
		int h , w , l;
		cin >> h >> w >> l;

		a[cn] = { h , max(l,w) , min(l,w) };
		a[cn+1] = { l , max( h ,w) , min( h,w ) };
		a[cn+2] = { w , max(h ,l) , min( h ,l) };

		cn += 3;
	}

	sort( a + 1 , a + 3*n + 1 , [&] ( box x , box y) -> bool
	{
		return ( x.w * x.l > y.w * y.l );
	});

	int ans = 0;

	memset( dp , 0 , sizeof(int)*(3*n+1) );
	dp[0] = 0;

	fo(i,1,3*n+1)
	{
		for(int j = i-1; ~j; j--)
		{
			if( can(j , i) ) // can ith box on top jth box
			{
				dp[i] = max( dp[i] , dp[j] + a[i].h ); // if ith box can be placed on top of jth box , then increase height of ith box by adding ith box height to jth box height
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

 