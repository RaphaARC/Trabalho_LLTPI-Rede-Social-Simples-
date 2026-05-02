#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void ocultarPost(Post* p) {
	
	if(p != nullptr){
		cout << "\n-> Post encontrado: "; 
	
		if(p->publico == false){
			cout << "Esse post ja esta oculto.\n\n\n"; 
		} else {
			p->publico=false;
			cout << "Post agora oculto.\n\n\n"; 
		}
	}
	else {
		cout << "\n-> Post nao encontrado.\n\n\n"; 
	}
}
