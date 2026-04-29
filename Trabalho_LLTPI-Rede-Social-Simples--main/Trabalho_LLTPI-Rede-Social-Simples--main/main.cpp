#include <iostream>
#include <string>
#include "header.hpp"

using namespace std;
int main(){
//Inicialização do Sistema
    int nUsers;
    int nPosts;

	cout << "NÚMERO DE USUÁRIOS: ";
    cin >> nUsers;
    cout << endl << endl;
	Usuario *users = new Usuario[nUsers];

    cout << "NÚMERO DE POSTS: ";
    cin >> nPosts;
    Post *posts = new Post[nPosts];

//Leitura de Usuários e Posts
    lerUsuarios(users, nUsers);
	
	
	delete[] users;
	users = nullptr;
    delete[] posts;
    posts = nullptr;
	
	return 0;
}