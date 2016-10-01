#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long int n,s;
        cin >> n >> s;
        long long ideal = (n*(n+1))/2;
        if(s == ideal)
            cout << "0" << endl;
        else{
            int a[n];
            for(int i=0;i<n;i++)
                a[i] = i+1;
            long long left = ideal - s;
            int index = n-1;
            while(left > 0){
                if(a[index] > left){
                    a[index] = a[index] - left;
                    left = 0;
                }
                else{   
                    left = left - a[index] + 1;
                    a[index] = 1;
                    index -- ;
                }
            }

            int count[n];
            memset(count,0,sizeof(count));
            int ans = 0;
            for(int i=0;i<n;i++)
                count[a[i]-1]++;
            for(int i=0;i<n;i++){
                if(count[i] > 1)
                    ans += (count[i]-1);
            }
            cout << ans << endl;
        }
    }   
    return 0;
}

