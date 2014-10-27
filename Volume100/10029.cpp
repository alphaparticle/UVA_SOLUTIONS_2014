#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> L;

int main()
{       
    // freopen("in.txt", "r" , stdin);
     ios::sync_with_stdio(0);
        int ans = 0;
        string w2;
        while (cin >> w2)
        {
            int length = 1;
            
            for (int i = 0; i <= w2.size(); ++i)
            for (char c = 'a'; c <= 'z'; ++c)
            {
                    string w1(w2);
                    w1.insert(i, 1, c);
                    if (w1 > w2)
                    break;
                if (L.count(w1))
                length = max(length, L[w1] + 1);
            }
            // Delete w2[i].
            for (int i = 0; i < w2.size(); ++i)
            {
              string w1(w2);
              w1.erase(i, 1);
                          
              if (L.count(w1))
              length = max(length, L[w1] + 1);
            }
            // Change w2[i].
            for (int i = 0; i < w2.size(); ++i)
            for (char c = 'a'; c <= 'z' && c != w2[i]; ++c)
            {
                string w1(w2);
                w1[i] = c;
                
                if (w1 > w2)
                break;
                
                if (L.count(w1))
                length = max(length, L[w1] + 1);
            }
        L[w2] = length;
        ans = max(ans, length);
      }
        cout << ans <<"\n";
    return 0 ;
}
