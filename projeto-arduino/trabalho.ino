/* ==================================================================================================================

   Sensor de Turbidez com Arduino

   Autores: Maria Tereza, Eduardo Santiago, Ivan Santos, Gustavo Nogueira, Alessandro Josino, Jefferson Santana

   Data: Setembro de 2023


   A turbidez pode ser entendida como a medida do espalhamento 
   de luz produzido pela presença de partículas em suspensão ou coloidais, 
   sendo expressa como Unidade Nefelométrica de Turbidez 
   (NTU – Nephelometric Turbidity Unity).

   Nefelometria:
   Processo de medida da concentração de uma emulsão por comparação 
   de sua transparência com a de uma preparação padrão.


   Cálculo para o sensor de Turbidez

   https://www.dfrobot.com/wiki/index.php/File:Relationship_diagram.jpg


   Hardware:

   Arduino     Sensor de Turbidez

   5V          V
   GND         G
   A0          A


================================================================================================================== */


// ==================================================================================================================
// --- Protótipo das Funções ---
double calc_NTU(double volt);


// ==================================================================================================================
// --- Variáveis Globais ---
double NTU = 0.0;


// ==================================================================================================================
// --- Configurações Iniciais ---
void setup() 
{
  Serial.begin(115200);

  
} //end setup


// ==================================================================================================================
// --- Loop Infinito ---
void loop() 
{
  int sensorValue = analogRead(A0); 
  float voltage = sensorValue * (5.0 / 1024.0);  

  NTU = calc_NTU(voltage);
  
  Serial.print(voltage);  
  Serial.print(" | ");
  Serial.println(NTU);

  
  delay(741);
  
} //end loop


// ==================================================================================================================
// --- Função para conversão de tensão para Turbidez em NTU ---
//
// Equação que relaciona tensão com NTU: NTU = -1120,4*volt*volt + 5742,3*volt - 4352,9
//
double calc_NTU(double volt)
{

  double NTU_val;

  NTU_val = -(1120.4*volt*volt)+(5742.3*volt)-4352.9;

  return NTU_val;
  
  
} //end calc_NTU







