#include <iostream>
#include <string>

using namespace std;

struct Usuario {
string username;
string email;
int id;
int seguidores;
bool ativo; // true = conta ativa, false = conta suspens
};

struct Post {
string conteudo; // texto do post
int id;
int idAutor; // id do Usuario que criou o post
int curtidas;
bool publico; // true = vis´ivel para todos, false = apenas seguidores
};



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

const Usuario* buscarUsuarioporId(const Usuario* v, int n, int id) {
    for(int i=0;i<n;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}

void exibirUsuarios(const Usuario* v, int n){
	for(int i=0; i<n; i++) {

        cout<<"["<< (v+i)->id<< "] "<<    	
	    (v+i)->username <<
	    " | E-mail: @" << (v+i)->email << 
	    " | Seguidores: " << (v+i)->seguidores << 
	    " | Status: "; 

        if((v+i)-> ativo) 
           cout << "Ativo"; 
	    else 
           cout << "Inativo";
	       cout << "\n"<<endl; 
	
	}
}

void lerPosts(Post* v, int p, const Usuario* usuarios, int n){
	
	cout << "=== LENDO POSTS ===\n\n";
    for(int i=0;i<p;i++){
		
		cout << "-- Post " << i+1 << " --\n";
		
        cout << "ID Autor: ";
        const Usuario *userEncontrado = nullptr;
        while(true){
        	cin >> (v+i)->idAutor;
        	userEncontrado = buscarUsuarioporId(usuarios, n, (v+i)->idAutor);
        	
        	if(userEncontrado != nullptr) {
                if(userEncontrado->ativo != 0){
        		    break;
                }else{
                    cout << "O ID inserido nao esta ativo, por favor, digite outro ID valido " << endl;
                }
			}else{
				cout << "Digite novamente um ID de autor valido: " << endl;
			}
		}

        cout << "Conteudo: ";
        cin.ignore();
        getline(cin, (v+i)->conteudo);

        cout << "Curtidas: ";
        cin >> (v+i)->curtidas;
        
        cout << "O post e publico? (0-nao, 1-sim): ";
        cin >> (v+i)->publico;
        
        (v+i)->id = i+1;
        
        cout << endl;
    }
    cout << endl;
}

void exibirPosts(Post* v, int p, const Usuario* usuarios, int n){
    for(int i=0;i<p;i++){

        const Usuario *userEncontrado = buscarUsuarioporId(usuarios, n, (v+i)->idAutor);
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

void curtir(Post *p){
    p->curtidas++;
}

int main(){



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
    lerPosts(posts, nPosts, users, nUsers);

//Exibição de Usuários e Posts
    exibirUsuarios(users, nUsers);
    exibirPosts(posts, nPosts, users, nUsers);    

	cout << "Digite um id para buscar: ";
	int x;
	cin >> x;




const Usuario* usuarioEncontrado = buscarUsuarioporId(users, nUsers, x);
if(usuarioEncontrado != nullptr) {
    cout << "Usuario encontrado: " << endl;
    exibirUsuarios(usuarioEncontrado, 1);
} else {
     cout << "Usuario nao encontrado." << endl;
}



delete[] users;
	users = nullptr;
delete[] posts;
    posts = nullptr;

return 0;
}