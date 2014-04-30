#include <bits/stdc++.h>
using namespace std;
#define readint(n) scanf("%d",&n) 
#define read2int(x,y) scanf( "%d %d" ,&x ,&y)

//typedef pair <int ,int > ii ;

float dis [10][10] ;
int x[10] ,y[10] ;
vector <int> sys ;
int n ;
float ans,temp;

int main(){
int i , j, k , kase = 1 ;
while (readint(n) ){
     if ( n == 0)
     break ;
      
    for ( i = 0 ; i < n ; i++)
    read2int( x[i] , y[i] );// ,printf("%d >> %d\n",x[i],y[i]);
    
    for ( i = 0 ; i < n ; i++){
      for ( j = i+1 ; j < n ; j++)
      dis[i][j] = dis[j][i] = 16.0 + sqrt( ( (x[i]-x[j])*(x[i]-x[j]) ) + ( (y[i]-y[j])*(y[i]-y[j]) ) );
    }

    /*for ( i = 0 ; i < n ; i++)
    {
    	 for( j = 0 ; j < n ; j++)
    	 printf("%f ", dis[i][j]);
    	cout << endl;
    }*/

   int per[n] ; sys.clear() ;
  
   for ( i = 0 ; i < n ; i++)
   per[i] = i , sys.push_back (i);

   //sys.clear() ;
   ans = 0.0 ; 
   for ( i = 1 ; i < n ; i++ )
   ans += dis[per[i]][per[i-1]] ;
 //  cout << ans << endl;
   while ( next_permutation (per , per+n) ){
   	     bool f = true ;
   	    // for ( i = 0 ; i < n ; i++)
   	     //cout<<per[i]<<" ";

   	     for ( i = 0 ; i < n ; i++)
   	     if ( per[i] != i) { f = false ; break ;}
   	     if (f) break ;
   	     temp = 0.0 ;
   	     for ( i = 1 ; i < n ; i++ )
         temp += dis[per[i]][per[i-1]] ;
 
         if ( temp < ans){
         	 sys.clear() ;
         	 ans = temp ;
             for ( i = 0 ; i < n ; i++)
             sys.push_back(per[i]);
        }   
   }
  printf("**********************************************************\n");
  printf("Network #%d\n",kase++);
  for ( i = 1 ;  i < n ; i++){
  	 printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n",x[sys[i-1]] ,y[sys[i-1]], x[sys[i]], y[sys[i]] , dis[sys[i]][sys[i-1]]);
  }
 printf("Number of feet of cable required is %0.2f.\n",ans);
}
	return 0 ;
}