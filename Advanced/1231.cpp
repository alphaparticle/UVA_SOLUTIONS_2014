#include <bits/stdc++.h>
using namespace std;
#define gc getchar
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int  acorn[2000][2001], dp[2001];

int main() {
  int i, j, c, t, h, f, a, n;
  scanint(c);
  while (c--) {
    scanf("%d %d %d", &t, &h, &f);
    
    for (i = 0; i < t; i++) {
      scanint(a) ;
      memset(acorn[i],0,sizeof (acorn[i]));
      for (j = 0; j < a; j++) {
        scanint(n);
        acorn[i][n]++; 
      }
    }
    memset(dp,0,sizeof dp);
    for (int tree = 0; tree < t; tree++) 
      dp[h] = max(dp[h], acorn[tree][h]);

    for (int height = h - 1; height >= 0; height--)
      for (int tree = 0; tree < t; tree++) {
        acorn[tree][height] +=
          max(acorn[tree][height + 1], 
          ((height + f <= h) ? dp[height + f] : 0)); 
        dp[height] = max(dp[height], acorn[tree][height]); 
      }
    printf("%d\n", dp[0]); 
  }
  

  return 0;
}
