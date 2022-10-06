#include "adts/node.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace eda;
using namespace std;

//hola catita bonita :D
/*
bool validateParenthesis(const std::string &input, int* pos){
	bool error = false;
	int i = 0;
	Stack stack;
	while (!error && i < input.length()){
		if (input[i] == '(') {
			stack.push(new Node(input[i]));
		}
		if (input[i] == ')') {
			if (stack.isEmpty()){
				error = true;
			}
			else{
				stack.pop();
			}
		}
		i = i + 1;
	}
	if (!stack.isEmpty()){
		error = true;
	}
	*pos = i - 1 ;
	return !error;
}
*/

/*int main(int nargs, char** vargs){
	std::string input;
	int pos=0;
	std::cout<<"Ingresa expresión: ";
	std::getline(std::cin, input);
	bool status = validateParenthesis(input, &pos);
	if (status){
		std::cout<< " Expresión Correcta " << std::endl;
	}
	else{
		std::cout<< " Expresión Inválida" << std::endl;
		std::cout<< "Pos error:  " << pos	<< std::endl;
	}

	return 0;
}
*/

int main(int nargs, char** vargs){
	string nombreArchivo;
	bool con = false;
	if (nargs < 2 ){
		cout << "No se ingreso el archivo a validar" << endl;
	}
	if (nargs == 2){
		nombreArchivo = vargs[1];
		string nombre;
		for (int j = 0; j < nombreArchivo.length(); j++){ //para obtener el nombre del archivo nuevo
			if (nombreArchivo[j] == '.'){
				break;
			}
			nombre += nombreArchivo[j];
		}
		string conf = ".html";
		string aux = nombreArchivo;
		int lon = nombreArchivo.length() - 5;
		aux = aux.erase(0,lon);
		if (aux == conf ){
			con = true;
		}
	}
	if (con){

	
	ifstream archivo(nombreArchivo.c_str());
	bool error = false;
	string linea;
	string name_tags[500];
	string tag;
	Stack opent;
	string dato;
	
	while(getline(archivo,linea)){
		bool add = false;
		if (error){
			break;
		}
		for(int i=0;i<linea.length();i++){
			if (error){
			break;
			}
			if(linea[i]=='>'){
				add= false;
				if(tag[0] != '/'){
					Node * nod = new Node(tag);
					opent.push(nod);
				}
				if(tag[0] == '/'){
					dato = "/" +opent.top()->getData();
					if(dato == tag){
						opent.pop(); //elimina el que esta arriba
					}
					if(dato != tag){
						error = true;
					}
				}
				cout<<"tag: "<<tag<<endl;
				tag="";
			}
			if(add){
				tag+=linea[i];
			}
			
			if(linea[i]=='<'){
				add= true;
			}
			

		}
	}
	return 0;
	}
	
	


	return 0;
}
