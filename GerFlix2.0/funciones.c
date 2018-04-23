#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"

void mostrarListaUsuarioSerieUno(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[]){
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

void mostrarListaUsuarioSerieDos(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[]){
    printf("Lista de usuarios y las series que ve\n");
    printf("-------------\n");
     for(int i=0;i<TUSUARIO;i++){
        printf("Usuario: %s\n",listaUsuario[i].nombre);
        printf("-------------\n");
        for(int j=0;j<TUSUARIOSERIE;j++){
            if(listaUsuario[i].idUsuario==listaUsuarioSerie[j].idUsuario){
                for(int k=0;k<TSERIE;k++){
                    if(listaUsuarioSerie[j].idSerie==listaSerie[k].idSerie){
                        printf("Serie: %s\n",listaSerie[k].nombre);
                        break;
                    }
                }
            }
        }
        printf("-------------\n");
    }
}
