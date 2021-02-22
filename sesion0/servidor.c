#include "cabecera.h"
#include <stdlib.h>
#include <rpc/rpc.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>


//Prototipos
int * obtenerProceso();


//La variable a resolver debe ser static int sol;

int main(int argc, char *argv[])
{
	

	//Control de los tres procedimientos

	//Se hara llamada 
	//char *(*)(char*))obtenerProceso. ese casting simpre hay que poberlo para que lo tome como cadena de caracteres.
	//xdr-void porque no debe pasarle param de entrada en este caso.
	//xdr_int porque devuelve un entero.
	registerrpc(NPROG,NVERS0,NPROC0,(char *(*)(char*))obtenerProceso, (xdrproc_t) xdr_void, (xdrproc_t) xdr_int);
	
	printf("Error al registrar el procedimiento remoto: obtenerProceso (%d)\n", NPROC0 );
	
	//Corro servicio y lo pone a la escucha.
	svc_run();


}


//Implementacion metodos
//Devuelve el primer identficador de proceso del servicio que se esta ejecutando en el servidor.

int * obtenerProceso(){

	static int resultado; //Todas las variables definidas dentro de un metodo deben ser staticas, porque se van a devolver.

	resultado = getpid(); //strdup getlogin.

	return &resultado;

}
