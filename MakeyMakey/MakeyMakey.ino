#define NUM_INPUTS 5

int codes[NUM_INPUTS] = {
  KEY_UP_ARROW,      // up arrow pad
  KEY_DOWN_ARROW,    // down arrow pad
  KEY_LEFT_ARROW,    // left arrow pad
  KEY_RIGHT_ARROW,   // right arrow pad
  ' '               // space button pad
};

int pins[NUM_INPUTS] = {
  10,   // left arm
  11,   // right leg
  5,    // right arm
  9,    // left leg
  13    // head
};

float values[NUM_INPUTS] = {
  1.0,   // left arm
  1.0,   // right leg
  1.0,    // right arm
  1.0,    // left leg
  1.0    // head
};

boolean pressed[NUM_INPUTS] = {
  false,   // right arm
  false,   // left leg
  false,   // left arm
  false,   // right leg
  false    // head
};


void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  
  for(int i = 0; i < NUM_INPUTS; i++){
   
   digitalWrite(pins[i], LOW);
   
  }
}

void loop(){
  for(int i = 0; i < NUM_INPUTS; i++){
    pinMode(pins[i], INPUT);
    delay(1);
    float v = digitalRead(pins[i]);
    
    values[i] = values[i] * 0.9 + v * 0.1;    
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
     
    boolean over = values[i] > 0.2;
   //Serial.print(over);
    //Serial.print(" | ");
    
    if(!over && !pressed[i]){
      pressed[i] = true;
      //Serial.print("press ");
      //Serial.println(i);
      Keyboard.press(codes[i]);
    }
    else if(over  && pressed[i]){
      pressed[i] = false;
      //Serial.print("release ");
      //Serial.println(i);
     Keyboard.release(codes[i]);
    }
  }
//Serial.println(" ");
       
}               
