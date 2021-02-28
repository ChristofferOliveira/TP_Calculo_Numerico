#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float funcao(float xAtual){
	float y;

	y = pow(xAtual, 3) - 2 * pow(xAtual, 2) - 5;
	return y;
}

float funcaoDerivada(float xAtual){
	float y;

	y = 3 * pow(xAtual, 2) - 4 * (xAtual);
	return y;
}

void secante(float epsilon, float xAtual, float xProximo){
    float xProx = 0.0;
    float erro = 0.0;
    int i = 0;

    do{
        printf("xAtual = %f iteracao = %d\n", xAtual, i);
        xProx = xAtual * funcao(xProximo) - xProximo * funcao(xAtual) / funcao(xProximo) - funcao(xAtual);
        erro = fabs((xProx - xAtual) / xAtual);
        xAtual = xProximo;
        xProximo = xProx;
        i++;
    }while(erro > epsilon);
}


void newton(float epsilon, float xAtual){

	int i = 0;
	float xProximo = 0.0;
	float erro = 0.0;

	do{
		printf("xAtual = %f iteracao = %d\n", xAtual, i);
		xProximo = xAtual - (funcao(xAtual)/funcaoDerivada(xAtual));
		erro = fabs((xProximo - xAtual) / xAtual);
		printf("ERRO = %f\n", erro);
		xAtual = xProximo;
		i++;

	}while(erro > epsilon);
	printf("Resultado do xfinal = %f\n", xAtual);
}

void falsaPosicao(float epsilon, float A, float B){
    float erro = 0.0;
    float xAnterior = 0.0;
    float xAtual = 0.0;
    int i = 0;

	do{
	    xAnterior = xAtual;
		xAtual = (A * fabs(funcao(B)) + B * fabs(funcao(A))) / (fabs(funcao(A)) + fabs(funcao(B)));

        erro = fabs((xAnterior - xAtual) / xAnterior);
        printf("Erro = %f\n", erro);

		if((xAtual < 0) && (funcao(A) < 0)){
			A = xAtual;
			printf("Entrou A = %f\n",A);
		}else{
			B = xAtual;
			printf("Entrou B = %f\n",B);
		}
		printf("xAtual = %f iteracao = %d\n", xAtual, i);
		i++;
	}while(erro > epsilon);
	printf("Resultado do xfinal = %f\n", xAtual);

}

void bissecao(float epsilon, float A, float B){

	float xProximo = 0.0;
	float xAtual = (A+B)/2;
	int i = 0;

	while(fabs(B-A) > epsilon){
		xProximo = funcao(xAtual);

		if((xProximo < 0) && (funcao(A) < 0)){
			A = xAtual;
		}else{
			B = xAtual;
		}
		xAtual = (A+B)/2;
		printf("xAtual = %f iteracao = %d\n", xAtual, i);
		i++;
	}
	printf("Resultado do xfinal = %f\n", xAtual);
}

int main(){
	float epsilon = 0.00005;
	float x0 = 4.0;
	float A = -10.0;
	float B = 10.0;

	printf("Usando newton\n");
	newton(epsilon, x0);
	printf("Usando bissecao\n");
	bissecao(epsilon, A, B);
	printf("Usando falsa posicao\n");
	falsaPosicao(epsilon, A, B);
	printf("Usando secante\n");
	secante(epsilon, 4, 3);

	return 0;
}
