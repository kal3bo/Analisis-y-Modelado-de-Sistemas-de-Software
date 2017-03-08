//
//  main.cpp
//  Borrar
//
//  Created by Diego Kaleb Valenzuela Carrillo on 08/03/17.
//  Copyright © 2017 Diego Kaleb Valenzuela Carrillo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractObserver{
public:
    virtual void update(int value) = 0;
};

class ConcreteAObserver : public AbstractObserver{
public:
    ConcreteAObserver(){};
    ~ConcreteAObserver(){};
    
    void update(int value){
        cout << "The observer value is: " << value << endl;
    }
};

class ObservedSubject{
public:
    ObservedSubject(){myValue = 0;}
    ~ObservedSubject(){};
    
    bool addObserver(AbstractObserver* obs){
        for(int i = 0; i < observerList.size(); i++){
            if (obs == observerList[i]){
                cout << "El observador ya habia sido agregado\n";
                return false;
            }
        }
        observerList.push_back(obs);
        obs -> update(myValue);
        return true;
    }
    
    void setValue(int value){
        myValue = value;
        for(int i = 0; observerList.size(); i++)
            observerList[i] -> update(myValue);
    }
    
private:
    int myValue;
    vector<AbstractObserver*> observerList;

};


class medios : public ConcreteAObserver{
public:
    string nombreDelMedio;
    void setNombreDelMedio(string nombre){nombreDelMedio = nombre;}
    string getNombreDelMedio(){return nombreDelMedio;}
};

class Reforma : public medios{
public:
    void funcionReforma(){cout << "Funcion de Reforma" << endl;}
};

class Televisa : public medios{
public:
    void funcionTelevisa(){cout << "Funcion de Televisa" << endl;}
};

class NBCNews : public medios{
public:
    void funcionNBCNews(){cout << "Funcion de NBCNews" << endl;}
};

int main() {
    ObservedSubject DTrump;
    ObservedSubject PNieto;
    
    Reforma *r = new Reforma();
    Televisa *t = new Televisa();
    NBCNews *n = new NBCNews();
    
    DTrump.setValue(1);
    DTrump.addObserver(r);
    DTrump.addObserver(t);
    DTrump.addObserver(n);
    
    PNieto.setValue(2);
    PNieto.addObserver(r);
    PNieto.addObserver(t);
    PNieto.addObserver(n);
    
    return 0;
}
