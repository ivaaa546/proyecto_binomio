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
//resta par el binomio sin expandir
unsigned long long resta(int n1, int n2){

    return n1-n2;

}
//sin expansion
void sin_expansion(int exponente, int coeficiente1, int coeficiente2, char l1, char l2, int expl1, int expl2, int no_econtrar) {
    cout << "(" << coeficiente1 << l1 << "^" << expl1 << " + " << coeficiente2 << l2 << "^" << expl2 << ")^" << exponente << endl;
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
//solucion sin expansion
void resultado_sin(int calcular_exponente, int calcular_coeficiente1_, int calcular_coeficiente2, int num_aecontrar, literales exp) {
    unsigned long long calcular_combinacion = Combinacion(calcular_exponente, num_aecontrar);
    unsigned long long resta = calcular_exponente - num_aecontrar;
    unsigned long long exponenteY = calcular_exponente;
    unsigned long long literal1 =  exp.exponente_literal1 * resta;
    unsigned long long literal2 = exp.exponente_literal2 * num_aecontrar;
    unsigned long long resultado = calcular_combinacion * pow(calcular_coeficiente1_, resta) * pow(calcular_coeficiente2, exponenteY);
    
    cout << "El resultado sin expandir es: " << resultado<<exp.literal1<<"^"<<literal1<<" "<<exp.literal2<<"^"<<literal2<<endl;
}

int main() {
    char opciones;
    int exponente;
    int coeficiente1_, coeficiente2_;
    int num_aecontrar;
    literales exp;

    cout << "Ingrese una opcion:\n 1.Binomio Expandido\n 2.Binomio sin expandir "<<endl;
    cin>> opciones;


        switch (opciones)
    {
    case '1':
    cout << "Ingresa el exponente del binomio: ";
    cin >> exponente;
    if (cin.fail()) {
    cout << "No es un numero. Intente de nuevo." << endl;
    return 1;
}
        cout << "\nIngrese el primer coeficiente: ";
    cin >> coeficiente1_;
    if (cin.fail()) {
    cout << "No es un digito, por favor intente de nuevo" << endl;
    return 1;
}
    cout << "Ingrese el primer literal del coeficiente y su exponente (por ejemplo : x 2): ";
    cin >> exp.literal1>>exp.exponente_literal1;
    
    cout << "\nIngrese el segundo coeficiente: ";
    cin >> coeficiente2_;
    if (cin.fail()) {
    cout << "No es un digito, por favor intente de nuevo" << endl;
    return 1;
}
    cout << "Ingrese el segundo literal del coeficiente y su exponente (por ejemplo: y 2): ";
    cin >> exp.literal2>>exp.exponente_literal2; 

    cout << "(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<" + " << coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << exponente<< endl;

    // Llamada a la función para mostrar el binomio expandido
    expansion_bionomio(exponente, coeficiente1_, coeficiente2_, exp.literal1, exp.exponente_literal2, exp.exponente_literal1, exp.exponente_literal2);
    // Llamada a la función para calcular y mostrar el resultado
    calcularResultado(exponente, coeficiente1_, coeficiente2_, exp);
    cout << endl;
        break;

    case '2': 
    cout << "Ingresa el exponente del binomio: ";
    cin >> exponente;
    if (cin.fail()) {
        cout << "No es un numero. Intente de nuevo." << endl;
        return 1;
    }
    cout << "\nIngrese el primer coeficiente: ";
    cin >> coeficiente1_;
    if (cin.fail()) {
        cout << "No es un digito, por favor intente de nuevo" << endl;
        return 1;
    }
    
    cout << "Ingrese el primer literal del coeficiente y su exponente (por ejemplo: x 2): ";
    cin >> exp.literal1 >> exp.exponente_literal1;
    
    cout << "\nIngrese el segundo coeficiente: ";
    cin >> coeficiente2_;
    if (cin.fail()) {
        cout << "No es un digito, por favor intente de nuevo" << endl;
        return 1;
    }

    cout << "Ingrese el segundo literal del coeficiente y su exponente (por ejemplo: y 2): ";
    cin >> exp.literal2 >> exp.exponente_literal2; 

    //Llamada para ver la operacion
    sin_expansion(exponente, coeficiente1_, coeficiente2_, exp.literal1, exp.literal2, exp.exponente_literal1, exp.exponente_literal2, num_aecontrar);
    

    cout << "Ingrese el digito que desea encontrar (para encontrar un numero se toma el 0 como 1 y el 1 como 2 asi sucesivamente): ";
    cin >> num_aecontrar;
   // Para mostrar como se hara la operacion
    unsigned long long restaresultado = resta(exponente,num_aecontrar);
    cout <<exponente<<"C"<<num_aecontrar<<" "<<"(" << coeficiente1_ << exp.literal1 <<"^"<<exp.exponente_literal1<<")"<<restaresultado<<"  " << coeficiente2_ << exp.literal2<<"^"<<exp.exponente_literal2<< ")^" << num_aecontrar<< endl;

    // Llamada a la función para calcular y mostrar el resultado
    resultado_sin(exponente, coeficiente1_, coeficiente2_, num_aecontrar, exp);
    break;
}


return 0;
}