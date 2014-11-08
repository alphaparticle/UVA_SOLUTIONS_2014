#include <bits/stdc++.h>
using namespace std ;
typedef long long LL ;
bool p[1000010] ;
vector < LL > aprimes ;

void seive(){
   memset ( p ,true ,sizeof p);
   LL i , j , x;
   for ( i = 2 ; i <= 1e6 ; i++)
   if( p[i] ){
   	 
   	 for ( j = i*i ; j <= 1e6  ; j += i)
   	 p[j] =false ;
   	 x = i*i ;
   	 //aprimes.push_back(i*i) ;
   	 while ( x <= 1e12){
   	 	 aprimes.push_back(x);
   	 	 x *= i ;
   	 }
   }
}

int main(){
  seive() ;// cout << aprimes.size()<<endl;
  sort( aprimes.begin() , aprimes.end());
 // for ( int i = 0 ; aprimes[i] <= 20 ; i++)
 // cout << aprimes[i]<<endl;
  int test ,  index1 ,index2;
  LL a , b;
  vector < LL > :: iterator it  ,fit ;
   scanf("%d",&test);
   while( test-- ){
         scanf("%lld %lld", &a ,&b);
         it = lower_bound(aprimes.begin() , aprimes.end() , a);
         fit = lower_bound(aprimes.begin() , aprimes.end() , b);
   //      cout << *it <<" ini "<<*fit <<endl;
         index1 = index2= -1 ;
         if( fit != aprimes.end() ){
         	while( fit != aprimes.begin() && *fit > b )
         	fit-- ;
            index2 = fit - aprimes.begin() ;
         }
         if( it != aprimes.end() ){
         	while( it != aprimes.end() && *it < a )
         	it++ ;
            index1 = it - aprimes.begin() ;
         }
      int ans = 0 ;
     // cout <<" "<<index2<<" "<<index1<<" ";
      if( index1!=-1 && index2 != -1){
           if( index2 >= index1)
           ans = index2-index1+1 ;
      }
      printf("%d\n",ans);
   }
	return 0;
}
