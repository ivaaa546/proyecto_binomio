#include <iostream>
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
unsigned long long Factorial(int num) {
    unsigned long long calculo_factorial = 1;
    for (int i = 1; i <= num; i++) {
        calculo_factorial *= i;
    }
    return calculo_factorial;
}

//calculo combinaciones
unsigned long long Combinacion(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Valor no válido
    }
    
    return Factorial(n) / (Factorial(n - k) * Factorial(k));
}





//expansión del binomio //
void expansion_bionomio(int combinacion_, int coeficiente1, int coeficiente2, char l1, char l2, int expl1, int expl2) {
    for (int i = 0; i <= combinacion_; ++i) {
        cout <<"("<<combinacion_<<"C"<<i<<")" << "(" << coeficiente1 << l1 <<"^"<<expl1<< ")^" << (combinacion_ - i) << "(" << coeficiente2 << l2 <<"^"<<expl2<< ")^" << i;
        
        // Si i es menor, seguirá poniendo el +, pero si i es igual que el exponente, se acaba la operación
        if (i < combinacion_) {
            cout << " + ";
        } else {
            cout << endl;
        }
        
    } 
}



//calcular resultado bionomio expandido//
void calcularResultado(int calcular_exponente, int calcular_coeficiente1_, int calcular_coeficiente2, literales exp) {
    cout << "\nResultado: ";
    for (int i = 0; i <= calcular_exponente; ++i) {
        unsigned long long calculo_combinacion = Combinacion(calcular_exponente, i);
        int resultado = calculo_combinacion * pow(calcular_coeficiente1_, calcular_exponente - i) * pow(calcular_coeficiente2, i);

        // Esta parte evita imprimir términos con coeficientes iguales a cero
        if (resultado != 0) {
            if (i > 0) {
                cout << "+ ";
            }   
            cout << resultado;

            // Literal 1 
            if (exp.exponente_literal1 * (calcular_exponente - i) > 0) {
                cout << exp.literal1;
                if (exp.exponente_literal1 * (calcular_exponente - i) > 1) {
                    cout << "^" << exp.exponente_literal1 * (calcular_exponente - i);
                }
            }

            // Literal 2
            if (exp.exponente_literal2 * i > 0) {
                cout << exp.literal2;
                if (exp.exponente_literal2 * i > 1) {
                    cout << "^" << exp.exponente_literal2 * i;
                }
            }
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int exponente;
    int coeficiente1_, coeficiente2_;
    int num_aecontrar;
    literales exp;

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
    

    cout << "Ingrese el primer literal del coeficiente y su exponente (por ejemplo : x 2): ";
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
    cout << "Ingrese el segundo literal del coeficiente y su exponente (por ejemplo: y 2): ";
    cin >> exp.literal2>>exp.exponente_literal2; 

    cout << "(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<" + " << coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << exponente<< endl;

    // Llamada a la función para mostrar el binomio expandido
    expansion_bionomio(exponente, coeficiente1_, coeficiente2_, exp.literal1, exp.exponente_literal2, exp.exponente_literal1, exp.exponente_literal2);
    // Llamada a la función para calcular y mostrar el resultado
    calcularResultado(exponente, coeficiente1_, coeficiente2_, exp);

    cout << endl;


return 0;
}