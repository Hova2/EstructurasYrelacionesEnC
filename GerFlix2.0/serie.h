#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED
#define TSERIE 5
typedef struct{
    int idSerie;
    char nombre[50];
    char genero[50];
}eSerie;

typedef struct{
    int idSerie;
    int cont;
}eSerieContador;

void CrearListadoSeries(eSerie [],int);
char buscarSerie(eSerie [],int);
#endif // SERIE_H_INCLUDED
