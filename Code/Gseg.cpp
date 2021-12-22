#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#define ll long long int
#define F first
#define S second
#define FOR(i , begin , step , end) for(int i = begin  ; i <= int(end) ; i+=step)
#define see(a) cout << a << '\n';
#define REN(a) auto it = nullptr; for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(std::istream_iterator<std::string> it) { std::cerr << '\n';}
template <typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
	std::cerr << "| " << *it << " = " << a << " ";
	err(++it, args...);
}

using namespace std;


// huy function
int t;

int const sz = (int)5e5 + 10;

int seg[sz << 2];
int lazy[sz << 2];

void addLazy(int node , int val){
    lazy[node << 1] += val;
    lazy[node << 1 | 1] += val;
}

void pushDown(int node , int lx , int rx , int val){
     if(lazy[node] > 0){
        seg[node] += val;
        if(lx != rx) {
            addLazy(node, val);
        }
        lazy[node] = 0;
    }
}

void update(int l , int r , int val , int node , int lx , int rx){
    pushDown(node , lx , rx , lazy[node]);
    if(lx > r || rx < l || lx > rx)
        return;
    if(lx >= l && rx <= r){
        seg[node] += val;
        if(lx != rx){
            addLazy(node , val);
        }
        return;
    }
    int mx = (lx + rx) >> 1;
    update(l, r, val, node << 1 , lx , mx);
    update(l , r, val, node << 1 | 1 , mx + 1 , rx);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int get(int l , int r , int node , int lx, int rx){
    if(lx > r || rx < l || lx > rx)
        return 0;
     pushDown(node , lx , rx, lazy[node]);
    if(lx >= l && rx <= r){
        return seg[node];
    }
    int mx = (lx + rx) >> 1;
    ll sum1 = get(l, r , node << 1 , lx , mx);
    ll sum2 = get(l , r , node << 1 | 1 , mx + 1 , rx);
    return sum1 + sum2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    /**
        hello Huy
    **/


    string s; cin >> s;
    
    cin >> t;

    while(t--){
        int index , l , r;
        cin >> index >> l >> r;
        update(l , r , index , 1 , 1 , sz);
    }

    FOR(i , 0 , 1 , s.size() - 1){
        int cycle = (int)s[i] + (get(i + 1 , i + 1 , 1 , 1 , sz) % 26);
        if(cycle > 90) cycle = '@' + (cycle - 'Z');
        s[i] = (char)cycle;
    }

    see(s)
    return 0;
}

