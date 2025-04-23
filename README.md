# Control-de-motor-DC-con-ponte-H

/*
* En este ejercicio debiamos simular el funcionamiento
* de una puente H con 4 Reles SPDT gobernaods por un pulsador 
* reactivo que nos permite cambiar el estado mediante una
* pulsación; Hay 5 estados diferentes el estado 0 o en reposo
* total al que se debera volver alcabo de 15s de los estados 2/4.
* Por el monitor serie deberan salir el estado y el valor de las salidas 
* en cada momento.
+
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
