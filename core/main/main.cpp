#include <iostream>
#include <string>
#include <windows.h>
#include "../include/header.hpp"

using namespace std;

int main(){
    SetConsoleTitle("EchoFeed");

	//Inicialização do Sistema
    int nUsers;
    int nPosts;

	cout << endl << endl;

	cout << "NUMERO DE USUARIOS: ";
    cin >> nUsers;
    cout << endl;
	Usuario *users = new Usuario[nUsers];

    cout << "NUMERO DE POSTS: ";
    cin >> nPosts;
    Post *posts = new Post[nPosts];
    
    cout << endl << endl;

	//Leitura de Usuários e Posts
    lerUsuarios(users, nUsers);
    lerPosts(posts, nPosts, users, nUsers);

	//Exibição de Usuários e Posts
	cout << "=== EXIBINDO USUARIOS ===\n\n";
    exibirUsuarios(users, nUsers);
    cout << "\n=== EXIBINDO POSTS ===\n\n";
    exibirPosts(posts, nPosts, users, nUsers);    

	// Busca de Usuário
	cout << "\n=== BUSCA DE USUARIO ===\n\n";
    cout << "Digite um id para buscar: ";
    int idUser;
    cin >> idUser;

    Usuario* userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
    
    if(userEncontrado != nullptr){
    	cout << "-> Usuario encontrado!\n-> ";
		exibirUsuarios(userEncontrado, 1);
	} else {
		cout << "-> O usuario de id [" << idUser << "] e inexistente.";
	}
	
	if(userEncontrado != nullptr) {
	cout << "Quantidade de posts do usuario [" << idUser << "]: " << contarPostsDeUsuario(posts, nPosts, idUser);
	}
	
	cout << endl << endl << endl;
	
	// Suspender Usuário
	cout << "Digite um id de usuário para suspender: ";
    cin >> idUser;

    userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
	suspenderUsuario(userEncontrado);
	exibirUsuarios(userEncontrado, 1);
	cout << "\n\n\n";
	
	// Reativar Usuário
	cout << "Digite um id de usuário para reativar: ";
    cin >> idUser;

    userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
	reativarUsuario(userEncontrado);
	exibirUsuarios(userEncontrado, 1);
	cout << "\n\n\n";
	
	
	// Busca de Post
	cout << "=== BUSCA DE POST ===\n\n";
    cout << "Digite um id de post para buscar: ";
    int idPost;
    cin >> idPost;

    Post* postEncontrado = buscarPostPorId(posts, nPosts, idPost);
    
    if(postEncontrado != nullptr){
    	cout << "-> Post encontrado!\n-> ";
		exibirPosts(postEncontrado, 1, users, nUsers);
	} else {
		cout << "-> O post de id [" << idPost << "] e inexistente.\n\n\n";
	}
	
	// Ocultar post.
	cout << "=== MUDANCA DE STATUS DE POST ===\n\n";
	cout << "Digite um id de post para ocultar: ";
    cin >> idPost;
    
    postEncontrado = buscarPostPorId(posts, nPosts, idPost);
    
    ocultarPost(postEncontrado);
    
    cout << endl;
    
    // Puplicaar post.
	cout << "Digite um id de post para publicar: ";
    cin >> idPost;
    
    postEncontrado = buscarPostPorId(posts, nPosts, idPost);
    
    publicarPost(postEncontrado);

	cout << endl << endl;
	
	cout << "\n=== EXIBINDO POSTS ===\n\n";
    exibirPosts(posts, nPosts, users, nUsers);
	
	// Fim
	delete[] users;
	users = nullptr;
    delete[] posts;
    posts = nullptr;
	
	system("pause");
	return 0;
}
