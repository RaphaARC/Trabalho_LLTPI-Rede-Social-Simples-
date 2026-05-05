#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void registrarCurtida(int** m, int idUsuario, const Usuario* usuarios, int n, int idPost, Post* posts, int p) {
    
    // Verificação de existência de usuario
    Usuario* userEncontrado = buscarUsuarioporId(usuarios, n, idUsuario);
    while(1) {
	
		// Verificação de existência do usuário
		if(userEncontrado == nullptr) {
        	cout << "Usuario inexistente. Digite novamente um ID valido: ";
        	cin >> idUsuario;
        	userEncontrado = buscarUsuarioporId(usuarios, n, idUsuario);
        	
			continue;
		}
			
		// Verificação da atividade do usuário
		if(userEncontrado->ativo == 0) {
			cout << "Usuario inativo. Digite novamente um ID valido: ";
        	cin >> idUsuario;
        	userEncontrado = buscarUsuarioporId(usuarios, n, idUsuario);
        	
			continue;
		}
			
		break;
    }
    
    // Verificação de post
    Post* postEncontrado = buscarPostPorId(posts, p, idPost);
    while(1) {
		
		// Verificação da existência de post
		if(postEncontrado == nullptr) {
        	cout << "Post inexistente. Digite novamente um ID valido: ";
        	cin >> idPost;
        	postEncontrado = buscarPostPorId(usuarios, n, idPost);
        	
			continue;
		}
			
		// Verificação da publicidade de post
		if(postEncontrado->publico == 0) {
			cout << "Post oculto. Digite novamente um ID valido: ";
        	cin >> idPost;
        	postEncontrado = buscarPostPorId(usuarios, n, idPost);
        	
			continue;
		}
			
		break;
    }
    
    // Verificação de existência de post
    if(m[idUsuario-1][idPost-1] == 1) {
    	cout << "O post já foi curtido.";
	}
    else {
    	
    	// Finalização da função
    	m[idUsuario-1][idPost-1] = 1;
    	curtir(postEncontrado);	
	}
}
