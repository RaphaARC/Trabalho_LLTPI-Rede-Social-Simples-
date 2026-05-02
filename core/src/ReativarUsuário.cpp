#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void reativarUsuario(Usuario* u){

	if(u != nullptr){
		cout << "\n\n-> Usuario encontrado.\n" << endl; 
		
		if(u->ativo == true){
			cout << "-> Esse usuario ja esta ativo.\n\n" << endl; 
		}
		else u->ativo=true;
		
	}
	else cout << "\n\n-> Usuario nao encontrado.\n\n" << endl; 

}
