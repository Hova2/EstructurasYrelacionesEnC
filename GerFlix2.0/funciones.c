#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"

void mostrarListaUsuarioSerie(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[]){
    printf("Lista de usuarios y las series que ve\n");
    printf("-------------\n");
    for(int i=0;i<TUSUARIOSERIE;i++){
        for(int j=0;j<TUSUARIO;j++){
            if(listaUsuarioSerie[i].idUsuario==listaUsuario[j].idUsuario){
                printf("Usuario: %s\n",listaUsuario[j].nombre);
                break;
            }
        }
        for(int j=0;j<TSERIE;j++){
            if(listaUsuarioSerie[i].idSerie==listaSerie[j].idSerie){
                printf("Serie: %s\n",listaSerie[j].nombre);
                break;
            }
        }
        printf("-------------\n");
    }
}
