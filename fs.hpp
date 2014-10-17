#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class FS
{
  private:
    unsigned p_,q_,s_,it_,N_;
    bool comprobar_primo (unsigned n);
    
  public:
    FS();
    inline ~FS(){};
    unsigned get_p (void);
    unsigned get_q (void);
    unsigned get_s (void);
    unsigned get_it (void);
    unsigned get_N (void);
    void pedir_datos (void);
    unsigned gcd (unsigned a, unsigned b);
    void output (void);
};