#include<stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int e89_putchar(char c )
{
  return(write(1, &c, 1 ) > 0);
}

void e89_putstr(char *s)
{
  int i ;
  i = 0 ;
  while(s[i])
    {
      e89_putchar(s[i]);
      i = i +1 ;
    }

}

int printbase10(int nbr)
{
  if(nbr != 0)
    {
      int i ;
      i = 0 ;
      if(nbr < 0)
	    {
	      e89_putchar('-');
	      nbr = nbr *-1 ;
	      printbase10(nbr);
	    }
      else
	    {
	      printbase10(nbr/10);
	      e89_putchar((nbr%10)+ '0');
	    }
    }
  return(0);
}


int printbaseNegatif(int nbr)
{

  if(nbr != 0)
    {
      int i ;
      i = 0 ;
      if(nbr < 0)
            {
              nbr = nbr *-1 ;
              printbaseNegatif(nbr);
            }
      else
            {
              printbaseNegatif(nbr/10);
              e89_putchar((nbr%10)+ '0');
            }
    }
  return(0);
}

char *convert(unsigned int nbr, int base)
{
    static char tab[]= "0123456789ABCDEF";
    static char buffer[17];
    char *ptr = NULL;

    ptr = &buffer[16];
    *ptr = '\0';

    do{
      ptr = ptr - 1 ;
      *ptr = tab[nbr%base];
      nbr = nbr/base ;
    }while (nbr != 0);
    return(ptr);
}

void Myprintf(char* format,...)
{
    char *str ;
    unsigned int i ;
    char *s ;
    int b ;
    double db ;

    i = 0 ;
    b = 0;
    db = 0 ;
    va_list arg;
    va_start(arg, format);
    str = format ;

    while(str[b] != '\0')
    {
        if(str[b] == '%' )
        {
            if(str[b + 1] == 'c')
            {
                i = va_arg(arg,int);
                e89_putchar(i);
            }
            if(str[b + 1] == 's')
            {
                s = va_arg(arg,char *);
                e89_putstr(s);
            }
            if(str[b + 1] == 'd')
            {
                i = va_arg(arg,int);
                s = convert(i,10);
                e89_putstr(s);
            }
            if(str[b + 1] == '%')
            {
                e89_putchar('%');
            }
            if(str[b + 1] == 'p')
            {
              i = va_arg(arg,int);
              s = convert(i,16);
              e89_putstr(s);
            }
            if(str[b+1] == 'f'){
              db = va_arg(arg,double);
              if(db > 0){
                printbase10(db);
                e89_putchar('.');
                db = db * 100;
                printbase10((int)db%100);
              }
              else{
                printbase10(db);
                e89_putchar('.');
                db = db * 100;
                printbaseNegatif((int)db%100);
              }
            }
          b = b + 1;
        }
        else
        e89_putchar(str[b]);
        b = b + 1;
    }
    va_end(arg);
}
