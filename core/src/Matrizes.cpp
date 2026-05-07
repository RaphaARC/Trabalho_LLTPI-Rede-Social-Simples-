/**
 * Contém funções para manipulação de matrizes dinâmicas.
 * Usado para armazenar as curtidas (usuários x posts).
 */

#include<iostream>
#include <string>
#include "../include/header.hpp"

/**
 * Cria uma matriz dinâmica de inteiros inicializada com zeros.
 * Paramêtro linhas Número de linhas da matriz.
 * Paramêtro colunas Número de colunas da matriz.
 * return Ponteiro para a matriz criada.
 */
int** criarMatriz(int linhas, int colunas){
    int** m = new int*[linhas];
    for(int i=0;i<linhas;i++){
        m[i] = new int[colunas];
    }
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            m[i][j] = 0;
        }
    }
    return m;
}
 
/**
 * Exibe a matriz na tela.
 * Paramêtro m Ponteiro para a matriz.
 * Paramêtro n Número de linhas.
 * Paramêtro p Número de colunas.
 */
void exibirMatriz(int** m, int n, int p){

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

}

/**
 * Libera a memória alocada para a matriz.
 * Paramêtro m Ponteiro para a matriz a ser liberada.
 * Paramêtro linhas Número de linhas da matriz.
 */
void liberarMatriz(int**m, int linhas){
    for(int i=0;i<linhas;i++){
        delete[] m[i];
    }
    delete[] m;
    m = nullptr;
}