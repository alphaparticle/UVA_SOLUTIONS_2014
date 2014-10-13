#include <bits/stdc++.h>
using namespace std ;

typedef vector < int > vi ;
map < vi , int > dp;
int tuple , combos , m ; int scost [11] , bcost[11] ;
int bonus [11][11] ;
vi order ;

int rec ( vi status ){
  	  if( dp.count(status) == 0)
	  dp[status] = -1 ;

	if( dp[status] != -1)
	return dp[status] ;
   
   int i , j, k ,ans = 0 ;
  
   for ( i = 0 ;  i < tuple ; i++)
   ans += scost[i]*status[i] ;
   
   for ( i = 0 ; i < combos ; i++ ){
   	    vi temp = status ; bool poss = true ;
   	    for ( j = 0 ; j < tuple ; j++)
   	    { 
           
            if( status[j] < bonus[i][j]){
   	    	poss = false ; break ;}
   	    }
   	   
   	    if( poss ){
   	    	for ( j = 0 ; j < tuple ; j++)
   	    	temp[j] -= bonus[i][j] ;
   	        ans = min ( ans , bcost[i] + rec(temp) ) ;
   	    }
   }

   dp[status] = ans;
  // for ( i = 0 ; i < tuple ; i++)
  // cout << status[i] <<" ";
  // cout << "-> "<<dp[status]<<endl;
   return dp[status] ; 
}

int main(){
    int i ,j, k, l; 
    while( scanf("%d",&tuple) != EOF ){
    	dp.clear() ;
    	for ( i = 0; i < tuple ; i++)
    	scanf("%d", scost+i);
        
        scanf("%d", &combos);
        for ( i = 0 ; i < combos ; i++){
        
	        for ( j = 0 ; j < tuple ; j++)
	        scanf("%d", &bonus[i][j]) ;
	        
	        scanf("%d", bcost+i);
       }

      dp.clear() ;
      scanf("%d", &m) ;
      while( m-- ){
      	  order.clear() ;
      	  for ( i = 0 ; i < tuple ; i++){
      	  	 scanf("%d" ,&j) ; order.push_back(j) ;
      	  }
         int ans = rec ( order );
         printf("%d\n", ans);
      }

    }
	return 0;
}
