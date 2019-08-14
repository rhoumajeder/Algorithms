//  Solution FOR 
// https://arena.topcoder.com/#/u/practiceCode/17193/65413/14946/2/331413

#include <vector>
#include <string>

using namespace std;

using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int r, c;

void dfs (vvi& v, const vs& a, int x, int y, int m) 
{
   auto is_valid = [](int x, int y) {
      return x >= 0 && x < r &&
               y >= 0 && y < c;
   };

   if (!(v[x][y] == -1 || v[x][y] > m)) return;

   v[x][y] = m;
   for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!is_valid (nx, ny)) continue;
      if (a[nx][ny] == '.') {
         dfs (v, a, nx, ny, m + 1);
      } else {
         do {
            if (a[nx][ny] == '.') {
               dfs (v, a, nx, ny, m + 2);
               break;
            }
            nx += dx[i], ny += dy[i];
         } while (is_valid (nx, ny));
      }
   }
}


int pathLength (vs a, int r1, int c1, int r2, int c2) 
{
   r = a.size ();
   c = a[0].size ();
   vvi v (r, vi (c, -1));

   dfs (v, a, r1, c1, 0);

   return v[r2][c2];
}
//---------------------------------------------//
//solution for
// https://leetcode.com/contest/weekly-contest-109/problems/shortest-bridge/


#define FORI(s,n) for(int i = s; i < n; i++)
#define FORJ(s,n) for(int j = s; j < n; j++)

using vi  = vector<int>;
using vvi = vector<vi>;
using island = set<pair<int, int>>;

class Solution {
public:

   int n;
   vi dx = { 0, 0, 1, -1 };
   vi dy = { 1, -1, 0, 0 };

   bool is_valid(int x, int y) {
      return (x >= 0 && x < n && y >= 0 && y < n);
   }

   void flood_fill(island& A, const vvi& g, int x, int y) {
      A.insert({ x, y });
      FORI(0, 4) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (is_valid(nx, ny) && g[nx][ny] && !A.count({ nx, ny }))
            flood_fill(A, g, nx, ny);
      }
   }

   template<class T>
   int dist(T a, T b) {
      return abs(a.first - b.first) + abs(a.second - b.second) - 1;
   }

   int shortestBridge(vvi& g) {
      n = g.size();
      island A, B;

      FORI(0, n) {
         FORJ(0, n) {
            if (g[i][j] == 0) continue;
            if (A.empty())
               flood_fill(A, g, i, j);
            else if (B.empty() && !A.count({ i, j }))
               flood_fill(B, g, i, j);
         }
      }

      int ans = 2 * n;
      for (auto i : A)
         for (auto j : B)
            ans = min(ans, dist(i, j));

      return ans;
   }
};
