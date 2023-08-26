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
AlumnoPtr crearAlumno(char *cadena, int creditos, int semestre);
NodoPtr crearNodo(AlumnoPtr alum);
void imprimirLista(NodoPtr actualPtr);
void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevoNodo);
void imprimirAlumno();

int main(){
    NodoPtr inicioPtr = NULL;
    
    AlumnoPtr alumno1 = crearAlumno("Cordova Martinez Ricardo", 60, 3);
    AlumnoPtr alumno2 = crearAlumno("Alcocer Herrera Julio Cesar", 120, 7);
    AlumnoPtr alumno3 = crearAlumno("Acierno Hernandez Deco", 80, 5);
    AlumnoPtr alumno4 = crearAlumno("Alcocer Cabrera Josueh", 30, 2);
    AlumnoPtr alumno5 = crearAlumno("Aguilar Johan RIcardo", 10, 1);
    
    imprimirAlumno(alumno1);
    imprimirAlumno(alumno2);
    imprimirAlumno(alumno3);
    imprimirAlumno(alumno4);
    imprimirAlumno(alumno5);

    NodoPtr nodo1 = crearNodo(alumno1);
    NodoPtr nodo2 = crearNodo(alumno2);
    NodoPtr nodo3 = crearNodo(alumno3);
    NodoPtr nodo4 = crearNodo(alumno4);
    NodoPtr nodo5 = crearNodo(alumno5);

    insertarNodoOrdenadoCreditos(&inicioPtr, nodo1);
    insertarNodoOrdenadoCreditos(&inicioPtr, nodo2);
    insertarNodoOrdenadoCreditos(&inicioPtr, nodo3);
    insertarNodoOrdenadoCreditos(&inicioPtr, nodo4);
    insertarNodoOrdenadoCreditos(&inicioPtr, nodo5);

    imprimirLista(inicioPtr);

    return 0;
}

NodoPtr crearNodo(AlumnoPtr alumnuevo){
    NodoPtr nuevoNodo = (Nodo*)malloc(sizeof( Nodo ));
    if (nuevoNodo != NULL) {
        nuevoNodo->alumno = alumnuevo;
        nuevoNodo->siguientePtr = NULL;
        printf("Se ha creado un nodo en la lista de alumnos en %p\n", nuevoNodo);
    }
    return nuevoNodo;
}

AlumnoPtr crearAlumno(char *cadena, int creditos, int semestre){
    AlumnoPtr *nuevoAlum = (Alumno*)malloc(sizeof( Alumno ));
    if (nuevoAlum != NULL) {
        nuevoAlum->Nombre_Completo = cadena;
        nuevoAlum->Creditos_Aprobados = creditos;
        nuevoAlum->Semestre_Equivalente = semestre;
        printf("Se ha creado una estructura Alumno en la dirección %p\n", nuevoAlum);
    }
    return *nuevoAlum;
}

void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevoNodo){
    if (*cabecera == NULL) {
        *cabecera = nuevoNodo;
    }else{
        NodoPtr actual, anterior;
        anterior=NULL;
        actual = *cabecera;

        while(actual != NULL  &&  actual->alumno.Creditos_Aprobados > nuevoNodo->alumno.Creditos_Aprobados){
            anterior=actual;
            actual = actual->siguientePtr;
        }

        if (anterior == NULL){
            nuevoNodo->siguientePtr=*cabecera;
            *cabecera=nuevoNodo;
        }else{
            anterior->siguientePtr=nuevoNodo;
            nuevoNodo->siguientePtr=actual;   
        }
    }
}

void imprimirLista(NodoPtr actualPtr){
    if (actualPtr==NULL){
        printf("Lista vacia \n\n");
        return;
    }
    else{
        printf("Contenido de la lista:\n");
        
        while(actualPtr != NULL){                   
            printf("%s ", actualPtr->alumno.Nombre_Completo);
            printf("%d ", actualPtr->alumno.Creditos_Aprobados);
            printf("%d\n", actualPtr->alumno.Semestre_Equivalente);
            actualPtr = actualPtr->siguientePtr;  
        }
    }
}

void imprimirAlumno(AlumnoPtr alum){
    printf("%s ", alum.Nombre_Completo);
    printf("%d ", alum.Creditos_Aprobados);
    printf("%d\n", alum.Semestre_Equivalente);

}