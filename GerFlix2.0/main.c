#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"
#include "funciones.h"

/**
*
    1. Mostrar c/d Usuario con las series que ve.
    2. Mostrar c/d Serie con los usuarios que la ve.
    3. Mostrar la/s series menos populares.
    4. Ingresar usuario y listar sus series.
    5. Ingresar serie y listar sus usuarios.
    6. Top 3 de series.
*
*/
void main()
{
    char seguir='s';
    int opcion=0;
    eSerie listaSerie[TSERIE];
    eUsuario listaUsuario[TUSUARIO];
    eUsuarioSerie listaUsuarioSerie[TUSUARIOSERIE];

    CrearListadoSeries(listaSerie,TSERIE);
    CrearListadoDeTresUsuarios(listaUsuario);
    CrearListadoUsuariosYSeries(listaUsuarioSerie);

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);

        printf("1- Mostrar c/d Usuario con las series que ve.\n");

        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                mostrarListaUsuarioSerieDos(listaSerie,listaUsuario,listaUsuarioSerie);
                break;
            case 7:
                seguir = 'n';
                break;
        }
        system("pause");
    }

    /*printf("Listado de series\n");
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
    }*/

    return;
}
