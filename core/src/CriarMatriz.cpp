#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

int** criarMatriz(int linhas, int colunas){
    int** m = new int*[linhas];
    for(int i=0;i<linhas;i++){
        m[i] = new int[colunas];
    }
    for(int i=0;i<linas;i++){
        for(int j=0;j<colunas;j++){
            m[i][j] = 0;
        }
    }
    return m;
}