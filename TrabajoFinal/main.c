#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "config/config.h"
#include "lib/orm/orm.h"
#include "lib/utils/utils.h"

#include "src/categoria/categoria.h"
#include "src/circuito/circuito.h"
#include "src/seccion/seccion.h"
#include "src/localidad/localidad.h"
#include "src/escuela/escuela.h"
#include "src/partido/partido.h"
#include "src/lista_partido/lista_partido.h"
#include "src/lista_partido_localidad/lista_partido_localidad.h"
#include "src/mesa/mesa.h"
#include "src/telegrama_acta/telegrama_acta.h"
#include "src/telegrama_acta_votos/telegrama_acta_votos.h"

#define MAXARG 30
#define TOPE 9
#define MENOSELE "-l"
#define TOKEN "-f"
#define EXTENSION ".txt"
#define TAMANIOEXT 4
#define MAXCOMANDO 50

// CRITERIO DE COMPARACION PARA ESCUELA UTILIZADO POR QSORT
/********************/
int OrdAlfabetico(const void *a, const void *b) {
	
	obj_Escuela *a1;
    obj_Escuela *b1;
    a1 =  *(obj_Escuela **)a;
    b1 =  *(obj_Escuela **)b;
    return (b1->info.Escuela_id-a1->info.Escuela_id);
    //return (strcmp(a1->info.nombre_Escuela,b1->info.nombre_Escuela)); 
}


// CRITERIO DE COMPARACION PARA CAETGORIA UTILIZADO POR QSORT

/*********************************/


int OrdAlfCat(const void *a, const void *b) 
{ 
    obj_Categoria *a1;
    obj_Categoria *b1;
    a1 =  *(obj_Categoria **)a;
    b1 =  *(obj_Categoria **)b;
    return (a1->info.Categoria_id-b1->info.Categoria_id);
	//return strcmp(a1->info.nombre_Categoria,ab1->info.nombre_Categoria);
} 

	

// LISTA EL NUMERO DE PARTIDOS, LISTAPARTIDO - NOMBRE DEL PARTIDO POLITICO- , CATEGORIA EN QUE SE PRESENTA Y LOCALIDAD 
/*******************************/



