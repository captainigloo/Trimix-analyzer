
/*********************************************************************************************\
 * Arduino project "trimix-analizer.ino"
\*********************************************************************************************/
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <RunningAverage.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display
Adafruit_ADS1115 ads; // convertisseur analogique --> digital ADS1115
// variables will change:
float TensionCalib = 0; // mise a 0 de la tension de calibrage de la cellule
float voltage = 0; // tension mesuree sur cellule
float wheatstone = 0; // tension sur pont de wheatsone
float gain = ; // gain du convertisseur ADS1115
float calibMD62 = ; // valeur de la tension du pont avec 100% helium
float WheatCalib = 10; // mise a 0 de la tension de calibrage du pont à l'air
float CorrFroid = 0 ; // correction de lecture du fait de lecture a froid (capteur pas assez chaud)
unsigned long time; // mesure du temps depuis allumage pour ajuster correction
RunningAverage RA0(10); // moyennage O2 sur 10 valeurs
RunningAverage RA1(10); // moyennage He sur 10 valeurs

/*********************************************************************************************\
 * SETUP
\*********************************************************************************************/
void setup()
{
for(i = 1; i <10 or (abs (voltage - (tensionMoyenne / (i-1)))) > 0.001; i++)
{
adc0 = ads.readADC_Differential_0_1();
RA0.addValue(adc0);
voltage = abs(RA0.getAverage()*gain);
tensionMoyenne = tensionMoyenne + voltage;
delay(200);
}
lcd.clear();
lcd.setCursor(0,1);
lcd.print(" Calibrage OK");
tensionMoyenne = tensionMoyenne / (i - 1);
TensionCalib = tensionMoyenne;
lcd.setCursor(0,2);
lcd.print("V calib = ");
lcd.print(TensionCalib,2);
lcd.print("mV");
delay(2000);
lcd.setCursor(0,0);
lcd.print("Prechauffage du");
lcd.print(" capteur Helium...");
delay(500);
while(wheatstone > 10){
adc1 = ads.readADC_Differential_2_3();
RA1.addValue(adc1);
wheatstone = RA1.getAverage()*gain;
lcd.setCursor(4,3);
lcd.print("Vpont=");
lcd.print(wheatstone,0);
lcd.print("mV ");
delay(50);
lcd.print(" Capteur He OK");
void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
lcd.begin();
lcd.backlight();
lcd.print(" Analyseur Trimix");
ads.setGain(GAIN_FOUR); // 4x gain 1 bit = mV
ads.begin();
int16_t adc0;
int16_t adc1;
adc0 = ads.readADC_Differential_0_1();
RA0.addValue(adc0);
voltage = abs(RA0.getAverage()*gain);
adc1 = ads.readADC_Differential_2_3();
RA1.addValue(adc1);
wheatstone = RA1.getAverage()*gain;
// affichage de la tension
lcd.setCursor(0,2);
lcd.print("V cell = ");
lcd.print(voltage,2);
lcd.print("mV");
lcd.setCursor(0,3);
lcd.print("V pont = ");
lcd.print(wheatstone,2);
delay(2000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print(" Calib. en cours ...");
lcd.print("(utiliser de l'air)");
// determination de la tension moyenne de la cellule à l'air libre
int i = 0;
float tensionMoyenne = 0;
