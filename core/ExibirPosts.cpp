#include <iostream>
#include <string>
#include "../header.hpp"

using namespace std;

void exibirPosts(const Post* v, int p, const Usuario* usuarios, int n) {
    for(int i=0;i<p;i++){

        const Usuario *userEncontrado = Search(usuarios, n, (v+i)->idAutor);
        cout<<"["<< (v+i)->id<< "] "<<    	
	    userEncontrado->username <<
	    ": " << (v+i)->conteudo << 
	    " | Curtidas: " << (v+i)->curtidas << 
	    " | Visibilidade: "; 

        if((v+i)-> publico) 
           cout << "Publico"; 
	    else 
           cout << "Apenas amigos";
	       cout << "\n"<<endl; 

    }
}

void curtir(Post *p){
    p->curtidas++;
}