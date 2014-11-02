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

int dp[33][642][642];
int arr[33] , sum,n;
int topdown( int ind , int a , int b){
	if( ind == n){
		 return  max(a,max(sum-a-b,b)) - min(a,min(sum-a-b,b));
	}
	if( dp[ind][a][b] != -1)
	return dp[ind][a][b] ;
   int ans  = 1e9 ;
   ans = min( ans  , topdown(ind+1,a+arr[ind],b));
   ans = min ( ans , topdown(ind+1,a,b+arr[ind]));
   ans = min( ans , topdown(ind+1,a,b));
   return dp[ind][a][b] = ans ;
}

int main(){
 // freopen("in.txt","r",stdin);
 // double st = clock() ;
   int i , j, k, l ,test;
    scanint(test);
    for( int ppp =  1 ; ppp <= test ; ppp++)
    {
   	    scanint(n) ;  sum = 0 ;
   	    for ( i = 0 ; i < n ; i++)
   	    scanint(arr[i]) , sum += arr[i] ;
   	    for ( i = 0 ; i < n ; i++)
   	    for( j = 0 ; j <= sum ; j++)
   	    for( k = 0 ; k <= sum ; k++)
   	    dp[i][j][k] = -1 ;
   	    printf("Case %d:",ppp);
   	    printf(" %d\n",topdown(0,0,0));     
    }
  //printf("%.3lf\n", ((clock()-st)*1.0)/(CLOCKS_PER_SEC*1.0) );
	return 0;
}
