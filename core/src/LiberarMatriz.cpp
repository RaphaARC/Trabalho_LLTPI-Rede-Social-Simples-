#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void liberarMatriz(int**m, int linhas){
    for(int i=0;i<linhas;i++){
        delete[] m[i];
    }
    delete[] m;
    m = nullptr;
}