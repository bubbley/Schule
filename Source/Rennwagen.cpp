#include <iostream>
using namespace std;

class Rennwagen {
public:
    int Geschwindigkeit;
    int Handling;
};

int main() {
    Rennwagen bmw, mercedes, audi;

    bmw.Geschwindigkeit = 100;

  cout << "Bmw Geschwindigkeit: " << bmw.Geschwindigkeit << endl;
  return 0;
}