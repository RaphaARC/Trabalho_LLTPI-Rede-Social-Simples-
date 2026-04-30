#include <iostream>
#include <string>
#include "header.hpp"

using namespace std;
int main(){
//Inicialização do Sistema
    int nUsers;
    int nPosts;

	cout << "NUMERO DE USUARIOS: ";
    cin >> nUsers;
    cout << endl << endl;
	Usuario *users = new Usuario[nUsers];

    cout << "NUMERO DE POSTS: ";
    cin >> nPosts;
    Post *posts = new Post[nPosts];

//Leitura de Usuários e Posts
    lerUsuarios(users, nUsers);
    lerPosts(posts, nPosts, users, nUsers);

//Exibição de Usuários e Posts
    exibirUsuarios(users, nUsers);
    exibirPosts(posts, nPosts, users, nUsers);    

    cout << "Digite um id para buscar: ";
    int x;
    cin >> x;

    const Usuario* usuarioEncontrado = Search(users, nUsers, x);

    if(usuarioEncontrado != nullptr) {
        cout << "Usuario encontrado: " << endl;
        exibirUsuarios(usuarioEncontrado, 1);
    } else {
        cout << "Usuario nao encontrado." << endl;
    }

	delete[] users;
	users = nullptr;
    delete[] posts;
    posts = nullptr;
	
	return 0;
}
