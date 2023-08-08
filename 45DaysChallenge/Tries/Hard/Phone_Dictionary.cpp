//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
    TrieNode*child[26];
    vector<int>indx;
    public:
    TrieNode()
    {
        for(int i=0;i<26;i++)child[i]=nullptr;
    }
    TrieNode*get(char ch)
    {
        return child[ch-'a'];
    }
    bool isContainChar(char ch)
    {
        return child[ch-'a']!=nullptr;
    }
    void addNode(char ch,TrieNode*node)
    {
        child[ch-'a']=node;
    }
    void addIndex(int i)
    {
        indx.push_back(i);
    }
    vector<int>getIndexes()
    {
        return indx;
    }
};

class Solution{
    TrieNode*trie;
    void add(string s,int indx)
    {
        TrieNode*curr=trie;
        for(int i=0;i<s.size();i++)
        {
            if(!curr->isContainChar(s[i]))
            {
                TrieNode*node=new TrieNode();
                curr->addNode(s[i],node);
            }
            curr->addIndex(indx);
            curr=curr->get(s[i]);
        }
    }
    vector<vector<int>> search(string s)
    {
        TrieNode*curr=trie;
        bool isTrue=true;
        vector<vector<int>>res;
        for(int i=0;i<s.size();i++)
        {
            if(!curr->isContainChar(s[i])||!isTrue)
            {
                res.push_back({});
                isTrue=false;
                continue;
            }
            curr=curr->get(s[i]);
            res.push_back(curr->getIndexes());
        }
        return res;
    }
public:
    Solution()
    {
        trie=new TrieNode();
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // sort(contact,contact+n);
        for(int i=0;i<n;i++)
        {
            add(contact[i],i);
        }
        vector<vector<int>>indxes=search(s);
        vector<vector<string>>result;
        for(int i=0;i<indxes.size();i++)
        {
            set<string>curr;
            for(int j=0;j<indxes[i].size();j++)
            {
                curr.insert(contact[indxes[i][j]]);
            }
            if(curr.empty())
                result.push_back({"0"});
            else
            {
                vector<string>temp(curr.begin(),curr.end());
                result.push_back(temp);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends