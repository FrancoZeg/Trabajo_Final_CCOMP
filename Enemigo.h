#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__

#include <iostream>
#include <string>
using namespace std;

class Enemigo {
public:
  Enemigo(int vidaE = 0, int dañoE = 0, string nombreE = "") {
    vida = vidaE;
    daño = dañoE;
    nombre = nombreE;
  }

  int getVida() const { return vida; }

  int getDaño() const { return daño; }

  string getNombre() const { return nombre; }

  void setDaño(int dañoE){
    daño = dañoE;
  }

  virtual void AtaqueComun(bool bate) {
    if (vida - 18 > 0 && vida - 12 > 0) {
      if (bate == true) {
        vida -= 18;
      } else {
        vida -= 12;
      }
      cout << "¡TOMA! AL " << nombre << " LE QUEDAN " << vida << " PUNTOS DE VIDA" << endl;
    } else {
      if (bate == true) {
        vida -= 18;
      } else {
        vida -= 12;
      }
      cout << "¡TOMA! EL " << nombre << " ESTÁ MORIBUNDO" << endl;
    }
  }

  virtual void AtaqueCritico(bool bate) {
    if (vida - 18 > 0 && vida - 12 > 0) {
      if (bate == true) {
        vida -= 22;
      } else {
        vida -= 15;
      }
      cout << "¡¡¡GOLPE CRÍTICO!!! POBRE " << nombre << " LE QUEDAN " << vida << " PUNTOS DE VIDA" << endl;
    } else {
      if (bate == true) {
        vida -= 18;
      } else {
        vida -= 12;
      }
      cout << "¡¡¡GOLPE CRÍTICO!!! EL " << nombre << " ESTÁ MORIBUNDO" << endl;
    }
  }

  bool ataqueono(bool ataque){
    if (vida == 0) {
      ataque = false;
      return ataque;
    }
    return ataque;
  }

  void esquiveConfundido(){
    daño -= 2;
  }

  void karate(){
    vida -= 15;
  }

protected:
  int vida, daño;
  string nombre;
};

#endif