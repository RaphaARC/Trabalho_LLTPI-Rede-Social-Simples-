#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void exibirMatriz(int** m, int n, int p){

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

}