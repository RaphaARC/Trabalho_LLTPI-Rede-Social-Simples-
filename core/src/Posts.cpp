/**
 * Contém funções para manipulação de posts no simulador de rede social.
 * Inclui leitura, exibição, busca, curtidas, publicação/ocultação e filtragem.
 */

#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

/**
 * Lê os dados dos posts a partir da entrada padrão, validando o autor.
 * Paramêtro v Ponteiro para o array de posts.
 * Paramêtro p Número de posts a serem lidos.
 * Paramêtro usuarios Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários.
 */
void lerPosts(Post* v, int p, const Usuario* usuarios, int n) {
	cout << "=== LENDO POSTS ===\n\n";
    for(int i=0;i<p;i++){
		
		cout << "-- Post " << i+1 << " --\n";
		
        cout << "ID Autor: ";
        int idAutor;
        while(1) {
        	cin >> idAutor;
        	const Usuario* userEncontrado = Search(usuarios, n, idAutor);
        	
        	if(userEncontrado == nullptr) {
        		cout << "Usuario inexistente. Digite novamente um ID valido: ";
				continue;
			}
			
			if(userEncontrado->ativo == 0) {
				cout << "Usuario inativo. Digite novamente um ID valido: ";
				continue;
			}
			
			break;
        }
        (v+i)->idAutor = idAutor;
        
        cout << "Conteudo: ";
        cin.ignore();
        getline(cin, (v+i)->conteudo);
        
        cout << "Curtidas: ";
        cin >> (v+i)->curtidas;
        
        cout << "Visibilidade (1 para publico, 0 para apenas amigos): ";
        int visibilidade;
        cin >> visibilidade;
        (v+i)->publico = (visibilidade == 1);
        
        (v+i)->id = i+1;
        
        cout << "\n";
    }
}

/**
 * Exibe os dados dos posts na tela, incluindo o nome do autor.
 * Paramêtro v Ponteiro para o array de posts.
 * Paramêtro p Número de posts a serem exibidos.
 * Paramêtro usuarios Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários.
 */
void exibirPosts(const Post* v, int p, const Usuario* usuarios, int n) {
    for(int i=0;i<p;i++){

        const Usuario *userEncontrado = Search(usuarios, n, (v+i)->idAutor);
        cout<<"["<< (v+i)->id<< "] "<<    	
	    userEncontrado->username <<
	    ": " << (v+i)->conteudo << 
	    " | Curtidas: " << (v+i)->curtidas << 
	    " | Visibilidade: "; 

        if((v+i)-> publico) 
           cout << "Publico"; 
	    else 
           cout << "Apenas amigos";
	       cout << "\n"<<endl; 

    }
}

/**
 * Incrementa o contador de curtidas de um post.
 * Paramêtro p Ponteiro para o post a ser curtido.
 */
void curtir(Post *p){
    p->curtidas++;
}

/**
 * Torna um post público.
 * Paramêtro p Ponteiro para o post a ser publicado.
 */
void publicarPost(Post* p) {
	
	if(p != nullptr){
		cout << "\n-> Post encontrado: "; 
	
		if(p->publico == true){
			cout << "Esse post ja esta publico.\n\n\n"; 
		} else {
			p->publico=true;
			cout << "Post agora publico.\n\n\n"; 
		}
	}
	else {
		cout << "\n-> Post nao encontrado.\n\n\n"; 
	}
}

/**
 * Torna um post privado (oculto).
 * Paramêtro p Ponteiro para o post a ser ocultado.
 */
void ocultarPost(Post* p) {
	
	if(p != nullptr){
		cout << "\n-> Post encontrado: "; 
	
		if(p->publico == false){
			cout << "Esse post ja esta oculto.\n\n\n"; 
		} else {
			p->publico=false;
			cout << "Post agora oculto.\n\n\n"; 
		}
	}
	else {
		cout << "\n-> Post nao encontrado.\n\n\n"; 
	}
}

/**
 * Busca um post pelo ID.
 * Paramêtro v Ponteiro para o array de posts.
 * Paramêtro p Número de posts no array.
 * Paramêtro id ID do post a ser buscado.
 * return Ponteiro para o post encontrado ou nullptr se não encontrado.
 */
Post* buscarPostPorId(Post* v, int p, int id) {
    for(int i=0;i<p;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}

/**
 * Filtra os posts públicos e retorna um novo array com eles.
 * Paramêtro v Ponteiro para o array de posts original.
 * Paramêtro p Número de posts no array original.
 * Paramêtro qtd Ponteiro para armazenar a quantidade de posts filtrados.
 * return Ponteiro para o novo array de posts públicos ou nullptr se nenhum.
 */
Post* filtrarPublicos(const Post* v, int p, int* qtd) {

    // Conta quantos posts publicos existem
    *qtd = 0;

    for (int i = 0; i < p; i++) {

        if (v[i].publico == true) {
            (*qtd)++;
        }
    }

    // Se nao existir nenhum post publico
    if (*qtd == 0) {
        return nullptr;
    }

    // Cria um novo vetor apenas para os posts publicos
    Post* filtrados = new Post[*qtd];

    int j = 0;

    // Copia apenas os posts publicos
    for (int i = 0; i < p; i++) {

        if (v[i].publico == true) {

            filtrados[j] = v[i];
            j++;
        }
    }

    // Retorna o novo vetor filtrado
    return filtrados;
}

/**
 * Registra uma curtida de um usuário em um post, atualizando a matriz e o contador.
 * Valida se o usuário e o post existem e estão ativos/visíveis.
 * Paramêtro m Matriz de curtidas (usuários x posts).
 * Paramêtro idUsuario ID do usuário que curte.
 * Paramêtro usuarios Ponteiro para o array de usuários.
 * Paramêtro n Número de usuários.
 * Paramêtro idPost ID do post a ser curtido.
 * Paramêtro posts Ponteiro para o array de posts.
 * Paramêtro p Número de posts.
 */
void registrarCurtida(int** m, int idUsuario, const Usuario* usuarios, int n, int idPost, Post* posts, int p) {
    
    const Usuario* userEncontrado = Search(usuarios, n, idUsuario);

    while (1) {

        // Usuario inexistente
        if (userEncontrado == nullptr) {

            cout << "Usuario inexistente. Digite novamente um ID valido: ";
            cin >> idUsuario;

            userEncontrado = Search(usuarios, n, idUsuario);

            continue;
        }

        // Usuario inativo
        if (userEncontrado->ativo == 0) {

            cout << "Usuario inativo. Digite novamente um ID valido: ";
            cin >> idUsuario;

            userEncontrado = Search(usuarios, n, idUsuario);

            continue;
        }

        break;
    }



    // Verificação de Posts
    
    Post* postEncontrado = buscarPostPorId(posts, p, idPost);

    while (1) {

        // Post inexistente
        if (postEncontrado == nullptr) {

            cout << "Post inexistente. Digite novamente um ID valido: ";
            cin >> idPost;

            postEncontrado = buscarPostPorId(posts, p, idPost);

            continue;
        }

        // Post oculto
        if (postEncontrado->publico == 0) {

            cout << "Post oculto. Digite novamente um ID valido: ";
            cin >> idPost;

            postEncontrado = buscarPostPorId(posts, p, idPost);
            
            continue;
        }
        break;
    }


    if(m[idUsuario-1][idPost-1] == 1){
        cout << "O post ja foi curtido.";
    } else {
        m[idUsuario - 1][idPost - 1] = 1;
        curtir(postEncontrado);
        cout << "Curtida registrada com sucesso.";
    }
}
