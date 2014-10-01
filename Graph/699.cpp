#include <bits/stdc++.h>
using namespace std ;
typedef pair < int , int > ii ;
map < int , int > node ;
int x,cmin , cmax ;
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

int build( int index , int column ){
    scanint(x) ;  
    if ( x == -1)
    return index;
    if( node.count(column) == 0)
    node[column] = 0 ;
    node[column] += x ;
    cmin = min(cmin ,column) ; cmax = max( cmax , column) ;
    int next = build(index+1,column-1) ;
    next = build(next,column+1);
    return next ;
}

int main(){
	int kase =0 ; 
    while (1){
       node.clear() ; cmin = 1e9 ; cmax = -1e9 ; 
       int last = build(0,0) ;
       if( node.size() == 0)
       break ;
       printf("Case %d:\n",++kase) ;
       printf("%d",node[cmin]) ;
       for ( int i = cmin+1 ; i <= cmax ; i++)
       printf(" %d",node[i]);
      printf("\n");
     puts("");
    }   
	return 0 ;
}
