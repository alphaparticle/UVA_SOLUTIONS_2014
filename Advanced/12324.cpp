#include <bits/stdc++.h>
using namespace std ;
#define gc getchar
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
typedef pair < int , int > ii ;

int n ; map < ii , int > dp ;
int t [111] , sphere[111] ;
int rec ( int index , int sphereleft){
	if( dp.count(ii(index,sphereleft)) == 0)
	dp[ ii ( index,sphereleft)] = -1 ;

	if( dp[ii(index,sphereleft)] != -1)
	return dp[ii(index,sphereleft)] ;
  
   int b,a = 1e9 ;
 
   if( index == n-1){
   	  for ( int j = 0 ; j <= min(1,sphereleft); j++)
   	  a = min( a ,((t[index])>>j) ) ;
   	  return dp[ii(index,sphereleft)] = a ;
   }
   
   for ( int j = 0 ; j <= min(1,sphereleft) ; j++)
   {
         // cout <<endl<< t[index] <<" "<<j <<" "<< (t[index]>>j)<<endl;
          b = (t[index]>>j) + rec( index+1 , sphereleft-j+sphere[index]);
         // cout << a <<" "<<b<<endl;
          a = min ( a , b);
         
   }
  // cout <<"final "<< a << endl;
   return dp[ii(index,sphereleft)] = a ;
}
int main(){
  int i , j, k, l ;
    while ( 1 ){
    	 scanint(n);
    	 if( n == 0 )
    	 break ;
    	dp.clear() ;
    	int sum = 0;
       for ( i = 0 ; i  < n ; i++)
       scanint(t[i]),scanint(sphere[i]), sum += sphere[i] ;
       assert( sum < 11111 );
       
       //memset ( dp , -1, sizeof dp);
       int ans  = rec ( 0 , 0 );
       printf("%d\n",ans);
    }

	return 0 ;
}
