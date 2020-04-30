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
#define          N (int)5e3+5
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
#define          bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

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
int a[N] , b[N];
vector< vi > dp;

void go()
{
    cin >> n >> m;

    dp.assign( n + 1 , vi( m+1 , inf) );

    fo(i,1,n+1) cin >> a[i];
    fo(i,1,m+1) cin >> b[i];

    sort( a + 1 , a + 1 + n);
    sort( b + 1 , b + 1 + m);

    fo(i,1,m+1) dp[1][i] = min( dp[1][i-1] , abs( a[1] - b[i] ) ); // base case

    fo(i,2,n+1)
    {
    	fo(j,1,m+1)
    	{
    		int xx = dp[i][j-1]; //  pairing with previous 
    		int yy = abs( a[i] - b[j] )  + dp[i-1][j-1]; // pairing with current 
    		dp[i][j] = min( xx , yy);
    	}
    }

    cout << dp[n][m] << endl;
}

int32_t main()
{
    FAST;     
    int t=1; 
    // cin>>t;
    test(t) go();
}
