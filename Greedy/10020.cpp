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

/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/



int main(){
 vii segs , ans ;
 int i , j , k ,target ;
 int test  , u ,v , index ;bool f  ;
// bool first = true ;
 gi(test);
   while (test--){

   	   segs.clear() ; ans.clear() ;

        gi(target) ;
   	   
   	    while (1){
   	    	 g2i(j,k) ;
   	    	 if( j == 0 && k == 0)
   	    	 break ;
           segs.pb(ii(j,k)) ;
   	    }
   	  // cout<<"yahan";
   	  sort(segs.begin() , segs.end()) ;

   	  u = v = 0 ;
   	  f = false ;
   	   for ( i = 0 ; i < segs.size() ; ){
   	   	  
   	   	  	 j = i ; index = -1 ; 
   	   	   		while ( segs[j].P <= u  && j < segs.size()){
   	   	   	   			if ( segs[j].Q >= v){
   	   	   	   	 				v = segs[j].Q ; index = j ;
   	   	   	   			}
   	   	   	  		j++ ;
   	   	   	}

          if ( index == -1)
          break ;

   	   	  ans.pb(ii(segs[index].P , segs[index].Q)) ;
   	   	  u = v = segs[index].Q ;
   	   	  if ( u >= target){
   	   	   f = true ;
   	   	   break ;
   	   	  }
   	   	  
   	   	  i = index+1 ; 

   	   }
   	  if ( !f ){
   	  	printf("0\n");
   	  }
   	  else{
   	  pi((int)ans.size()) ;
   	  rep(i,ans.size())
   	   p2i(ans[i].P , ans[i].Q) ;
   	}

   	if(test)
   	printf("\n") ;
   
   }


	return 0;
}
