#ifndef __RATA_H__
#define __RATA_H__
#include <iostream>
#include "Enemigo.h"

using namespace std;

class Rata : public Enemigo {
  private:
    int pulgas = 7;
    friend ostream& operator<<(ostream& output, Rata rata);
  public:
    Rata(int vidaR, int dañoR, string nombreR, int pulgasR): Enemigo(vidaR, dañoR, nombreR) {setPulgas(pulgasR);}

    void setPulgas(int pulgasR){
      pulgas = pulgasR;
    }

    void ataquePulgas(){
      if (pulgas > 0){
        std::cout << "LA RATA INTENTÓ LANZAR SUS PULGAS" << endl;
        std::cout << "TIENES PULGAS EN TODO EL CUERPO" << endl;
        pulgas -= 1;
      } else {
        cout << "LA RATA INTENTÓ LANZAR SUS PULGAS" << endl;
        cout << "LA RATA YA NO TIENE PULGAS" << endl;
      }
    }

    int getPulgas () const {
      return pulgas;
    }
    
    bool PulgasConf() const {
      if (pulgas == 7)
        return true;
      else
        return false;
    }

    void AtaqueComun(bool bate) {
    if (vida - 18 > 0 && vida - 12 > 0) {
      if (bate == true) {
        vida -= 22;
      } else {
        vida -= 16;
      }
      cout << "¡TOMA! A LA RATA LE QUEDAN " << vida << " PUNTOS DE VIDA" << endl;
    } else {
      if (bate == true) {
        vida -= 22;
      } else {
        vida -= 16;
      }
      cout << "¡TOMA! LA RATA ESTÁ MORIBUNDA" << endl;
    }
  }

  void AtaqueCritico(bool bate) {
    if (vida - 18 > 0 && vida - 12 > 0) {
      if (bate == true) {
        vida -= 26;
      } else {
        vida -= 20;
      }
      cout << "¡¡¡GOLPE CRÍTICO!!! A LA RATA LE QUEDAN " << vida << " PUNTOS DE VIDA" << endl;
    } else {
      if (bate == true) {
        vida -= 18;
      } else {
        vida -= 12;
      }
      cout << "¡¡¡GOLPE CRÍTICO!!! LA RATA ESTÁ MORIBUNDA" << endl;
    }
  }

};

ostream& operator<<(ostream& output, Rata rata){
  output << rata.nombre;
  return output;
}

#endif