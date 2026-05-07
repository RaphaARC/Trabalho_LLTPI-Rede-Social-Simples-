/**
 * Programa principal para o simulador de rede social EchoFeed.
 * Este programa permite gerenciar usuários, posts e interações como curtidas,
 * suspensão de usuários, ocultação de posts, etc.
 */

#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

/**
 * Função principal do programa.
 * Inicializa os arrays de usuários e posts, lê os dados, cria a matriz de curtidas
 * e entra no loop do menu para interagir com o usuário.
 */

int main(){
	
	// Declaração de variáveis principais
	int x, nUsers, nPosts, idUser, idPost, qtd;
	
	// Solicita ao usuário o número de usuários a serem criados
	cout << "NUMERO DE USUARIOS: ";
    cin >> nUsers;
    cout << endl;


	// Aloca dinamicamente um array de usuários
	Usuario *users = new Usuario[nUsers];

	// Solicita ao usuário o número de posts a serem criados
    cout << "\nNUMERO DE POSTS: ";
    cin >> nPosts;
    Post *posts = new Post[nPosts];
    
    cout << endl << endl;

	// Leitura dos dados dos usuários e posts a partir da entrada
    lerUsuarios(users, nUsers);
    lerPosts(posts, nPosts, users, nUsers);
	
	// Criação da matriz dinâmica para armazenar as curtidas (usuários x posts)
	int** mat = criarMatriz(nUsers, nPosts);
	
	while(1){
			
		cout << "========================================\n";
		cout << "        EchoFeed -- Menu\n";
		cout << "========================================";
		
		cout <<
	  		"\n\n0. Sair" << endl <<
			"1. Listar usuarios" << endl <<
			"2. Listar posts (feed completo)" << endl <<
			"3. Buscar usuario por ID" << endl <<
			"4. Suspender usuario" << endl <<
			"5. Reativar usuario" << endl <<
			"6. Buscar post por ID" << endl <<
			"7. Ocultar post" << endl <<
			"8. Publicar post" << endl <<
			"9. Exibir feed publico (filtrado)" << endl <<
			"10. Registrar curtida" << endl <<
			"11. Exibir matriz de curtidas" << endl <<
			"----------------------------------------\n\n" << endl;
		
		cin >> x;
		
		// Processa a opção escolhida pelo usuário
		switch (x){
			
			case 0:{
				// Libera a memória alocada dinamicamente
					delete[] users;
					users = nullptr;
		   			delete[] posts;
		   			posts = nullptr;
			
			cout << "\n\nVoce saiu do programa, obrigado por usar!"<< endl;
				return 0;
			}
			
			case 1:{
				// Exibe todos os usuários cadastrados
				cout << "\n\n=== EXIBINDO USUARIOS ===\n\n";
				exibirUsuarios(users, nUsers);
					cout<<"\n\n"<<endl;
						break;
		}
		
			case 2:{
				// Exibe todos os posts no feed completo
				cout << "\n\n=== EXIBINDO POSTS ===\n\n";
				exibirPosts(posts, nPosts, users, nUsers);
					cout<<"\n\n"<<endl;
						break;
		
			}
			
			case 3:{
				// Busca um usuário específico pelo ID
				cout << "\n=== BUSCA DE USUARIO ===\n\n";
				cout << "Digite um id para buscar: ";
			    int idUser;
			    cin >> idUser;
			
			    Usuario* userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
			    
			    if(userEncontrado != nullptr){
			    	cout << "\n-> Usuario encontrado!\n-> ";
					exibirUsuarios(userEncontrado, 1);
				} else {
					cout << "\n-> O usuario de id [" << idUser << "] e inexistente.";
				}
				
				if(userEncontrado != nullptr) {
				cout << "\nQuantidade de posts do usuario [" << idUser << "]: " << contarPostsDeUsuario(posts, nPosts, idUser);
				}
				
				cout << endl << endl << endl;
					break;
			}
				
			case 4:{
				// Suspende um usuário pelo ID
				cout << "\n\nDigite um id de usuario para suspender: ";
			    cin >> idUser;
			
			    Usuario* userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
				suspenderUsuario(userEncontrado);
				exibirUsuarios(userEncontrado, 1);
				cout << "\n\n\n";	
					break;
			}
		
			case 5:{
				// Reativa um usuário suspenso pelo ID
				cout << "\n\nDigite um id de usuario para reativar: ";
			    cin >> idUser;
			
			    Usuario* userEncontrado = buscarUsuarioporId(users, nUsers, idUser);
				reativarUsuario(userEncontrado);
				exibirUsuarios(userEncontrado, 1);
				cout << "\n\n\n";
					break;
			}
	
			case 6:{
				// Busca um post específico pelo ID
				cout << "\n\n=== BUSCA DE POST ===\n\n";
			    cout << "Digite um id de post para buscar: ";
			    int idPost;
			    cin >> idPost;
			
			    Post* postEncontrado = buscarPostPorId(posts, nPosts, idPost);
			    
			    if(postEncontrado != nullptr){
			    	cout << "\n\n-> Post encontrado!\n-> ";
					exibirPosts(postEncontrado, 1, users, nUsers);
				} else {
					cout << "\n-> O post de id [" << idPost << "] e inexistente.\n\n\n";
				}
					break;
			}
			
			case 7:{
				// Oculta um post pelo ID
				cout << "\n\n Digite um id de post para ocultar: ";
			    cin >> idPost;
			    
			    Post* postEncontrado = buscarPostPorId(posts, nPosts, idPost);
			    
			    ocultarPost(postEncontrado);
			    
			    cout << endl;
		    		break;
			
			}
				
			case 8:{
				// Publica um post oculto pelo ID
				cout << "\n\nDigite um id de post para publicar: ";
			    cin >> idPost;
			    
			    Post* postEncontrado = buscarPostPorId(posts, nPosts, idPost);
			    
			    publicarPost(postEncontrado);
			
				cout << endl << endl;
					break;
			}
			
			case 9:{
				// Exibe apenas os posts públicos (filtrados)
 			  	int qtd;
    
  			  	Post* postsPublicos = filtrarPublicos(posts, nPosts, &qtd);

   		 			if(postsPublicos != nullptr){

  						cout << "\n=== FEED PUBLICO ===\n\n";

  				      	exibirPosts(postsPublicos, qtd, users, nUsers);

 				       	delete[] postsPublicos;
 			}
  			  	else{
  				      	cout << "\nNao existem posts publicos.\n";
   			}

		   				 cout << "\n\n";

							 break;
			}
				
			case 10:{
				// Registra uma curtida de um usuário em um post
				// Lendo o id do usuário que vai curtir
				cout << "Digite um id do usuario que vai curtir: ";
			    cin >> idUser;

			    // Lendo o id do post que será curtido
			    cout << "Digite um id do post para curtir: ";
			    cin >> idPost;
			    
				registrarCurtida(mat, idUser, users, nUsers, idPost, posts, nPosts);
				
				cout << "\n\n";
				
				
				break;
			}
			
			case 11:{
				// Exibe a matriz de curtidas e a quantidade total
				cout<<"\n\nA quantidade total de curtidas foi:\n\n"; 
				exibirMatriz(mat, nUsers, nPosts); 
				cout<< "\n" << endl;
				
					break;
			}
					
			default: {
				// Opção inválida
				cout << "Valor nao reconhecido. Digite novamente.\n\n";
	
		}

	}
}
 
	
	return 0;
}