void lista_partido_localidad(){
	obj_ListaPartidoLocalidad *listaPartidoLocalidad;
 	listaPartidoLocalidad =ListaPartidoLocalidad_new ();
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=listaPartidoLocalidad->findAll(listaPartidoLocalidad,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_ListaPartidoLocalidad**)list)[i];
    	((obj_ListaPartidoLocalidad*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(listaPartidoLocalidad);	
}


// LISTA EL NUMERO DE LOS PARTIDOS POLITICOS QUE SE PRESENTAN Y SUS NOMBRES
/*********************************/
void lista_partido(){
	obj_ListaPartido*listaPartido;
 	listaPartido =ListaPartido_new();
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=listaPartido->findAll(listaPartido,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_ListaPartido**)list)[i];
    	((obj_ListaPartido*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(listaPartido);
}


//LISTA NUMERO Y NOMBRE DE SECCION
/********************************/
void seccion(){
	obj_Seccion *seccion;
 	seccion =Seccion_new();
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=seccion->findAll(seccion,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_Seccion**)list)[i];
    	((obj_Seccion*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(seccion);	
}


// LISTA NUMERO DE PARTIDO Y NOMBRE
/*******************************/
void partido(){
	obj_Partido *partido;
 	partido =Partido_new();
 //	circuito.info.Circuito_id;
 	//ca
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=partido->findAll(partido,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_Partido**)list)[i];
    	((obj_Partido*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(partido);
}



//LISTADO DE NUMERO DE MESA, NOMBRE DE ESCUELA, LOCALIDAD, CIRCUITO Y SECCION
/*****************************/
void mesa(){
    obj_Mesa *mesa;
 	mesa =Mesa_new();
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=mesa->findAll(mesa,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_Mesa**)list)[i];
    	((obj_Mesa*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(mesa);
	
}
//LISTA LAS LOCALIDADES POR ID Y NOMBRE
/************************/
void localidad(){
	obj_Localidad *localidad;
	localidad=Localidad_new();
	int i=0,size=0;
	void *list;
	void *itm;
	size=localidad->findAll(localidad,&list,NULL);
	for(i=0;i<size;++i){
    	itm=((obj_Localidad **)list)[i];
    	((obj_Localidad*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(esc);
  	destroyObj(localidad);
}

//LISTA LAS ESCULEAS POR ID, NOMBRE, LOCALIDAD, CIRCUITOEscuelaId1|Nombre1|Localidad1|Circuito1|Direccion1|
/***********************/
void escuela(){
	obj_Escuela *escuela;
	escuela=Escuela_new();
	int i=0,size=0;
	void *list;
	void *itm;
	size=escuela->findAll(escuela,&list,NULL);
	printf("Antes de Ordenar\n");
	for(i=0;i<size;++i){
   		itm=((obj_Circuito **)list)[i];
    	((obj_Circuito*)itm)->toString(itm);
	}
	qsort((obj_Escuela**)list,size,sizeof(obj_Escuela*),OrdAlfabetico);
	printf("despues de ordenar\n");
	for(i=0;i<size;++i){
    	itm=((obj_Circuito **)list)[i];
    	((obj_Circuito*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(esc);
  	destroyObj(escuela);
}



//LISTA LOS CIRCUITOS POR ID, NOMBRE DE CIRCUITO, SECCION Y LOCALIDAD
/******************/
void circuito(){
	obj_Circuito *circuito;
 	circuito = Circuito_new();
 //	circuito.info.Circuito_id;
 	//ca
	int i=0,size=0;
  	void *list;
 	void *itm;
	size=circuito->findAll(circuito,&list,NULL);
    for(i=0;i<size;++i){
    	itm=((obj_Circuito **)list)[i];
    	((obj_Circuito*)itm)->toString(itm);
	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(circuito);
}





// LISTA LAS CATEGORIAS POR NOMBRE DE CATEGORIA
/***************************************/

void categoria(){
	obj_Categoria *categoria;
 	categoria = Categoria_new();
 	int i=0,size=0;
  	void *list;
 	void *itm;
	size=categoria->findAll(categoria,&list,NULL);
	qsort((obj_Categoria**)list,size,sizeof(obj_Categoria*),OrdAlfCat);
	for(i=0;i<size;++i)
  	{
  	itm=((obj_Categoria **)list)[i];   
   ((obj_Categoria*)itm)->toString(itm);
     	}
  	// librerar memoria
  	destroyObjList(list,size);
  	//destroyObj(secc);
  	destroyObj(categoria);

}	


/***************************************/
int main(int argc, char *argv[]){
   	 char argumentos[][MAXARG]={
	 "categoria",
	 "circuito",
	 "escuela",
	 "localidad",
	 "mesa",
	 "partido",
	 "seccion",
	 "listapartido",
	 "listapartidolocalidad"};
   if(argc>=2 && argc<=4){
		int bandera=0;
  		int i=0;
  		if(argc ==4 && !strcmp("-l",argv[1])){
  			if(strtok(argv[3],TOKEN)){
  				printf("****** USTED SELECCIONO LA OPCION DE SALIDA POR ARCHIVO DE TEXTO PLANO ****** \n");
				char *ptr;
				ptr = strtok( argv[3], TOKEN );  
   				int largo=strlen(ptr);
   				char nombreArchivo[(largo+TAMANIOEXT)];
   				strcpy(nombreArchivo,ptr);
   				strcat(nombreArchivo,EXTENSION);
			 	printf( "Nombre del Archivo de Salida: ---->%s\n",nombreArchivo);
			 	for(i;i<TOPE;i++){
				if(!strcmp(argumentos[i],argv[2])){
					bandera=1;
					char comando[MAXCOMANDO]={};
					strcat(comando,argv[0]);
					strcat(comando," ");
					strcat(comando,argv[1]);
					strcat(comando," ");
					strcat(comando,argv[2]);
					strcat(comando,">>");
					strcat(comando,nombreArchivo);
					system(comando);
					printf("SU SELECCION %s HA SIDO IMPRESA EN EL ARCHIVO %s \n",argumentos[i],nombreArchivo);
							
				}
			}
		  }
		}
		  
		else if(argc ==3 && !strcmp("-l",argv[1])){
  			for(i;i<TOPE;i++){
				if(!strcmp(argumentos[i],argv[2])){
					bandera=1;
					printf("HAS SELECCIONADO LA OPCION %s\n",argumentos[i],i);
					switch (i){
						case 0:{
								printf("		**************************************\n");	
								printf("		******* LISTADO DE CATEGORIAS ********\n");	
								printf("		**************************************\n");	
							categoria();
							break;
						}
						case 1:{
								printf("		*************************************\n");	
								printf("		******* LISTADO DE CIRCUITOS ********\n");	
								printf("		*************************************\n");	
							circuito();
							break;
						}
						case 2:{
								printf("		************************************\n");	
								printf("		******* LISTADO DE ESCUELAS ********\n");	
								printf("		************************************\n");	
							escuela();
							break;
						}
						case 3:{
								printf("		***************************************\n");	
								printf("		******* LISTADO DE LOCALIDADES ********\n");	
								printf("		***************************************\n");	
							localidad();
							break;
						}
						case 4:{
								printf("		*********************************\n");	
								printf("		******* LISTADO DE MESAS ********\n");	
								printf("		*********************************\n");	
							mesa();
							break;
						}
						case 5:{
								printf("		************************************\n");	
								printf("		******* LISTADO DE PARTIDOS ********\n");	
								printf("		************************************\n");	
							partido();
							break;
						}
						case 6:{
								printf("		*************************************\n");	
								printf("		******* LISTADO DE SECCIONES ********\n");	
								printf("		*************************************\n");	
							seccion();
							break;
						}
						case 7:{
								printf("		********************************************\n");	
								printf("		******* LISTADO DE LISTA - PARTIDOS ********\n");	
								printf("		********************************************\n");	
							lista_partido();
							break;
						}
						case 8:{
								printf("		****************************************************\n");	
								printf("		******* LISTADO DE LISTA-PARTIDOS-LOCALIDAD ********\n");	
								printf("		****************************************************\n");	
							lista_partido_localidad();
							break;
						}

					}
				}
			}
			if (bandera==0){
				int i=0;
				printf("Ingrese Alguno De Los Siguientes  argumentos:\n");
				for(i;i<TOPE;i++){
					printf("%s\n",argumentos[i],i);
				}
			}
		}
	}
  return 0;
}


