#include<iostream>
#include <string>
#include <header.hpp>

using namespace std;

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
