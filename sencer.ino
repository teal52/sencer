const int  echoPin = 2;
const int trigPin = 3;
const int LED = 13;




double Duration = 0; //受信した間隔
double Distance = 0; //距離
int Distance-output = 20;

void setup() {
Serial.begin( 9600 );
pinMode( echoPin, INPUT ); 
pinMode( trigPin, OUTPUT );
pinMode(LED,OUTPUT);
}


void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite( trigPin, HIGH ); //超音波を出力
  delayMicroseconds( 10 ); //
  digitalWrite( trigPin, LOW );

  
  Duration = pulseIn( echoPin, HIGH ); //センサからの入力
  
  if (Duration > 0) {
    Duration = Duration/2; //往復距離を半分にする
    Distance = Duration*340*100/1000000; // 音速を340m/sに設定
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
  }

  if(Distance < Distance-output){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
  
  delay(100);
}
