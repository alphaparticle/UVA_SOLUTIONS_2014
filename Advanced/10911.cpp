#include <bits/stdc++.h>
using namespace std ;

map < string , double > dp; 
double dis [20][20] ;
char name [22] ;
double x[20] ,y[20] ;
int n ;

double rec( string u , int index ){
     
     if( index >= u.length())
     return 0.0 ;
     if( u[index] == '1' )
     return rec( u , index+1) ;

	 if( dp.count(u) == 0 )
	 dp[u] = -1.0 ;

	if( dp[u] != -1.0)
	return dp[u] ;
   
   double sol = 1e9 ;
   for (int i = 0 ; i < u.length() ; i++){
   	  string temp = u ;
   	  if ( u[i] == '0' && i!= index){
   	  	  temp[i] = temp[index] = '1' ;
   	  	  sol = min ( sol , dis[index][i] + rec(temp ,index+1));
   	  }
   }
  dp[u] = sol ;
  return dp[u] ;
}

int main(){
	int kase = 1 ;
     while( scanf("%d",&n) != EOF){
     	 if( n == 0 )
     	 break;
     	 for ( int i = 0 ; i < 2*n ; i++)
     	 scanf("%s %lf %lf",name , &x[i], &y[i]) ;
     	 for (int i = 0 ; i < 2*n; i++)
     	 for ( int j = i+1 ; j < 2*n ; j++)
     	 dis[i][j] = dis[j][i] = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ) ;

     	 dp.clear();
     	 string t ;
     	 for (int i = 0 ; i < 2*n ; i++ )
     	 t += '0' ;

     	 double ans = rec(t,0);
     	 printf("Case %d: %.2lf\n",kase++, ans) ;
     }

	return 0;
}
