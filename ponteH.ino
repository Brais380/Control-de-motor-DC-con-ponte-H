/*
* En este ejercicio debiamos simular el funcionamiento
* de una puente H con 4 Reles SPDT gobernaods por un pulsador 
* reactivo que nos permite cambiar el estado mediante una
* pulsación; Hay 5 estados diferentes el estado -1 o en reposo
* total al que se debera volver alcabo de 15s de los estados 1/3.
* Por el monitor serie deberan salir el estado y el valor de las salidas 
* en cada momento.
*
*  TABLA DE LA VERDAD                                         PERMITIDO 
*   R1 R2 R3 R4 | S |                                        |          |
*   0  0  0  0  | 0 | Parada por inercia                     |    S     |
*   0  0  0  1  | 0 |                                        |    S     |
*   0  0  1  0  | 0 |                                        |    S     |
*   0  0  1  1  | 0 | Paro inmediato                         |    S     |
*   0  1  0  0  | 0 |                                        |    S     |
*   0  1  0  1  | x | Cortocircuito                          |    N     |
*   0  1  1  0  | 1 | Marcha sentido horario / derecha       |    S     |
*   0  1  1  1  | X | Cortocircuito                          |    N     |
*   1  0  0  0  | 0 |                                        |    S     |
*   1  0  0  1  | 1 | Marcha sentido antihorario / izquierda |    S     |
*   1  0  1  0  | x | Cortocircuito                          |    N     |
*   1  1  0  0  | 0 | Paro inmediato                         |    S     |
*   1  1  0  1  | X | Cortocircuito                          |    N     |
*   1  1  1  0  | X | Cortocircuito                          |    N     |
*   1  1  1  1  | X | Cortocircuito                          |    N     |
*
* Rey Mirón Brais
* 23 / 04 / 2025
*/
// Se definen nombres para estradas y salidas
#define PUL 7
#define R1  8
#define R2  9
#define R4 10
#define R3 11

int tiempo = 20; 
int estado = -1; // Valor entero que varia de 0-4 en funcion del estado actual 
int contador = 0; // Contador para el regreso de estado a 0
bool r1 = 0; // Valor booleana de la salida 1
bool r2 = 0; // Valor booleana de la salida 2
bool r3 = 0; // Valor booleana de la salida 3
bool r4 = 0; // Valor booleana de la salida 4


void setup(){ // Se define que son entradas y que son salidas  
  pinMode(PUL, INPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  Serial.begin(9600); // Activación del monitor serie
}

void loop(){
  if(digitalRead(PUL)){ // Si se pulsa el pusador sucede:
    contador = 135; // Iniciar contador
    if(estado >= -1 && estado <= 4){ // Condicion de suma +1 al estado mientras sea <=5
      estado += 1;
    }
    if(estado == 4){ // Reiniciar estado al llegar a 5 para tener valores de 0-4
      estado = 0;
    }
  }
    while(digitalRead(PUL)){ // Esperar a que se suelte el pulsador
        delay (tiempo);
    }
      if(estado == 0){ // En caso de estado 1
        Rele(0, 1, 1, 0); // Llamada ala funcion Rele para acmbier valores (s1, s2, s3, s4)
        delay(tiempo); 
      }
      if(estado == 1){ // En caso de estado 2
        if(contador <= 135){ // Si el contador es menor o igual que 135:
          contador -= 1; // Desconta -1 a contador
          delay(50);
        }
        Rele(1, 1, 0, 0); // Llamada ala funcion Rele para acmbier valores (s1, s2, s3, s4)
        delay(tiempo);
      }
      if(estado == 2){ // En caso de estado 3
        Rele(1, 0, 0, 1); // Llamada ala funcion Rele para acmbier valores (s1, s2, s3, s4)
        delay(tiempo);
      }
      if(estado == 3){ // En caso de estado 4
        if(contador <= 135){ // Si el contador es menor o igual que 135:
          contador -= 1; // Desconta -1 a contador
          delay(50);
        }
        Rele(0, 0, 1, 1); // Llamada ala funcion Rele para acmbier valores (s1, s2, s3, s4)
        delay(tiempo);
      }
      if(estado == -1){ // En caso de estado 0
        if(digitalRead(PUL)){
          contador = 100;
          estado += 1;
        }
        Rele(0, 0, 0, 0); // Llamada ala funcion Rele para acmbier valores (s1, s2, s3, s4)
        delay(tiempo);
      }
      if(contador <= 0){ // Si contador == 0 / estado == 0
        estado = -1;
        delay(tiempo);
      }
  r1 = digitalRead(8); // Asociación de valores boleanos a cada salida para mostrar en monitor serie
  r2 = digitalRead(9);
  r3 = digitalRead(10);
  r4 = digitalRead(11);
  Serial.print(" Estado: "); Serial.print(estado); // Imprimir Estado y Salidas en el monitor serie 
  Serial.print("    ");
  Serial.print("Salidas S1/S2/S3/S4: "); Serial.print(r1); Serial.print(r2); Serial.print(r3); Serial.println(r4);
}  

void Rele(bool S1,bool S2,bool S3,bool S4){ // Funcion void Rele
  digitalWrite(R1, S1);
  digitalWrite(R2, S2);
  digitalWrite(R3, S3);
  digitalWrite(R4, S4);
}
