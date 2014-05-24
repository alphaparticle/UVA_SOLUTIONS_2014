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


typedef vector <int> vi ;
bool used[21000] ;
int main(){
  vi dragonHead ,  knight ;
  vi :: iterator it ;
  int i , j , k , n , m ,x , ans; bool f ;
  while ( g2i(n,m)){
  	   if( n == 0 && m == 0)
  	   break ;
        dragonHead.clear() ;
  	   	rep(i,n)
  	   	{
  	   		gi(j);
  	   		dragonHead.pb(j) ;
  	   	}

  	   	knight.clear() ;
  	   	rep(i,m){
  	   		gi(j);
  	   		used[i] = false ;
  	   		knight.pb(j) ;
  	   	}

  	   	sort(knight.begin() , knight.end()) ;
  	   	ans =  0 ; f = true ;
  	   	rep(i,n){
  	   		 x = dragonHead[i] ;
             it = lower_bound(knight.begin() , knight.end() , x) ;
             if( it != knight.end() ){
                       if ( !used[it - knight.begin()] ){
                       	 ans += *it ;
                       	 used[ it - knight.begin() ] = true ;
                       }
                       else{
                       	     while( it != knight.end() ){
                       	     	  	if ( !used[it - knight.begin()] ){
				                         ans += *it ;
				                       	 used[ it - knight.begin() ] = true ;
				                       	 break ;
				                       }
				                    it++ ;
                       	     }

                       	     if( it == knight.end() ){ f = false ; break ;}
                       }
             }
             else{
             		f  = false ; break ; 
             }
  	   	}

  	   	if(f){
  	   		pi(ans);
  	   	}
  	   	else
  	   		printf("Loowater is doomed!\n");

  }


	return 0;
}
