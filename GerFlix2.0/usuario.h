#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#define TUSUARIO 3

typedef struct{
    int idUsuario;
    char nombre[50];
}eUsuario;

char buscarUsuario(eUsuario [],int);

#endif // USUARIO_H_INCLUDED
