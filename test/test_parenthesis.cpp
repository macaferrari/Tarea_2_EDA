#include "adts/node.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace eda;
using namespace std;

//hola catita bonita :D
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
	string nombreArchivo="estructura.txt";
	ifstream archivo(nombreArchivo.c_str());
	string linea;
	string name_tags[500];
	string tag;
	while(getline(archivo,linea)){
		bool add=false;
		for(int i=0;i<linea.length();i++){
			
			if(linea[i]=='>'){
				add= false;
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
