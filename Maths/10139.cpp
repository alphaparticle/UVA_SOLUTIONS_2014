#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const LL m = 34000 ;
bool p[m+10];

vector < LL > prime ;

void seive () {
 memset ( p ,true , sizeof p ) ;
 LL i , j ;

   for ( i = 2; i <= m ; i++)
   if( p[i]){
      prime.push_back (i) ;
      for( j = i*i ; j <= m ; j += i)
      p[j] = false ; 
   }
  
}



bool itdivides ( LL FACT , LL num ){
	map < LL , LL > m1 ;
	map < LL , LL > m2 ;

	LL t,x ;
	t = x = num ;

	for (int i = 0 ; i < prime.size() && prime[i]*prime[i] <= t && prime[i] <= x ; i++)
	if( x%prime[i] == 0)
	{
		int p = 0 ;

		while ( x%prime[i] == 0)
		x /= prime[i] , p++ ;

	    m2 [ prime[i] ] = p ;
	}

	if( x > 1 )
	m2[x] = 1 ;
    
    for (map<LL ,LL> :: iterator it = m2.begin() ; it != m2.end() ; it++){
    	LL u = (*it).first ;
    	m1[ u ] = 0 ;
    	int p = 0 ;
    	for (LL j = u ; j <= FACT ; j  *= u )
        p += FACT/j ;
      // cout << "ff "<<prime[i] <<" "<<p << endl;
       m1[u] = p ;
    }

  bool istrue = true ;
  
  for (map<LL ,LL> :: iterator it = m2.begin() ; it != m2.end() ; it++)
  	if( m1[ (*it).first ] < (*it).second ){
  	 istrue = false ;
     break ;
    }
  

  if( istrue )
  	return true ;
  else
  	return false ;

}



int main(){

cin.sync_with_stdio(0) ;
cin.tie(0) ;
seive() ;


  LL x , y ;
  while ( cin >> x >> y ){
  	if( y == 0)
  	  {
         
  	  	cout << y <<" does not divide "<<x<<"!\n" ;
  	  	continue;
  	  }  
         
        if( y <= x){
  	  	 cout << y <<" divides "<<x<<"!\n" ; 
  	  	 continue ;
  	  }

  	  if ( itdivides(x,y) )
  	  	 cout << y <<" divides "<<x<<"!\n" ;
  	  	else
  	  	 cout << y <<" does not divide "<<x<<"!\n" ;

  }


}
