class DisjointSet
{
    vector<int>rank,parent,size;
    
    public:
      DisjointSet(int n)
      {
          rank.resize(n+1);
          parent.resize(n+1);
          size.resize(n+1);
          
          for(int i=0;i<=n;i++)
          {
              parent[i] = i;
              size[i] = 1;
          }
      }
      
      int findUparent(int node)
      {
          if(node == parent[node])
          {
              return node;
          }
          
          return parent[node] = findUparent(parent[node]);
      }
      
      void UnionByRank(int u,int v)
      {
          int ulp_u = findUparent(u);
          int ulp_v = findUparent(v);
          
          if(ulp_u == ulp_v)
          {
              return;
          }
          
          if(rank[ulp_v] < rank[ulp_v])
          {
              parent[ulp_u] = ulp_v;
          }
          
          else if(rank[ulp_v] > rank[ulp_u])
          {
              parent[ulp_v] = ulp_u;
          }
          
          else
          {
              parent[ulp_v] = ulp_u;
              rank[ulp_u]++;
          }
      }
      
      void UnionBySize(int u,int v)
      {
          int ulp_u = findUparent(u);
          int ulp_v = findUparent(v);
          
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
               size[ulp_u] = size[ulp_v] + size[ulp_u];
          }
      }
};



class Solution {
public:    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<vector<int>>adj(n);
        
        DisjointSet ds(n);
        
       for(int i = 0;i < isConnected.size();i++)   
       {
           for(int j = 0;j < isConnected[0].size();j++)
           {
               if(i != j && isConnected[i][j] == 1)
               {
                   adj[i].push_back(j);
                   adj[j].push_back(i);
                   ds.UnionBySize(i,j);
               }
           }
       }
       
       int cnt = 0; 
        
       for(int i=0;i<n;i++) 
       {
           if(i == ds.findUparent(i))
           {
               cnt++;
           }
       }
        
       return cnt; 
        
    }
};