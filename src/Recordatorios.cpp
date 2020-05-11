#include <iostream>
#include<list>
using uint = uint32_t ;
using namespace std;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
public:
    Fecha(int mes, int dia);
    int dia();
    int mes();
#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
#endif
    void incrementar_dia();

private:
    int dia_;
    int mes_;
};
Fecha::Fecha(int mes, int dia) : mes_(mes) , dia_(dia) {}

int Fecha::mes(){
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = (this->dia() == o.dia() and
                      this-> mes() == o.mes());
    return igual_dia;
}
#endif

void Fecha::incrementar_dia(){
    if ( dia_==dias_en_mes(mes_) ) {
        dia_=1;
        mes_++;
    } else {
        dia_++;
    }
}
// Ejercicio 11, 12
// Clase Horario
class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}

uint Horario::hora(){
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    bool igual_hora = (this->hora() == o.hora() and
                       this-> min() == o.min());
    return igual_hora;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
    bool menor_Hora = ((this->hora()==h.hora() and
                        this->min()<h.min()) ||
                       this ->hora()<h.hora());
    return menor_Hora;
}
// Ejercicio 13
class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string evento);
    string evento();
    Fecha fecha();
    Horario horario();
private:
    string evento_;
    Fecha fecha_;
    Horario horario_;

};
Recordatorio::Recordatorio(Fecha fecha, Horario horario, string evento) : fecha_(fecha), horario_(horario),  evento_(evento) {}


string Recordatorio::evento() {
    return evento_;
}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio:: horario() {
    return horario_;
}


ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.evento() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

//Ejercicio 14
class Agenda {
public:
    Agenda(Fecha hoy);
    void agregar_recordatorio (Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
    //

private:
    Fecha fecha_actual_;
    list<Recordatorio> rec_;
};

Fecha Agenda:: hoy(){
    return fecha_actual_;
}

list<Recordatorio> Agenda:: recordatorios_de_hoy(){
    return  rec_;
}

Agenda:: Agenda(Fecha fecha_inicial) : fecha_actual_(fecha_inicial) , rec_() {}

void Agenda:: agregar_recordatorio (Recordatorio rec){
    rec_.push_back(rec);
}

void Agenda::incrementar_dia() {
    fecha_actual_.incrementar_dia();
    rec_={};
}

bool Compare_Horarios(Recordatorio First, Recordatorio Next) {
    if (First.horario() < Next.horario() || First.horario() == Next.horario()) return true;
    else return false;
}



ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os<<"====="<< endl;
    list<Recordatorio> lr=a.recordatorios_de_hoy();
    lr.sort(Compare_Horarios);
    for (Recordatorio r : lr) {
        os << r << endl;
    }
    return os;
}
