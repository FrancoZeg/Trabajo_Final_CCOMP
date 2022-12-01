#include <string>
using namespace std;

class Jugador {
public:
  Jugador(int vidaJ, int dañoJ, string nombreJ) {
    vida = vidaJ;
    daño = dañoJ;
    nombre = nombreJ;
  }

  Jugador(const Jugador &o) {
    vida = o.vida;
    daño = o.daño;
    nombre = o.nombre;
  }

  int getVida() const {
    return vida;
  }
      
  int getDaño() const {
    return daño;
  }

  string getNombre() const {
    return nombre;
  }

  void ataqueEnemigo(int dañoEnemigo) {
    vida -= dañoEnemigo;
  }

  void setDaño(){
    daño += 6;
  }

  void subirDaño(){
    daño += 2;
  }

  void setVida(int _vida){
    vida = _vida;
  }

  void botella(){
    if (vida < 100 && vida >= 75){
      vida = 100;
    } else if (vida < 75){
      vida += 25;
    }
  }

  void eneVerif(){
    daño += 4;
  }

private:
  int vida, daño;
  string nombre;
};
