#include<iostream>
#include <string>
#include "../header.hpp"

using namespace std;

int nUsers;


void reativarUsuario(Usuario* u){
int x; 

	cout << "Digite o id do ususario que gostaria de reativar abaixo: " << endl; 
	cin >> x; 
	
		Usuario* usuarioEncontrado = buscarUsuarioporId(u, nUsers, x); 
	
	if(usuarioEncontrado != nullptr){
		cout << "\n\n==Usuario encontrado== \n" << endl; 
	
	if(usuarioEncontrado->ativo == true){
		cout << "Esse usuario ja esta ativo\n\n" << endl; 
}

	else usuarioEncontrado->ativo=true;
}
	else cout << "\n\n==Usuario nao encontrado==\n\n" << endl; }
