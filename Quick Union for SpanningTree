

"""
Adapted to Challenge Coding test , https://arena.topcoder.com/#/u/practiceCode/17142/62856/14888/2/331177

"""


#include <algorithm>
#include <vector>
#include <numeric>


using namespace std;

 

   const int MOD = 987654323;

   void Quick_Union (int x, int y, vector<int>& root, vector<int>& size)
   {
      while (y != root[y]) y = root[y];
      while (x != root[x]) x = root[x];
      
      if (x == y) return;
      
      root[x] = root[y];
      size[y] += size[x];
   }

   int Number_Spanning_Tree(int n,  vector<int> y,vector<int> x)
   {
      int m = n - 3;

      for (auto& e : x) e--;  
      for (auto& e : y) e--;  

      vector<int> root (n);    // after quick union, will store "root" of connected component
      vector<int> size (n, 1); // after quick union, will store "size" of each connected component
      iota (root.begin (), root.end (), 0);

      for (int i = 0; i < m; i++) Quick_Union (x[i], y[i], root, size);

      vector<long long> size_comp; //  store size of each connected component 
      for (int i = 0; i < n; i++) if (root[i] == i) size_comp.push_back (size[i]);

      if (size_comp.size () != 3) return 0;

      long long A = size_comp[0] * size_comp[1]; // edge 1
      long long B = size_comp[1] * size_comp[2]; // edge 2
      long long C = size_comp[0] * size_comp[2]; // edge 3

      return (A*B + B*C + A*C) % MOD;
   }
 
