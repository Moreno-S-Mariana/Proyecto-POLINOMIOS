#include "pol.h"


/**
 * 
 * @brief: función para mostrar el menu
 * 
 * @return: mustra el menú 
 * 
 * @programador: 
 * 
 * @fecha: 14 / 12 /2021 
 * */

void menu ()
{
    printf("---------CALCULADORA DE POLINOMIOS---------\n");
    printf("Selecciona la operacion a realizar: \n");
    printf("1. Leer polinomio del teclado \n");
    printf("2. Leer polinomio de un archivo \n");
    printf("3. Sumar polinomios \n");
    printf("4. Restar  polinomios \n");
    printf("5. Multiplicar polinomios \n");
    printf("6. Dividir polinomio entre monomio \n");
    printf("Nota:\n");
    printf("\t Selecciona primero el polinomio y despues el monomio \n");
    printf("7. Dividir polinomio entre binomio con division sintetica \n");
    printf("Nota:\n");
    printf("\t Selecciona primero el polinomio y despues el binomio de la forma x+a \n");
    printf("8. Escribir en pantalla  \n");
    printf("9. Escribir en un archivo \n");
    printf("10. Ayuda")
    printf("11. Salir");
}

/*
 * 
 * FUNCIONES PARA REALIZAR LAS OPERACIONES 
 * 
 */

// -------------- SUMA ------------------

/**
 * 
 * @brief: Función para sumar polinomios 
 * 
 * @param: dos polinomios, p0 y p1
 * 
 * @return: un polinomio resultante 
 * 
 * @programador:
 * 
 * @fecha: 14/12/2021
 * */

polinomio pol_suma (polinomio p0, polinomio p1)
{
    polinomio res;
    int i=0, j=0, k=0;
    termino term0, term1;
    res.numTerm= p0.numTerm + p1.numTerm;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    while (i < p0.numTerm)
    {
        while (p0.terminos [i].exp < p1.terminos [j].exp)
        {
            res.terminos [k++]=p1.terminos [j++];
        }
        while (j < p1.numTerm)
        {
            term0= p0.terminos[i];
            term1=p1.terminos [j];
            if (term0.exp > term1.exp )
            {
                res.terminos[k].coef = term0.coef;
                res.terminos [k].exp = term0.exp;
                k++;
                i++;
            }
            else if (term0.exp == term1.exp)
            {
                res.terminos[k].coef = term0.coef + term1.coef ;
                res.terminos[k].exp=term0.exp;
                i++;
                j++;
                k++;
            }
            else if (term1.exp> term0.exp)
            {
                res.terminos[k].coef=term1.coef ;
                res.terminos [k]. coef= term0.coef ; 
                k++;
                j++;
            }
        }
    }
    res.numTerm=k;
    res.terminos = (termino*)realloc (res.terminos, k*sizeof (termino)); // REAJUSTO LA MEMORIA 
    return res;
}


// -------------- RESTA ------------------

/**
 * 
 * @brief: Función para restar polinomios 
 * 
 * @param: dos polinomios p0 y p1
 * 
 * @return: un polinomio resultante, res 
 * 
 * @programador: 
 * 
 * @fecha: 14/12/2021
 * */

polinomio pol_resta (polinomio p0, polinomio p1)
{
    polinomio res;
    int i=0, j=0, k=0;
    termino term0, term1;
    res.numTerm= p0.numTerm + p1.numTerm;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    while (i < p0.numTerm)
    {
        while (p0.terminos [i].exp < p1.terminos [j].exp)
        {
            res.terminos [k++]=p1.terminos [j++];
        }
        while (j < p1.numTerm)
        {
            term0= p0.terminos[i];
            term1=p1.terminos [j];
            if (term0.exp > term1.exp )
            {
                res.terminos[k].coef = term0.coef;
                res.terminos [k].exp = term0.exp;
                k++;
                i++;
            }
            else if (term0.exp == term1.exp)
            {
                res.terminos[k].coef = term0.coef - term1.coef ;
                res.terminos[k].exp=term0.exp;
                i++;
                j++;
                k++;
            }
            else if (term1.exp> term0.exp)
            {
                res.terminos[k].coef=term1.coef ;
                res.terminos [k]. coef= term0.coef ; 
                k++;
                j++;
            }
        }
    }
    res.numTerm=k;
    res.terminos = (termino*)realloc (res.terminos, k*sizeof (termino)); // REAJUSTO LA MEMORIA 
    return res;

}


