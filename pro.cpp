#include <iostream>
#include <locale.h>
#include <limits>
#include <cmath>
#include <cctype>
using namespace std;

struct literales
{
    char literal1;
    char literal2;
    int  exponente_literal1;
    int  exponente_literal2;
};

//  para calcular el factorial de un número
int factorial(int num) {
    int calculo_factorial = 1;
    for (int f = 1; f <= num; f++) {
        calculo_factorial = calculo_factorial* f;
    }
    return calculo_factorial;
}

//calculo combinaciones
int  Combinacion(int n, int k) {
    if (k < 0 or k > n) {
        return 0; 
    }
    
    return factorial(n) / (factorial(n - k) * factorial(k));
}

//calcular resultado bionomio expandido//
void resultado_binomio(int calcular_exponente, int calcular_coeficiente1_, int calcular_coeficiente2, literales exp) {
    cout << "\nResultado: ";
    for (int b = 0; b <= calcular_exponente; b++) {
        int calculo_combinacion = Combinacion(calcular_exponente, b);
        int resultado = calculo_combinacion * pow(calcular_coeficiente1_, calcular_exponente - b) * pow(calcular_coeficiente2, b);

        if (resultado != 0) {
            if (b > 0) {
                cout << "+ ";
            }
            cout << resultado;

            // Literal 1 
            if (exp.exponente_literal1 * (calcular_exponente - b) > 0) {
                cout << exp.literal1;
                if (exp.exponente_literal1 * (calcular_exponente - b) > 1) {
                    cout << "^" << exp.exponente_literal1 * (calcular_exponente - b);
                }
            }
            // Literal 2
            if (exp.exponente_literal2 * b > 0) {
                cout << exp.literal2;
                if (exp.exponente_literal2 * b > 1) {
                    cout << "^" << exp.exponente_literal2 * b;
                }
            }
            cout << " ";
        }
    }
    cout << endl;
}
//Imprension expansión del binomio 
void expansion_bionomio(int combinacion_, int coeficiente1, int coeficiente2, char l1, char l2, int expl1, int expl2) {
    for (int b = 0; b <= combinacion_; ++b) {
        cout <<"("<<combinacion_<<"C"<<b<<")" << "(" << coeficiente1 << l1 <<"^"<<expl1<< ")^" << (combinacion_ - b) << "(" << coeficiente2 << l2 <<"^"<<expl2<< ")^" << b;
        
        // Si i es menor, seguirá poniendo el +, pero si i es igual que el exponente, se acaba la operación
        if (b < combinacion_) {
            cout << " + ";
        } else {
            cout << endl;
        }
        
    } 
}
//resta par el binomio sin expandir
int resta(int n1, int n2){

    return n1-n2;

}
//Sin expansion
void resultado_sin(int calcular_exponente, int calcular_coeficiente1_, int calcular_coeficiente2, int num_aecontrar, literales exp) 
{
    int calcular_combinacion = Combinacion(calcular_exponente, num_aecontrar);
    int resta = calcular_exponente - num_aecontrar;
    int  literal1 =  exp.exponente_literal1 * resta;
    int literal2 = exp.exponente_literal2 * num_aecontrar;

    int resultado = calcular_combinacion * pow(calcular_coeficiente1_, resta) * pow(calcular_coeficiente2, num_aecontrar);
    
    cout << "El resultado sin expandir es: " << resultado<<exp.literal1<<"^"<<literal1<<" "<<exp.literal2<<"^"<<literal2<<endl;
}
//Impresion binomio sin expansion
void sin_expansion(int exponente, int coeficiente1, int coeficiente2, char l1, char l2, int expl1, int expl2, int no_econtrar) {
    cout << "(" << coeficiente1 << l1 << "^" << expl1 << " + " << coeficiente2 << l2 << "^" << expl2 << ")^" << exponente << endl;
}

//encontrar el coeficiente de un termino
void coeficientede(int calcular_exponente, int terminocalcular, int calcular_coeficiente1_, int calcular_coeficiente2){
    int resultado;
    int combinacionde = Combinacion(calcular_exponente,terminocalcular);
    resultado = combinacionde *pow(calcular_coeficiente1_,terminocalcular)*calcular_coeficiente2;
    cout<<resultado<<endl;
}


