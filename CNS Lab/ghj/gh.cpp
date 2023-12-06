#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    // string t="",r="";
    // for(int i=0;i<s.size();i++)
    // {
    //     if(i%2==0)t+=s[i];
    //     else r+=s[i];
    // }
    unordered_set<string>p;
    for(int i=0;i<s.size();i++)
    {
        string tem="";
        tem+=s[i];
        // p.insert(tem);
        for(int j=0;j<s.size();j++)
        {
            if(i!=j)tem+=s[j];
            cout<<tem<<" ";
        }
    }
    // for(int i=0;i<r.size();i++)
    // {
    //     string tem="";
    //     tem+=r[i];
    //     p.insert(tem);
    //     for(int j=0;j<r.size();j++)
    //     {
    //         if(i!=j)tem+=r[j];
    //         p.insert(tem);
    //     }
    // }
    // for(auto  i:p)cout<<i<<" ";
    // cout<<p.size();
return 0;
}