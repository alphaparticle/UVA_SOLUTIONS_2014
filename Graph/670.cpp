#include <bits/stdc++.h>
using namespace std ; 

vector < int > owner , vis ;
double dogx[111] , dogy[111] , bobx[111] , boby[111] ;
vector < int > adj [222];
int n , m , test ;

bool poss ( int i , int j ){
	if( i+1 >= n)
	return false ;
   double a = sqrt( (bobx[i+1]-bobx[i])*(bobx[i+1]-bobx[i]) + ((boby[i+1]-boby[i]))*(boby[i+1]-boby[i])) ;
   double b = sqrt( (dogx[j]-bobx[i])*(dogx[j]-bobx[i]) + (dogy[j]-boby[i])*(dogy[j]-boby[i]) ) ;
   b += sqrt ( (bobx[i+1]-dogx[j])*(bobx[i+1]-dogx[j]) + (boby[i+1]-dogy[j])*(boby[i+1]-dogy[j]) ) ;
 /*
   cout << i <<" "<<j+n <<" "<<"bob ("<< bobx[i]<<","<<boby[i]<<") -> ";
   cout << bobx[i+1]<<","<<boby[i+1]<<") ";
   cout << "("<<dogx[j] <<" "<<dogy[j]<<") " ;
   cout << 2.*a <<" "<<b << endl ;
   */
   if( b <= 2.0*a)
   return true ;
   else
   return false ;
}

int mcbm( int u ){
	if( vis[u])
	return 0 ;
   vis[u] = 1 ;
   for ( int i = 0 ; i < adj[u].size() ;i++){
   	int v = adj[u][i];
   	  if( owner[v] == -1 || mcbm(owner[v])){
   	  	 owner[v] = u ; return 1 ;
   	  }
   }
  return 0 ;
}

int main(){
	int i , j, k, l ;
   scanf("%d", &test);
   while ( test--){
   	 scanf("%d %d", &n , &m) ;
   	 for ( i = 0 ;  i <= n+m ; i++)
   	 adj[i].clear() ;
     for ( i = 0 ; i < n ; i++)
     scanf("%lf %lf", &bobx[i] , &boby[i]);
     for ( i = 0 ; i < m ; i++)
     scanf ("%lf %lf", &dogx[i] , &dogy[i]) ;
 //    for ( i = 0 ;i < m ; i++)
  //   cout << dogx[i] <<" "<<dogy[i] << endl;
      for ( i = 0 ;  i < n ; i++){
      	 for ( j = 0 ; j < m ; j++)
      	 if( poss(i,j) ){
      	 	 adj[i].push_back(n+j) ;
      	 }
      }
    /*
    for ( i = 0 ; i <= n+m ; i++){
    	 cout << i <<"->";
      for ( j = 0 ; j < adj[i].size() ;j++)
      cout << " "<<adj[i][j] ;
      cout << endl; 
    }
    */
    owner.assign(n+m+1,-1);
    int cc = 0 ;
    for ( i = 0 ;  i < n ; i++)
    {
    	 vis.assign(n+1,0);
         cc += mcbm (i) ;
    }
   // for ( i = n ; i < n+m ; i++)
  //  cout << i <<" "<<owner[i]<<endl;

    printf("%d\n", n+cc);
    for ( i = 0; i < n-1; i++){
    	printf("%.lf %.lf ", bobx[i],boby[i]);
    	for ( j = n ; j < n+m ; j++)
    	if( owner[j] == i){
    		printf("%.lf %.lf ", dogx[j-n],dogy[j-n]);
    		break ; 
    	}
    }
    printf("%.lf %.lf\n",bobx[n-1],boby[n-1] );
    if( test )
    printf("\n") ;
  }
	return 0; 
}
