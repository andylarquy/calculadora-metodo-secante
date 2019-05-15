#include <stdio.h>
#include <math.h>

void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones);
double evaluarEn(double x);
double formula(double n0, double n1);
double error(double x0, double x1);

int main(){

printf("La funcion elegida es: 3 * sen(x) + 2\n");

int i;
int iteraciones;

double a;
double b;
double c;//Variable temporal usada para las iteraciones
double chequeoAltaConvergencia;

double epsilon;

valoresIniciales(&a,&b,&epsilon,&iteraciones);

c = formula(a,b);
printf("\nx2 %.15lf\n dif: %.15lf\n\n",c,error(c,b));

a = b;
b = c;

for(i = 1; i < iteraciones && error(a,b) > epsilon; i++){

    chequeoAltaConvergencia = c;
    c = formula(a,b);

    printf("\nx%d = %.15lf\n dif: %.15lf\n\n",i+2,c,error(c,b));

    a = b;
    b = c;


    if(chequeoAltaConvergencia == c){
        printf("Hay una alta convergencia en x = %.15f",c);
        break;
    }


}

}


double formula(double n0, double n1){

    double temp;
    temp = n1 - ((n1-n0) * evaluarEn(n1) ) / (evaluarEn(n1)-evaluarEn(n0)); //Formula con pequeña simplificacion

    return temp;


}

double evaluarEn(double x){

double temp;
temp = (3 * sin(x)) + 2;

return temp;
}


double error(double x0, double x1){
    return fabs(x1 - x0);
}




void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones){

printf("Ingrese un numero real A:\n");
scanf("%lf",a);

printf("Ingrese un numero real B:\n");
scanf("%lf",b);

printf("Ingrese un Epsilon:\n");
scanf("%lf",epsilon);

printf("Ingrese la cantidad maxima de iteraciones:");
scanf("%d",iteraciones);

printf("\n");
}
