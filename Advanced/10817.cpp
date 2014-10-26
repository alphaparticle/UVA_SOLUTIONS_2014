#include <bits/stdc++.h>
using namespace std ;
typedef vector < int > vi ;
typedef pair < int , vi > iv; 
int s , t , n ;
int dp[100][3][3][3][3][3][3][3][3];
int cost [100];
bool teaches [100][8];

inline int topdown ( int index , int a , int b , int c ,int d ,int e ,int f ,int g  ,int h){
      
      if ( index >= n ){
      	   if( a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0)
      	   	return 1e9 ;
      	  return 0;
      }
     if( a <= 0 && b <= 0 && c <= 0 && d <= 0 && e <= 0 && f <= 0 && g <= 0 && h <= 0)
     return 0;
     
     if( dp[index][a][b][c][d][e][f][g][h] != -1)
     return dp[index][a][b][c][d][e][f][g][h] ;
   
   int ans = 0 ;
   ans =topdown( index+1 ,a , b ,c,d,e,f,g,h);
   int a1,b1,c1,d1,e1,f1,g1,h1 ;
   a1 = a ; b1 = b ; c1 = c ; d1 = d ;e1 = e ;f1 = f ; g1 = g ; h1 = h;
   if( teaches[index][0] )
   a1  = max( 0 , a1-1);
   if( teaches[index][1] )
   b1  = max( 0 , b1-1);
   if( teaches[index][2] )
   c1  = max( 0 , c1-1);
   if( teaches[index][3] )
   d1  = max( 0 , d1-1);
   if( teaches[index][4] )
   e1  = max( 0 , e1-1);
   if( teaches[index][5] )
   f1  = max( 0 , f1-1);
   if( teaches[index][6] )
   g1  = max( 0 , g1-1);
   if( teaches[index][7] )
   h1  = max( 0 , h1-1);
  
  ans = min ( ans , cost[index] + topdown(index+1,a1,b1,c1,d1,e1,f1,g1,h1));  

  return dp[index][a][b][c][d][e][f][g][h]= ans;
}


char arr[55];
int main(){
    
  int i , j, k, l;
  while ( scanf("%d %d %d",&s ,&t,&n) ){
  	  if( s == 0)
  	  break ;
  	 
  	  int temp[10];
  	  memset ( temp , 0 , sizeof temp);
  	  for ( i = 0 ; i < s ;i++)
  	  temp[i] = 2 ;
  	  memset ( teaches , false ,sizeof teaches);
  	  memset ( cost , 0, sizeof cost);
  	  getchar();
  	  int ans = 0 ;
  	  
  	  for ( i = 0 ;  i < t ; i++){
	  	  gets(arr);
	  	//  cout<<"teacher "; //puts(arr);
	  	  char *ptr ;
	  	  ptr = strtok( arr , " " );
	  	   j = 0 ;
	  	  while ( ptr != NULL ){
	         sscanf( ptr, "%d" , &j);
	  //       cout <<" -> "<<j ;
	         if( j >= 1000 )
	         ans += j ;
	         else
	         { 
	         	 temp[j-1] = max( 0 , temp[j-1]-1);
	         }
	         ptr = strtok(NULL, " ");
	  	  }
	  //	 cout << endl;
  	}
	  	for ( i = 0 ;  i < n ; i++){
		  	  gets(arr);
	//	  	  cout <<"applicant ";//puts(arr);
		  	  char *ptr ;
		  	  ptr = strtok( arr , " " );
		  	   j = 0 ;
		  	  while ( ptr != NULL ){
		         sscanf( ptr, "%d" , &j);
		         if( j >= 10000 )
		         cost[i] = j ;
		         else
		         teaches[i][j-1] = true;
		         ptr = strtok(NULL, " ");
		  	  }
	  	}
    
     memset ( dp ,-1,sizeof dp); 
	 ans += topdown(0, temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7]);
     printf("%d\n",ans);
  }
	return 0;
}
