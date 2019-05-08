#include<stdio.h>
#include<stdlib.h>
#include<time.h>	
#include <unistd.h>
#include"liblab2Windows.h"

void main(){
	//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
	//unNumero: Número digitado por usuario para ser buscado.
	clock_t start_t,end_t,total_t;
	int tamano2,respuesta=1;
	float tiempo_insertar=0;
	float tiempo_buscar=0;
	float aux;	
	int tamano = 1000,max = 1000, unNumero,i=0,opcion,pasadas=1,pausa=0;
	srand(time(NULL));
	
   
	system("cls");
	printf("1.-Caso base\n2.-Segundo Laboratorio\n3.-Segundo Laboratorio (experimentacion)\n4.-Salir\nOpcion: ");
	scanf("%i",&opcion);
	//CASO BASE
	//Se llama al módulo creaListaNumerosLlena y se almacena la lista creada en un puntero de tipo estructura .
	ListaNumeros *unaListaNumeros = creaListaNumerosVacia(tamano);
	ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
	ListaNumeros *lista3 = creaListaNumerosVacia(tamano);
	ListaNumeros *lista2 = creaListaNumerosVacia(tamano);
	//Se llama al procedimiento imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
	switch(opcion){
		case 1:
			imprimirLista(unaListaNumeros);
			//El usuario digita un número para ser buscado dentro de la lista.
			printf("Digite un número para buscarlo: ");
			scanf("%i",&unNumero);
			
	
			//llama a la función buscaNumeroEnListaNumero, si encuentra un número: retorna 1 y si no lo encuentra retorna: -1.
			if(buscaSecuencialNumeroEnListaNumeros(unaListaNumeros, unNumero)!=(-1)){
				printf("\nNúmero %i encontrado\n", unNumero);
			}else{
				printf("\nEl número %i no ha sido encontrado\n", unNumero);
			}
			
			//llama a la función eliminaListaNumeros, donde se libera la memoria creada para "unaListaNumeros" y "arreglo". 
			if(eliminaListaNumeros(unaListaNumeros)){
				printf("\nLista eliminada con éxito\n");
			}
			else{
				printf("\nNo hay lista para eliminar");
			}
			;break;
		case 2:
			printf("1.-Insertar al final y buscar secuencialmente\n2.-Insertar en orden y usar busqueda binaria\n3.-Insertar siempre al final, ordenar despues de cada insercion y usar busqueda binaria\n ");
			printf("\nOpcion=");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
					
					printf("\nIndique el tama�o del arreglo: ");
					scanf("%i",&tamano2);
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano2);
					while(respuesta==1){
						system("cls");
						printf("\nIndique el numero que desea insertar: ");
						scanf("%i",&unNumero);
						lista1=insertaFinalLista(lista1,unNumero);
						imprimirLista(lista1);
						printf("\n�Desea seguir a�adiendo? (1 para si y 0 para no): ");
						scanf("%i",&respuesta);
											
					}
					printf("\nIndique un numero para buscarlo: ");
					scanf("%i",&unNumero);
					if(buscaSecuencialNumeroEnListaNumeros(lista1, unNumero)!=(-1)){
						printf("\nNumero %i encontrado\n", unNumero);
					}else{
						printf("\nEl numero %i no ha sido encontrado\n", unNumero);
					}
					;break;
					
				case 2:
				
					printf("\nIndique el tama�o del arreglo: ");
					scanf("%i",&tamano2);
					ListaNumeros *lista2 = creaListaNumerosVacia(tamano2);
					while(respuesta==1){
						system("cls");
						printf("\nIndique el numero que desea insertar: ");
						scanf("%i",&unNumero);
						lista2=insertaEnOrden(lista2,unNumero);
						imprimirLista(lista2);
						printf("\n�Desea seguir a�adiendo? (1 para si y 0 para no): ");
						scanf("%i",&respuesta);
											
					}
					lista2=ordenarMenorMayor(lista2);
					printf("\nIndique un numero para buscarlo: ");
					scanf("%i",&unNumero);
				
					if(busquedaBinaria(lista2,unNumero)){
						printf("\nNumero %i encontrado\n", unNumero);
					}else{
						printf("\nEl numero %i no ha sido encontrado\n",unNumero);
					}
					;break;
					
				case 3:
					printf("\nIndique el tama�o del arreglo: ");
					scanf("%i",&tamano2);
					ListaNumeros *lista3 = creaListaNumerosVacia(tamano2);
					while(respuesta==1){
						system("cls");
						printf("\nIndique el numero que desea insertar: ");
						scanf("%i",&unNumero);
						lista3=insertaFinalLista(lista3,unNumero);
						
						lista3=ordenamientoLista(lista3);
						imprimirLista(lista3);
						printf("\n�Desea seguir a�adiendo? (1 para si y 0 para no): ");
						scanf("%i",&respuesta);
											
					}
					
					printf("\nIndique un numero para buscarlo: ");
					scanf("%i",&unNumero);
				
					if(busquedaBinaria(lista3,unNumero)){
						printf("\nNumero %i encontrado\n", unNumero);
					}else{
						printf("\nEl numero %i no ha sido encontrado\n",unNumero);
					}
					;break;			
			};break;
		case 3:
