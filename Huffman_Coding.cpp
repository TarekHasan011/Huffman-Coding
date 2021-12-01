#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    string str; cin >> str;
    map< char, int > mp;
    for(char c : str)
        mp[c]++;
    for(auto x : mp)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
