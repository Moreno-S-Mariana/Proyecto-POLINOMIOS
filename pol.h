#ifndef __POL_H__
#define __POL_H__


#include <stdio.h>

FILE *in_file;
FILE *out_file;



polinomio  complex_static_memory [10];
polinomio **complex_dynamic_memory;
polinomio countMemory;



//MECANISMO PARA AGRUPAR VARIABLES DE DISTINTOS TIPOS
struct _termino {
    float coef;
    int exp;
};


// ASIGNAR UN NOMBRE ALTERNATIVO A UN TIPO EN ESTE CASO A UNA ESTRUCTURA  

typedef struct _termino termino;

struct _polinomio {
    int grado;
    int numTerm;
    // COMO NO CONOZCO EL NUMERO DE TERMINOS O EL GRADO EN ESTE MOMENTO NO SE LE PUEDE USAR COMO ARREGLO
    termino *terminos; 
};

typedef struct _polinomio polinomio;


// MEMORIA ES UN APUNTADOR A POLINOMIO 
struct _memoria
{
    polinomio *datos;
    int numPol;
};

typedef struct _memoria memoria;

memoria memoria_principal;

void menu (); //*


polinomio pol_suma (polinomio , polinomio); //*
polinomio pol_resta (polinomio , polinomio); //*
polinomio pol_multiplicacion (polinomio , polinomio); //* 
polinomio pol_multiplicacion_esc (float s, polinomio); //* 
polinomio pol_division_monomio (polinomio , polinomio); //*
polinomio pol_division_binomio (polinomio , polinomio); //* 


void burbuja (polinomio); //*


void imprimir_polinomio (polinomio);
void leer_polinomio (polinomio);
void agregar_polinomio_teclado ();//*


void iniciar_memoria ();//*
polinomio *crear_polinomio (int grado, int numTerm);
void liberar_memoria (float **); //*
void mostrar_polinomio (int i);




void open_in_file(char *filename);//*
void open_out_file(char *filename);//*
void close_file(FILE *f);//*


void memory_delete ();
void memory_read(polinomio);
void memory_write(polinomio);
#endif 