#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int N = 5;
	char M[N][N];
	M[0][0]='A'; M[0][1]='B'; M[0][2]='C'; M[0][3]='D'; M[0][4]='E';
	M[1][0]='A'; M[1][1]='B'; M[1][2]='C'; M[1][3]='D'; M[1][4]='E';
	M[2][0]='A'; M[2][1]='B'; M[2][2]='C'; M[2][3]='D'; M[2][4]='E';
	M[3][0]='A'; M[3][1]='B'; M[3][2]='C'; M[3][3]='D'; M[3][4]='E';
	M[4][0]='A'; M[4][1]='B'; M[4][2]='C'; M[4][3]='D'; M[4][4]='E';
	char S[]="A";
	//dužina stringa K
	int K = strlen(S);
	
	//vodoravno u oba smjera
	int vod1 = 0, vod2 = 0, hor1=0, hor2=0, dij1=0, dij2=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(M[i][j] == S[0]){
				for(int k=0; k<K; k++){
					if(M[i][j+k] == S[k]){
						vod1++;
					}
					if(M[i][j-k] == S[k]){
						vod2++;
					}
					if(M[i+k][j] == S[k]){
						hor1++;
					}
					if(M[i-k][j] == S[k]){
						hor2++;
					}
					if(M[i+k][j+k] == S[k]){
						dij1++;
					}
					if(M[i-k][j-k] == S[k]){
						dij2++;
					}
				}
				if(vod1==K || vod2==K || hor1==K || hor2==K || dij1==K || dij2==K){
					printf("\nDA\n");
					return 0;
				}
				vod1=0; vod2=0; hor1=0; hor2=0; dij1=0; dij2=0;
			}
		}
	}
	
	//sporedna dijagonala
	dij1=0; dij2=0;
	for(int i=0; i<N; i++){
		for(int j=N; j!=0; j--){
			if(M[i][j] == S[0]){
				for(int k=0; k<K; k++){
					if(M[i+k][j-k] == S[k]){
						dij1++;
					}
					if(M[i-k][j+k] == S[k]){
						dij2++;
					}
				}
				if(dij1 == K || dij2 == K){
					printf("\nDA\n");
					return 0;
				}
				dij1=0; dij2=0;
			}
		}
	}
	
	printf("\nNE\n");
	return 0;
}
