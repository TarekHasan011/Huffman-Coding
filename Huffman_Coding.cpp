#include<bits/stdc++.h>
using namespace std;
struct TreeList
{
    int frequency;
    char c;
    TreeList* left;
    TreeList* right;
};

typedef struct TreeList TreeList;

TreeList* encoding(string &str)
{
    auto cmp = [](TreeList* a, TreeList* b)
    {
        return a->frequency>b->frequency;
    };

    priority_queue< TreeList* , vector< TreeList* >, decltype(cmp)> pq(cmp);
    map< char, int > mp;
    for(char c : str)
        mp[c]++;
    for(auto x : mp)
    {
        TreeList* temp = new TreeList();
        temp->frequency = x.second;
        temp->c = x.first;
        temp->left = temp->right = NULL;
        pq.push(temp);
    }
    while(pq.size()>1)
    {
        TreeList* temp = new TreeList();

        temp->left = pq.top();
        pq.pop();
        temp->right = pq.top();
        pq.pop();
        temp->c = '#';
        temp->frequency = temp->left->frequency+temp->right->frequency;
        pq.push(temp);
    }
    return pq.top();
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    string str; cin >> str;
    encoding(str);
    return 0;
}
