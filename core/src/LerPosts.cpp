#include <iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;
void lerPosts(Post* v, int p, const Usuario* usuarios, int n) {
	cout << "=== LENDO POSTS ===\n\n";
    for(int i=0;i<n;i++){
		
		cout << "-- Post " << i+1 << " --\n";
		
        cout << "ID Autor: ";
        int id;
        while(1) {
        	cin >> id;
        	const Usuario* userEncontrado = Search(usuarios, n, id);
        	
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
        (v+i)->idAutor = id;
        
        cout << "Conteudo: ";
        cin.ignore();
        getline(cin, (v+i)->conteudo);
        
        cout << "Curtidas: ";
        cin >> (v+i)->curtidas;
        
        cout << "Visibilidade (1 para publico, 0 para apenas amigos): ";
        int visibilidade;
        cin >> visibilidade;
        (v+i)->publico = (visibilidade == 1);
        
        cout << "\n";
    }
}
