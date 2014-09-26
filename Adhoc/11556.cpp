#include <bits/stdc++.h>
using namespace std ;

int main(){
 long long n , b , c;
 while (cin >> n >> b ){
  c = 1LL<<(b+1) ;
 //cout << c << endl;
 if( n < c )
 	puts("yes");
 else
 	puts("no") ;
}

	return 0;
}
