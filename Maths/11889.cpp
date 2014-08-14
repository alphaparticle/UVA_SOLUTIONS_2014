#include <bits/stdc++.h>
using namespace std ;


typedef long long LL ;

LL gcd( LL a , LL b ){
	return (b==0)?a:(gcd(b,a%b)) ;
}

LL lcm ( LL a , LL b){
	return (a*b)/gcd(a,b) ;
}

int main(){
  
 cin.sync_with_stdio(0);
 cin.tie(0) ;

  LL a , c,b ;
  int test ;
  cin >> test ;
  while ( test-- ){
  	 cin >> a >> c ;
     if( c%a != 0)
     {
     	 cout<<"NO SOLUTION\n" ;
     	 continue;
     }

     b = c/a ;
     LL i ;
     for ( i = b ; i <= c ; i += b )
     if( lcm ( i , a) == c )
     break ;

     cout << i << "\n" ;
  }
    



	return 0 ;
}
