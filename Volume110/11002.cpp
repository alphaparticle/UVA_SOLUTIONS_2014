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

typedef vector < int > vi ;
bool ispresent[62][62][6010];
int n ;
int input[66][66];
int  rl   [66] ,rr[66];



void solve () {
    int i , j, k, l , sum = 0;
    for( i = 0 ; i <= 2*n ; i++)
    for ( j = 0 ; j <= 2*n ; j++)
    { input[i][j] = 0  ;
    }
  
   l = 2 ;
   for( i = 0 ; i < 2*n-1 ; i++){
   	   
   	   if( i <= n-1){
   	   rl[i] = n-i ; rr[i] = n+i ;
   	   for( j = rl[i]; j <= rr[i] ; j += 2 )
   	   scanint( input[i][j]) , sum += abs(input[i][j]);// cout<<" "<<input[i][j] ;
   	   //cout << endl;
   	  }
   	  if( i > n-1)
   	  {
   	  	 rl[i] = rl[i-l]  ; rr[i] = rr[i-l];
   	  	 for ( j = rl[i] ; j <= rr[i] ; j += 2)
   	  	 scanint( input[i][j] ), sum += abs(input[i][j]) ;
   	  	 //cout << endl;
   	  	 l+=2 ;
   	  }
   }
  //cout << sum << endl;
  sum = min( sum ,3000);
  for (  i = 0 ; i < 2*n ;i++)
  {  //cout << rl[i] <<" "<<rr[i]<< endl;
  	 for( j = 0 ; j < 2*n ; j ++){
  	  //printf(" %3d",input[i][j]);
       for ( k = 3000-sum ; k <= 3000+sum ; k++)
       ispresent[i][j][k] = false;
  	}
  	 //cout << endl;
  }
  
  ispresent[0][n][3000-input[0][n]] = ispresent[0][n][3000+input[0][n]] = true ;
  for ( i = 1 ; i < 2*n-1 ; i++)
  {   
  	  
  	 for( j = rl[i] ; j <= rr[i] ; j += 2)
  	 {
  	 	  //int q = 0 ;
  	 	  for ( k = 3000-sum ; k <= 3000+sum ; k++)
  	 	  if( ispresent[i-1][j-1][k] )
  	 	  ispresent[i][j][k+input[i][j]] = ispresent[i][j][k-input[i][j]] = true ;
  	      
  	      for ( k = 3000-sum ; k <= 3000+sum ; k++)
  	 	  if( ispresent[i-1][j+1][k] )
  	 	  ispresent[i][j][k+input[i][j]] = ispresent[i][j][k-input[i][j]] = true ;
  	      //for ( k = 3000 -sum ; k <= 3000+sum ; k++)
  	     // if ( ispresent[i][j][k])
  	     // q++ ;
  	     //cout << i <<" "<<j <<" "<<q << endl;
  	 }
  
  }
  int ans = 1e9 ;
  for ( i = 3000 ; i <= 3000+sum ; i++)
  if( ispresent[2*n-2][n][i] )
  {
  	 ans = min( ans ,abs(i-3000)); break ;
  }

  for ( i = 3000 ; i >= 3000-sum ; i++)
  if( ispresent[2*n-2][n][i] )
  {
  	 ans = min( ans ,abs(i-3000)); break ;
  }
  printf("%d\n",ans);
}


int main(){
	memset ( ispresent,false,sizeof ispresent);
    while(1){
    	scanint(n);
    	if(n == 0)
    	break ;
        solve() ;
    }
	return 0;
}
