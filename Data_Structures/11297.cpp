//2D Segment Tree
// 500*500 


#include<bits/stdc++.h>
using namespace std; 

struct  st {
   int mini , maxi ;
} ;
st node [510][2500] ;

int matrix [510][510] ;
int n ,m ; 

void init ( int p , int L , int R , int row ){
 
    if ( L == R ){
    	node[row][p].mini = node[row][p].maxi  = matrix [row][L] ;
    	return ;
    }
    else{
        
        init ( p*2 , L , (L+R)/2 , row) ;
        init ( p*2+1 , (L+R)/2+1 ,R , row) ;
        node[row][p].mini = min ( node[row][p*2].mini , node[row][p*2 + 1].mini) ;
        node[row][p].maxi = max ( node [row][p*2].maxi , node[row][p*2+1].maxi ) ;
    }
}


void update ( int p , int L , int R , int row , int col , int value ){
     
      if( L > col || R < col)
      return  ;

			
			if( L == R &&  L == col ){
			//	matrix [row][col] = value ;
				node[row][p].mini = node[row][p].maxi = value ; //matrix [row][col]; 
        return ;
			}
		
				update ( p*2 , L , (L+R)/2 , row , col , value) ;
				update (p*2+1 , (L+R)/2  + 1 , R , row ,col ,value ) ;
				node[row][p].mini = min ( node[row][p*2].mini , node[row][p*2 + 1].mini) ;
		    node[row][p].maxi = max ( node [row][p*2].maxi , node[row][p*2+1].maxi ) ;

   
}


int RminQ (  int row , int p , int L ,int R , int start , int  end ){
  
  
    if ( L == R ){
    	if ( L >= start && R <= end)
    	return node[row][p].mini ;
        else
        return 99999999 ;
    }
    
    if( L > end || R < start )
    return 99999999 ;
    
     if( L >= start && R <= end ){
    	 return node[row][p].mini ;
    }
    
    
    	int ans = 99999999 ;
    	ans = min ( ans , RminQ ( row , p*2 , L , (L+R)/2 , start , end) ) ;
    	ans = min ( ans , RminQ  (row , p*2+1 , (L+R)/2+1, R ,start , end)) ;
    	return ans ;
    

} 

int RmaxQ ( int row , int p , int L , int R , int start , int end ){
  
    if ( L == R ){
    	if ( L >= start && R <= end)
    	return node[row][p].maxi ;
        else
        return -99999999 ;
    }
    
    if( L > end || R < start )
    return -99999999 ;
    
     if( L >= start && R <= end ){
    	 return node[row][p].maxi ;
    }
    
    
    	int ans = -99999999 ;
    	ans = max ( ans , RmaxQ ( row , p*2 , L , (L+R)/2 , start , end) ) ;
    	ans = max ( ans , RmaxQ  (row , p*2+1 , (L+R)/2+1, R ,start , end)) ;
    	return ans ;
}


int INF = 99999999 ;

int main(){

cin.sync_with_stdio(0);
cin.tie(0) ;
int i , j, k, l , query ;

cin >> n >> m ;
for ( i = 1; i <= n ; i++)
	for ( j = 1 ; j <= m ; j ++)
	cin >> matrix [i][j] ;

for ( i = 1 ; i <= n ; i++)
for ( j = 1 ; j <= 4*m ; j++)
	node[i][j].maxi = -INF , node[i][j].mini = INF ;

for ( i = 1 ; i <= n ; i++)
init ( 1 , 1 , m , i) ;

char type ;
cin >> query ;
int x1 , y1 , x2 ,y2 , x , y , w;
while( query--){
	 cin >> type ;
	 if( type == 'c' ){
	 	 cin >> x >> y >> w ;
     matrix [x][y] = w ;
	 	 update ( 1 , 1 , m , x , y , w) ;
      
	 }
	 else {
	 	 cin >> x1 >> y1 >> x2 >> y2 ;
	 	 x = INF , y = -INF ;
	 	
     
     for ( i = x1 ; i <= x2 ; i++){
	 	  int a = RminQ(i , 1 , 1 , m , y1 , y2) ;
	 	 
	 	  int b = RmaxQ(i,1,1,m,y1,y2);
      x = min ( x , a) ;
      y = max( y , b) ; 
	 	 
      }
	 
	 	cout << y <<" "<<x <<"\n" ;
	 
 }
}

	return 0  ;
}
