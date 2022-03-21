#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

void lexer(string archivo) {
  ifstream input; //file
  char current; //current character
  input.open(archivo); //open file to read
  current =' '; //current character starts as empty
  string number = "";
  string var = "";

  while(input.get(current)){//while you can get a character from file
    if(current == '+'){
      cout << current << " " << "Operador de Suma" << endl;
    }
    if(current == '*'){
      cout << current << " " << "Operador de Multiplicacion" << endl;
    }
    if(current == '('){
      cout << current << " " << "Caracter Especial" <<endl;
    }
    if(current == ')'){
      cout << current << " " << "Caracter Especial" <<endl;
    }
    if(current == '^'){
      cout << current << " " << "Operador de Potencia" << endl;
    }
    if(current == '='){
      cout << current << " " << "Operador de Igual" << endl;
    }
    if(isdigit(current)){
      number = number + current;
    }
    if(isalpha(current)){

      var = var + current;
    }
      }
      cout << var << " " << "Variable" << endl;
      cout << number << " " << "Numero Entero" <<endl;
}








int main() {
  lexer("input1.txt");
  return 0;
}
