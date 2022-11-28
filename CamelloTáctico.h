#ifndef __CamelloTactico_H__
#define __CamelloTatico_H__

#include <iostream>
#include <string>
#include "Enemigo.h"
using namespace std;

class CamelloTactico : public Enemigo {
public:
  CamelloTactico(int vidaP, int dañoP, string nombreP): Enemigo(vidaP, dañoP, nombreP) {}

  void Joroba (){
    if (jorobas > 0) {
      vida += 25;
      jorobas -= 1;
      } else {
      cout << "EL CAMELLO SE QUEDÓ SIN GRASA CORPORAL";
      }
  } 

  int getJorobas () const {
    return jorobas;
  }

private:
  int jorobas =2;
  friend ostream& operator<<(ostream& output, CamelloTactico camello);
};

ostream& operator<<(ostream& output, CamelloTactico camello){
  output << camello.nombre << " ";
  return output;
}

#endif