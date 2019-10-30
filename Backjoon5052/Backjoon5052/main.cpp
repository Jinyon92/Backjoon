#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int TrieNode = 10;

struct Trie{
    Trie *next[TrieNode];
    bool nextChild;
    bool finish;
    
    Trie(){
        fill(next, next+TrieNode, nullptr);
        finish = nextChild = false;
    }
    
    ~Trie(){
        for(int i=0; i<TrieNode; i++){
            if(next[i]) delete next[i];
        }
    }
    
    bool insert(const char *key){
        if(*key == '\0'){
            finish = true;
            
            if(nextChild) return 0;
            else return 1;
        }
        int nextKey = *key - '0';
        if(!next[nextKey]) next[nextKey] = new Trie;
        
        nextChild = true;
        bool get = next[nextKey]->insert(key+1);
        return !finish && get;
    }
};

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--){
        int n;
        scanf("%d", &n);

        Trie *root = new Trie;
        bool chk = true;

        for(int i=0; i<n; i++){
            char phone[11];
            scanf("%s", phone);

            if(chk && root->insert(phone) == 0) chk = false;
        }

        if(chk) printf("YES\n");
        else printf("NO\n");

        delete root;
    }
    return 0;
}
