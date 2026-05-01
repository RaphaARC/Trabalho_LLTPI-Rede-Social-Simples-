#include<iostream>
#include <string>
#include "../header.hpp"

using namespace std;


Usuario* buscarUsuarioporId(Usuario* v, int n, int id) {
    for(int i=0;i<n;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}

const Usuario* Search(const Usuario* users, int nUsers, int userID) {
    
	const Usuario* usuarioEncontrado = nullptr;
	for(int i=0; i<nUsers; i++) {
	    if(users[i].id == userID) {
	        usuarioEncontrado = &users[i];
	        break;
	    }
	}
	
	if(usuarioEncontrado != nullptr) {
	    cout << "Usuario encontrado: " << endl;
	    exibirUsuarios(usuarioEncontrado, 1);
	} else {
	     cout << "Usuario nao encontrado." << endl;
	}   
	
	return usuarioEncontrado;

}
