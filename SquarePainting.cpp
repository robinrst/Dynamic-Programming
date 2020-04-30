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

int n,m,k,q , row , col;
string s[N];
int a[N][N];
int pRow[N] , pCol[N] , 
canR[N][N], // canR[i][j] -> if (i,j) is clicked then how many rows will be white 
canC[N][N]; // canC[i][j] -> if (i,j) is clicked then how many columns will be white 


void go()
{
	cin >> n >> k;

	fo(i,1,n+1) 
	{
		cin >> s[i];
		s[i] = " " + s[i];
		fo(j,1,n+1)
		{
			a[i][j] = ( s[i][j] == 'B' );
		}
	}

	fo(i,1,n+1) 
	{
		fo(j,1,n+1)
		{
			pRow[j] = pRow[j-1] + a[i][j];
		}

		if( !pRow[n] ) row++;
		for( int j = 1; j + k - 1 <= n; j++)
		{
			int req = pRow[j+k-1] - pRow[j-1];
			canR[i][j] = canR[i-1][j] + ( req == pRow[n] and pRow[n] != 0);
		}

	}

	fo(j,1,n+1)
	{
		fo(i,1,n+1)
		{
			pCol[i] = pCol[i-1] + a[i][j];
		}

		if( !pCol[n] ) col++;

		for( int i = 1; i + k - 1 <= n; i++)
		{
			int req = pCol[i+k-1] - pCol[i-1];
			canC[i][j] = canC[i][j-1] + ( req == pCol[n] and pCol[n] != 0);
		}
	}
   	int ans = 0;

	for( int i = 1; i + k -1 <= n; i++)
	{
		for( int j = 1; j + k -1 <= n; j++)
		{
			int r = canR[i+k-1][j] - canR[i-1][j];
			int c = canC[i][j+k-1] - canC[i][j-1];

			ans = max( ans , r + c  );
		}
	}

	cout << ans + row + col << endl;
}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}

 