#include <bits/stdc++.h>
using namespace std ;

int test , len; 
char path [1111];
int dp[1111][25][17] ;
bool pos ;

int rec ( int step , int timeofday , int timefromrest ){
	 if( step > len || timeofday >= 24 || timefromrest > 16 ){
	 	return 1e9 ;
	 }
	if( timeofday <= 6 || timeofday >= 18 )
	if( path[step] == '*' )
	return 1e9 ;
   
    if( dp[step][timeofday][timefromrest] != -1)
    return dp[step][timeofday][timefromrest] ;
    

    if( step == len ){
    	pos = true ;
    	dp[step][timeofday][timefromrest]= 0 ; return dp[step][timeofday][timefromrest] ;
    }

    dp[step][timeofday][timefromrest] = 0 ;
    int a , b ; a = b = 1e9 ;
    if( timefromrest <= 15 )
    a = 1 + rec ( step+1 , (timeofday+1)%24 , timefromrest+1 ) ;

    b = 1 + 8 + rec ( step+1 , (timeofday+9)%24 ,1) ;
    dp[step][timeofday][timefromrest] = min(a,b) ;
    return dp[step][timeofday][timefromrest] ;
}

int main(){
    scanf("%d",&test);
    for ( int kase = 1; kase <= test ; kase++ ){
    	scanf("%s",path);
        len = strlen ( path ) - 1 ;
        for (int i= 0; i <= len ; i++)
        for ( int j = 0 ; j <= 25 ; j++)
        for( int k = 0 ; k <= 16 ; k++)
        dp[i][j][k] = -1 ;

        pos = false ;
        int ans = rec ( 0 , 6 , 0);
        if( pos && ans < 1e9 ){
        	 printf("Case #%d: %d\n",kase ,ans) ;
        }
        else{
        	printf("Case #%d: -1\n",kase) ;
        }
    }
	return 0;
}
