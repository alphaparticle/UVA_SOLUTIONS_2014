#include <bits/stdc++.h>
using namespace std ;

int gcd ( int a , int  b){
	 return ( (b==0)?a:(gcd(b ,a%b)) ) ;
}


int main(){
 
 cin.sync_with_stdio(0);
 cin.tie(0);
  int a , b  , i, j, k , l ;
  while ( cin >> a){
  	  if( a == 0)
  	  break ;
  	vector  < int > p ;
  	p.push_back ( a) ;
  	while ( cin >> b ){
  		 if( b == 0 )
  		 break ;
  		p.push_back (b) ;
  	}
  	sort(p.begin() , p.end()) ;
  	vector < int > diff ;
  	for ( i = 1 ; i < p.size() ; i++)
  	diff.push_back( p[i] - p[i-1] ) ;
    
    int ans = diff[0] ;
    for (  i = 1 ; i < diff.size() ; i++)
    ans = gcd ( ans , diff[i]) ;
   
   cout << ans << endl;

  }


	return 0 ;
}
