//Diego Kaleb Valenzuela Carrillo
//A01018992
#include <iostream>
#include <string>

using namespace std;

class Visitor;
class Asteroid;
class Spacecrafts;
class Planet;

class Spacecrafts {
protected:
    string queSoy;
public:
    string getSpace() { return queSoy; }
    virtual void accept(Visitor*) = 0;
    void getAsteroid(Asteroid *a);
    void getPlanet(Planet *p);
};
class PlanetExplorationShips : public Spacecrafts {
public:
    PlanetExplorationShips() { queSoy = "Planet Exploration Ship"; }
    void accept(Visitor*);
};
class ColonizationShips : public Spacecrafts {
public:
    ColonizationShips() { queSoy = "Colonization Ship"; }
    void accept(Visitor*);
};
class PlanetObservationShips : public Spacecrafts {
public:
    PlanetObservationShips() { queSoy = "Observation Ship"; }
    void accept(Visitor*);
};
////////////////////////////////////////////////////////////////////////////////////////////
class Asteroid {
protected:
    string queAsteroidSoy;
public:
    string getAsteroid() { return queAsteroidSoy; }
    virtual void accept(Visitor*) = 0;
    void getSpace(Spacecrafts *s);
    void getPlanet(Planet *p);
};
class StonyMeteorites : public Asteroid {
public:
    StonyMeteorites() { queAsteroidSoy = "Stony Meteorite"; }
    void accept(Visitor*);
};
class IonMeteorites : public Asteroid {
public:
    IonMeteorites() { queAsteroidSoy = "Ion Meteorite"; }
    void accept(Visitor*);
};
////////////////////////////////////////////////////////////////////////////////////////////
class Planet{
protected:
    string quePlanetaSoy;
public:
    string getPlanet() { return quePlanetaSoy; }
};
class DesertPlanet : public Planet{
public:
    DesertPlanet() { quePlanetaSoy = "Desert Planet"; }
};
class EarthAnalog : public Planet{
public:
    EarthAnalog() { quePlanetaSoy = "Earth Analog"; }
};
////////////////////////////////////////////////////////////////////////////////////////////
class Visitor {
public:
    virtual void visit(PlanetExplorationShips*) = 0;
    virtual void visit(ColonizationShips*) = 0;
    virtual void visit(PlanetObservationShips*) = 0;
    
    virtual void visit(StonyMeteorites*) = 0;
    virtual void visit(IonMeteorites*) = 0;
    //Singleton
    template <class T>
    static Visitor* getInstance() {
        static T instance;
        return &instance;
    }
};
class PresentVisitor : public Visitor {
    void visit(PlanetExplorationShips* PES) { cout << PES->getSpace(); }
    void visit(ColonizationShips* CS) { cout << CS->getSpace(); }
    void visit(PlanetObservationShips* POS) { cout << POS->getSpace(); }
    
    void visit(StonyMeteorites* SM) { cout << SM->getAsteroid(); }
    void visit(IonMeteorites* IM) { cout << IM->getAsteroid(); }
};
void PlanetExplorationShips::accept(Visitor* v) { v->visit(this); }
void ColonizationShips::accept(Visitor* v) { v->visit(this); }
void PlanetObservationShips::accept(Visitor* v) { v->visit(this); }

void StonyMeteorites::accept(Visitor* v) { v->visit(this); }
void IonMeteorites::accept(Visitor* v) { v->visit(this); }

//
void Spacecrafts::getAsteroid(Asteroid *a) { cout << " collisions with a " << a->getAsteroid(); }
void Spacecrafts::getPlanet(Planet *p) { cout << " collisions with a " << p->getPlanet(); }

void Asteroid::getSpace(Spacecrafts *s) { cout << " collisions with a " << s->getSpace(); }
void Asteroid::getPlanet(Planet *p) { cout << " collisions with a " << p->getPlanet(); }
////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    
    Visitor* V = Visitor::getInstance<PresentVisitor>();
    Spacecrafts* S[] = { new PlanetExplorationShips, new ColonizationShips, new PlanetObservationShips };
    Asteroid* A[] = { new StonyMeteorites, new IonMeteorites };
    Planet* P[] = {new DesertPlanet, new EarthAnalog };
    
    S[0]->accept(V);
    S[0]->getAsteroid(A[0]);
    cout << endl;
    S[1]->accept(V);
    S[1]->getAsteroid(A[1]);
    cout << endl;
    S[2]->accept(V);
    S[2]->getPlanet(P[0]);
    cout << endl;
    S[0]->accept(V);
    S[0]->getPlanet(P[1]);
    cout << endl;
    A[0]->accept(V);
    A[0]->getSpace(S[0]);
    
    return 0;
}

