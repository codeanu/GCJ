#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
//#define SMALL
#define LARGE
//#define DEBUG

#ifdef SMALL    
#define MAX 7 
#endif    

#ifdef LARGE    
#define MAX 50 
#endif    

void display_arr(char arr[][MAX], int , string);
void gravity_arr(char arr[][MAX], int );
void rotate(char arr[][MAX], int, int, int);

int main(){
    FILE *fp, *fpout;
    int T,N,K;
    string line;
    
#ifdef SMALL    
    freopen("A-small-0.in", "rt", stdin);
    freopen("A-small-0.out", "wt", stdout);
#endif    

#ifdef LARGE    
    freopen("A-large-0.in", "rt", stdin);
    freopen("A-large-0.out", "wt", stdout);
#endif    

    cin >> T;
    for(int cur = 1; cur<= T; cur++){
        cin >> N;
        cin >> K;
        char arr[MAX][MAX];
        for (int i = 0; i< N ; i++){
            cin >> line;
            for(int j=0; j< line.length(); j++){
                arr[i][j] = line[j];
            }
        }
        rotate(arr, N, K, cur);
        bool f = false;
    }

    return 0;
}

void display_arr(char arr[][MAX], int N, string message){
    cout << message << "\n";

    for (int i = 0; i< N ; i++){
        for(int j=0; j< N; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
void gravity_arr(char arr[][MAX], int N){
    for(int i =0; i< N; i++){
        for(int j=0; j< N;j++){
            if(i !=0 && arr[i][j] == '.' && arr[i-1][j] != '.')
            {
                for(int k = i;k > 0;k--){
                    arr[k][j] = arr[k-1][j];
                }
                arr[0][j] = '.';
            }
        }
    }
}

void rotate(char arr[][MAX], int N, int K, int curr){
    char array[MAX][MAX];

    #ifdef DEBUG
    display_arr(arr, N, "\nInitial Array");
    #endif    

    for(int i =0; i< N; i++){
        for(int j=0; j< N;j++){
            array[j][N-i-1] = arr[i][j];
        }
    }

    gravity_arr(array, N);
    #ifdef DEBUG
    display_arr(array, N, "After Gravity Array");
    #endif    
    bool B_win = false;
    bool R_win = false;

    for(int i = 0 ;i < N; i++){
        for(int j = 0 ;j < N; j++){
            int count = 1; 
            char compare = array[i][j];
            bool *booldata;

            if(compare == 'R')
                booldata = &R_win;
            else if(compare == 'B')
                booldata = &B_win;
            else if(compare == '.') 
                continue; // Continue when . is found 
            else
                continue;

            // Check for row wise right hand side
            for(int k = j+1; k < N; k++){
                if(array[i][k] == compare){
                    count ++;
                    #ifdef DEBUG
                    cout << "pass1: K=" << K << " i- " << i << " j-" << j << " k-" << k << compare << count <<endl ;
                    #endif    
                    if(count == K){
                        //cout << "pass1:success" << endl;
                        *booldata = true;
                        break;
                    }
                }
                else
                    break;
            }
            count = 1; 

            // Check for column wise right hand side
            for(int k = i+1; k < N; k++){
                if(array[k][j] == compare){
                    count ++;
                    #ifdef DEBUG
                    cout << "pass2: K=" << K << " i- " << i << " j-" << j << " k-" << k << compare << count <<endl ;
                    #endif    
                    if(count == K){
                        *booldata = true;
                        break;
                    }
                }
                else
                    break;
            }
            count = 1; 

            // Check for diagonal right hand side  
            for(int k = i+1, l=j+1; k < N && l< N; k++, l++){
                if(array[k][l] == compare){
                    count ++;
                    #ifdef DEBUG
                    cout << "pass3: K=" << K << " i- " << i << " j-" << j << " k-" << k << " l-" << l << " " << compare << count <<endl ;
                    #endif    
                    if(count == K){
                        *booldata = true;
                        break;
                    }
                }
                else
                    break;
            }
            count = 1; 

            // Check for diagonal right hand side  
            for(int k = i+1, l=j-1; k < N && l>= 0; k++, l--){
                if(array[k][l] == compare){
                    count ++;
                    #ifdef DEBUG
                    cout << "pass4: K=" << K << " i- " << i << " j-" << j << " k-" << k << " l-" << l << " " << compare << count <<endl ;
                    #endif    
                    if(count == K){
                        *booldata = true;
                        break;
                    }
                }
                else
                    break;
            }

        }
    }

    if(B_win == false && R_win == false){
        cout << "Case #" << curr << ": " << "Neither" << endl;
    }
    if(B_win == true && R_win == true){
        cout << "Case #" << curr << ": " << "Both" << endl;
    }
    if(B_win == true && R_win == false){
        cout << "Case #" << curr << ": " << "Blue" << endl;
    }
    if(B_win == false && R_win == true){
        cout << "Case #" << curr << ": " << "Red" << endl;
    }
}

