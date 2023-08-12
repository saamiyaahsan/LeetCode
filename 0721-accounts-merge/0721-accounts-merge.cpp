class DisjointSet{
    
    vector<int>rank;
    vector<int>parent;
    vector<int>size;
    
    public:
       DisjointSet(int n)
       {
           rank.resize(n+1);
           parent.resize(n+1);
           size.resize(n+1,0);
           
           for(int i=0;i<=n;i++)
           {
               parent[i] = i;
           }
       }
    
       int findParent(int node)
       {
           if(node == parent[node])
           {
               return node;
           }
           
           return parent[node] = findParent(parent[node]);
       }
    
       void unionByRank(int u,int v)
       {
           int ulp_u = findParent(u);
           int ulp_v = findParent(v);
           
           if(ulp_u == ulp_v)
           {
               return;
           }
           
           if(rank[ulp_u] < rank[ulp_v])
           {
               parent[ulp_u] = ulp_v;
           }
           
           else if(rank[ulp_u] > rank[ulp_v])
           {
               parent[ulp_v] = ulp_u;
           }
           
           else
           {
               parent[ulp_v] = ulp_u;
               rank[ulp_u]++;
           }
       }
    
       void unionBySize(int u,int v)
       {
           int ulp_u = findParent(u);
           int ulp_v = findParent(v);
           
           if(ulp_u == ulp_v)
           {
               return;
           }
           
           if(size[ulp_u] < size[ulp_v])
           {
               parent[ulp_u] = ulp_v;
               size[ulp_v] = size[ulp_v] + size[ulp_u];
           }
           
           else
           {
               parent[ulp_v] = ulp_u;
               size[ulp_u] = size[ulp_u] + size[ulp_v];
           }
       }
};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        
        DisjointSet ds(n);
        
        unordered_map<string,int>MapmailNode;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                
                if(MapmailNode.find(mail) == MapmailNode.end())
                {
                    MapmailNode[mail] = i;
                }
                
                else
                {
                    ds.unionByRank(i,MapmailNode[mail]);
                }
            }
        }
        
        vector<string>mergedMail[n];
        
        vector<vector<string>>ans;
        
        for(auto it : MapmailNode)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(it.first);
        }
        
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size() == 0)
            {
                continue;
            }
            
            else
            {
                sort(mergedMail[i].begin(),mergedMail[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                
                for(auto it : mergedMail[i])
                {
                    temp.push_back(it);
                }
                
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};