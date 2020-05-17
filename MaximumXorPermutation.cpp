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
#define          N (int)2e5+5
#define          pb push_back
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long 
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
#define          PI acos(-1.0)
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

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m, k,xx , yy, zz;
vi v[11];
int dp[11][11][11];

void process()
{
	fo(i,0,1024) // 2^10 can be upto 1024
	{
		int no = i;
		int ones = 0;

		while( no )
		{
			if( no&1 ) ones++; // count number of ones
			no >>= 1;
		}

		v[ones].pb(i);
	}
}

bool check( int xx, int yy , int zz )
{
	return ( dp[xx][yy][zz] != -1 );
}

void makeAns(int xx)
{
	vi temp;
	while( xx )
	{
		temp.pb(xx&1);
		xx >>= 1;
	}

	reverse(all(temp) );
	while(temp.size() < 10 ) temp.pb(0);

	for( auto j : temp ) cout << j;
	cout << endl;
}

void go()
{
	string aa,bb,cc;

	cin >> aa >> bb >> cc;
	xx = yy = zz = 0;

	fo(i,0,aa.size()) xx += ( aa[i] - '0' );// number of ones in string
	fo(i,0,bb.size()) yy += ( bb[i] - '0' );// number of ones in string
	fo(i,0,cc.size()) zz += ( cc[i] - '0' );// number of ones in string

	if( check(xx,yy,zz) ) // if already computed for that number of ones
	{
		makeAns(dp[xx][yy][zz]); 
		return;
	}

	int ans = 0;

	for( int i = 0; i < v[xx].size(); i++)
	{
		for( int j = 0; j < v[yy].size(); j++)
		{
			for( int k = 0; k < v[zz].size(); k++)
			{
				int pehla = v[xx][i];// using a particular number with that number of ones
				int dusra = v[yy][j];// using a particular number with that number of ones
				int tisra = v[zz][k];// using a particular number with that number of ones
				
				int XOR = pehla^dusra^tisra; 
				ans = max( ans , XOR); // updating maximum xor;
			}
		}
	}

	dp[xx][yy][zz] = ans; // for that particular number of ones , storing the answer
	makeAns(ans);
}

int32_t main()
{
	// INP(); 
	FAST; 
	process();
	memset(dp,-1,sizeof dp);    
	int t=1; 
	cin>>t;
	test(t) go();
}

 