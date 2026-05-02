#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

int contarPostsDeUsuario(const Post* v, int p, int idUsuario) {
	int qtd=0;
	
	for(int i=0;i<p;i++){
		if((v+i)->idAutor == idUsuario){
			qtd++;
		}
	}
	
	return qtd;
}
