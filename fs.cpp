#include "fs.hpp"

FS::FS (void)
{
  p_= 0; q_= 0; it_=0; N_= 0; s_=0;
}

unsigned FS::get_p (void)
{
  return p_;
}

unsigned FS::get_q (void)
{
  return q_;
}

unsigned FS::get_s (void)
{
  return s_;
}

unsigned FS::get_it (void)
{
  return it_;
}

unsigned FS::get_N (void)
{
  return N_;
}

bool FS::comprobar_primo (unsigned n)
{
  unsigned a=0;
  for (unsigned i=1; i<(n+1); i++) //empiezo en 2 pq por 1 son todos divisibles
  {
      if(n%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
      a++;
  }
  if (a==2) //solo tiene dos divisores: 1 y si mismo
    return true;
  else //tiene mas de un divisor, no es primo
    return false;
}


unsigned FS::gcd (unsigned a, unsigned b)
{
//   unsigned a= n1;
  unsigned swap_a;
//   unsigned b= n2;
  while (b != 0)
  {
    swap_a=b;
    b = a%b;
    a = swap_a;
  }
  return a; 
}


void FS::pedir_datos (void)
{
    unsigned n;
    do
    {
      cout<<"Introduce el valor de p (debe ser un nº primo): ";
      cin>>n;
    }while (!comprobar_primo(n));   //comprobamos que el numero introducido es primo
    p_ = n;
    do
    {
      cout<<"Introduce el valor de q (debe ser un nº primo): ";
      cin>>n;
    }while (!comprobar_primo(n));   //comprobamos que el numero introducido es primo
    q_ = n;
    N_= p_*q_;
    do
    {
	cout<<"Introduce el valor de s (0<s<N) y es primo con N ";
	cout<<"(N = "<<N_<<"): ";
	cin>>n;
	if (gcd(n,N_)!=1)
	  cout<<"El num elegido y N no son primos entre si!"<<endl;
    } while ((n <= 0) || (n >= N_) || (gcd(n,N_)!=1));
    s_= n;
    cout<<"Numero de iteraciones? :";
    cin>>it_;
}

void FS::output (void)
{
//   float v= (s_*s_)%N_; //me da error de esta forma asi q lo calculo el mod paso por paso
  float v= pow(s_,2) - (trunc(pow(s_,2)/N_)*N_);
  cout<<"A elige s = "<<s_<<" y publica v = "<<v<<endl;
  
  for (unsigned i=0; i<it_;i++)
  {
      cout<<"\n"<<i+1<<"ª iteracion:"<<endl;
      unsigned long x,y;
      do
      {
	  cout<<"Introduce el valor compromiso de A (0<x<"<<N_<<"): ";
	  cin>>x;
      } while ((x<1)||(x>(N_-1)));
      unsigned long a = (x*x)%N_;
      cout<<"\tA elige x = "<<x<<", y envia a B a = "<<a<<endl;
      
      srand (time(NULL));
//       unsigned e = rand() % 2;
      short e; cout<<"e? : "; cin>>e;
      cout<<"\tReto: B envia a A: e= "<<e<<endl;
      
      float r;
      if (e==0)
      {
	y = x%N_;
	r = a%N_;
      }
      else
      {
	y = (x*s_)%N_;
// 	r = (a*v)%N_;
	r = (a*v) - (trunc((a*v)/N_)*N_);
      }
      float y2 = (pow(y,2)) - (trunc(pow(y,2)/N_)*N_);
      if (y2==r)
	cout<<"\tB acepta la identificacion porque y= "<<y<<", y^2= "<<y2<<" = "<<r<<" = ("<<a<<"*"<<v<<")%"<<N_<<" = (av^e)modN"<<endl;
      else
	cout<<"\tB rechaza la identificacion porque y= "<<y<<", y^2= "<<y2<<" <> "<<r<<" = ("<<a<<"*"<<v<<")%"<<N_<<" = (av^e)modN"<<endl;
  }
}

