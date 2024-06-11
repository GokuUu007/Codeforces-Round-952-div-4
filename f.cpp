/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifdef AKSHAT
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T, typename TT> void chmin (T &a, TT b) {if (a > b) swap(a, b);}
template<typename T, typename TT> void chmax (T &a, TT b) {if (a < b) swap(a, b);}



void solve() {
    int h, n;
    cin >> h >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    if (accumulate(all(a), 0LL) >= h) {
        cout << "1\n";
        return;
    }

    priority_queue<array<ll,3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    for (int i = 0; i < n; ++i) {
        h -= a[i];
        pq.push({b[i] + 1, b[i], a[i]});
    }
    while (h) {
        auto p = pq.top();
        pq.pop();

        if (h <= p[2]) {
            cout << p[0] << '\n';
            return;
        }

        h -= p[2];
        pq.push({p[0] + p[1], p[1], p[2]});
    }
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifdef AKSHAT   
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifdef AKSHAT
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
