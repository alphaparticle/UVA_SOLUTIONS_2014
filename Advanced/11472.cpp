#include <bits/stdc++.h>
using namespace std ;
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

int dp[102][12][1026];
int res;

int main ()
{
 int all, i , j, k , l , nx , pr ,n, m, t;
 //memset (dp, 0, sizeof dp);
 for ( j = 1; j <= 9; j++)
    dp[1][j][1<<j] = 1;
 for ( i = 1; i < 101; i++)
    for ( j = 0; j < 10; j++)
       for ( k = 1; k < 1024; k++)
       {
           nx = j+1;
           pr = j-1;
          if (nx < 10)
          {
             res = dp[i+1][nx][k|(1<<nx)];
             dp[i+1][nx][k|(1<<nx)] = (res + dp[i][j][k]) ; 
             if( dp[i+1][nx][k|1<<nx] >= 1000000007)
              dp[i+1][nx][k|1<<nx] -= 1000000007 ;
          }
          if (pr >= 0)
          {
             res = dp[i+1][pr][k|(1<<pr)];
             dp[i+1][pr][k|(k|1<<pr)] = (res + dp[i][j][k]) ;
             if( dp[i+1][pr][k|1<<pr] >= 1000000007)
             dp[i+1][pr][k|1<<pr] -= 1000000007 ; 
          }
       }   
 
 scanint(t) ;
 while(t--)
 {
    res = 0;
    scanint(n); scanint(m) ;
     all = (1<<n)-1 ;
    for ( i = n; i <= m; i++)
       for ( j = 0; j < n; j++){
          res = (res + dp[i][j][all]);
          if( res >= 1000000007)
          res -= 1000000007 ;
      }
    printf("%d\n",res);
 }
 return 0;
}