// -------------- MULTIPLICACION DE POLINOMIOS ------------------

/**
 * 
 * @brief: función que multiplica dos polinomios 
 * 
 * @param:dos polinomios p0 y p1
 * 
 * @return: un polinomio resultante , res 
 * 
 * @programador: Mariana 
 * 
 * @fecha:14/12/2021 
 * */

polinomio pol_multiplicacion(polinomio p0, polinomio p1)
{
    polinomio res;
    int i=0, j=0, k=0,l=0;
    termino term0, term1, aux;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    while (i < p0.numTerm)
    {
        term0= p0.terminos[i];
        term1=p1.terminos [j];
        for (i=0 ; i < p0.numTerm; i++)
        {
            res.terminos[k].coef = term0.coef * term1.coef;
            res.terminos[k].exp= term0.exp * term1.exp;
            k++;
            j++;
        }
        burbuja(res);
        for (l=0; l<res.numTerm; l++)
        {
            if (res.terminos[l].exp == res.terminos[l+1].exp )
            {
                res.terminos[k].coef = res.terminos[l].coef+ res.terminos[l+1].coef ;
                res.terminos[k].exp=res.terminos[l].exp;
                l++;
                k++;
            }
            else
            {
                res.terminos[k].coef= res.terminos[l].coef;
                res.terminos[k].exp= res.terminos[l].exp;
                l++;
                k++;
            }
        }
    res.numTerm=k;
    res.terminos = (termino*)realloc (res.terminos, k*sizeof (termino)); // REAJUSTO LA MEMORIA 
    return res;
    }
}   


// -------------- MULTIPLICACION POR ESCALAR ------------------

/**
 * 
 * @brief: función que multiplica un polinomio por un escalar 
 * 
 * @param: un  polinomio p0 y un escalar s
 * 
 * @return: un polinomio resultante res 
 * 
 * @programador:
 * 
 * @fecha: 15/12/2021
 * */

polinomio pol_multiplicacion_esc (float s, polinomio p0)
{
    polinomio res;
    int i=0,j=0;
    termino term0;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    while (i < p0.numTerm)
    {
        term0= p0.terminos[i];
        res.terminos[j].coef = s * term0.coef;
        res.terminos[j].exp= term0.exp;
        j++;
        i++;
    }
    return res;
}


// -------------- DIVISION CON MONOMIO ------------------

/**
 * 
 * @brief: función que divide un polinomio entre un monomio 
 * 
 * @param:un polinomio p0 y un monomio p1
 * 
 * @return:un polinomio resultante, res  
 * 
 * @programador: 
 * 
 * @fecha: 15/12/2021
 * */


polinomio pol_division_monomio (polinomio p1 , polinomio p0)
{
    //tomando como concideración que p1 es el MONOMIO 
    polinomio res;
    int i=0, j=0, k=0;
    termino term0, term1;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    while (i < p0.numTerm)
    {
        term0= p0.terminos[i];
        term1=p1.terminos [j];
        res.terminos[k].coef = term0.coef / term1.coef ;
        res.terminos[k].exp=term0.exp- term1.exp;
        i++;
        k++;
    }
    res.terminos = (termino*)realloc (res.terminos, k*sizeof (termino)); // REAJUSTO LA MEMORIA 
    return res;
}


// -------------- DIVISION CON BINOMIO ------------------
// -------------- DIVISION SINTÉTICA ------------------

/**
 * 
 * @brief: función que divide un polinomio entre un binomio 
 * 
 * @param: un polinomio p0, y un binomio p1
 * 
 * @return: un polinomio resultante, res  
 * 
 * @programador: Mariana 
 * 
 * @fecha: 15/12/2021
 * */

