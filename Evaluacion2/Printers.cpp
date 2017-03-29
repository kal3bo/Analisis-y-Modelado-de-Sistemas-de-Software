#include <iostream>
#include <string>
using namespace std;

/*class Visitor;
class Impresoras {
protected:
	string queImpresoraSoy;
public:
	string getImpresora() { return queImpresoraSoy; }
	virtual void accept(Visitor*) = 0;
};
//Tipos de impresoras:
class Laser : public Impresoras {
public:
	Laser() { queImpresoraSoy = "Soy la impresora Laser..."; }
	static int countLaser;
	void accept(Visitor*);
};
int Laser::countLaser = 0;
class Inyeccion : public Impresoras {
public:
	Inyeccion() { queImpresoraSoy = "Soy la impresora de Inyección..."; }
	static int countInyeccion;
	void accept(Visitor*);
};
int Inyeccion::countInyeccion = 0;
class PDF : public Impresoras {
public:
	PDF() { queImpresoraSoy = "Soy la impresora de PDF..."; }
	static int countPDF;
	void accept(Visitor*);
};
int PDF::countPDF = 0;
class PostScript : public Impresoras {
public:
	PostScript() { queImpresoraSoy = "Soy la impresora PostScript";  }
	static int countPostScript;
	void accept(Visitor*);
};
int PostScript::countPostScript = 0;
//Clase visitor:
class Visitor {
public:
	virtual void visit(Laser*) = 0;
	virtual void visit(Inyeccion*) = 0;
	virtual void visit(PDF*) = 0;
	virtual void visit(PostScript*) = 0;
	//Singleton
	template <class T>
	static Visitor* getInstance() {
		static T instance;
		return &instance;
	}
};
//GetImpresora (visit = printOn)
class PresentVisitor : public Visitor {
	void visit(Laser* l) { cout << l->getImpresora(); }
	void visit(Inyeccion* i) { cout << i->getImpresora(); }
	void visit(PDF* pdf) { cout << pdf->getImpresora(); }
	void visit(PostScript* ps) { cout << ps->getImpresora(); }
};
//CountImpresoras
class CountVisitor : public Visitor {
public:
	void visit(Laser* l) { cout << Laser::countLaser; }
	void visit(Inyeccion* i) { cout << Inyeccion::countInyeccion; }
	void visit(PDF* pdf) { cout << PDF::countPDF; }
	void visit(PostScript* ps) { cout << PostScript::countPostScript; }
};
//Añadir visitante:
class AddVisitor : public Visitor {
public:
	void visit(Laser*) { Laser::countLaser++; }
	void visit(Inyeccion*) { Inyeccion::countInyeccion++; }
	void visit(PDF*) { PDF::countPDF++; }
	void visit(PostScript*) { PostScript::countPostScript++; }
};

void Inyeccion::accept(Visitor* v) { v->visit(this); }
void Laser::accept(Visitor* v) { v->visit(this); }
void PDF::accept(Visitor* v) { v->visit(this); }
void PostScript::accept(Visitor* v) { v->visit(this); }

class Documentos {
protected:
	string queDocumentoSoy;
public:
	string getImpresora() { return queDocumentoSoy; }
};

class Texto : public Documentos {
public:
	Texto() { queDocumentoSoy = "Soy un documento de texto"; }
	static int countTextos;
};
int Texto::countTextos = 0;

class TextoFormato : public Documentos {
public:
	TextoFormato() { queDocumentoSoy = "Soy un documento de texto con formato"; }
	static int countTextosFormato;
};
int TextoFormato::countTextosFormato = 0;

class Imagenes : public Documentos {
public:
	Imagenes() { queDocumentoSoy = "Soy un documento de imagenes"; }
	static int countImagenes;
};
int Imagenes::countImagenes = 0;

class NuevoDocumento : public Documentos {
public:
	NuevoDocumento() {
		cout << "Nombre del nuevo tipo de documento: ";
		cin >> queDocumentoSoy;
	}
	static int countNuevo;
};
int NuevoDocumento::countNuevo = 0;*/

int main() {
	/*Visitor* a = Visitor::getInstance<AddVisitor>();
	Visitor* c = Visitor::getInstance<CountVisitor>();
	Visitor* p = Visitor::getInstance<PresentVisitor>();

	Impresoras* n[] = { new Laser, new Inyeccion, new PDF, new PostScript };
	for (int i = 0; i< 5; i++)
		for (int j = 0; j < 2; j++)
			n[j]->accept(a);
	
	n[0]->accept(p);
	n[0]->accept(c);
	cout << endl;
	n[1]->accept(p);
	n[1]->accept(c);*/
	cout << "PenesxD" << endl;
	system("pause");
	return 0;
}
