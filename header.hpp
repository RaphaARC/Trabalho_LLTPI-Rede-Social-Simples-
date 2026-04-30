#ifndef HEADER
#define HEADER

#include <string>
using namespace std;

class Usuario
{
public:
    string username;
    string email;
    int id;
    int seguidores;
    bool ativo; // true = conta ativa, false = conta suspensa
};


class Post {
    public:
    string conteudo; // texto do post
    int id;
    int idAutor; // id do Usuario que criou o post
    int curtidas;
    bool publico; // true = vis´ıvel para todos, false = apenas seguidores
};
    
};


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
void exibirUsuarios(const Usuario* v, int n);
void Search(Usuario* users, int nUsers, int userID);
Usuario* buscarUsuarioporId(Usuario* v, int n, int id);

#endif // MATEMATICA_H
