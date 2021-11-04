#include <iostream>

using namespace std;

struct nodo
{
    int id;
    string dueno;
    string raza;
    float peso;
    float edadpet;
    nodo *sig;
} *primero, *ultimo;

void insertarDatos();
void mostrarDatos();
void eliminarDatos();
void buscarDat();

int main()
{
    int opcion;
    cout << endl;
    cout << "\tAdministracion de una Veterinaria." << endl << endl;
    do
    {
        cout << "Opciones: " << endl;
        cout << "1. Insertar datos de su mascota." << endl;
        cout << "2. Mostrar datos de su mascota." << endl;
        cout << "3. Eliminar datos de su mascota." << endl;
        cout << "4. Terminar/Finalizar." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
            insertarDatos();
            break;
            case 2:
            cout << "Los datos que ingreso son los siguientes: " << endl << endl;
            mostrarDatos();
            break;
            case 3:
            eliminarDatos();
            break;
        }
    } while(opcion != 4);
    return 0;
}

void insertarDatos()
{
    nodo* nuevo = new nodo();
    cout << "Ingrese el id: ";
    cin >> nuevo->id;
    cout << "Ingrese el nombre del dueno: ";
    cin >> nuevo->dueno;
    cout << "Ingrese la especie/raza: ";
    cin >> nuevo->raza;
    cout << "Ingrese el peso: ";
    cin >> nuevo->peso;
    cout << "Ingrese la edad: ";
    cin >> nuevo->edadpet;
    cout << endl;

    if(primero == NULL)
    {
        primero = nuevo;
        primero->sig = primero;
        ultimo = primero;
    }
    else
    {
        ultimo->sig = nuevo;
        nuevo->sig = primero;
        ultimo = nuevo;
    }
    cout << "Datos ingresados correctamente." << endl << endl;
}

void mostrarDatos()
{
    nodo* actual = new nodo();
    actual = primero;
    if(primero != NULL)
    {
        do
        {
            cout << "[" << actual->id << "]";
            cout << "_" << actual->dueno;
            cout << "_" << actual->raza;
            cout << "_" << actual->peso;
            cout << "_" << actual->edadpet << endl << endl;
            actual = actual->sig;
        }
        while(actual != primero);
    }
    else
    {
        cout << "No se encuentran ningun dato." << endl << endl;
    }
}

void buscarDat()
{
    nodo* actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBusc = 0;
    cout << "Ingrese el dato del nodo: ";
    cin >> nodoBusc;
    if(primero != NULL)
    {
        do
        {
            if(actual->id == nodoBusc)
            {
                cout << "Le nodo " << nodoBusc << "fue encontrado";
                encontrado = true;
            }

            actual = actual->sig;
        }
        while(actual != primero && encontrado != true);
        if(!encontrado)
        {
            cout << "No encontrado";
        }
    }
    else
    {
        cout << "No se encuentrar datos.";
    }
}

void eliminarDatos()
{
    nodo* actual = new nodo();
    actual = primero;
    nodo* anterior = new nodo();
    anterior = NULL;
    bool encontrado = false;
    int nodoBusc = 0;
    cout << "Ingrese el id que desea eliminar: ";
    cin >> nodoBusc;
    if(primero != NULL)
    {
        do
        {
            if(actual->id == nodoBusc)
            {
                cout << "Los datos del id [ " << nodoBusc;
                if(actual == primero)
                {
                    primero = primero->sig;
                    ultimo->sig = primero;
                }
                else if( actual == ultimo)
                {
                   anterior->sig = primero;
                   ultimo = anterior;
                }
                else{
                    anterior->sig = actual->sig;
                }
                cout << " ] fueron ELIMINADO" << endl << endl;
                encontrado = true;
            }
            anterior = actual;
            actual = actual->sig;
        }
        while(actual != primero && encontrado != true);
        if(!encontrado)
        {
            cout << endl << "El id que ingreso no se encuentra disponible." << endl << endl;
        }
    }
    else
    {
        cout << endl << "El id que ingreso no se encuentra disponible." << endl << endl;
    }
}
