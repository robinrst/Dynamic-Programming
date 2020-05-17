#include        "algorithm"
#include        "iostream"
#include        "numeric"
#include        "iomanip"
#include        "cstring"
#include        "math.h"
#include        "bitset"
#include        "string"
#include        "vector"
#include        "random"
#include        "chrono"
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
#define          N (int)2e3+5
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
mii mp;
int dp[N]; // dp[i] -> denotes no of ways to make valid string till ith index

int makeAns(int i = 0 )
{
     if( i > n ) return 0;
     if( i == n ) return 1;

     int& ans = dp[i];
     if( ~ans ) return ans;

     ans = 0;

     for( int j = i; j < n; j++)
     {
          int len = j - i + 1;
          int ii = i;
          bool ok = 0;
            
          while( ii <= j ) ok |= ( len > mp[ s[ii++] - 'a' ] ); // check if (i ,j) is a valid substring 

          if( !ok ) ans = ( ans%mod + makeAns(j + 1)%mod )%mod;
     }

     return ans;
}

void go()
{
     cin >> n;
     cin >> s;

     fo(i,0,26) 
     {
          int x;
          cin >> x;
          mp[i] = x;
     }

     memset( dp , -1 , sizeof dp);

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

