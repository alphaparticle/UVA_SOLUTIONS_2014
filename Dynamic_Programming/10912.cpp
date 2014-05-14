#include <bits/stdc++.h>
using namespace std ;

int dp [ 352 ] [ 27 ] [ 27 ];
 
int rec(int score,int len,int value)
{
    if( score<0 || len<0 || value*len > score)
        return 0;
    else if( score == 0 && len == 0)
        return dp [score] [len] [value] = 1;
    else if( dp [score] [len] [value] != -1 )
        return dp[score][len][value] ;
    else
    {
        int i;
        int sum = 0;
        for( i = value+1 ; i < 27 ; i++ )
            sum += rec ( score-i , len-1 , i );
       
        return dp [score] [len] [value] = sum;
    }
}
int main()
{
    int i,j,k;
    memset ( dp , -1, sizeof dp) ;
    int kase = 1 ;
    while(scanf("%d %d",&i,&j) == 2)
    {
         if ( i == 0 || j == 0)
         break ;

        if(i>26||j>351)
            printf("Case %d: %d\n",kase++,0);
        else
            printf("Case %d: %d\n",kase++,rec(j,i,0));
    }
    return 0;
}
