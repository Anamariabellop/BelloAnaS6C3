#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

void cuerda(double con, double longitud,double t0, double tf, int npuntos);

int main(){

	double L=1.0;
	double dx=0.01;
	double c= 300.0;
	int N = 100;
	double t =0.0;
	double tfinal=0.1;
	cuerda(c,L,t,tfinal,1001);

	return 0;
}

void cuerda(double con, double longitud,double t0, double tf, int npuntos){
	ofstream outfile;
	outfile.open("cuerda.txt");

	//Arreglos.
	double Aactual[npuntos];
	double Aold[npuntos];
	double Anew[npuntos];
	//Deltas.
	double A0=0.01;
	double dx=0.05;// dx de la ecuacion
	double deltat=(dx*0.7)/(con);// de la ecuacion
	//cout << deltat*deltat << endl;

	//double dt=(tf-t0)/(npuntos-1); //Para linspace de tiempo 
	double tiempo[npuntos];

	double delta= (longitud)/(npuntos-1);//pendientes condiciones iniciales.
	double m=(A0)/(longitud/2.0);
	double L[npuntos];
	//Constante. 
	double k=(con*(deltat/dx));
	L[0]=0.0;
	tiempo[0]=t0;

	//Caso 1:

	//condiciones iniciales con extremos fijos.

	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     //tiempo[i]= tiempo[i-1]+dt;
     L[i]=L[i-1]+delta;
    }

    for(int i=0; i<(npuntos/2); i++)
    {
  		Aold[i]=i*delta*m;	
    }

    for(int i=(npuntos/2); i<npuntos+1; i++)
    {
    	Aold[i]= ((-m)*i*delta)+(2.0*A0);
    }

    for(int i=0; i< npuntos;i++){
    	Anew[i]=  (2.0*Aold[i] + ((k*k)*(Aold[i+1]+Aold[i-1]-(2.0*Aold[i]))))/2;
    	Aactual[i]=Anew[i];//Actualizo actual con respecto al nuevo.
    }

    for(int i=0; i<npuntos; i++)
    {
    	outfile  << L[i] << "  " << i << "  " << Aold[i] << "  " << Anew[i]<< "  " << Aactual[i]<< endl;
    }

	outfile.close();

	ofstream outfile2;
	outfile2.open("cuerda2.txt");

	int contador=0;
	for(int i=0; i<700;i++){
		contador++;
		for (int j = 1; j <=npuntos-1; j++)
		{
			Anew[j]= ((k*k)*(Aactual[j+1]+Aactual[j-1]-(2.0*Aactual[j]))) -Aold[j] + (2.0*Aactual[j]);
			if(contador%30==0){
				outfile2 << L[j-1] << "  " << j << "  " << Aold[j-1] << "  " << Anew[j-1]<< "  " << Aactual[j-1]<< endl;
			}

		}
		for(int k=1; k<=npuntos-1;k++){
			Aold[k]=Aactual[k];//Actualizo el viejo con respecto a actual.
    		Aactual[k]=Anew[k];//Actualizo actual con respecto a nuevo.
		}
	}

	outfile2.close();

	//Caso 2:
	// Un extremo fijo y otro libre.

	double A2old[npuntos];
	double A2actual[npuntos];
	double A2new[npuntos];

	ofstream outfile3;
	outfile3.open("cuerdacaso2.txt");
	//condicion inicial.

	for(int i=0; i<(npuntos/2); i++)
    {
  		A2old[i]=i*delta*m;	
    }

    for(int i=(npuntos/2); i<npuntos+1; i++)
    {
    	A2old[i]= ((-m)*i*delta)+(2.0*A0);
    }

    for(int i=1; i<npuntos+2;i++){
    	A2new[i]=  (2.0*A2old[i] + ((k*k)*(A2old[i+1]+A2old[i-1]-(2.0*A2old[i]))))/2;
    	A2actual[i]=A2new[i];//Actualizo actual con respecto al nuevo.
    }

    for(int i=0; i<npuntos; i++)
    {
    	outfile3  << L[i] << "  " << i << "  " << A2old[i] << "  " << A2new[i]<< "  " << A2actual[i]<< endl;
    }

    outfile3.close();

    ofstream outfile4;
	outfile4.open("cuerda2caso2.txt");

	int contador2=0;
	for(int i=0; i<500;i++){
		contador2++;
		for (int j = 1; j <=npuntos+1; j++)
		{
			A2new[j]= ((k*k)*(A2actual[j+1]+A2actual[j-1]-(2.0*A2actual[j]))) -A2old[j] + (2.0*A2actual[j]);
			if(contador2%90==0){
				outfile4 << L[j-1] << "  " << j << "  " << A2old[j-1] << "  " << A2new[j-1]<< "  " << A2actual[j-1]<< endl;
			}

		}
		for(int k=1; k<=npuntos+1;k++){
			A2old[k]=A2actual[k];//Actualizo el viejo con respecto a actual.
    		A2actual[k]=A2new[k];//Actualizo actual con respecto a nuevo.
		}
	}
	
	outfile4.close();

	// Caso 3:
	// inicialmente en reposo y su posición de equilibrio. Extremo fijo y extremo amplitud varia.

	double A3old[npuntos];
	double A3actual[npuntos];
	double A3new[npuntos];
	
	ofstream outfile5;
	outfile5.open("cuerdacaso3.txt");

	// condiciones iniciales.

	for(int i=0; i<=npuntos-1;i++){

		A3old[i]=0;

		if(i==(npuntos-1)){
			A3old[i]=A0*sin((3.0*con*M_PI)/(longitud));
		}

	}

	//Primer paso.

	for(int i=1; i<npuntos+2;i++){
    	A3new[i]=  (2.0*A3old[i] + ((k*k)*(A3old[i+1]+A3old[i-1]-(2.0*A3old[i]))))/2;
    	A3actual[i]=A3new[i];//Actualizo actual con respecto al nuevo.
    }

	for(int i=0; i<npuntos; i++)
    {
    	outfile5  << L[i] << "  " << i << "  " << A3old[i] << "  " << A3new[i]<< "  " << A3actual[i]<< endl;
    }

	outfile5.close();

	ofstream outfile6;
	outfile6.open("cuerda2caso3.txt");

	int contador3=0;
	for(int i=0; i<700;i++){
		contador3++;
		for (int j = 1; j <=npuntos+1; j++)
		{
			A3new[j]= ((k*k)*(A3actual[j+1]+A3actual[j-1]-(2.0*A3actual[j]))) -A3old[j] + (2.0*A3actual[j]);
			if(contador3%60==0){
				outfile6 << L[j-1] << "  " << j << "  " << A2old[j-1] << "  " << A2new[j-1]<< "  " << A2actual[j-1]<< endl;
			}

		}
		for(int k=1; k<=npuntos+1;k++){
			A3old[k]=A3actual[k];//Actualizo el viejo con respecto a actual.
    		A3actual[k]=A3new[k];//Actualizo actual con respecto a nuevo.
		}
	}
	
	outfile6.close();
}


void tambor(double con, double longitud,double t0, double tf, int npuntos){
	ofstream outfile7;
	outfile7.open("tambor.txt");

	//Arreglos.
	double Axactual[npuntos];
	double Axold[npuntos];
	double Axnew[npuntos];

	double Ayactual[npuntos];
	double Ayold[npuntos];
	double Aynew[npuntos];

	//Deltas.
	double A0=0.01;
	double dx=0.05;// dx de la ecuacion
	double deltat=(dx*0.7)/(con);// de la ecuacion
	//cout << deltat*deltat << endl;

	//double dt=(tf-t0)/(npuntos-1); //Para linspace de tiempo 
	double tiempo[npuntos];

	double delta= (longitud)/(npuntos-1);//pendientes condiciones iniciales.
	double m=(A0)/(longitud/2.0);
	double L[npuntos];
	//Constante. 
	double k=(con*(deltat/dx));
	L[0]=0.0;
	tiempo[0]=t0;

	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
     //tiempo[i]= tiempo[i-1]+dt;
     L[i]=L[i-1]+delta;
    }

    /*for(int i=0; i<=npuntos; i++){
    	Axold[i]=1/(pow(2*M_PI*sigma*sigma,0.5))*
    	Ayold[i]=
    }*/
}
