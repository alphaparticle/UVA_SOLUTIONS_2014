#include <bits/stdc++.h>
using namespace std;

int dp[10002] ;

int rec ( int x ){
	if ( dp[x] != -1)
	return dp[x] ;
	
	dp[x] = 1000 ;
	
	for ( int i = 1 ; i <= (int)sqrt(x) ; i++)
	dp[x] = min(dp[x] , 1+rec(x - (i*i)) );
	
	
	return dp[x] ;
	
}

int main() {
	memset ( dp , -1, sizeof dp);
	int i , j, k ;
	dp[0] = 0 ;
	dp[1] = 1;
	
	for ( i = 2 ; i <= 10000 ; i++)
	{
		cout<<rec(i);
	}

	
	
	return 0;
}
