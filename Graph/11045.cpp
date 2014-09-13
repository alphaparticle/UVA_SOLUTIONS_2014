#include <bits/stdc++.h>
using namespace std;

bool possible ;
int  n ,moo ;
vector <string > cur [33] ;
map < string , int > dic ;
void rec (int index , int xxl , int xl , int l , int m , int s , int xs ){
   //cout << index <<" "<<xxl<<" "<<xl <<" "<<l <<" "<< m <<" "<<s <<" "<<xs <<endl;
    if ( possible )
    return;
   
   if ( xxl < 0 || xl < 0 || l < 0 || m < 0 || s < 0 || xs < 0)
   return ;

    if( index == moo && xxl >= 0 && xl >= 0 && l >= 0 && m >= 0 && s >= 0 && xs >= 0 ){
    	// cout <<"--------------> "<< index <<" "<<xxl<<" "<<xl <<" "<<l <<" "<< m <<" "<<s <<" "<<xs <<endl;
  
    	possible = true ; return ;
    }
    else if( index == moo)
    return ;
    
   int type1  = dic[ cur[index][0] ] ;
   switch ( type1 ){
   	  case 0 :
   	     rec (index+1,xxl-1,xl,l,m,s,xs);
   	     break;
   	  case 1 :
   	     rec (index+1,xxl,xl-1,l,m,s,xs);
   	     break;
   	  case 2 :
   	     rec (index+1,xxl,xl,l-1,m,s,xs);
   	     break;
   	  case 3 :
   	     rec (index+1,xxl,xl,l,m-1,s,xs);
   	     break;
   	  case 4 :
   	     rec (index+1,xxl,xl,l,m,s-1,xs);
   	     break;
   	  case 5 :
   	     rec (index+1,xxl,xl,l,m,s,xs-1);
         break;
   }

   type1  = dic[ cur[index][1] ] ;
   switch ( type1 ){
   	  case 0 :
   	     rec (index+1,xxl-1,xl,l,m,s,xs);
   	     break;
   	  case 1 :
   	     rec (index+1,xxl,xl-1,l,m,s,xs);
   	     break;
   	  case 2 :
   	     rec (index+1,xxl,xl,l-1,m,s,xs);
   	     break;
   	  case 3 :
   	     rec (index+1,xxl,xl,l,m-1,s,xs);
   	     break;
   	  case 4 :
   	     rec (index+1,xxl,xl,l,m,s-1,xs);
   	     break;
   	  case 5 :
   	     rec (index+1,xxl,xl,l,m,s,xs-1);
         break;
   }  
   
   return ;


}

int main(){
  cin.sync_with_stdio(0) ; cin.tie(0) ;
	dic["XXL"] = 0 ;
	dic["XL"] = 1 ;
	dic["L"] = 2 ;
	dic["M"] = 3 ;dic["S"] = 4 ; dic["XS"] = 5; 
    int test , i, j , k, l;
    cin >> test ;
    string a , b ;

    while ( test-- ){
    	 cin >> n >> moo ;
    	 possible  = false ; n /= 6 ;
    	 for ( i = 0 ; i < moo ; i++){
    	 	  cur[i].clear() ;
              cin >> a >> b ;
              cur[i].push_back(a) ; cur[i].push_back(b) ;              
    	 }
    	rec(0,n,n,n,n,n,n) ;
    	if( possible )
    	cout<<"YES\n";
    	else
    	cout<<"NO\n" ;     
    }
	return 0;
}
