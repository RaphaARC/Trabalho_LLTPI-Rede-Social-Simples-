#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

Post* buscarPostPorId(Post* v, int p, int id) {
    for(int i=0;i<p;i++) {
    if(v[i].id == id)
        return &v[i];
    } return nullptr;
}
