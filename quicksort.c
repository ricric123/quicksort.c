#include <stdio.h>
#include <stdlib.h>
#define TAM 30000
#include <locale.h>
#include <time.h>

//prototipo
void preencheRandomico();
void mostraVetor();
void quicksort();
//void bolha();
void selecaoDireta();
//variavel global
int vet[TAM];

void quicksort(int esq, int dir){
	int i, j, aux, pivo;
	i=esq;
	j=dir;
	pivo=vet[(i+j)/2];
	
	while(i<j){
		while(vet[i]<pivo){
			i++;
		}
		while(vet[j]>pivo){
			j--;
		}
		if(i<=j){
			aux=vet[i];
			vet[i]=vet[j];
			vet[j]=aux;
			i++;
			j--;
		}
	}
	if(esq<j){
		quicksort(esq,j);
	}
	if(i<dir){
		quicksort(i, dir);
	}
}
//
void mostraVetor(){
	int i;
	
	for(i=0;i<TAM;i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}
//
//// void bolha(){
////	int i, aux, j, cont;
////	cont=0;
////
////	for(j=0;j<TAM;j++){
////		cont=0;
////		for(i=0;i<TAM-1;i++){
////			if(vet[i]>vet[i+1]){
////				aux=vet[i];
////				vet[i]=vet[i+1];
////				vet[i+1]=aux;
////				cont++;
////				mostraVetor();
////			}
////		}
////		if(cont==0){
////			break;
////		}
////	}
////}
//
//void selecaoDireta(){
//	int aux, i, j, iMaior, maior;
//	
//	for(j=TAM-1;j>0;j--){
//		//achar o maior elemento e colocalo na ultima posiçao do vetor
//		maior=vet[0];
//		iMaior=0;
//		
//		for(i=1;i<=j;i++){
//			if(vet[i]>maior){
//				maior=vet[i];
//				iMaior=i;
//			}
//		}
//		//trocar o maior com o ultimo elemento
//		aux=vet[j];
//		vet[j]=maior;
//		vet[iMaior]=aux;
//		mostraVetor();
//	}
//}

 void preencheRandomico(){
	int i, j;
	//controlar a posição onde será posionado o número randomico
	for(i=0;i<TAM;i++){
		vet[i]=rand()% TAM;
		
		//buscar o elemento no vetor
		for(j=0;j<i;j++){
			if(vet[i]==vet[j]){
				i--;
				break;
			}
		}
	}
}

main(){
	srand(time(NULL));
	preencheRandomico();
	mostraVetor();
	quicksort(0, TAM-1);
	mostraVetor();
	
//	selecaoDireta();
//	bolha();
}
