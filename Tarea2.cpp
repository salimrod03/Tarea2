#include <iostream>
#include <stdlib.h>


using namespace std;

class Personaje
{
protected:
    string nombre;
    string tipo;
    int niveldepelea;
    string ubicacion;
private:
    int *data;
    int np;
public:
    Personaje(string,string,int,string);
    virtual void imprimir();
    void resize(int&, int );
    void remove(const int);
};

Personaje::Personaje(string n,string t,int ndp,string u)
{
    nombre = n;
    tipo = t;
    niveldepelea = ndp;
    ubicacion = u;
    cout<<"Personaje creado"<<endl;
}

void Personaje::imprimir()
{
    cout<<"Su nombre es: "<<nombre<<","<<" es de tipo: "<<tipo<<","<<" tiene: "<<niveldepelea<<" de nivel de pelea y se ubica en: "<<ubicacion<<"."<<endl;
}

void Personaje::resize(int &np, int tam)
{
    np += tam;
    int *data2 = new int[np];
    for(int i = 0; i< np; i++)
            data2[i] = data[i];
    delete[] data;
    data = data2;
}
void Personaje::remove(const int pos)
{
    data[pos] = 0;
    for (int i = pos; i < np - 1; i++){
        data[i] = data[i+1];
        }
    resize(np, - 1);
}
int main()
{
    int np;//numero de personajes
    cout<<"Ingrese la cantidad de personajes que desea agregar a la lista: ";cin>>np;

    Personaje *listapersonajes[np];

    for(int i=0;i<np;i++){
        string n,u,t;//nombre, ubicacion y tipo
        int ndp;//Nivel de Pelea
        cout<<"\nNombre: ";cin>>n;
        cout<<"Tipo: ";cin>>t;
        cout<<"Nivel de Pelea: ";cin>>ndp;
        cout<<"Ubicacion: ";cin>>u;
        *(listapersonajes+i)= new Personaje(n,t,ndp,u);
    }

    cout<<"\nMostrando lista de personajes: \n";
    for(int i=0;i<np;i++){
        cout<<"Personaje "<< i+1 <<": ";
        listapersonajes[i]->imprimir();
    }

    int pos;
    cout<<"\nAhora eliminaremos un personaje "<<endl<<"Escoga el numero del que desea eliminar: "<<endl;
    cin>>pos;
    listapersonajes[np]->remove(pos);

    cout<<"\nMostrando lista de personajes actualizada: \n";
    for(int i=0;i<np;i++){
        cout<<"Personaje "<< i+1 <<": ";
        listapersonajes[i]->imprimir();
    }
    return 0;
}
