#include<iostream>
#include <string>
#include "../include/header.hpp"

using namespace std;

void publicarPost(Post* p) {
	
	if(p != nullptr){
		cout << "\n-> Post encontrado: "; 
	
		if(p->publico == true){
			cout << "Esse post ja esta publico.\n\n\n"; 
		} else {
			p->publico=true;
			cout << "Post agora publico.\n\n\n"; 
		}
	}
	else {
		cout << "\n-> Post nao encontrado.\n\n\n"; 
	}
}
