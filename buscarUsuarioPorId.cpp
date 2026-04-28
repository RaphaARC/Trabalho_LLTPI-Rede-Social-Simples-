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
bool publico; // true = vis´ıvel para todos, false = apenas seguidores
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

Usuario* buscarUsuarioporId(Usuario* v, int n, int id){
    for(int i=0;i<n;i++){

        if(v[i].id == id){

            return &v[i];

        }

    }
    return nullptr;
}

void exibirUsuarios(const Usuario* v, int n){
    for(int i=0; i<n; i++){
        
    cout<<"["<< (v+i)->id<< "] "<<      
    (v+i)->username <<
    " | E-mail: @" << (v+i)->email << 
    " | Seguidores: " << (v+i)->seguidores << 
    " | Status: "; if((v+i)->ativo){ cout<<"Ativo";} 
    else {cout<<"Inativo";}
    cout <<"\n"<<endl; 
    
    }
}

int main(){
    int x;
	
	Usuario *users = new Usuario[2];
	
	lerUsuarios(users, 2);
	
    cout << "Digite um ID para buscar o usuario deste ID " << endl;
    cin >> x;

    Usuario* usuarioEncontrado = buscarUsuarioporId(users, 2, x);
    if(usuarioEncontrado != nullptr){

        cout << "Usuario encontrado: " << endl;
        exibirUsuarios(usuarioEncontrado, 1);

    }else{

        cout << "Usuario nao encontrado." << endl;

    }

	delete[] users;
	users = nullptr;
	
	return 0;
}
