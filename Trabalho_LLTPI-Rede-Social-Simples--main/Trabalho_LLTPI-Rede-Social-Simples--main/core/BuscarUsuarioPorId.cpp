#include<iostream>
#include <string>
#include <header.hpp>

using namespace std;


Usuario* buscarUsuarioporId(Usuario* v, int n, int id) {
    for(int i=0;i<n;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}

void Search(Usuario* users, int nUsers, int userID) {
    
Usuario* usuarioEncontrado = buscarUsuarioporId(users, nUsers, userID); // Exemplo: buscando o usuário com id 2

if(usuarioEncontrado != nullptr) {
    cout << "Usuario encontrado: " << endl;
    exibirUsuarios(usuarioEncontrado, 1);
} else {
     cout << "Usuario nao encontrado." << endl;
}   

}