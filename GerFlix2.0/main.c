#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
/**
*
    1. los datos de la serie que ve cada usuario
    2. por cada serie todos los usuarios que la ven
    3. por cada serie cuantos usuarios la ven
*
*/
void main()
{
    eSerie listaSerie[TSERIE];
    eUsuario listaUsuario[TUSUARIO];

    CrearListadoSeries(listaSerie,TSERIE);
    CrearListadoDeTresUsuarios(listaUsuario);

    printf("Listado de series\n");
    printf("-----------------\n");
    for(int i=0;i<TSERIE;i++){
        printf("ID Serie: %d\n",listaSerie[i].idSerie);
        printf("Nombre  : %s\n",listaSerie[i].nombre);
        printf("Genero  : %s\n",listaSerie[i].genero);
        printf("-----------------\n");
    }
    printf("Listado de usuarios\n");
    printf("-----------------\n");
    for(int i=0;i<TUSUARIO;i++){
        printf("ID Usuario: %d\n",listaUsuario[i].idUsuario);
        printf("Nombre    : %s\n",listaUsuario[i].nombre);
        printf("-----------------\n");
    }

    return;
}
