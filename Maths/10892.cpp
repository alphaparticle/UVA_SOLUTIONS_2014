#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;
set  <LL> store ;

LL gcd ( LL a ,LL b){
	 return ( (b==0)?a:(gcd(b,a%b))) ;
}

LL lcm ( LL a ,LL b){
	return (a*b)/gcd(a,b) ;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
 LL a  ;
 while ( cin >> a){
 	 if( a == 0)
 	 break ;
    store.clear() ;
    for ( LL i = 1 ; i*i <= a ; i++ )
    if( a%i == 0 )
    store.insert(i),store.insert(a/i) ;
   
  //  cout << store.size() << endl;
   // for ( set <LL> :: iterator it = store.begin() ; it != store.end() ; it++)
  //  cout << " "<<*it ;
   // cout << endl;
     int steps = 0 ; 
     for ( set <LL >:: iterator it = store.begin() ; it != store.end() ; it++ )
     for ( set <LL> :: iterator fit = it ; fit != store.end() ; fit++)
     if( lcm (*it , *fit) == a )
     steps++ ;

   cout << a <<" "<<steps <<"\n";

 }
  return 0 ;

}
