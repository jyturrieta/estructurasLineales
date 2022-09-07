#include "lista.h"


Lista::Lista() {
    primero = 0;
    largo = 0;
}

bool Lista::vacia() {
    return (largo == 0);
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);

    if (pos == 1) {
        nuevo -> cambiar_siguiente(primero);
        primero = nuevo;
    } 
    else {
        Nodo* anterior = obtener_nodo(pos-1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    
    for (int i=1; i<pos; i++) {
        aux = aux->obtener_siguiente();
    }
    return aux;
}

Dato Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::baja(int pos) {
    Nodo* borrar;

    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    largo--;
}

Lista::~Lista() {
    while (!vacia()) {
        baja(1);
    }
}

int Lista::obtener_largo() {
    return largo;
}

void Lista::mostrar(){
    cout << "[";
    if (!vacia()) {
        for (int i=1; i<largo; i++) {
            cout << this->consulta(i)<<",";
        }
        cout << consulta(largo);
    }
    cout << "]" <<endl;
}


void Lista::insertarProductos() {
    int pos = 1;
    int dato1, dato2 ;
    while (pos != obtener_largo()){
        dato1 = consulta(pos);
        dato2 = consulta(pos+1);
        int producto = dato1*dato2;
        alta(producto, pos+1);
        pos+=2;
    } cout << "Lista con productos insertados: ";
    mostrar();
}

void Lista::separarContiguosDivisibles(){
    int pos = 1;
    int a, b;
    while(pos<=obtener_largo()){
        a=consulta(pos);
        b=consulta(pos+1);
        int resultado;
        if(a%b==0){
            resultado = a/b;
            alta(resultado, pos+1);
            pos+=2;
        }
        pos+=1;
    }
    cout << "Lista con contiguos divisibles: ";
    mostrar();
}

Lista* Lista::eliminarYRetornarImpares(){
    int pos = 1;
    int dato;
    Lista* listaImpares = new Lista();
    
    while(pos<=obtener_largo()){
        dato = consulta(pos);
        if(dato%2==1){
            
            baja(pos);
            listaImpares -> alta(dato, listaImpares -> obtener_largo() + 1);
        }else{
            pos+=1;
        }
    }
    cout << "Lista de pares: ";
    mostrar();
    cout << "Lista de impares: ";
    listaImpares -> mostrar();
}