polinomio pol_division_binomio (polinomio p1 , polinomio p0)
{
    //tomando como concideración que p1 es el BINOMIO 
    polinomio res;
    int i=0, k=0;
    termino term0, term1;
    res.terminos=(termino *) malloc (res.numTerm * sizeof (termino)); //RESERVO MEMORIA 
    term0= p0.terminos[i];
    res.terminos[0].coef= p0.terminos[0].coef;
    while (i < p0.numTerm -1)
    {
        res.terminos[k+1].coef = (term0.coef*(-1* p1.terminos[1].coef ) )+p0.terminos[i+1].coef;
        res.terminos[k].exp=term0.exp -1;
        i++;
        k++;
    }
    res.terminos = (termino*)realloc (res.terminos, k*sizeof (termino)); // REAJUSTO LA MEMORIA 
    return res;
}


/*
 * 
 * ORDENAMIENTO BURBUJA
 * 
 */

/**
 * 
 * @brief: función que hace uso del ordenamiento por burbuja 
 * 
 * @param: un polinomio p 
 * 
 * @return: el polinomio p ordenado 
 * 
 * @programador: Mariana
 * 
 * @fecha: 15/12/2021
 * */

void burbuja (polinomio p)
{
    termino aux, aux2;
    for (int i=0; i < p.numTerm; i++)
    {
        if (p.terminos[i].exp < p.terminos[i+1].exp)
        {
            aux= p.terminos[i];
            aux2=p.terminos[i+1];
            p.terminos[i+1]= aux;
            p.terminos[i]=aux2;
        }
    }
    return p; 
}

void iniciar_memoria ()
{
    memoria_principal.datos = (polinomio*)malloc (10 *sizeof(polinomio));
    memoria_principal.numPol= 0;
}

/**
 * 
 * @brief: función que lee polinomios desde el teclado
 * 
 * @param:un polinomio p
 * 
 * @programador: Mariana
 * 
 * @fecha: 16/12/2021
 * 
 * */

void agregar_polinomio_del_teclado ()
{
    polinomio p;
    termino term;
    int i,x;
    if(memoria_principal.numPol < 10)
    {
        printf("Dame el grado del polinomio que quieres agregar:");
        scanf("%d", &p.grado);
        printf("Dame el numero de terminos que quieres agregar:");
        scanf("%d", &p.numTerm);
        for ( int aux=0; aux < p.numTerm; aux++ )
        {
            term = p.terminos[i];
            printf("Dame un término:");
            scanf("%f", & term.coef);
            printf("Dame el exponente de el termino:");
            scanf("%d", & term.exp);
            i++;
        }
        printf("Tu polinomio es: %s ", p);
        memoria_principal.datos[memoria_principal.numPol-1]= p;
    }
    else
    {
        printf("Ya no hay memoria disponible");
    }
}


void mostrar_polinomio (int i)
{
    imprimir_polinomio(memoria_principal.datos[i]) ;
}

// de polinomio  dame su numero de terminos  en la linea del ciclo for

void imprimir_polinomio (polinomio p)
{
    //flocha por que p es apuntador
    for (int i=0; i < p.numTerm ; i++)
    {
        //punto y no flecha por que es notación de arreglos
        printf ("%f x ^ %i ", p.terminos[i].coef , p.terminos[i].exp );
    }
    printf("\n");
}
 //si el coheficiente es mayor que cero imprimo un simbolo de mas 
 //if dentro de for 
void operaciones( int op, int p0, int p1)
{
    if (memoria_principal.numPol>=10)
    {
        memoria_principal.numPol++;
        memoria_principal.datos=(polinomio *)realloc (memoria_principal.datos, memoria_principal.numPol*sizeof(polinomio));
        memoria_principal.datos[memoria_principal.numPol-1]=pol_suma (memoria_principal.datos[p0], memoria_principal.datos[p1]);
    }
}
void mostrar_polinomio (int i )
{
    imprimir_polinomio (memoria_principal.datos[i]);
}
polinomio leer_polinomio()
{

}
