#ifndef __POL_H__
#define __POL_H__

//MECANICAMO PARA AGURPAR VARIABLES DE DISTINOTS TIPOS

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


polinomio pol_suma (polinomio , polinomio); //*
polinomio pol_resta (polinomio , polinomio); //*
polinomio pol_multiplicacion (polinomio , polinomio); //* 
polinomio pol_multiplicacion_esc (float s, polinomio); //* 
polinomio pol_division_monomio (polinomio , polinomio); //*
polinomio pol_division_binomio (polinomio , polinomio); //* 
void open_in_file(char *filename);
void open_out_file(char *filename);
void close_file(FILE *f);
void memory_read(polinomio);
void memory_write(polinomio);
float **resize(int n);
void memory_delete();
void iniciar_memoria ();
void agregar_polinomio_teclado ();
polinomio *crear_polinomio (int grado, int numTerm);
void liberar_memoria (polinomio);
void burbuja (polinomio); //*
void mostrar_polinomio (int i);
void imprimir_polinomio (polinomio);
void leer_polinomio ();
void menu (); //*






#endif 