#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
using namespace std;

// =======================
// 👤 USUARIOS
// =======================

struct Usuario {
    string username;
    string email;
    int id;
    int seguidores;
    bool ativo; // true = conta ativa, false = conta suspensa
};

void lerUsuarios(Usuario* v, int n);
void exibirUsuarios(const Usuario* v, int n);
Usuario* buscarUsuarioporId(Usuario* v, int n, int id);
const Usuario* Search(const Usuario* users, int nUsers, int userID);
void reativarUsuario(Usuario* u, int nUsers);
void suspenderUsuario(Usuario* u, int nUsers);

// =======================
// 📝 POSTS
// =======================

struct Post {
    string conteudo; // texto do post
    int id;
    int idAutor; // id do Usuario que criou o post
    int curtidas;
    bool publico; // true = vis´ıvel para todos, false = apenas seguidores
};

void lerPosts(Post* v, int n, const Usuario* users, int nUsers);
void exibirPosts(const Post* v, int n, const Usuario* users, int nUsers);
Post* buscarPostPorId(Post* v, int p, int id);
int contarPostsDeUsuario(const Post* v, int p, int idUsuario);

#endif // HEADER_HPP
