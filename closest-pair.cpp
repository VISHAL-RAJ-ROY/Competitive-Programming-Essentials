/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define um(A,B) unordered_map <A, B>
#define us(A) unordered_set <A>
#define ms(A) multiset <A>
#define all(x) x.begin(),x.end()
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(X) freopen("X.txt","w",stdout);
#define read(X) freopen("X.txt","r",stdin);
#define FOR(i,A,B) for( auto (i) = (A); (i) < (B); (i)++ )
#define FORN(i,A,B) for( auto (i) = (B); (i) >= (A); (i)-- )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN

typedef long long int li;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef unordered_map<int,int> umii;
typedef unordered_map<string,int> umsi;
typedef unordered_set<string> uss;
typedef unordered_set<int> usi;
typedef unordered_set<int, usi> usii;
typedef multiset<int> msi;
typedef multiset<string> mss;
typedef pair<li, li> ll;
typedef pair<li, ll> lll;
typedef vector<li> vl;
typedef vector<ll> vll;
typedef vector<lll> vlll;
typedef vector<vl> vvl;
typedef unordered_map<li,li> umll;
typedef unordered_map<string,li> umsl;
typedef unordered_set<string> uss;
typedef unordered_set<li> usl;
typedef unordered_set<li, usl> usll;
typedef multiset<li> msl;
typedef multiset<string> mss;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

int mindist = ima; pair<ii,ii> bestpoint;

vii t;

bool c_x( ii a, ii b ) {
    return a.xx < b.xx || (a.xx == b.xx && a.yy < b.yy );
}

bool c_y( ii a, ii b ) {
    return a.yy < b.yy;
}

void update( ii p1, ii p2 ) {
    int d = sqr(p1.xx-p2.xx)+sqr(p1.yy-p2.yy); 
    if( d < mindist ) {
        mindist = d; bestpoint = {p1,p2};
    }
}

void closestpair( vii A, int l, int r ) {
    if( r-l <= 3 ) {
        sort(A.begin()+l,A.begin()+r,c_y);
        FOR(i,l,r)
            FOR(j,i+1,r)
                update(A[i],A[j]);
        return;
    }
    int mid = (l+r) >> 1;
    ii midp = A[mid];
    closestpair(A,l,mid); closestpair(A,mid,r);
    merge(A.begin()+l, A.begin()+mid, A.begin()+mid, A.begin()+r, t.begin(), c_y);
    copy(t.begin(),t.begin()+r-l,A.begin()+l);
    int k = 0;
    FOR(i,l,r)
        if( sqr(midp.xx-A[i].xx) < mindist ) {
            for( int j = k-1; j >= 0 && sqr(A[i].yy-t[j].yy) < mindist; j-- ) update(A[i],t[j]);
            t[k++] = A[i];
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    //vii A{{15,2},{7,2},{5,2},{1,2},{30,2},{16,16},{32,35},{45,32}};
    vii A{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sort(A.begin(), A.end(), c_x);
    t.resize(sz(A));
    closestpair(A,0,sz(A));
    cout<<sqrt(mindist)<<"dddddd\n";
    cout<< bestpoint.xx.xx <<" "<< bestpoint.xx.yy<<" "<< bestpoint.yy.xx<<" "<< bestpoint.yy.yy<<"\n";
    return 0;
}