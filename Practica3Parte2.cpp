#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    float x;
    float y;
};

void ingresarLim(int &xmin, int &xmax, int &ymin, int &ymax){
    cout<< "X maximo: ";
    cin>> xmax;
    cout<< "X minimo: ";
    cin>> xmin;
    cout<< "Y maximo: ";
    cin>> ymax;
    cout<< "Y minimo: ";
    cin>> ymin;
}

void ingresarPts(Punto* puntos, int n, int xmin, int xmax, int ymin, int ymax){
    for(int i = 0; i < n; i++){
        bool PuntoValido = false;
        while(!PuntoValido){
            float xi = 0, yi = 0;
            cout<< "Ingrese el punto " << i + 1 << " en x: ";
            cin>> xi;
            cout<< "Ingrese el punto " << i + 1 << " en y: ";
            cin>> yi;
            if(xi >= xmin && xi <= xmax && yi >= ymin && yi <= ymax){
                PuntoValido = true;
                puntos[i].x = xi;
                puntos[i].y = yi;
            }else{
                cout << "El punto ingresado se encuentra fuera de los limites del plano." << endl << endl;
            }
        }
    }
}

void calcularDistanciaMax(Punto* puntos, int n, double &distanciaMaxima, Punto &punto1, Punto &punto2, int xmin, int xmax, int ymin, int ymax){
    for(int i = 0; i < n; ++i){
        if(puntos[i].x < xmin || puntos[i].x > xmax || puntos[i].y < ymin || puntos[i].y > ymax){
            continue;
        }
        for(int j = i + 1; j < n; ++j){
            if(puntos[j].x < xmin || puntos[j].x > xmax || puntos[j].y < ymin || puntos[j].y > ymax){
                continue;
            }
            double distancia = sqrt((puntos[j].x - puntos[i].x) * (puntos[j].x - puntos[i].x) + (puntos[j].y - puntos[i].y) * (puntos[j].y - puntos[i].y));
            if(distancia > distanciaMaxima){
                distanciaMaxima = distancia;
                punto1 = puntos[i];
                punto2 = puntos[j];
            }
        }
    }
}

void mostrarResultados(double distanciaMaxima, Punto punto1, Punto punto2){
    cout<< "La distancia maxima entre dos puntos dentro del plano es: " << distanciaMaxima << endl;
    cout<< "Entre los puntos (" << punto1.x << ", " << punto1.y << ") y (" << punto2.x << ", " << punto2.y << ")." << endl;
}

void calcularDistDesdePt(Punto* puntos, int n, int indicePunto, int xmin, int xmax, int ymin, int ymax){
    if(puntos[indicePunto].x >= xmin && puntos[indicePunto].x <= xmax && puntos[indicePunto].y >= ymin && puntos[indicePunto].y <= ymax){
        cout<< "Distancias desde el punto (" << puntos[indicePunto].x << ", " << puntos[indicePunto].y << "):" << endl;
        for(int i = 0; i < n; ++i){
            if(i == indicePunto) continue;
            if(puntos[i].x >= xmin && puntos[i].x <= xmax && puntos[i].y >= ymin && puntos[i].y <= ymax){
                double distancia = sqrt((puntos[i].x - puntos[indicePunto].x) * (puntos[i].x - puntos[indicePunto].x) + (puntos[i].y - puntos[indicePunto].y) * (puntos[i].y - puntos[indicePunto].y));
                cout<< "(" << puntos[i].x << "," << puntos[i].y << "):" << distancia << endl;
            }
        }
    }else{
        cout<< "El punto no está dentro del cuadrante." << endl;
    }
}

int main(){
    int n = 0, xmin, xmax, ymin, ymax;
    
    ingresarLim(xmin, xmax, ymin, ymax);
    
    cout<< "Ingrese la cantidad de puntos a analizar: ";
    cin>> n;
    Punto puntos[n];
    
    ingresarPts(puntos, n, xmin, xmax, ymin, ymax);

    double distanciaMaxima = 0;
    Punto punto1, punto2;
    calcularDistanciaMax(puntos, n, distanciaMaxima, punto1, punto2, xmin, xmax, ymin, ymax);
    
    mostrarResultados(distanciaMaxima, punto1, punto2);

    int indicePunto;
    cout<< "Ingrese el indice del punto: ";
    cin>> indicePunto;
    indicePunto--;

    if(indicePunto >= 0 && indicePunto < n){
        calcularDistDesdePt(puntos, n, indicePunto, xmin, xmax, ymin, ymax);
    }else{
        cout << "Indice de punto fuera de rango." << endl;
    }

    return 0;
}