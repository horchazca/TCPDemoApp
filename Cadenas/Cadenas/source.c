#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

//Función para procesar la cadena de texto recibida
void ProcesaCad(char data[200], double vars[4])
{
	// Declaramos las variables
    int pos = 0;
    int pc = 0;
    int i = 0;
	int cnt = 0;

    char cad01[50] = "";
    char cad02[50] = "";
    char cad03[50] = "";
    char cad04[50] = "";
    char cadN01[50] = "";
    char cadN02[50] = "";
    char cadN03[50] = "";
    char cadN04[50] = "";

	double xf;
	double yf;
	double xaf;
	double yaf;

	double numerales[50];
	double mult = 1/1000;
    
    // Recorremos la cadena para sacar cada uno de los miembros
    for(i = 0;  i < 200 && data[i] != '\0'; i++)
    {
        //Comenzamos checando la posicion
        if(pos == 0)
        {
            if(data[i] == '&')
            {
                cad01[pc] = '\0';
                pos = 1;
                pc = 0;
            }
            else
            {
                cad01[pc] = data[i];
                pc++;
            }
        }
        else if(pos == 1)
        {
            if(data[i] == '&')
            {
                cad02[pc] = '\0';
                pos = 2;
                pc = 0;
            }
            else
            {
                cad02[pc] = data[i];
                pc++;
            }
        }
        else if(pos == 2)
        {
            if(data[i] == '&')
            {
                cad03[pc] = '\0';
                pos = 3;
                pc = 0;
            }
            else
            {
                cad03[pc] = data[i];
                pc++;
            }
            
        }
        else if(pos == 3)
        {
            if(data[i] == '&')
            {
                cad04[pc] = '\0';
                pos = 4;
                pc = 0;
            }
            else
            {
                cad04[pc] = data[i];
                pc++;
            }
        }
        else
        {
            // ERROR
			break;
        }
    }

	// Hasta es punto tenemos las cadenas formadas
	// Ahora, le quitamos las primeras letras

	// Ahora, identificamos a qué miembro corresponde cada una:
	// Verificamos la cadena 1
	xf = 0;
	yf = 0;
	xaf = 0;
	yaf = 0;

	for(i = 0; i < 50; i++)
	{
		numerales[i] = 0;
	}

	if(cad01[0] == 'x' && cad01[1] == 'f')
	{
		// Este es el caso ideal...
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad01[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad01[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xf = xf + (numerales[i]*mult);
		}
	}
	else if(cad01[0] == 'y' && cad01[1] == 'f')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad01[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad01[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yf = yf + (numerales[i]*mult);
		}
	}
	else if(cad01[0] == 'x' && cad01[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad01[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad01[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xaf = xaf + (numerales[i]*mult);
		}
	}
	else if(cad01[0] == 'y' && cad01[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad01[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad01[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yaf = yaf + (numerales[i]*mult);
		}
	}
	else
	{
		//Error
		xf = yf = xaf = yaf = -99;
	}

	for(i = 0; i < 50; i++)
	{
		numerales[i] = 0;
	}

	// Vamos con la segunda cadena
	if(cad02[0] == 'x' && cad02[1] == 'f')
	{
		// Este es el caso ideal...
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad02[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad02[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xf = xf + (numerales[i]*mult);
		}
	}
	else if(cad02[0] == 'y' && cad02[1] == 'f')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad02[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad02[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yf = yf + (numerales[i]*mult);
		}
	}
	else if(cad02[0] == 'x' && cad02[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad02[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad02[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xaf = xaf + (numerales[i]*mult);
		}
	}
	else if(cad02[0] == 'y' && cad02[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad02[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad02[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yaf = yaf + (numerales[i]*mult);
		}
	}
	else
	{
		//Error
		xf = yf = xaf = yaf = -99;
	}

	for(i = 0; i < 50; i++)
	{
		numerales[i] = 0;
	}

	// Vamos con la tercer cadena
	if(cad03[0] == 'x' && cad03[1] == 'f')
	{
		// Este es el caso ideal...
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad03[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad03[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xf = xf + (numerales[i]*mult);
		}
	}
	else if(cad03[0] == 'y' && cad03[1] == 'f')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad03[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad03[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yf = yf + (numerales[i]*mult);
		}
	}
	else if(cad03[0] == 'x' && cad03[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad03[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad03[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xaf = xaf + (numerales[i]*mult);
		}
	}
	else if(cad03[0] == 'y' && cad03[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad03[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad03[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yaf = yaf + (numerales[i]*mult);
		}
	}
	else
	{
		//Error
		xf = yf = xaf = yaf = -99;
	}

	for(i = 0; i < 50; i++)
	{
		numerales[i] = 0;
	}

	// Vamos con la cuarta cadena
	if(cad04[0] == 'x' && cad04[1] == 'f')
	{
		// Este es el caso ideal...
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad04[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad04[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xf = xf + (numerales[i]*mult);
		}
	}
	else if(cad04[0] == 'y' && cad04[1] == 'f')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad04[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad04[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yf = yf + (numerales[i]*mult);
		}
	}
	else if(cad04[0] == 'x' && cad04[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad04[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad04[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, xaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			xaf = xaf + (numerales[i]*mult);
		}
	}
	else if(cad04[0] == 'y' && cad04[1] == 'a')
	{
		// Cuando esto sucede, ahora sacamos los números
		for(i = 2; cad04[i] != '\0' && i < 50; i++)
		{
			numerales[i - 2] = cad04[i] - 48;
		}

		//Ahora, ya que se tienen los numerales, los sumamos...
		for(i = i - 3, mult = 1.0/1000, yaf = 0; 0 <= i; i--, mult = mult * 10)
		{
			yaf = yaf + (numerales[i]*mult);
		}
	}
	else
	{
		//Error
		xf = yf = xaf = yaf = -99;
	}

	vars[0] = xf;
	vars[1] = yf;
	vars[2] = xaf;
	vars[3] = yaf;

}

int main()
{
	double vars[4];

	ProcesaCad("yf51254&xa45145&xf125362&ya388975", vars);

	printf("Los valores son: %f, %f, %f, %f\n", vars[0], vars[1], vars[2], vars[3]);

	system("pause");

	return 0;
}