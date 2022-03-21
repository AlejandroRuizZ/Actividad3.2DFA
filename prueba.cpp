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
  string var = " ";
  
  while(input.get(current)){//while you can get a character from file 
    char c = input.peek();
    
    if (current =='/' and c == '/'){
      var=current;
    }
    if ( var.at(0) == '/' and current != '\n'){
      var=var+current;
    }
    if (current == '\n' and var.at(0) == '/'){
      var.erase(0,1);
      cout << var << " " << "Comentario" << endl;
      var = " ";
    }
    
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
    if(isdigit(current) || isalpha(current)||input.eof() ){
        if(isalpha(current) and var.at(0) == ' '){
            var = current;
        }

        if (isalpha(var.at(0))){
            if(isalpha(current) ){
            var = var + current;
            }
            if(isdigit(current) ){
            var = var + current;
            } 
            if (input.eof() || c == ' ' ||  c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' ||
            c == '=' || c == '/' || c == '(' || c== ')') {
                var.erase(0,1);
                cout << var << " " << "Variable" << endl;
                var = " ";
            };

        }

    }  //Esto es un commentario Commentario
      //number = number + current; 
  }
    /*if(isalpha(current)){
        var = var + current;
        if ( current == ' ')
        {
            cout << var << " " << "Variable" << endl; 
            var= "";
        }
        
       
      
    }
    */
    //cout << var << " " << "Numero Entero" <<endl;
}

int main() {
  lexer("input1.txt");
  return 0;
}
