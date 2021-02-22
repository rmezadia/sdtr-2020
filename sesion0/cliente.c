#include "cabecera.h"
#include <stdlib.h>
#include <rpc/rpc.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//No se le pasa ningun parametro.
//argc es la cantidad total de programas puede recibir elprigrama.

int main(int argc, char *argv[]){
	
	//Primera llamada  al procedimiento.
	int numproceso_server,num_procedimiento, stat;
	char * host;   //Puntero a char que es el host.

	host=argv[1];
	num_procedimiento=atoi(argv[2]); //atoi convierte

	//llamada a procedimiento remoto
	if(stat=callrpc(host,NPROG,NVERS0,NPROC0,(xdrproc_t)xdr_void,0,(xdrproc_t)xdr_int,&numproceso_server)!=0){
		
		printf("Error desde el cliente. \n" );

	}else{

		printf("Identificador de proceso devuelto %d \n", numproceso_server );

	}
	

	
}