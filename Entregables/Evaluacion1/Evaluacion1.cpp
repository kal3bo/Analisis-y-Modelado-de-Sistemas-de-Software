//Diego Kaleb Valenzuela Carrillo
//A01018992
//Evaluación 1

#include <iostream>
#include <string>
#include <vector>
using namespace std; 

//Creación de la clase Videojuego:
class Videojuego{
public:
    //Atributos generales:
    string nombre;                                  
    float precio, califiacion;
    int ano;
    long int nSerie;
    //Clonar:
    virtual Videojuego* clon() = 0;
    //Funciones:
    void setAll(string n, float p, int a, float c, long int nS){
        nombre = n;
        precio = p;
        ano = a;
        califiacion = c;
        nSerie = nS;
    }
    long int getNserie(){
        return nSerie;
    }
    void getAll(){cout << "Titulo: " << nombre <<  "\nPrecio: " << precio << "\nAño: " <<  ano << "\nCalificación: " << califiacion << "\nNúmero de Serie: " << nSerie << endl; }
    //Funciones requeridas por el cliente:
    virtual void concepcion() = 0;                  
    virtual void diseno() = 0;
    virtual void planificacion() = 0;
    virtual void produccion() = 0;
    virtual void pruebas() = 0;
    
    //Creación de Factory Method:
    template<class T>
    static Videojuego* factoryMethod(){
        T* t = new T;

        t->concepcion();
        t->diseno();
        t->planificacion();
        t->produccion();
        t->pruebas();
        return t;
    }
};

//Clase para clonar:
template <class SubClase>
class ClonVideojuego : public Videojuego{
public:
    virtual Videojuego* clon(){
        return new SubClase(dynamic_cast<SubClase&>(*this));    
    }
};

//Tipos de videojuegos: (Subclases)
class Estrategia : public ClonVideojuego<Estrategia>{
public:
    void concepcion(){ cout << "Operación Concepción en Estrategia" << endl; }
    void diseno(){ cout << "Operación Diseño en Estrategia" << endl; }
    void planificacion(){ cout << "Operación Planificación en Estrategia" << endl; }
    void produccion(){ cout << "Operación Producción en Estrategia" << endl; }
    void pruebas(){ cout << "Operación Pruebas en Estrategia" << endl; }
    
};

class Aventura : public ClonVideojuego<Aventura>{
public:
    void concepcion(){ cout << "Operación Concepción en Aventura" << endl; }
    void diseno(){ cout << "Operación Diseño en Aventura" << endl; }
    void planificacion(){ cout << "Operación Planificación en Aventura" << endl; }
    void produccion(){ cout << "Operación Producción en Aventura" << endl; }
    void pruebas(){ cout << "Operación Pruebas en Aventura" << endl; }
};

class Aprendizaje : public ClonVideojuego<Aprendizaje>{
public:
    void concepcion(){ cout << "Operación Concepción en Aprendizaje" << endl; }
    void diseno(){ cout << "Operación Diseño en Aprendizaje" << endl; }
    void planificacion(){ cout << "Operación Planificación en Aprendizaje" << endl; }
    void produccion(){ cout << "Operación Producción en Aprendizaje" << endl; }
    void pruebas(){ cout << "Operación Pruebas en Aprendizaje" << endl; }
};

//Almacen:
class AlmacenDeVideojuegos{
  private:
  vector<Videojuego*> inventario;
  public:
  AlmacenDeVideojuegos(){}
  void anadirVideojuego(Videojuego* v){
      inventario.push_back(v);
  }
  void eliminarVideojuego(long int n){
      int aux = 1;
      for(int i = 0; i < inventario.size() && aux == 1; i++){
          if (inventario[i]->getNserie() == n){
              inventario.erase(inventario.begin() + i);
              aux = 0;
              cout << "Videojuego con número de serie " << n << " eliminado" << endl;
          }
      }
  }
  void ordenarInventario(){
      for (int i = 0; i < inventario.size(); i++) {
		for (int j = 1; j < inventario.size() - i; j++) {	//Iniatilise the count 'j' in 1 'cause it need to compare to the next index in the array
			if (inventario[j]->getNserie() < inventario[j - 1]->getNserie()) {		//We want to move the element to another position
				//swap(inventario[j], inventario[j - 1]);		//Notice that we're comparing Student classes using the operator overloading <
			}
		}
	}
	cout << "Inventario ordenado con éxito" << endl;
  }
  /*void swap(Videojuego *a, Videojuego *b) {
	Videojuego temp = *a;
	*a = *b;
	*b = *a;
    }*/
    void buscarVideojuego(){
        int op;
        do{
        cout << "Buscar por:\n\t(1)Número de serie\n\t(2)Nombre\n\t\t\t: ";
        cin >> op;
        }while(op<1 || op >2);
        
    }
    int totalInventario(){
        return inventario.size();
    }
    void imprimirInventario(){
        
    }
  
};

int main(){
    Estrategia ejemploEstrategia;
    ejemploEstrategia.setAll("Gears of War", 500, 2016, 8.6, 10101010);
    cout << "Ejemplo subclase Estrategia: " << endl;
    ejemploEstrategia.getAll();
    cout << "Factory Method: " << endl;
    Estrategia::factoryMethod<Estrategia>();
    Videojuego* ejemploClon = ejemploEstrategia.clon();
    cout << "Ejemplo del clon del videojuego pasado: " << endl;
    ejemploClon->getAll();
    
    return 0;
}



