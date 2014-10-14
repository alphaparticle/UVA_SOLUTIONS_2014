#include <bits/stdc++.h>
using namespace std;

int dp [1<<20] ;
int n ; int ability [33] ;

int rec ( int status ){
   

   int index = 0; int i , j, k , ans = 0 ;
   
   for ( i = 0 ; i < n ;i++){
     if( status[i] == '1' )
   	 index += (1<<i) ;
   }

   if( dp[index] != -1){ 
   return dp[index] ; }
   
   
   for ( i = 0 ; i < n ; i++)
   if( status[i] == '0')
   for ( j = i+1 ; j < n ; j++)
   if( status[j] == '0' )
   for ( k = j+1 ; k < n ; k++)
   if( status[k] == '0' && ability[i]+ability[j]+ability[k] >= 20 ){
   	  string alpha = status ; alpha[i]= alpha[j] = alpha[k] = '1' ;
   	  ans = max( ans , 1 + rec(alpha)) ;
   }

   dp[index] = ans ;
   
   return dp[index] ;

}


int main(){
    int kase = 1 ;
    while( scanf("%d",&n)  ){
    	 if( n == 0)
    	 break ;
    	 string t ;
    	 for ( int i = 0 ;  i < n ; i++ )
    	 {
    	 	  t += '0' ;
    	 	  scanf("%d" ,ability+i) ;
    	 }
         for (int i = 0 ; i <= (1<<n) ; i++)
         dp[i] = -1 ;
    	 sort ( ability ,ability+n);
    	 reverse( ability , ability+n) ;
    	
    	printf("Case %d: %d\n",kase++, rec(t) );
    
    }

	return 0;
}
