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
	void getAsteroid(Asteroid a);
	void getPlanet(Planet p);
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
};
void Spacecrafts::getAsteroid(Asteroid a) { cout << " collisions with a " << a.getAsteroid(); }
class StonyMeteorites : public Asteroid {
public:
	StonyMeteorites() { queAsteroidSoy = "Stony Meteorite"; }
};
class IonMeteorites : public Asteroid {
public:
	IonMeteorites() { queAsteroidSoy = "Ion Meteorite"; }
};
////////////////////////////////////////////////////////////////////////////////////////////
class Planet{
  protected:
  string quePlanetaSoy;
  public:
  string getPlanet() { return quePlanetaSoy; }
};
void Spacecrafts::getPlanet(Planet p) { cout << " collisions with a " << p.getPlanet(); }
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
};
void PlanetExplorationShips::accept(Visitor* v) { v->visit(this); }
void ColonizationShips::accept(Visitor* v) { v->visit(this); }
void PlanetObservationShips::accept(Visitor* v) { v->visit(this); }
//////////////////////////////////////////////////////////////////////////////////////////// 
int main() {
    
	Visitor* V = Visitor::getInstance<PresentVisitor>();
	Spacecrafts* S[] = { new PlanetExplorationShips, new ColonizationShips, new PlanetObservationShips };
	Asteroid* A[] = { new StonyMeteorites, new IonMeteorites };
	Planet* P[] = {new DesertPlanet, new EarthAnalog };

	S[0]->accept(V);
	S[0]->getAsteroid(*A[0]);
	cout << endl;
	S[1]->accept(V);
	S[1]->getAsteroid(*A[1]);
	cout << endl;
	S[2]->accept(V);
	S[2]->getPlanet(*P[0]);
	cout << endl;
	S[0]->accept(V);
	S[0]->getPlanet(*P[1]);
	cout << endl;
	
	return 0;
}

