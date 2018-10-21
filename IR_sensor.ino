/* Flame Sensor analog example.
Code by Reichenstein7 (thejamerson.com)

Flame Sensor Ordered from DX ( http://www.dx.com/p/arduino-flame-sensor-for-temperature-
detection-blue-dc-3-3-5v-118075?tc=USD&gclid=CPX6sYCRrMACFZJr7AodewsA-Q#.U_n5jWOrjfU )

To test view the output, point a serial monitor such as Putty at your arduino. 
*/

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 900;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
  int sensorReadingLeft = analogRead(A5);
	int sensorReadingCenter = analogRead(A3);
  int sensorReadingRight = analogRead(A4);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReadingCenter, sensorMin, sensorMax, 2, 0);
  Serial.println("Range: " + int(range));
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close Fire **");
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire **");
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    break;
  }
  delay(10);  // delay between reads
}