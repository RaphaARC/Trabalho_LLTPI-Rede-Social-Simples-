#include<iostream>
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

Usuario* buscarUsuarioporId(Usuario* v, int n, int id) {
    for(int i=0;i<n;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}
    
Usuario* usuarioEncontrado = buscarUsuarioporId(users, 2, x);
if(usuarioEncontrado != nullptr) {
    cout << "Usuario encontrado: " << endl;
    exibirUsuarios(usuarioEncontrado, 1);
} else {
     cout << "Usuario nao encontrado." << endl;
}