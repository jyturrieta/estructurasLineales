#include <iostream>
#include "nodo.h"
#include "lista.h"

using namespace std;

/*ejercicio1*/
/*int main(){
    Lista lista = Lista();
    lista.alta(2,1);
    lista.alta(5,2);
    lista.alta(4,3);
    lista.alta(3,4);
    cout << "Lista original: "; lista.mostrar();
    lista.insertarProductos();
    return 0;
}*/

/*ejercicio2*/
/*int main(){
    Lista lista = Lista();
    lista.alta(20,1);
    lista.alta(10,2);
    lista.alta(6,3);
    lista.alta(3,4);
    cout << "Lista original: "; lista.mostrar();
    lista.separarContiguosDivisibles();
    return 0;
}*/

/*ejercicio3*/
int main(){
    Lista lista = Lista();
    lista.alta(2,1);
    lista.alta(5,2);
    lista.alta(4,3);
    lista.alta(3,4);
    cout << "Lista original: "; lista.mostrar();
    lista.eliminarYRetornarImpares();
    return 0;
}