#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
//#define SMALL
#define LARGE

int main(){
    FILE *fp, *fpout;
    int arr[2001];
    int N,C,I;
    string line;
    
#ifdef SMALL    
    freopen("A-small-0.in", "rt", stdin);
    freopen("A-small-0.out", "wt", stdout);
#endif    

#ifdef LARGE    
    freopen("A-large-0.in", "rt", stdin);
    freopen("A-large-0.out", "wt", stdout);
#endif    

    cin >> N;
    for(int cur = 1; cur<= N; cur++){
        cin >> C;
        cin >> I;
        for (int i = 0; i< I ; i++){
            cin >> arr[i];
        }
        bool f = false;
        for(int i=0; i< I && !f; ++i){
            if(arr[i] > C)
                continue;
            for(int j= i+1; j< I; ++j){
                if(arr[i] + arr[j] == C){
                    f = true;
                    printf("Case #%d: %d %d\n", cur, i+1 , j+1);
                    break;
                }
            }
        }
    }

    return 0;
}

