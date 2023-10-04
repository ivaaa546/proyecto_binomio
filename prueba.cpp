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
//resta par el binomio sin expandir
unsigned long long resta(int n1,int n2){

    return n1-n2;

}
//sin expansion
void sin_expansion(int exponente, int coeficiente1, int coeficiente2, char l1, char l2, int expl1, int expl2, int no_econtrar) {
    cout << "(" << coeficiente1 << l1 << "^" << expl1 << " + " << coeficiente2 << l2 << "^" << expl2 << ")^" << exponente << endl;
}

//solucion sin expansion
void resultado_sin(int calcular_exponente, int calcular_coeficiente1_, int calcular_coeficiente2, int num_aecontrar, literales exp) {
    unsigned long long calcular_combinacion = Combinacion(calcular_exponente, num_aecontrar);
    unsigned long long resta = calcular_exponente - num_aecontrar;

    unsigned long long literal1 =  exp.exponente_literal1 * resta;
    unsigned long long literal2 = exp.exponente_literal2 * num_aecontrar;

    unsigned long long resultado = calcular_combinacion * pow(calcular_coeficiente1_, resta) * pow(calcular_coeficiente2, num_aecontrar);
    
    cout << "El resultado sin expandir es: " << resultado<<exp.literal1<<"^"<<literal1<<" "<<exp.literal2<<"^"<<literal2<<endl;
}

int main() {
    char opciones;
    int exponente;
    int coeficiente1_, coeficiente2_;
    int num_aecontrar;
    int restaresultado;
    literales exp;

    cout << "Ingrese una opcion:\n 1.Binomio Expandido\n 2.Binomio sin expandir \n 3.Calcular el coeficiente de un término "<<endl;
    cin>> opciones;


        switch (opciones)
    {
    //Opcion 1.Binomio Expandido
    case '2':
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
    cout << "Ingrese el primer literal del coeficiente y su exponente (por ejemplo: x 2): ";
    cin >> exp.literal1 >> exp.exponente_literal1;
    
    
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
    //Binomio sin expandir
    
    case '3':

    break;

}
return 0;
}