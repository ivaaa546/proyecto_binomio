#include <iostream>
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

//calcular resultado//
void calcularResultado(int exponente, int coeficiente1_, int coeficiente2, literales exp) {
    cout << "\nResultado: ";
    for (int i = 0; i <= exponente; ++i) {
        unsigned long long calculo_combinacion = Combinacion(exponente, i);
        int resultado = calculo_combinacion * pow(coeficiente1_, exponente - i) * pow(coeficiente2, i);

        // Esta parte evita imprimir términos con coeficientes iguales a cero
        if (resultado != 0) {
            if (i > 0) {
                cout << "+ ";
            }
            cout << resultado;

            // Literal 1 
            if (exp.exponente_literal1 * (exponente - i) > 0) {
                cout << exp.literal1;
                if (exp.exponente_literal1 * (exponente - i) > 1) {
                    cout << "^" << exp.exponente_literal1 * (exponente - i);
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
    literales exp;

    cout << "Ingresa el exponente del binomio: ";
    cin >> exponente;
    
    if (cin.fail()) {
    cout << "No es un número. Intente de nuevo." << endl;
    return 1;
}


    cout << "\nIngrese el primer coeficiente: ";
    cin >> coeficiente1_;
    if (cin.fail()) {
    cout << "No es un digito, por favor intente de nuevo" << endl;
    return 1;
}

    
    cout << "Ingrese el primer literal del coeficiente: ";
    cin >> exp.literal1>>exp.exponente_literal1;
    
    cout << "\nIngrese el segundo coeficiente: ";
    cin >> coeficiente2_;
    if (cin.fail()) {
    cout << "No es un digito, por favor intente de nuevo" << endl;
    return 1;
}
    cout << "Ingrese el segundo literal del coeficiente: ";
    cin >> exp.literal2>>exp.exponente_literal2; 

    cout << "(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<" + " << coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << exponente<< endl;
    
    expansion_bionomio(exponente, coeficiente1_, coeficiente2_, exp.literal1, exp.exponente_literal2, exp.exponente_literal1, exp.exponente_literal2);
    // Llamada a la función para calcular y mostrar el resultado
    calcularResultado(exponente, coeficiente1_, coeficiente2_, exp);


    cout << endl;

    
    return 0;
}