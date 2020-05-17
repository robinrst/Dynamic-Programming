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

int a , b , c , A , B , aa , bb;
int dp[32][32][32][2];

int can( int aa , int bb , int cc )
{
     return ( aa + bb + cc )%2;
}

int getCarry( int aa , int bb , int cc)
{
     return ( aa + bb + cc )/2;
}

int makeAns(int i = 0, int A = aa , int B = bb , int pre = 0)
{
     if( A < 0 or B < 0 ) return 0;
     if( i == 31 )
     {
          return ( A == 0 and B == 0 and pre == 0 );
     }

     int& ans = dp[i][A][B][pre];
     if( ~ans ) return ans;

     ans = 0;

     int now = ( (c>>i)&1 );

     int _00 = can( 0 , 0 , pre);
     int _01 = can( 0 , 1 , pre);
     int _10 = can( 1 , 0 , pre);
     int _11 = can( 1 , 1 , pre);

     if( _00 == now)
     {
          int _00c = getCarry( 0 , 0 , pre );
          ans += makeAns( i + 1 , A , B , _00c );
     }

     if( _01 == now )
     {
          int _01c = getCarry( 0 , 1 , pre );
          ans += makeAns( i + 1, A , B - 1 , _01c );
     }

     if( _10 == now )
     {
          int _10c = getCarry( 1 , 0 , pre );
          ans += makeAns( i + 1 , A - 1 , B , _10c );
     }

     if( _11 == now )
     {
          int _11c = getCarry( 1 , 1 , pre );
          ans += makeAns( i + 1, A - 1 , B - 1 , _11c );
     }

     return ans;
}

void go()
{
     cin >> a >> b >> c;

     aa = __builtin_popcountll( a );
     bb = __builtin_popcountll( b );

     memset( dp , -1 , sizeof dp );

     int ans = makeAns();

     cout << ans << endl;
}

int32_t main()
{
     FAST;     
     int t=1; 
     cin>>t;
     test(t) go();
}

 