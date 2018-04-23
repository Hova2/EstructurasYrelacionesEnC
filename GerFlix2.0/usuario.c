#include "usuario.h"

void CrearListadoDeTresUsuarios(eUsuario MisUsuarios[])
{
    int i;
    for(i=0;i<3;i++)
    {
        MisUsuarios[i].idUsuario=i+100;

    }
     strcpy(MisUsuarios[0].nombre,"Maria pia");
     strcpy(MisUsuarios[1].nombre,"Jose luis");
     strcpy(MisUsuarios[2].nombre,"Dafne");
}

char buscarUsuario(eUsuario listaUsuario[], int idUsuario){
    for(int i=0;i<TUSUARIO;i++){
        if(listaUsuario[i].idUsuario==idUsuario){
            return 1;
        }
    }
    return 0;
}
