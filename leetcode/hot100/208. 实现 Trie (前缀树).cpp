/*
 * @Author: dsaDadas11
 * @Date: 2026-04-23 21:49:51
 * @LastEditTime: 2026-04-23 22:08:02
 * @Description: go for it!
 */
class Trie {
public:
    int ch[600007][29];
    int cnt[600007];
    int idx;
        
    Trie() {
        idx=0;
        memset(ch,0,sizeof ch);
        memset(cnt,0,sizeof cnt);
    }
    
    void insert(string word) {
        int p=0;
        int len=word.size();
        for(int i=0;i<len;i++)
        {
            int u=word[i]-'a';
            if(!ch[p][u]) ch[p][u]=++idx;
            p=ch[p][u];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p=0;
        int len=word.size();
        for(int i=0;i<len;i++)
        {
            int u=word[i]-'a';
            if(!ch[p][u]) return 0;
            p=ch[p][u];
        }
        return cnt[p];
    }
    
    bool startsWith(string prefix) {
        int p=0;
        int len=prefix.size();
        for(int i=0;i<len;i++)
        {
            int u=prefix[i]-'a';
            if(!ch[p][u]) return 0;
            p=ch[p][u];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


/*
链表实现，可以实现动态开点

class Trie {
public:
    bool ed;
    vector<Trie*> ch;
        
    Trie() : ch(26), ed(0) {
        
    }
    
    void insert(string word) {
        Trie *node=this;
        int len=word.size(); // 注意要指向当前的 Trie 对象
        for(int i=0;i<len;i++)
        {
            int u=word[i]-'a';
            if(node->ch[u]==NULL) node->ch[u]=new Trie();
            node=node->ch[u];
        }
        node->ed=1;
    }
    
    bool search(string word) {
        Trie *node=this;
        int len=word.size();
        for(int i=0;i<len;i++)
        {
            int u=word[i]-'a';
            if(node->ch[u]==NULL) return 0;
            node=node->ch[u];
        }
        return node->ed;
    }
    
    bool startsWith(string prefix) {
        Trie *node=this;
        int len=prefix.size();
        for(int i=0;i<len;i++)
        {
            int u=prefix[i]-'a';
            if(node->ch[u]==NULL) return 0;
            node=node->ch[u];
        }
        return 1;
    }
};
*/