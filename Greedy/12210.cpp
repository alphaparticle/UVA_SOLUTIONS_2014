/*
Date : 
Time : 
author - @alphaparticle
Problem id : 
Problem name : 
Problem Link : 
*/

#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610 
#define LIM 1000000
#define gi(n)                      scanf("%d", &n) 
#define gc(c)                      scanf("%c", &c) 
#define g2i(n,m)                   scanf("%d %d", &n , &m) 
#define g3i(a,b,c)                 scanf("%d %d %d",&a ,&b ,&c)
#define gl(n)                      scanf("%ld",&n)
#define g2l(a,b)                   scanf("%ld %ld",&a ,&b)
#define g3l(a,b,c)                 scanf("%ld %ld %ld",&a,&b,&c)
#define pb                         push_back
#define rep(i,n)                   for( int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
#define P                          first
#define Q                          second
#define pi(n)                      printf("%d\n",n)
#define ps(s)                      printf("%s\n",s.c_str()) 
#define p2i(a,b)                   printf("%d %d\n",a,b)
#define FILL (x,a)                 memset ( x , a ,sizeof x) 

typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
typedef vector <int> vi ;
/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/
vi s , b ;


int main(){
vi :: iterator it , fit , kit;
int ns , nb , i  , j , k , kase = 1 ;
  while ( g2i(nb,ns) ){
  	   	if( nb == 0 && ns == 0)
  	   	break ;
  	    s.clear() ; b.clear() ;
  	    rep( i , nb ){
  	    	 gi(j) ;
  	    	 b.pb(j) ;
  	    }
  	    rep(i,ns){ gi(j); s.pb(j) ; }
  	    sort(s.begin() , s.end()) ;
  	    sort(b.begin() , b.end() );
                
        		for(  ; b.size() > 0 ;  )
        		 {
        		 	   it = b.end() ; it-- ;
        		 	   fit = lower_bound( s.begin() , s.end() , *it) ;
        		 	   //cout << *it <<" >>  " ;
        		 	  
        		 	   if ( fit != s.end() ) {
        		 	   	     
        		 	   	     if( *fit == *it  || fit == s.begin() ){
        		 	   	  			// cout << *fit << endl; 
        		 	   	   			b.erase(it) ; s.erase(fit) ;
        		 	   	   			continue ;
        		 	          }
        		 	   	    kit = fit ; kit-- ;
        		 	   	    if( abs(*it - *kit) < abs(*it - *fit) ) {  // cout << *kit << endl ;
        		 	   	    											s.erase(kit) ; }
        		 	   	    else {
        		 	   	    	 //  cout << *fit << endl;
        		 	   	    		s.erase(fit) ;
        		 	   	    	 }
        		 	   	    b.erase(it) ;
        		 	   }
        		 	   else if ( fit == s.end() && s.size() > 0 )
        		 	   	{
                                   fit-- ;
                                   s.erase(fit) ; b.erase(it) ;
        		 	   	}
        		 	   	else
        		 	   	break ;
        		 	   	

        		 	   if ( s.size() == 0)
        		 	   	break ;
        		 }

  	    if ( (int)b.size() > 0){
  	    	printf("Case %d: %d %d\n",kase++ , (int)b.size() , b[0] ) ;
  	    }
  	    else{
  	    	printf("Case %d: 0\n",kase++) ;
  	    }
  }


	return 0;
}
