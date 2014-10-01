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
int ok;
int dfs()
{
    int w1, d1, w2, d2;
    scanint(w1) ; scanint(d1) ;scanint(w2);scanint(d2) ;
    if (w1 && w2 && d1 && d2)
    {
        if ( (w1 * d1) != (w2 * d2) )
        {
            ok = 0;
            return 0;
        }
        else
            return (w1 + w2);
    }
    else
    {
        if (!w1)  w1 = dfs();
        if (!w2)  w2 = dfs();
        if ( (w1 * d1) != (w2 * d2) )
        {
            ok = 0;
            return 0 ;
        }
        else    return (w1 + w2);
    }
}
int main()
{
    int i, N;  int sum;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        ok = 1; dfs();
        if ( ok == 1 )
            puts("YES");
        else
            puts("NO");
        if (i != N)  
         puts("");
    }
    return 0;
}
