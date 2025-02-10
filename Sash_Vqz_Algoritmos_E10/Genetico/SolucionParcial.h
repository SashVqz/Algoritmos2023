#include <iostream>
#include <iomanip>

using namespace std;


class SolucionParcial {
 	public:
  		float x; 
  		float y; 
  
  		void imprimir(){
    		cout<<setprecision(5)<<"("<<x<<","<<y<<")"<<endl;
  		}
};