//SEGUNDO LABORATORIO
			
			printf("1.-Insertar al final y buscar secuencialmente\n2.-Insertar en orden y usar busqueda binaria\n3.-Insertar siempre al final, ordenar despúes de cada inserción y usar busqueda binaria\n ");
			printf("\n4.-Caso de prueba busqueda binaria (caso peor) con un arreglo de tama�o 6.000.000.000)");
			printf("\nOpcion=");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
//1.- Insertar al final y buscar secuencialmente.
//Se llama al módulo creaListaNumerosVacia y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
				system("clear");
				while(pasadas <= 1000){ // se cuentan 1000 iteraciones de tamaño 10000
					
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).			
					start_t=clock();	/*inicia cronometro Insertar.*/
					moduloInsertarFinal(lista1,max);
					end_t=clock();	/*finaliza cronometro Insertar.*/
					total_t=(end_t - start_t);
					tiempo_insertar=total_t;
				
					
				
					
					
					unNumero = -1;/*Crea un numero para ser buscado.*/
					start_t=clock();	/*inicia cronometro busqueda secuencial.*/
				 	//Busca secuencialmente un numero en el arreglo.
					if(buscaSecuencialNumeroEnListaNumeros(lista1, unNumero)!=(-1)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n", unNumero);
					}
					
					end_t=clock();/*finaliza cronometro busqueda secuencial*/
					total_t=(end_t - start_t);
					tiempo_buscar=total_t;
			
					
					guardarEnArchivo(pasadas,tamano,tiempo_insertar,tiempo_buscar,1);
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %f [Mseg]\ntiempo busqueda: %f [Mseg]\n\n", pasadas,tamano, tiempo_insertar, tiempo_buscar);
					pasadas++;
					tamano = tamano + 10000; //el tamaño maximo posible fue de 6.400.000 o se congela el proceso
				}	
				;break;
				
				case 2:
//2.- Inserta en orden y usa búsqueda binaria.
				while(pasadas <= 1000){
					int aux2;
					
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					
					ordenamientoLista(lista1);	/*Ordena la lista de Mayor a menor.*/
					//calcularEspacio(lista1); 	calcula cuantos elementos hay en la lista y devuelve la cantidad
				

					start_t=clock(); 	/*inicia cronometro Insercion Ordenada.*/
					lista1=InsertarVariosEnOrden(lista1,unNumero,max);
			
					end_t=clock();	/*finaliza cronometro Insercion Ordenada.*/
					
					total_t=(end_t - start_t);
					tiempo_insertar=total_t;
				
					
					unNumero = lista1->arreglo[tamano-1]; // numero a buscar

					start_t=clock(); 	/*inicia cronometro busqueda binaria.*/
					
					
					if(busquedaBinaria(lista1,unNumero)){
						printf("\nNumero %i encontrado\n", unNumero);
					}else{
						printf("\nEl numero %i no ha sido encontrado\n",unNumero);
					}
					end_t=clock();		/*finaliza cronometro busqueda binaria*/
					printf("\n%i\n",pausa++);

					total_t=(end_t-start_t);
					tiempo_buscar=total_t;	
				
					
					
					guardarEnArchivo(pasadas,tamano,tiempo_insertar,tiempo_buscar,2);
				
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %f [Mseg]\ntiempo busqueda: %f [Mseg]\n",pasadas,tamano, tiempo_insertar, tiempo_buscar);
					//printf("\n");
					//scanf("%i",&pausa);
					pasadas++;
					tamano = tamano + 1000; 
				}
				;break;
				
				case 3:
//3.- Insertar siempre al final, ordenar con quicksort después de cada inserción, y usar busqueda binaria.
//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).
				while(pasadas <= 1000){	
					
					ListaNumeros *lista3 = creaListaNumerosVacia(tamano);//creaListaNumerosVacia(tamano);
					
					start_t=clock();	/*inicia cronometro Insercion.*/
				
					
					lista3=InsertarVariosAlFinal(lista3,unNumero,max);
					
					
					end_t=clock();	/*finaliza cronometro Insercion.*/
					total_t=(end_t - start_t);
					
					tiempo_insertar=total_t;
					
					
					if(lista3->cantidadActual == lista3->cantidadMaxima){ /*Busca un numero por busqueda binaria*/
					
						
						unNumero = -1;
						start_t=clock();	/*inicia cronometro busqueda binaria.*/
						if(busquedaBinaria(lista3,unNumero)){
							printf("\nNúmero %i encontrado\n", unNumero);
						}else{
							printf("\nEl número %i no ha sido encontrado\n",unNumero);
						}
						end_t=clock();	/*finaliza cronometro busqueda binaria*/
						
						total_t=(end_t-start_t);
						tiempo_buscar=total_t;	
					
					}
					else{
						printf("\nEl arreglo esta lleno");
					}
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %f [Mseg]\ntiempo busqueda: %f [Mseg]\n\n",pasadas,tamano, tiempo_insertar, tiempo_buscar);
					
					guardarEnArchivo(pasadas,tamano,tiempo_insertar,tiempo_buscar,3);
					tamano = tamano + 1000;
					pasadas = pasadas + 1;
				}
					;break;
				case 4:
					lista2=creaListaNumerosordenados(6000000000);
					
					unNumero=-1;
					
					start_t=clock();
					if(busquedaBinaria(lista2,unNumero)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n",unNumero);
					}
					end_t=clock();
					total_t=(end_t-start_t);
					aux=total_t;
					printf("\ntiempo busqueda= %f",aux);
					
					
					
					


					;break;
	
			}
			;break;
		
	}
}


