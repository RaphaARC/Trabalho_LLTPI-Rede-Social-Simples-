#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void suspenderUsuario(Usuario* u){
	
	if(u != nullptr){
		cout << "\n\n-> Usuario encontrado.\n" << endl; 
	
		if(u->ativo == false){
			cout << "-> Esse usuario ja esta suspenso.\n\n" << endl; 
		}
		else u->ativo=false;
		
	}
	else cout << "\n\n -> Usuario nao encontrado.\n\n" << endl; 
}	
