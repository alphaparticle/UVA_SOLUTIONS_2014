#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

LL gcd ( LL a , LL b)
{
	 return ( (b==0)?a:(gcd(b,a%b)) ) ;
}

int main(){

 cin.sync_with_stdio(0);
 cin.tie(0);
   int test , i, j, k;
   string s ;
   cin >> test;

   while ( test){
   	   getline(cin,s);
       
       if( s.length() <= 1){
       	 continue ;
       }
      
       //cout << s <<"--\n";
       test--;
 
   	   LL a ,temp ;
   	   a = temp = 0;
       vector < LL > NUM ;
   	   for ( i = 0 ; i < s.length() ; i++)
   	   if( s[i] >= '0' && s[i] <= '9' ){
   	   	   temp = temp * 10 + ( s[i] - '0' );
   	   }
   	   else{
   	   	 // cout << temp << endl;
   	   	  if( temp > 0)
   	   	  NUM.push_back ( temp );
   	   	  temp = 0;
   	   }

   	  if( temp > 0)
   	  NUM.push_back ( temp );
   	  
   	 //cout << NUM.size() << endl;
   	 for ( i = 0 ; i < NUM.size() ; i++)
   	 for ( j = i+1 ; j < NUM.size() ; j++)
   	 a = max( a , gcd(NUM[i],NUM[j])) ;
   	cout << a << "\n";
   }
	return 0; 
}
