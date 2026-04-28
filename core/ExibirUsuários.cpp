#include<iostream>
#include <string>

using namespace std;

struct Usuario {
string username;
string email;
int id;
int seguidores;
bool ativo; // true = conta ativa, false = conta suspensa
};

struct Post {
string conteudo; // texto do post
int id;
int idAutor; // id do Usuario que criou o post
int curtidas;
bool publico; // true = vis´ıvel para todos, false = apenas seguidores
};

void exibirUsuarios(const Usuario* v, int n){
	for(int i=0; i<n; i++) {

        cout<<"["<< (v+i)->id<< "] "<<    	
	    (v+i)->username <<
	    " | E-mail: @" << (v+i)->email << 
	    " | Seguidores: " << (v+i)->seguidores << 
	    " | Status: "; 

        if((v+i)-> ativo) 
           cout << "Ativo"; 
	    else 
           cout << "Inativo";
	       cout << "\n"<<endl; 
	
	}
}