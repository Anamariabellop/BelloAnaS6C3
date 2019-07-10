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
	cuerda(c,L,t,tfinal,101);

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
	cout << deltat*deltat << endl;

	//double dt=(tf-t0)/(npuntos-1); //Para linspace de tiempo 
	
	double tiempo[npuntos];

	double delta= (longitud)/(npuntos-1);//pendientes condiciones iniciales.
	double m=(A0)/(longitud/2.0);
	double L[npuntos];
	//Constante. 
	double k=(con*(deltat/dx));

	L[0]=0.0;
	tiempo[0]=t0;

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

    for(int i=0; i<2*npuntos; i++){
    	int contador=0;
    	for(int j=1; i<npuntos-1; i++){
    		Anew[j]= ((k*k)*(Aactual[j+1]+Aactual[j-1]-(2.0*Aactual[j])))-Aold[j]+ (2.0*Aactual[j]);
    		if(contador==20){
    			outfile2  << L[i] << "  " << i << "  " << Aold[i] << "  " << Anew[i]<< "  " << Aactual[i]<< endl;
    			contador=0;
    		}
    	}
    }

    for(int i=0; i<2*npuntos; i++){
    	for(int i=1; i< npuntos-1; i++){
    		Aold[i]=Aactual[i];//Actualizo el viejo con respecto a actual.
    		Aactual[i]=Anew[i];//Actualizo actual con respecto a nuevo.
    	}
    }

    for(int i=0; i<200;i++){
    	for(int i=0; i<npuntos; i++)
    	{
    	outfile2  << L[i] << "  " << i << "  " << Aold[i] << "  " << Anew[i]<< "  " << Aactual[i]<< endl;
    	}

    }
    
    outfile2.close();
}
