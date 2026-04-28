#include <iostream>
#include <string>

using namespace std;

struct Usuario {
string username;
string email;
int id;
int seguidores;
bool ativo; // true = conta ativa, false = conta suspensa
};

struct Post {
string conteudo; // texto do post
int id;
int idAutor; // id do Usuario que criou o post
int curtidas;
bool publico; // true = visível para todos, false = apenas seguidores
};


void lerUsuarios(Usuario* v, int n){

    cout << "=== LENDO USUARIOS ===\n\n";
    for(int i=0;i<n;i++){
		
		cout << "-- Usuario " << i+1 << " --\n";
		
        cout << "Nome: ";
        cin.ignore();
        getline(cin, (v+i)->username);

        cout << "Email: ";
        cin.ignore();
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
	
	return 0;
}