int main() {    
    char opciones;
    int exponente;
    int coeficiente1_, coeficiente2_;
    int num_aecontrar;
    int restaresultado; 
    int terminocalcular;
    literales exp;

    cout << "Ingrese una opcion:\n 1.Binomio Expandido\n 2.Binomio sin expandir \n 3.Calcular el coeficiente de un termino "<<endl;
    cin>> opciones;


        switch (opciones)
    {
    //Opcion 1.Binomio Expandido
    case '1':
    while (true) {
        cout << "Ingresa el exponente del binomio: ";
        if (cin >> exponente) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero. Intente de nuevo." << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    while (true) {
        cout << "\nIngrese el primer coeficiente: ";
        if (cin >> coeficiente1_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero. Intente de nuevo." << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }

    cout << "Ingrese el primer literal del coeficiente y su exponente: ";
    cin >> exp.literal1>>exp.exponente_literal1;
    
     while (true) {
        cout << "\nIngrese el segundo coeficiente: ";
        if (cin >> coeficiente2_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero. Intente de nuevo." << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    cout << "Ingrese el segundo literal del coeficiente y su exponente: ";
    cin >> exp.literal2>>exp.exponente_literal2; 

    cout << "(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<" + " << coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << exponente<< endl;

    // Llamada a la función para mostrar el binomio expandido
    expansion_bionomio(exponente, coeficiente1_, coeficiente2_, exp.literal1, exp.exponente_literal2, exp.exponente_literal1, exp.exponente_literal2);
    // Llamada a la función para calcular y mostrar el resultado
    resultado_binomio(exponente, coeficiente1_, coeficiente2_, exp);
    cout << endl;
        break;
    //Binomio sin expandir
    case '2': 
   
    while (true) {
        cout << "Ingresa el exponente del binomio: ";
        if (cin >> exponente) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero, ingrese la opcion valida" << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }

        while (true) {
        cout << "\nIngrese el primer coeficiente: ";
        if (cin >> coeficiente1_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero, ingrese la opcion valida" << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    cout << "Ingrese el primer literal del coeficiente y su exponente: ";
    cin >> exp.literal1 >> exp.exponente_literal1;
    
    
    while (true) {
        cout << "\nIngrese el segundo coeficiente: ";
        if (cin >> coeficiente2_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero, ingrese la opcion valida" << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }

    cout << "Ingrese el segundo literal del coeficiente y su exponente: ";
    cin >> exp.literal2 >> exp.exponente_literal2; 

    //Llamada para ver la operacion
    sin_expansion(exponente, coeficiente1_, coeficiente2_,num_aecontrar, exp.literal1, exp.literal2, exp.exponente_literal1, exp.exponente_literal2);
    

    cout << "Ingrese el digito que desea encontrar (para encontrar un numero se toma el 0 como 1 y el 1 como 2 asi sucesivamente): ";
    cin >> num_aecontrar;
   // Para mostrar como se hara la operacion
    restaresultado = resta(exponente,num_aecontrar);
    cout <<exponente<<"C"<<num_aecontrar<<" "<<"(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<")"<<"^"<<restaresultado<<"  " <<"("<< coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << num_aecontrar<< endl;

    // Llamada a la función para calcular y mostrar el resultado
    resultado_sin(exponente, coeficiente1_, coeficiente2_, num_aecontrar, exp);

    break;
    case '3':
     while (true) {
        cout << "Ingresa el exponente del binomio: ";
        if (cin >> exponente) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero. Intente de nuevo." << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }

    while (true) {
        cout << "\nIngrese el primer coeficiente: ";
        if (cin >> coeficiente1_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero. Intente de nuevo." << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    cout << "Ingrese el primer literal del coeficiente y su exponente: ";
    cin >> exp.literal1 >> exp.exponente_literal1;

    while (true) {
        cout << "\nIngrese el segundo coeficiente: ";
        if (cin >> coeficiente2_) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero, ingrese la opcion valida" << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    cout << "Ingrese el segundo literal del coeficiente y su exponente: ";
    cin >> exp.literal2 >> exp.exponente_literal2; 
    
    while (true) {
        cout << "\nIngrese el termino que desee calcular ";
        if (cin >> terminocalcular) {
            break; // Salir del bucle si se ingresó un número válido
        } else {
            cout << "No es un numero, ingrese la opcion valida" << endl;
            cin.clear(); // Restablecer el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
    }
    cout<<"("<<coeficiente1_<<exp.literal1<<"+"<<coeficiente2_<<exp.literal2<<")"<<"^"<<exponente<<endl;
     coeficientede(exponente,terminocalcular, coeficiente1_, coeficiente2_);

    break;
    default:
    cout<<"ingresa una opcion valida";
    break;
}

system("pause");
return 0;
}