#include "Enemigo.h"
#include "Jugador.h"
#include "Suerte.h"
#include "Perro.h"
#include "Rata.h"
#include "CamelloTáctico.h""
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void menu(int vida, int daño, string nombre) {
  cout << nombre << " ------ " << daño << " DE DAÑO"
       << " ------ " << vida << " PUNTOS DE VIDA" << endl;
  cout << "¿QUÉ DESEAS HACER?" << endl;
  cout << "1. ATACAR  2. A. COMPUESTO  3.MOCHILA  4.ESCAPE" << endl;
}

int main() {
  cout << "INGRESE SU NOMBRE JUGADOR" << endl;
  string nombre;
  getline(cin, nombre);
  Jugador jugador1(100, 12, nombre);
  Perro perro (100, 10, "PERRO ENORME", 4);
  Rata rata (100, 6, "RATA ENORME", 7);
  CamelloTactico camello (100, 14, "CAMELLO TÁCTICO");
  bool bate = false;
  bool juego = true;
  bool ruda = false;
  int karate = 3;
  int finta = 2;
  int yoga = 5;
  int botella = 3;
  bool escape = false;
  int s1[10]{1,0,0,0,0,0,1,0,0,1};
  int s2[10]{0,1,0,0,1,0,1,0,0,1};
  int s3[10]{1,1,1,0,1,0,1,0,0,1};
  int sp[10]{1,0,1,0,1,0,1,0,0,1};
  Suerte s4(s1, 10);
  Suerte s5(s2, 10);
  Suerte s6(s3, 10);
  Suerte ss(sp, 10);
  sleep(1);
  while (juego == true){
    cout << "SELECCIONE SU DIFICULTAD:\n1. FÁCIL\n2. MEDIO\n3. DIFÍCIL" << endl;
    int eleccionD;
    cin >> eleccionD;
    if (eleccionD == 1 || eleccionD == 2 || eleccionD == 3)
      cout << "PREPARATE PARA PELEAR" << endl;
    if (eleccionD == 1){
      cout << "EL " << perro << " ATACÓ" << endl;
      sleep(1);
      while (jugador1.getVida() > 0 && perro.getVida() > 0 && escape == false) {
        int eleccionM;
        int eleccion;
        bool ataque = true;
        menu(jugador1.getVida(), jugador1.getDaño(), jugador1.getNombre());
        cin >> eleccion;
        ataque = true;
        if (eleccion == 1) {
          if (s5.throwrand() == 0){
            perro.AtaqueComun(bate);
          } else {
            perro.AtaqueCritico(bate);
            perro.setDaño((perro.getDaño())-1);
          }
        } else if (eleccion == 2) {
          int eleccionA;
          sleep(1);
          cout << "CUENTAS CON ESTOS ATAQUES ---- VECES QUE PUEDE SER USADO\n1. "
                  "MOVIMIENTO DE KARATE ------ "
               << karate << "\n2. FINTA --------------------- " << finta
               << "\n3. MOVIMIENTO DE YOGA -------- " << yoga
               << "\nPRESIONA CUALQUIER OTRO PARA VOLVER AL MENÚ" << endl;
          cin >> eleccionA;
          if (eleccionA == 1) {
            if (karate > 0) {
              if (s6.throwrand() == 1){
                cout << "¡¡¡HIYAH!!!\nEL " << perro << " PERDIÓ 15 PUNTOS DE VIDA\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
                perro.karate();
              } else {
                cout << "¿PERO CÓMO...?\nEL " << perro << " ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              karate -= 1;
              sleep(1);
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else if (eleccionA == 2) {
            if (finta > 0) {
              if (s6.throwrand() == 1){
              cout
                  << "EL " << perro << " ESTÁ CONFUNDIDO\nPERDIÓ 2 PUNTOS DE DAÑO\nTE QUEDAN "
                  << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                  << endl;
              perro.esquiveConfundido();
              } else {
                cout << "¿PERO CÓMO...?\nEL " << perro << "ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              finta -= 1;
              sleep(1);
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else if (eleccionA == 3){
            if (yoga > 0) {
              yoga -= 1;
              cout << "INHALA EL FUTURO, EXHALA EL PASADO\nTU ATAQUE SUBE EN 2 "
                      "PUNTOS\nTE QUEDAN "
                   << yoga << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              jugador1.esquiveExitoso();
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else {
            continue;
          }
        } else if (eleccion == 3){
          cout << "ESTO SE ENCUENTRA EN TU MOCHILA:\n1. BATE\n2. BOTELLA\n3. TRÉBOL \nPRESIONA "
                  "CUALQUIER OTRO PARA VOLVER AL MENÚ"
               << endl;
          cin >> eleccionM;
          if (eleccionM == 1) {
            if (bate == false) {
              jugador1.setDaño();
              bate = true;
            } else {
              cout << "YA TIENES EQUIPADO EL BATE, ¡ATACA!" << endl;
              ataque = false;
            }
            sleep(1);
            break;
          } else if (eleccionM == 2) {
            if (botella == 3) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ LLENA" << endl;
            } else if (botella == 2) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO LLENA" << endl;
            } else if (botella == 1) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO VACÍA" << endl;
            } else {
              cout << "MIRAS CON TRISTEZA UNA BOTELLA VACÍA" << endl;
              continue;
            }
            sleep(1);
          } else if (eleccionM == 3) {
            if (ruda == false){
              cout << "UNA ACTITUD POSITIVA ATRAE LA BUENA SUERTE\nTU SUERTE SUBE" << endl;
              s4.push_back(1);
              s5.push_back(1);
              s6.push_back(1);
              ruda = true;
            } else {
              cout << "LO MÍO NO ES SUERTE, SON PURAS BENDICIONES" << endl;
            }
          } else {
            continue;
          }
        } else if (eleccion == 4) {
          if(s4.throwrand() == 1){
            escape = true;
            continue;
          } else {
            cout << "EL " << perro << " EVITÓ TU ESCAPE" << endl;
          }
          sleep(1);
        } else {
          cout << "ESO NO SE ENCUENTRA ENTRE LAS OPCIONES >:C" << endl;
          ataque = false;
          sleep(1); 
        }
        if (ataque == true && perro.getVida() >= 0) {
          if (ss.throwrand() == 1){
            cout << "\nEL " << perro << " ATACÓ, HIZO " << perro.getDaño() << " DE DAÑO\n"
               << endl;
            jugador1.ataquePerro(perro.getDaño());
            sleep(1);
          } else {
            perro.Mordisco();
            jugador1.setVida(jugador1.getVida() - perro.getDientes()*2);
          }
        }
      }
      if (perro.getVida() <= 0) {
        cout << "¡¡¡GANASTE!!!" << endl;
      } else if (jugador1.getVida() <= 0) {
        cout << "Perdiste..." << endl;
      } else if (escape == true){
        cout << "ESCAPASTE" << endl;
      }
      sleep(1);
      int eleccionf;
      cout << "DESEAS SEGUIR JUGANDO\n1.SI\n2.NO" << endl;
      cin >> eleccionf;
      if (eleccionf == 1){
        escape = false;
        Jugador jugadorcopia(100, 12, nombre);
        Perro perrocopia(95, 10, "PERRO ENORME", 6);
        jugador1 = jugadorcopia;
        perro = perrocopia;
        bate = false;
        karate = 3;
        finta = 2; 
        yoga = 5;
        botella = 3;
        Suerte s4copia(s1, 10);
        Suerte s5copia(s2, 10);
        Suerte s6copia(s3, 10);
        s4 = s4copia;
        s5 = s5copia;
        s6 = s6copia;
        continue;
      } else{
        juego = false;
    }
    sleep(1);
  } else if (eleccionD == 2){
      cout << "LA " << rata << " ATACÓ" << endl;
      sleep(1);
      while (jugador1.getVida() > 0 && rata.getVida() > 0 && escape == false) {
        int eleccion;
        bool ataque = true;
        menu(jugador1.getVida(), jugador1.getDaño(), jugador1.getNombre());
        cin >> eleccion;
        switch (eleccion) {
        case 1:
          if (ss.throwrand() == 1){
            if (s5.throwrand() == 0){
              rata.AtaqueComun(bate);
            } else {
              rata.AtaqueCritico(bate);
            }
          } else {
            cout << "LA " << rata << " ESQUIVÓ TU ATAQUE" << endl;
            sleep(1);
          }
          break;
        case 2:
          int eleccionA;
          sleep(1);
          cout << "CUENTAS CON ESTOS ATAQUES ---- VECES QUE PUEDE SER USADO\n1. "
                  "MOVIMIENTO DE KARATE ------ "
               << karate << "\n2. FINTA --------------------- " << finta
               << "\n3. MOVIMIENTO DE YOGA -------- " << yoga
               << "\nPRESIONA CUALQUIER OTRO PARA VOLVER AL MENÚ" << endl;
          cin >> eleccionA;
          switch (eleccionA) {
          case 1:
            if (karate > 0) {
              if (s6.throwrand() == 1){
                cout << "¡¡¡HIYAH!!!\nLA " << rata << " PERDIÓ 15 PUNTOS DE VIDA\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
                rata.karate();
              } else {
                cout << "¿PERO CÓMO...?\nLA" << rata << "ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              karate -= 1;
              sleep(1);
              break;
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          case 2:
            if (finta > 0) {
              if (s6.throwrand() == 1){
              cout
                  << "LA " << rata << " ESTÁ CONFUNDIDA\nPERDIÓ 2 PUNTOS DE DAÑO\nTE QUEDAN "
                  << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                  << endl;
              rata.esquiveConfundido();
              } else {
                cout << "¿PERO CÓMO...?\nLA " << rata << " ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              finta -= 1;
              sleep(1);
              break;
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          case 3:
            if (yoga > 0) {
              yoga -= 1;
              cout << "INHALA EL FUTURO, EXHALA EL PASADO\nTU ATAQUE SUBE EN 2 "
                      "PUNTOS\nTE QUEDAN "
                   << yoga << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              jugador1.esquiveExitoso();
              break;
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              continue;
            }
            sleep(1);
          default:
            ataque = false;
            break;
          }
          break;
        case 3:
          int eleccionM;
          cout << "ESTO SE ENCUENTRA EN TU MOCHILA:\n1. BATE\n2. BOTELLA\n3. TRÉBOL \nPRESIONA "
                  "CUALQUIER OTRO PARA VOLVER AL MENÚ"
               << endl;
          cin >> eleccionM;
          switch (eleccionM) {
          case 1:
            if (bate == false) {
              jugador1.setDaño();
              bate = true;
            } else {
              cout << "YA TIENES EQUIPADO EL BATE, ¡ATACA!" << endl;
              ataque = false;
            }
            sleep(1);
            break;
          case 2:
            if (botella == 3) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ LLENA" << endl;
              break;
            } else if (botella == 2) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO LLENA" << endl;
              break;
            } else if (botella == 1) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO VACÍA" << endl;
              break;
            } else {
              cout << "MIRAS CON TRISTEZA UNA BOTELLA VACÍA" << endl;
              continue;
            }
            sleep(1);
          case 3:
            if (ruda == false){
              cout << "UNA ACTITUD POSITIVA ATRAE LA BUENA SUERTE\nTU SUERTE SUBE" << endl;
              s4.push_back(1);
              s5.push_back(1);
              s6.push_back(1);
              ruda = true;
            } else {
              cout << "LO MÍO NO ES SUERTE, SON PURAS BENDICIONES" << endl;
            }
            break;
          default:
            ataque = false;
          }
          break;
        case 4:
          if(s4.throwrand() == 1){
            escape = true;
            continue;
          } else {
            cout << "LA " << rata << " EVITÓ TU ESCAPE" << endl;
          }
          sleep(1);
          break;
        default:
          cout << "ESO NO SE ENCUENTRA ENTRE LAS OPCIONES >:C" << endl;
          ataque = false;
          sleep(1);
        }
        if (ataque == true && rata.getVida() >= 0) {
          if (ss.throwrand() == 1){
            cout << "\nLA " << rata << " ATACÓ, HIZO " << rata.getDaño() << " DE DAÑO\n"
               << endl;
            jugador1.ataquePerro(rata.getDaño());
            if (rata.PulgasConf() == false){
              cout << "¡¡¡LAS PULGAS PICAN!!!\nHACEN " << 7 - rata.getPulgas() << " DE DAÑO" << endl;
              jugador1.ataquePerro(7 - rata.getPulgas());
            } 
            sleep(1);
          } else {
            rata.ataquePulgas();
            if (rata.PulgasConf() == false){
              cout << "¡¡¡LAS PULGAS PICAN!!!\nHACEN " << 7 - rata.getPulgas() << " DE DAÑO" << endl;
              jugador1.ataquePerro(7 - rata.getPulgas());
            } 
          }
        }
      }
      if (rata.getVida() <= 0) {
        cout << "¡¡¡GANASTE!!!" << endl;
      } else if (jugador1.getVida() <= 0) {
        cout << "Perdiste..." << endl;
      } else if (escape == true){
        cout << "ESCAPASTE" << endl;
      }
      sleep(1);
      int eleccionf;
      cout << "DESEAS SEGUIR JUGANDO\n1.SI\n2.NO" << endl;
      cin >> eleccionf;
      if (eleccionf == 1){
        escape = false;
        Jugador jugadorcopia(100, 12, nombre);
        Rata ratacopia (100, 6, "RATA ENORME", 7);
        jugador1 = jugadorcopia;
        rata = ratacopia;
        bate = false;
        karate = 3;
        finta = 2; 
        yoga = 5;
        botella = 3;
        Suerte s4copia(s1, 10);
        Suerte s5copia(s2, 10);
        Suerte s6copia(s3, 10);
        s4 = s4copia;
        s5 = s5copia;
        s6 = s6copia;
        continue;
      } else{
        juego = false;
    }
    sleep(1);
  } else if (eleccionD == 3){
    cout << "EL " << camello << " ATACÓ" << endl;
      sleep(1);
      while (jugador1.getVida() > 0 && camello.getVida() > 0 && escape == false) {
        int eleccionM;
        int eleccion;
        bool ataque = true;
        menu(jugador1.getVida(), jugador1.getDaño(), jugador1.getNombre());
        cin >> eleccion;
        ataque = true;
        if (eleccion == 1) {
          if (s5.throwrand() == 0){
            camello.AtaqueComun(bate);
          } else {
            camello.AtaqueCritico(bate);
          }
        } else if (eleccion == 2) {
          int eleccionA;
          sleep(1);
          cout << "CUENTAS CON ESTOS ATAQUES ---- VECES QUE PUEDE SER USADO\n1. "
                  "MOVIMIENTO DE KARATE ------ "
               << karate << "\n2. FINTA --------------------- " << finta
               << "\n3. MOVIMIENTO DE YOGA -------- " << yoga
               << "\nPRESIONA CUALQUIER OTRO PARA VOLVER AL MENÚ" << endl;
          cin >> eleccionA;
          if (eleccionA == 1) {
            if (karate > 0) {
              if (s6.throwrand() == 1){
                cout << "¡¡¡HIYAH!!!\nEL " << camello << " PERDIÓ 15 PUNTOS DE VIDA\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
                camello.karate();
              } else {
                cout << "¿PERO CÓMO...?\nEL " << camello << " ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << karate << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              karate -= 1;
              sleep(1);
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else if (eleccionA == 2) {
            if (finta > 0) {
              if (s6.throwrand() == 1){
              cout
                  << "EL " << camello << " ESTÁ CONFUNDIDO\nPERDIÓ 2 PUNTOS DE DAÑO\nTE QUEDAN "
                  << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                  << endl;
              camello.esquiveConfundido();
              } else {
                cout << "¿PERO CÓMO...?\nEL " << camello << "ESQUIVÓ EL ATAQUE\nTE QUEDAN "
                   << finta << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              }
              finta -= 1;
              sleep(1);
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else if (eleccionA == 3){
            if (yoga > 0) {
              yoga -= 1;
              cout << "INHALA EL FUTURO, EXHALA EL PASADO\nTU ATAQUE SUBE EN 2 "
                      "PUNTOS\nTE QUEDAN "
                   << yoga << " VECES EN LAS QUE PUEDES USAR ESTE MOVIMIENTO"
                   << endl;
              jugador1.esquiveExitoso();
            } else {
              cout << "YA NO PUEDES USAR ESTE MOVIMIENTO" << endl;
              sleep(1);
              continue;
            }
          } else {
            continue;
          }
        } else if (eleccion == 3){
          cout << "ESTO SE ENCUENTRA EN TU MOCHILA:\n1. BATE\n2. BOTELLA\n3. TRÉBOL \nPRESIONA "
                  "CUALQUIER OTRO PARA VOLVER AL MENÚ"
               << endl;
          cin >> eleccionM;
          if (eleccionM == 1) {
            if (bate == false) {
              jugador1.setDaño();
              bate = true;
            } else {
              cout << "YA TIENES EQUIPADO EL BATE, ¡ATACA!" << endl;
              ataque = false;
            }
            sleep(1);
            break;
          } else if (eleccionM == 2) {
            if (botella == 3) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ LLENA" << endl;
            } else if (botella == 2) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO LLENA" << endl;
            } else if (botella == 1) {
              if (jugador1.getVida() == 100) {
                cout << "Vaya despedicio..." << endl;
              } else if (jugador1.getVida() < 100 && jugador1.getVida() >= 75) {
                cout << "BUENO, RECUPERAS TODA TU VIDA" << endl;
                jugador1.botella();
              } else {
                cout << "¡¡¡REFRESCANTE!!!  RECUPERAS 25 PUNTOS DE VIDA" << endl;
                jugador1.botella();
              }
              botella -= 1;
              cout << "LA BOTELLA ESTÁ MEDIO VACÍA" << endl;
            } else {
              cout << "MIRAS CON TRISTEZA UNA BOTELLA VACÍA" << endl;
              continue;
            }
            sleep(1);
          } else if (eleccionM == 3) {
            if (ruda == false){
              cout << "UNA ACTITUD POSITIVA ATRAE LA BUENA SUERTE\nTU SUERTE SUBE" << endl;
              s4.push_back(1);
              s5.push_back(1);
              s6.push_back(1);
              ruda = true;
            } else {
              cout << "LO MÍO NO ES SUERTE, SON PURAS BENDICIONES" << endl;
            }
          } else {
            continue;
          }
        } else if (eleccion == 4) {
          if(s4.throwrand() == 1){
            escape = true;
            continue;
          } else {
            cout << "EL " << camello << " EVITÓ TU ESCAPE" << endl;
          }
          sleep(1);
        } else {
          cout << "ESO NO SE ENCUENTRA ENTRE LAS OPCIONES >:C" << endl;
          ataque = false;
          sleep(1); 
        }
        if (ataque == true && camello.getVida() >= 0) {
          if (camello.getVida() > 0){
            cout << "\nEL " << camello << " ATACÓ, HIZO " << camello.getDaño() << " DE DAÑO\n"
               << endl;
            jugador1.ataquePerro(camello.getDaño());
            sleep(1);
          } else {
            if (camello.getJorobas() < 0){
              camello.Joroba(); 
              cout << "EL" << camello << "CONSUMIÓ GRASA ALMACENADA EN SU JOROBA\n RECUPERA 25 PUNTOS DE VIDA" << endl;
            } else {
              cout << "EL" << camello << "SE QUEDÓ SIN GRASA Y ENTRÓ EN DEPRESIÓN" << endl;
            }
          }
        }
      }
      if (camello.getVida() <= 0) {
        cout << "¡¡¡GANASTE!!!" << endl;
      } else if (jugador1.getVida() <= 0) {
        cout << "Perdiste..." << endl;
      } else if (escape == true){
        cout << "ESCAPASTE" << endl;
      }
      sleep(1);
      int eleccionf;
      cout << "DESEAS SEGUIR JUGANDO\n1.SI\n2.NO" << endl;
      cin >> eleccionf;
      if (eleccionf == 1){
        escape = false;
        Jugador jugadorcopia(100, 12, nombre);
        CamelloTactico camellocopia(95, 10, "CAMELLO TÁCTICO");
        jugador1 = jugadorcopia;
        camello = camellocopia;
        bate = false;
        karate = 3;
        finta = 2; 
        yoga = 5;
        botella = 3;
        Suerte s4copia(s1, 10);
        Suerte s5copia(s2, 10);
        Suerte s6copia(s3, 10);
        s4 = s4copia;
        s5 = s5copia;
        s6 = s6copia;
        continue;
      } else{
        juego = false;
    }
    sleep(1);
  } else {
    break;
  }
  }
  return 0;
}