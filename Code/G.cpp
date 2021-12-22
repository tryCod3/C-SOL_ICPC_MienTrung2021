#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /**
        hello Huy
    **/
    
    string s; cin >> s;
    cin >> t;
    int a[s.size() + 2];
    memset(a , 0 , sizeof(a));

    while(t--){
        int index , l , r; cin >> index >> l >> r;
        a[l - 1] += index;  a[r] -= index;      
    }

    FOR(i , 0 , 1 , s.size() - 1){
        if(i > 0)
            a[i] += a[i - 1]; 
        int cycle = (int)s[i] + (a[i] % 26);
        if(cycle > 90) cycle = '@' + (cycle - 'Z');
        s[i] = (char)cycle;
    }

    see(s)

    return 0;
}

