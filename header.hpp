#ifndef HEADER
#define HEADER

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


// Declaração da função (protótipo)
void lerUsuarios(Usuario* v, int n);
void lerPosts(Post* v, int n, const Usuario* users, int nUsers);
void exibirPosts(const Post* v, int n, const Usuario* users, int nUsers);
void exibirUsuarios(const Usuario* v, int n);
const Usuario* Search(const Usuario* users, int nUsers, int userID);

#endif // HEADER
