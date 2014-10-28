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

int test , n ;
int arr[4][15];
int dp [1<<13][301][3];

int topdown( int mask , int t , int last){
	//cout << mask <<" "<<t <<" "<<last << endl;
	 if( t < 0)
	 return -1e9 ;
		if( t == 0)
		return 0 ;
		
		if( last == -1){
		 	int ans = 0 ;
		 	for (int i = 0 ; i < 3; i++)
		 	for (int j = 0 ; j < n ; j++)
		 	ans = max( ans , 1 + topdown( mask|(1<<j) , t-arr[i][j] , i) );
		    return ans;
	   }

	if( dp[mask][t][last] != -1 )
	return dp[mask][t][last];
    
    int ans = 0;
    
    for( int i = 0 ; i < 3; i++)
    if( i != last )
    for( int j = 0; j < n ; j++)
    if( !(mask&(1<<j)) ) 	
    ans = max ( ans , 1 + topdown( mask|(1<<j) , t - arr[i][j] , i )) ;
  
  return dp[mask][t][last] = ans ;
}

int main(){
int i , j, k,l ;
   scanint(test);
   while( test-- ){
   	   scanint(n);
   	   for( i = 0 ; i < 3; i++){
   	   	  for( j = 0 ; j < n ; j++)
   	   	  scanint(arr[i][j]);
   	   }
   	   for ( i = 0 ; i <= (1<<n) ; i++)
   	   for( j = 0;  j <= 280 ; j++)
   	   for( k = 0;  k < 3 ; k++ )
   	   dp[i][j][k] = -1 ;
   	  int ans = topdown(0,280,-1);
   	  printf("%d\n",ans);
   }
	return 0;
}
