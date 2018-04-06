/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // the analog reading from the FSR resistor divider
int fsrAnalogPin4 = 2;
int fsrReadingMilk;
int fsrAnalogPin2 = 3;
int fsrReading2;
int fsrAnalogPin3 = 5;
int fsrReading3;
int numEggs;
int milkPercent;
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  numEggs = 0;
  fsrReading = analogRead(fsrAnalogPin);
  fsrReading2 = analogRead(fsrAnalogPin2);
  fsrReading3 = analogRead(fsrAnalogPin3);
  fsrReadingMilk = analogRead(fsrAnalogPin4);
  
  if (fsrReading > 3) {
    numEggs= numEggs + 1;
  } 
  if (fsrReading2 > 3) {
    numEggs = numEggs + 1;
  } 
  if (fsrReading3 > 3) {
    numEggs = numEggs + 1;
  } 
  if (fsrReadingMilk <4){
    milkPercent = 0;
  }
  if (fsrReadingMilk >4){
     if (fsrReadingMilk <100){
        milkPercent = 5;
      
     }
  }
  if (fsrReadingMilk > 160) {
        milkPercent = 50;
  } 
  if (fsrReadingMilk > 265) {
        milkPercent = 98;
  }
  
 // Serial.print("Analog reading 2 = ");
 // Serial.println(fsrReading);
 // Serial.print("Analog reading 1 = ");
 // Serial.println(fsrReading2);
 // Serial.print("Analog reading 3 = ");
 // Serial.println(fsrReading3);
  Serial.print("\n Number of eggs = ");
  Serial.println(numEggs);
  Serial.print("Percentage of Milk: " );
  if (milkPercent == 0){
      Serial.print(" No Milk Container Found \n");
  }
  else Serial.println(milkPercent);
  
  

  
  delay(1000);
}
