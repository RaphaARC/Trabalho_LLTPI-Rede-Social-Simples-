#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void reativarUsuario(Usuario* u, int nUsers){
int x; 

	cout << "Digite o id do ususario que gostaria de reativar abaixo: " << endl; 
	cin >> x; 
	
		Usuario* usuarioEncontrado = buscarUsuarioporId(u, nUsers, x); //nUsers precisa se tornar uma variável global para ser usada nesse parâmetro
	
	if(usuarioEncontrado != nullptr){
		cout << "\n\n==Usuario encontrado== \n" << endl; 
	
	if(usuarioEncontrado->ativo == true){
		cout << "Esse usuario ja esta ativo\n\n" << endl; 
}

	else usuarioEncontrado->ativo=true;
}
	else cout << "\n\n==Usuario nao encontrado==\n\n" << endl; }
