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
#define          N (int) 51+5
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
#define            bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

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
int a[N][N];
int pre[N][N];
int dp[N][N][N][N]; // dp[i][j][k][l] -> minimum cost to make whole rectangle white

bool EMPTY(int x1, int y1, int x2 , int y2)
{
     return ( pre[x2][y2] - pre[x2][y1-1] - pre[x1 - 1][y2]  + pre[x1-1][y1-1] == 0 );
}

int makeAns(int x1 = 1 , int y1 = 1 , int x2 = n , int y2 = n )
{
     int& ans = dp[x1][y1][x2][y2];
     if( ~ans ) return ans;
     
     if( EMPTY( x1 , y1 , x2 , y2) ) return dp[x1][y1][x2][y2] = 0;


     ans = max( x2 - x1 + 1 , y2 - y1 + 1);

     for( int i = x1; i < x2; i++)
     {
          ans = min( ans , makeAns( x1 , y1 , i , y2 ) + makeAns( i+1 , y1 , x2 , y2 ) );
     }

     for( int j = y1; j < y2; j++)
     {
          ans = min( ans , makeAns( x1 , y1 , x2 , j ) + makeAns( x1 , j + 1 , x2 , y2) );
     }

     return ans;
}

void go()
{
     cin >> n;

     fo(i,1,n+1) 
     {
          fo(j,1,n+1)
          {
               char ch;
               cin >> ch;
               a[i][j] = ( ch == '#' );
          }
     }

     fo(i,1,n+1) fo(j,1,n+1) pre[i][j] = pre[i][j-1] + a[i][j];
     fo(j,1,n+1) fo(i,1,n+1) pre[i][j] += pre[i-1][j];

     memset( dp , -1 , sizeof dp );

     int ans = makeAns();

     cout << ans << endl;
}

int32_t main()
{
     FAST;     
     int t=1; 
     // cin>>t;
     test(t) go();
}
