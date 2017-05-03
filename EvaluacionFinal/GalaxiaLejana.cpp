//Diego Kaleb Valenzuela Carrillo
    //A01018992
#include <iostream>
#include <string>

using namespace std;

class Visitor;
class Asteroid;
class Spacecrafts;
class Planets;

class Spacecrafts {
protected:
	string queSoy;
public:
	string getSpace() { return queSoy; }
	virtual void accept(Visitor*) = 0;
	void getAsteroid(Asteroid a);
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
    
	Visitor* p = Visitor::getInstance<PresentVisitor>();
	Spacecrafts* n[] = { new PlanetExplorationShips, new ColonizationShips, new PlanetObservationShips };
	
	Asteroid* d[] = { new StonyMeteorites, new IonMeteorites };

	n[0]->accept(p);
	n[0]->getAsteroid(*d[0]);
	cout << endl;
	n[1]->accept(p);
	n[1]->getAsteroid(*d[1]);
	cout << endl;
	
	return 0;
}

