#include <iostream> //NO NEED TO EXPLAIN?!

using namespace std;//NO NEED TO EXPLAIN?!


//Objekt Punkt definieren
class Punkt{
	private:
		
	
	public:
		int x,y;
		
		Punkt(){ //Konstruktor
		}
		~Punkt(){ //Destruktor
		}
		
		
		void setxy(int i, int a){
			x = i;
			y = a;
		}
		
};


//Objekt temp defninieren
class Temp{
	private:
		
		//Einen Zeigercontainer erstellen der Sp�ter eine Objektinstanzadresse �bergeben bekommt.
		Punkt *punk;
	public:
		int x,y;
		Temp(){ //Konstruktor
			
		}
		
		~Temp(){ //Destruktor
		}

		
		void setP(Punkt *p){//Hier wird die Adresse �bergeben die auf das Obejkt 	P	 siehe main() zeigt
			
			
			punk = p; //das �bergebene in punk schreiben
			x = punk->x; 	//<-- x mit dem X wert aus punk f�llen, dabei den "<-" verwenden da es sich lediglich um einen Zeiger 
							//		auf das Objekt handelt was in main �bergeben wurde.
							
			y = punk->y; 	//das gleiche mit Y
			
			
			punk->x = 50;      //den Wert x in dem Objekt   P   siehe main() auf 50 setzen.
		
			/* Dadurch das es sich bei "punk" lediglich um einen Zeiger auf das Originale Objekt 	P	 handelt kann dieses auch weiterhin manipuliert werden.
			H�tte man anstatt eines Zeigers das Gesamte Objekt �bergeben w�re lediglich eine Kopie von P enstanden die uns in diesem Fall nicht weiter hilft. */
		
		}
};

int main(){
	Punkt P = Punkt();  //Erstellen einer instanz des Obejktes Punkt in diesem Fall P getauft
	
	P.x = 20;           //Punkt int x setzen
	P.y = 20;			//Punkt int y setzen
	
	Temp t = Temp();	//Erstellen einer instanz des Obejktes Temp in diesem Fall t getauft
	
	t.setP(&P); //Hier wird die Adresse von P geholt und �bergeben, da es nicht m�glich ist komplette 
				//Klasseninstanzen �ber den stack zu schieben sondern lediglich sie zu kopieren, wir hier 
				//nur einzeiger auf das original benutzt damit dieses weiter manipuliert werden kann
	
	cout << "Punkte nach der Manipulations ueber den Zeiger\n";
	cout << "Objekt P Punkt X:" << P.x << endl;
	cout << "Objekt P Punkt Y:" << P.y << endl;
	
	cout << endl;
	cout << "Punkte vor der Manipulations ueber den Zeiger\n";
	cout << "Objekt t Punkt X:" << t.x << endl;
	cout << "Objekt t Punkt Y:" << t.y << endl;
	

	return 0; //Because why not?
}
