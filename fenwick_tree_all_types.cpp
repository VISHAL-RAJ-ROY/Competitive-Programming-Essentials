/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define posLSB(X) __builtin_ctz(X)
#define num1bit(X) __builtin_popcount(X)
#define numlead0(X) __builtin_clz(X)
#define gcd(X,Y) __gcd(X,Y)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<"\n";
#define name(X) (#X)
#define watch(X) cout << (#X) << " is " << (X) << "\n"
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SEL(X,C) for( auto & X : C )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {} template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cout << *it << " = " << a << "\n"; err(++it, args...);}
template <class T> struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } T operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);} T operator()(tuple<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(get<0>(x) + FIXED_RANDOM)^(splitmix64(get<1>(x) + FIXED_RANDOM) >> 1); } }; // T operator()(pair<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1); } }; 
template <class L, class R> ostream & operator<<(ostream &os, pair<L,R> P) { return os << "(" << P.xx << "," << P.yy << ")"; } template<class L, class R> ostream &operator<<(ostream &os, tuple<L,R> P) {return os << "(" << get<0>(P) << "," << get<1>(P) <<")"; } template<class L, class R, class S> ostream &operator<<(ostream &os, tuple<L,R,S> P) { return os << "(" << get<0>(P) << "," << get<1>(P) << ","<< get<2>(P) <<")"; } template<class T, class A> ostream &operator<<(ostream& os, vector<T,A> V) {os /*<< name(V)<< " is "*/ << "\n"; FOR(i,0,sz(V)) os <<"  "<< name(V) << "["<<i<<"] = "<< V[i] << "\n"; return os; /*<<"\n";*/ } template<class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_set<T,H,P,A> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class S, class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_map<S,T,H,P,A> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class C, class A> ostream &operator<<(ostream& os, multiset<T,C,A> S) { os /*name(S) << " is"*/<<"["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class R> ostream &operator<<(ostream& os, gp_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, gp_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class R> ostream &operator<<(ostream& os, cc_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, cc_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ }

using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>; template <class S, class T = le<S>> using ms =  multiset<S,T>; template <class S,class T = null_type, class R = size_t> using gp =  gp_hash_table<S,T,custom_hash<R>>; template <class S,class T = null_type, class R = size_t> using cc =  cc_hash_table<S,T,custom_hash<R>>; template <class S,class T, class R = size_t> using um =  unordered_map<S,T,custom_hash<R>>; template <class S, class R = size_t> using us =  unordered_set<S,custom_hash<R>>;

/*
Welcome to VISHAL RAJ ROY's template library :) the following are here to serve you>>
v_ = vector of '_'                   |    li = long long int      |   For fast insertion/deletion ->
vl = vector of long                  |    db = double             |               gp<T,S,R>
vi = vector of int                   |    st = string             |   For fast read/write -> cc<T,S,R>
supported:                           |    ii = pair<int,int>      |   For slow everything ->
1) vi, vvi, vvvi   4) vl, vvl, vvvl  |    iii = pair<int,ii>      |        um<T,S,R> .. R = ( size_t or uint64_t )
2) vii, viii       5) vll, vlll      |    i2 = tuple<int,int>     |        and us<T,R> .. R = ( size_t or uint64_t )
3) vi2, vi3        6) vl2, vl3       |    cdb = complex double    |   supported :
7) vcd                               |    i3 = tuple<int,int,int> |   int/li/pair -> int/li/string/pair...pair<int/li,int/li>
watch(X) is the WATCH DOG, it can print anything and everything, COULD'NT believe? just try it>> 
error(a,b,c,......) takes many parameters and shows you their true face>> 
*/

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

class ftree {
    private:
        vi tree; int n;
    public : 
        void initialize( int N ) {
            n = N; tree.assign(N,0);
        }
        ftree() {}
        ftree( vi & init ) {
            initialize(sz(init));
            FOR(i,0,n)
                point_update(i,init[i]);
        }
        void point_update( int pos, int val ) {
            for(;pos < n; pos = (pos|(pos+1)))
                tree[pos] += val;
        }
        int sum( int l ) {
            int ans = 0;
            for( ; l >= 0 ; l = (l&(l+1))-1 )
                ans += tree[l];
            return ans;
        }
        int sum( int l, int r ) {
            return sum(r)-(l > 0 ? sum(l-1) : 0 );
        }
};

class ftree_one_indexed {
    private:
        vi tree; int n;
    public:
        void initialize( int N ) {
            n = N+1; 
            tree.assign(n,0);
        }
        ftree_one_indexed() {}
        ftree_one_indexed( vi & init ) {
            initialize(sz(init));
            FOR(i,1,n)
                point_update(i,init[i-1]);
        }
        void point_update( int pos, int val ) {
            for(; pos < n; pos += (pos&(-1*pos))) 
                tree[pos] += val;
        }
        int sum( int pos ) {
            int ans = 0;
            for(; pos > 0; pos -= (pos&(-1*pos))) 
                ans += tree[pos];
            return ans;
        }
        int sum( int l, int r ) {
            return sum(r)-sum(l-1);
        }
};

class ftree_point_query_range_update {
    private:
        ftree norm_f; int n;
    public:
        ftree_point_query_range_update( int N ) {
            n = N;
            norm_f.initialize(n);
        }
        ftree_point_query_range_update( vi & init ) : ftree_point_query_range_update(sz(init)) {
            FOR(i,0,n) 
                range_update(i,i,init[i]);
        }
        void range_update( int l, int r, int val ) {
            norm_f.point_update(l,val);
            if( r+1 < n ) norm_f.point_update(r+1,-1*val);
        }
        int point_query( int pos ) {
            return norm_f.sum(pos);
        }
};

class ftree_range_update_range_query {
    private:
        ftree f1, f2; int n;
    public:
        ftree_range_update_range_query( int N ) {
            n = N;
            f1.initialize(N); f2.initialize(N);
        }
        ftree_range_update_range_query( vi & init ) : ftree_range_update_range_query(sz(init)) {
            FOR(i,0,n) 
                update(i,i,init[i]);
        }
        void update( int l, int r, int val ) {
            f1.point_update(l,val);
            if( r+1 < n ) f1.point_update(r+1,-1*val);
            f2.point_update(l,val*(l-1)); 
            if( r+1 < n ) f2.point_update(r+1,-1*val*r);
        }
        int sum( int pos ) {
            return f1.sum(pos)*pos-f2.sum(pos);
        }
        int sum( int l, int r ) {
            return sum(r)-(l > 0 ? sum(l-1) : 0);
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    vi v{1,2,3,4,5,6,7,8,9,10};
    ftree f1(v);
    ftree_point_query_range_update f2(v);
    ftree_range_update_range_query f3(v);
    // testing ftree
    cout<<f1.sum(2,5);nl;
    f1.point_update(4,1); f1.point_update(0,1); f1.point_update(9,1);
    cout<<f1.sum(0,9)<<" "<<f1.sum(2,5)<<" "<<f1.sum(0,2)<<" "<<f1.sum(9); nl; 
    // testing ftree_point_query_range_update
    FOR(i,0,10) 
        if( f2.point_query(i) != v[i] ) 
            cout<<"lol",nl;
    f2.range_update(0,0,1);
    f2.range_update(9,9,1);
    f2.range_update(2,5,1);
    FOR(i,0,10) 
        cout<<f2.point_query(i)<<" ";
    nl;
    f2.range_update(2,5,1);
    FOR(i,0,10) 
        cout<<f2.point_query(i)<<" ";
    nl;
    f2.range_update(2,9,1);
    FOR(i,0,10) 
        cout<<f2.point_query(i)<<" ";
    nl;
    f2.range_update(0,5,1);
    FOR(i,0,10) 
        cout<<f2.point_query(i)<<" ";
    nl;
    // testing ftree_range_update_range_query
    FOR(i,0,10) 
        cout<<f3.sum(i,i)<<" ";
    nl;
    f3.update(2,4,1); f3.update(0,0,1); f3.update(0,1,1); f3.update(6,9,1); f3.update(9,9,1);
    FOR(i,0,10) 
        cout<<f3.sum(i,i)<<" ";
    nl;
    f3.update(2,8,1);
    FOR(i,0,10) 
        cout<<f3.sum(i,i)<<" ";
    nl;
     // testing ftree_one_indexed
    ftree_one_indexed f4(v);
    cout<<f4.sum(3,6);nl;
    f4.point_update(5,1); f4.point_update(1,1); f4.point_update(10,1);
    cout<<f4.sum(1,10)<<" "<<f4.sum(3,6)<<" "<<f4.sum(1,3)<<" "<<f4.sum(10); nl; 
    return 0;
}
