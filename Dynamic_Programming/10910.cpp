#include <bits/stdc++.h>
using namespace std;

long dp[75][75] ;
long N,T,P ;

int rec ( int cur , int left){
  

   if ( dp[cur][left] != -1)
   return dp[cur][left] ;
   
   
  if ( cur == N){
  	  if ( left >= P)
  	  {
  	  	 if (dp[cur][left] == -1)
  	  	 dp[cur][left] = 1 ;
  	  	 else
  	  	 dp[cur][left] += 1 ;
  	  	 return dp[cur][left] ;
  	  }
  	  else
  	  return  0 ;
  }
  
  
  
   
   dp[cur][left] = 0 ;
   for ( int i = P ; i < left ; i++)
   dp [cur][left] += rec ( cur+1 , left-i ) ;
   
   return dp[cur][left] ;

}

int main() {
	long  i , j,  k , test ;
	cin >> test ;
	while(test--){
		  memset ( dp , -1 ,sizeof dp) ;
	    scanf("%ld %ld %ld",&N ,&T ,&P) ;
		  long ans = rec ( 1 , T);
		  printf("%ld\n",ans) ;
		  
		  
		  
		 
	}
	return 0;
}
