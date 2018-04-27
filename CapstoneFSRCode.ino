/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // the analog reading from the FSR resistor divider
int fsrAnalogPin1 = 1;
int fsrReading1;
int fsrAnalogPin2 = 2;
int fsrReading2;
int fsrAnalogPin3 = 3;
int fsrReading3;
int numEggs;
int fsrAnalogPin4 = 4;
int fsrReadingMilk;
int fsrAnalogPin5 = 5;
int fsrReadingMilk1;
int milkPercent;
int milkPercent1;
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  numEggs = 0;
  fsrReading = analogRead(fsrAnalogPin);
  fsrReading1 = analogRead(fsrAnalogPin1);
  fsrReading2 = analogRead(fsrAnalogPin2);
  fsrReading3 = analogRead(fsrAnalogPin3);
  fsrReadingMilk = analogRead(fsrAnalogPin4);
  fsrReadingMilk1 = analogRead(fsrAnalogPin5);
  
  if (fsrReading > 3) {
    numEggs= numEggs + 1;
  } 
  if (fsrReading1 > 3) {
    numEggs = numEggs + 1;
  } 
  if (fsrReading2 > 3) {
    numEggs = numEggs + 1;
  } 
  if (fsrReading3 > 3){
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
  if (fsrReadingMilk > 100) {
        milkPercent = 50;
  } 
  if (fsrReadingMilk > 350) {
        milkPercent = 98;
  }
  if (fsrReadingMilk1 <4){
    milkPercent1 = 0;
  }
  if (fsrReadingMilk1 >4){
     if (fsrReadingMilk1 <100){
        milkPercent1 = 5;
      
     }
  }
  if (fsrReadingMilk1 > 100) {
        milkPercent1 = 50;
  } 
  if (fsrReadingMilk1 > 350) {
        milkPercent1 = 98;
  }
  
  
 // Serial.print("Analog reading 0 = ");
 // Serial.println(fsrReading);
 // Serial.print("Analog reading 1 = ");
 // Serial.println(fsrReading1);
 // Serial.print("Analog reading 2 = ");
 // Serial.println(fsrReading2);
 // Serial.print("Analog reading 3 = ");
 // Serial.println(fsrReading3);
 // Serial.print("Analog reading 4 = ");
 // Serial.println(fsrReadingMilk);
 // Serial.print("Analog reading 5 = ");
 // Serial.println(fsrReadingMilk1);
  
  //Serial.print("\n Number of eggs = ");
  Serial.println(numEggs);
  //Serial.print("Percentage of Milkin First Slot: " );
  //if (milkPercent == 0){
      //Serial.print(" No Milk Container Found in First Slot \n");
  //}
  Serial.println(milkPercent);
  //Serial.print("Percentage of Milk in Second Slot: " );
  //if (milkPercent1 == 0){
  //    Serial.print(" No Milk Container Found in Second Slot \n");
  //}
  Serial.println(milkPercent1);
  delay(1000);
}
