#include <iostream>
#include <string>
#include "../header.hpp"

using namespace std;
void lerPosts(Post* v, int p, const Usuario* usuarios, int n) {
	cout << "=== LENDO POSTS ===\n\n";
    for(int i=0;i<n;i++){
		
		cout << "-- Post " << i+1 << " --\n";
		
        cout << "ID Autor: ";
        int id;
        const Usuario *userEncontrado = nullptr;
        while(1) {
        	cin >> id;
        	userEncontrado = Search(usuarios, n, id);
        	
        	if(userEncontrado != nullptr) 
        		break;
			else
				cout << "Digite novamente um ID de autor valido: ";
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