#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct alumno{
    char *Nombre_Completo;
    int Creditos_Aprobados;
    int Semestre_Equivalente;
};
typedef struct alumno Alumno;
typedef Alumno AlumnoPtr;

struct nodo{
    Alumno alumno;
    struct nodo *siguientePtr;
};
typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

//firmas
AlumnoPtr crearAlumno(*char, int, int);
void imprimirAlumno();
NodoPtr crearNodo(AlumnoPtr alum);
void insertarNodoOrdenadoCréditos(*nodo);
void imprimirLista();

int main(){

    return 0;
}

NodoPtr crearNodo(AlumnoPtr alumnuevo){
    NodoPtr nuevoNodo = (Nodo*)malloc(sizeof( Nodo ));
    if (nuevoNodo != NULL) {
        nuevoNodo->alumno = alumnuevo;
        nuevoNodo->siguientePtr = NULL;
    }
    return nuevoNodo;
}

AlumnoPtr crearAlumno(char *cadena, int creditos, int semestre){
    AlumnoPtr *nuevoAlum = (Alumno*)malloc(sizeof( Alumno ));
    if (nuevoAlum != NULL) {
        nuevoAlum->Nombre_Completo = char *cadena;
        nuevoAlum->Creditos_Aprobados = creditos;
        nuevoAlum->Semestre_Equivalente = semestre;
    }
    return nuevoAlum;
}