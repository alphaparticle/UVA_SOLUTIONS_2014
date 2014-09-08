#include <bits/stdc++.h>
using namespace std ;

int test , D , n ;
char buffer [30] ;

int dist [111] , cost [111] ;
int dp   [111][211] ;
bool possible  ;

int rec ( int station , int fuelLeft ){
  //cout << station <<" "<< fuelLeft << endl; 
  if( fuelLeft < 0 || station > n)
  return 1e9 ;

    if( dp[station][fuelLeft] != -1 ){
      return dp[station][fuelLeft] ;
    }

    if( station == n && fuelLeft >= 100 ){
      dp[station][fuelLeft] = 0 ; possible = true ;
      //cout <<" pahucha "<< fuelLeft << endl;
      return dp[station][fuelLeft] ;
    }
    if( station == 0){
      int c = 1e9 ;
      for(int j = 1 ; j <= n && (dist[j] <= fuelLeft) ; j++){
       c = min ( c , rec( j , fuelLeft - dist[j]) ) ;
        // cout << j <<" "<< c << endl;
       }
        dp[station][fuelLeft] = c ;
        return c ;
    } 

    dp[station][fuelLeft] = 0;    
    int c = 1e9 ;
    for (int j = station+1 ; j <= n && ( dist[j] - dist[station] <= 200 ) ; j++ )
    for (int k = 0 ; k + fuelLeft <= 200 ; k++ )
    c = min ( c , (k) * cost[station] + rec( j , k + fuelLeft - ( dist[j] - dist[station] ) )  ) ;
   
   dp[station][fuelLeft] = c ;
   return dp[station][fuelLeft] ;
}

int main(){
   int i , j, k , len ; 
   int distance  ,tcost ; 
   scanf("%d",&test);
   while ( test--){
      scanf("%d",&D) ; possible = false ;
      getchar() ; 
      n = 1 ;
      while ( gets(buffer) && strlen(buffer) > 1  ){
         //puts(buffer) ;
          distance = tcost = 0 ;
          len = strlen ( buffer) ;
           for (i = 0 ; i < len ; i++ )
           if( buffer[i] >= '0' && buffer[i] <= '9' )
           distance = distance * 10 + ( buffer[i] - '0') ;
           else{ break ; }
          
           for (  ; i < len ; i++ )
           if ( buffer[i] >= '0' && buffer[i] <= '9' )
           tcost = tcost * 10 + ( buffer[i] - '0' ) ;
        
            dist[n] = distance ; cost[n] = tcost ;
            //cout << dist[n] <<" y "<<cost[n] << endl;
            n++;  
    }
   dist[n] = D ;
     dist [0] = 0 ; 
    // cout << n << endl; 
     for ( i  = 0 ; i <= n ;i++)
     for ( j =  0 ; j <= 200 ; j++)
     dp[i][j] = -1; 
    
     int ans = rec (0,100) ;
     
     if( possible && ans < 1e9 ){
      printf("%d\n",ans);
     }
     else
      puts("Impossible") ;
     if( test > 0)
     putchar('\n') ;
   } 
   return 0;
}
