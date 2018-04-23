#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

void mostrarListaSerieUsuario(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[]){
    printf("Lista de series y los usuarios que la ven\n");
    printf("-------------\n");
     for(int i=0;i<TSERIE;i++){
        printf("Serie: %s\n",listaSerie[i].nombre);
        printf("-------------\n");
        for(int j=0;j<TUSUARIOSERIE;j++){
            if(listaSerie[i].idSerie==listaUsuarioSerie[j].idSerie){
                for(int k=0;k<TUSUARIO;k++){
                    if(listaUsuarioSerie[j].idUsuario==listaUsuario[k].idUsuario){
                        printf("Usuario: %s\n",listaUsuario[k].nombre);
                        break;
                    }
                }
            }
        }
        printf("-------------\n");
    }
}

void mostrarSerieMenosPopular(eSerie listaSerie[],eUsuarioSerie listaUsuarioSerie[]){
    eSerieContador contSerie[TSERIE];
    int menor=INT_MAX;

    for(int i=0;i<TSERIE;i++){
        contSerie[i].idSerie=listaSerie[i].idSerie;
        contSerie[i].cont=0;
    }
    for(int i=0;i<TSERIE;i++){
        for(int j=0;j<TUSUARIOSERIE;j++){
            if(listaSerie[i].idSerie==listaUsuarioSerie[j].idSerie){
                contSerie[i].cont++;
            }
        }
    }
    for(int i=0;i<TSERIE;i++){
        if(contSerie[i].cont<menor){
            menor=contSerie[i].cont;
        }
    }
    printf("Lista de serie%cs menos popular\n",'/');
    printf("-------------\n");
    for(int i=0;i<TSERIE;i++){
        if(contSerie[i].cont==menor){
            printf("Serie: %s\n",listaSerie[(contSerie[i].idSerie)-1].nombre);
        }
    }
}

void mostrarUsuarioSerie(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[],int idUsuario){
    if(buscarUsuario(listaUsuario,idUsuario)){
        printf("Lista de serie%cs de un usuario\n",'/');
        printf("-------------\n");
        printf("Usuario: %s\n",listaUsuario[idUsuario-100].nombre);
        printf("-------------\n");
        for(int i=0;i<TUSUARIOSERIE;i++){
            if(listaUsuarioSerie[i].idUsuario==idUsuario){
                for(int j=0;j<TSERIE;j++){
                    if(listaUsuarioSerie[i].idSerie==listaSerie[j].idSerie){
                        printf("Serie: %s\n",listaSerie[j].nombre);
                        break;
                    }
                }
            }
        }
    }else{
        printf("No existe usuario!!!\n");
    }
}

void mostrarSerieUsuario(eSerie listaSerie[],eUsuario listaUsuario[],eUsuarioSerie listaUsuarioSerie[],int idSerie){
    if(buscarSerie(listaSerie,idSerie)){
        printf("Lista de usuario%cs de una serie\n",'/');
        printf("-------------\n");
        printf("Serie: %s\n",listaSerie[idSerie-1].nombre);
        printf("-------------\n");
        for(int i=0;i<TUSUARIOSERIE;i++){
            if(listaUsuarioSerie[i].idSerie==idSerie){
                for(int j=0;j<TUSUARIO;j++){
                    if(listaUsuarioSerie[i].idUsuario==listaUsuario[j].idUsuario){
                        printf("Usuario: %s\n",listaUsuario[j].nombre);
                        break;
                    }
                }
            }
        }
    }else{
        printf("No existe la serie!!!\n");
    }
}

void mostrarTopTres(eSerie listaSerie[],eUsuarioSerie listaUsuarioSerie[]){
    eSerieContador contSerie[TSERIE];
    int mayorUno=INT_MIN;
    int mayorDos=INT_MIN;
    int mayorTres=INT_MIN;

    for(int i=0;i<TSERIE;i++){
        contSerie[i].idSerie=listaSerie[i].idSerie;
        contSerie[i].cont=0;
    }
    for(int i=0;i<TSERIE;i++){
        for(int j=0;j<TUSUARIOSERIE;j++){
            if(listaSerie[i].idSerie==listaUsuarioSerie[j].idSerie){
                contSerie[i].cont++;
            }
        }
    }
    for(int i=0;i<TSERIE;i++){
        if(contSerie[i].cont>mayorUno){
            mayorUno=contSerie[i].cont;
        }
    }
    for(int i=0;i<TSERIE;i++){
        if(contSerie[i].cont>mayorDos && contSerie[i].cont!=mayorUno){
            mayorDos=contSerie[i].cont;
        }
    }
    for(int i=0;i<TSERIE;i++){
        if(contSerie[i].cont>mayorTres && contSerie[i].cont!=mayorUno && contSerie[i].cont!=mayorDos){
            mayorTres=contSerie[i].cont;
        }
    }
    printf("Lista de Top 3 de series mas populares\n",'/');
    printf("-------------\n");
    printf("Primeras: \n");
    if(mayorUno){
        for(int i=0;i<TSERIE;i++){
            if(contSerie[i].cont==mayorUno){
                printf("Serie: %s\n",listaSerie[(contSerie[i].idSerie)-1].nombre);
            }
        }
    }else{
        printf("No hay serie/s para mostrar!!!\n");
    }
    printf("-------------\n");
    printf("Segundas: \n");
    if(mayorDos){
        for(int i=0;i<TSERIE;i++){
            if(contSerie[i].cont==mayorDos){
                printf("Serie: %s\n",listaSerie[(contSerie[i].idSerie)-1].nombre);
            }
        }
    }else{
        printf("No hay serie/s para mostrar!!!\n");
    }
    printf("-------------\n");
    printf("Terceras: \n");
    if(mayorTres){
        for(int i=0;i<TSERIE;i++){
            if(contSerie[i].cont==mayorTres){
                printf("Serie: %s\n",listaSerie[(contSerie[i].idSerie)-1].nombre);
            }
        }
    }else{
        printf("No hay serie/s para mostrar!!!\n");
    }
}
