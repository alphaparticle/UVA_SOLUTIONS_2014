#include <bits/stdc++.h>
using namespace std ;

int n ;
double checkpoint [101] ,b, r , v , e ,f ;
double dp[101][10001] ;
double res [11111];

double topdown( int index , int distancewithoutchangingtyre ){
   
   if( dp[index][distancewithoutchangingtyre] != -1.0 )
   	return dp[index][distancewithoutchangingtyre] ;

   
	     double t = 0.0 ;
         t = res[ distancewithoutchangingtyre-1];           
         
         if( index+1 <= n)
         t = min ( t + b + topdown(index+1,checkpoint[index+1]-checkpoint[index]),  topdown(index+1, distancewithoutchangingtyre+ checkpoint[index+1]-checkpoint[index]));   
         return dp[index][distancewithoutchangingtyre] = t;
	   
   
}


int main(){
  int i  , j, k, l ;
  while ( scanf("%d", &n)){
  	  if ( n == 0)
  	  break ;
  	  checkpoint[0] = 0.0;
  	  for ( i = 1; i <= n ; i++)
  	  scanf("%lf", checkpoint+i);
  	  scanf("%lf",&b);
  	  scanf("%lf %lf %lf %lf", &r , &v , &e ,&f) ;
      for ( int x = 0 ; x <= checkpoint[n] ; x++)
      res[x] = 0.0 ;

  	  for( int x = 0 ; x <= checkpoint[n] ; x++)
         if( x >= r){
         	  //assert(( v - ( e*((x*1.0)-r))) >= 0.01 ) ;
         	  //cout <<" < "<<( v - ( e*((x*1.0)-r)))<<endl;
              res[x]= (1*1.0)/( v - ( e*((x*1.0)-r))) ;
              if( x-1 >=0)
              res[x] += res[x-1];
         }
         else{
         	 //assert(( v - (f *( r - (x*1.0)))) >= 0.01) ;
            // cout <<" > "<< ( v - (f *( r - (x*1.0)))) <<endl;
             res[x] = (1*1.0)/( v - (f *( r - (x*1.0)))) ;
             if( x-1 >= 0)
             res[x] += res[x-1] ;
         }
  	  
  	  for ( i = 0 ;  i <= n ; i++)
  	  for ( j = 0 ; j <= checkpoint[n] ;j++)
  	  dp[i][j] = -1.0 ;
  	  double ans = topdown (1,checkpoint[1]);
  	  printf("%.4lf\n",ans);
  }


	return 0 ;
}
