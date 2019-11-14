#include<iostream>
#include <vector>
#include <math.h> 
#include<cmath>
#include <fstream>
#include <vector>

using namespace std;

    float static g = -9.8;
    float static vox = 10.0;
    float static voy = 10.0;
    float static fr = 0.7;
    float static PI = 3.14159265359;


void rungeKuttaVx(float t0, float vox, float t, float h);
void rungeKuttaVy(float t0, float voy, float t, float h);

int main(void)
{

    float t0 = 0.0;
    float t = 3.0;
    float h = 0.01; 
    rungeKuttaVx(t0, vox, t, h);
    rungeKuttaVy(t0, voy, t, h);

    
    
    return 0; 

}


float x(float t)
{
    float x;
    x = vox * t;
    return x;
}

float y(float t)
{
    float y;
    y = (voy * t) - 0.5*(g * t * t);
    return y;
}

float vx(float t, float x)
{
    return vox;
}

float vy(float t, float y)
{
    float vy;
    vy = voy - (g*t);
    return vy;
}


void rungeKuttaVx(float t0, float xo, float t, float h) 
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((t - t0) / h); 
  
    float k1, k2, k3, k4, k5; 
  
    // Iterate for number of iterations 
    float x = xo; 
    
    string filename = "datavx.dat";
    ofstream outfile;
    outfile.open(filename);
    
    for (int i=1; i<=n; i++) 
    { 
        // Apply Runge Kutta Formulas to find 
        // next value of y 
        k1 = h*vx(t0, x); 
        k2 = h*vx(t0 + 0.5*h, x + 0.5*k1); 
        k3 = h*vx(t0 + 0.5*h, x + 0.5*k2); 
        k4 = h*vx(t0 + h, x + k3); 
        
        outfile<<t<<" "<<x<<endl;
  
        // Update next value of y 
        x = x + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
  
        // Update next value of x 
        t0 = t0 + h; 
    } 
  
    outfile.close();
} 


void rungeKuttaVy(float t0, float yo, float t, float h) 
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((t - t0) / h); 
  
    float k1, k2, k3, k4, k5; 
    
  
    // Iterate for number of iterations 
    float y = yo; 
    
    string filename = "datavy.dat";
    ofstream outfile;
    outfile.open(filename);    
    
    for (int i=1; i<=n; i++) 
    { 
        // Apply Runge Kutta Formulas to find 
        // next value of y 
        k1 = h*vy(t0, y); 
        k2 = h*vy(t0 + 0.5*h, y + 0.5*k1); 
        k3 = h*vy(t0 + 0.5*h, y + 0.5*k2); 
        k4 = h*vy(t0 + h, y + k3); 
        
        outfile<<t<<" "<<y<<endl;
  
        // Update next value of y 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
  
        // Update next value of x 
        t0 = t0 + h; 
    } 
    
    outfile.close();

} 