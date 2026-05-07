/**
 * Contém funções para manipulação de usuários.
 * Inclui leitura, exibição, busca, contagem de posts, suspensão e reativação.
 */

#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

/**
 * Lê os dados dos usuários a partir da entrada padrão.
 * Paramêtro v Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários a serem lidos.
 */
void lerUsuarios(Usuario* v, int n){

    cout << "=== LENDO USUARIOS ===\n\n";
    for(int i=0;i<n;i++){
		
		cout << "-- Usuario " << i+1 << " --\n";
		
        cout << "Nome: ";
        cin.ignore();
        getline(cin, (v+i)->username);

        cout << "Email: ";
        getline(cin, (v+i)->email);
        
        cout << "Seguidores: ";
        cin >> (v+i)->seguidores;
        
        cout << "Ativo? (0-nao, 1-sim): ";
        cin >> (v+i)->ativo;
        
        (v+i)->id = i+1;
        
        cout << endl;
    }
    cout << endl;
}

/**
 * Exibe os dados dos usuários na tela.
 * Paramêtro v Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários a serem exibidos.
 */
void exibirUsuarios(const Usuario* v, int n){
	for(int i=0; i<n; i++) {

        cout<<"["<< (v+i)->id<< "] "<<    	
	    (v+i)->username <<
	    " | E-mail: @" << (v+i)->email << 
	    " | Seguidores: " << (v+i)->seguidores << 
	    " | Status: "; 

        if((v+i)-> ativo) 
           cout << "Ativo\n"; 
	    else 
           cout << "Inativo";
	       cout << "\n"<<endl; 
	
	}
}

/**
 * Busca um usuário pelo ID.
 * Paramêtro v Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários no array.
 * Paramêtro id ID do usuário a ser buscado.
 * return Ponteiro para o usuário encontrado ou nullptr se não encontrado.
 */
Usuario* buscarUsuarioporId(Usuario* v, int n, int id) {
    for(int i=0;i<n;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}

/**
 * Busca um usuário pelo ID e exibe o resultado.
 * Paramêtro users Ponteiro para o array de usuários.
 * Paramêtro nUsers Número de usuários no array.
 * Paramêtro userID ID do usuário a ser buscado.
 * retrun Ponteiro para o usuário encontrado ou nullptr se não encontrado.
 */
const Usuario* Search(const Usuario* users, int nUsers, int userID) {
    
	const Usuario* usuarioEncontrado = nullptr;
	for(int i=0; i<nUsers; i++) {
	    if(users[i].id == userID) {
	        usuarioEncontrado = &users[i];
	        break;
	    }
	}
	
	if(usuarioEncontrado != nullptr) {
	    cout << "\n\nUsuario encontrado: " << endl;
	    exibirUsuarios(usuarioEncontrado, 1);
	} else {
	     cout << "\n\nUsuario nao encontrado." << endl;
	}   
	
	return usuarioEncontrado;

}

/**
 * Conta o número de posts de um usuário específico.
 * Paramêtro v Ponteiro para o array de posts.
 * Paramêtro p Número de posts no array.
 * ParamêtroidUsuario ID do usuário.
 * return Número de posts do usuário.
 */
int contarPostsDeUsuario(const Post* v, int p, int idUsuario) {
	int qtd=0;
	
	for(int i=0;i<p;i++){
		if((v+i)->idAutor == idUsuario){
			qtd++;
		}
	}
	
	return qtd;
}

/**
 * Suspende um usuário, definindo seu status como inativo.
 * Paramêtro u Ponteiro para o usuário a ser suspenso.
 */
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

/**
 * Reativa um usuário suspenso, definindo seu status como ativo.
 * Paramêtro u Ponteiro para o usuário a ser reativado.
 */
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