#include "./tests/gtest-1.8.1/gtest.h"
#include "./src/Recordatorios.cpp"
#include <sstream>

int main(int argc, char const *argv[]) {
  /* code */

  Agenda a(Fecha(6, 10));
  a.agregar_recordatorio(Recordatorio(Fecha(6, 10), Horario(11, 0), "Labo Algo2"));
  a.agregar_recordatorio(Recordatorio(Fecha(6, 10), Horario(9, 0), "Clase Algo2"));

  stringstream ss;
  ss << a;

  std::cout << ss.str() << '\n';

  return 0;
}
