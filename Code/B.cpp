#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

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


ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    /**
        hello Huy
    **/
    
    int n; cin >> n;

    vector<ll> ve;
    ll checkZero = 0;
    ll res = 0;

    FOR(i , 1 , 1 , n){
        ll x; cin >> x;
        if(x == 0){ checkZero ++;
            continue;
        }
        ve.push_back(x);
    }

    if(checkZero > 1){
        see(res)
    }else{
        bool check1 = false;
        int dem = 0;
        res = 1;
        sort(ve.begin(), ve.end());
        FOR(i , 0 , 1 , ve.size() - 1){
            if(ve[i] < 0) dem++;
            if( ( (ve[i] < 0 && i + 1 < ve.size() && ve[i + 1] > 0) || (ve[i] < 0 && i + 1 == ve.size()) )  && dem & 1 && !checkZero)
                continue;
            check1 = true;
            res *= ve[i]; res %= mod;
        }
        if(!check1) res = 0;
        if(res < 0 && checkZero) res = 0;
        see(res)
    }


    while(t--){
	
    }

    return 0;
}

