boolean buttonWasUp = true;
boolean ledEnabled = false;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  
 boolean buttonIsUp = digitalRead(2); //кнопка отпущена?
 
 if(buttonWasUp&&!buttonIsUp)
 {
  delay(10);  //исключаем дребезк контактов кнопки 
  buttonIsUp = digitalRead(2); //считываем сигнал снова
   
   if(!buttonIsUp)  //если кнопка нажата, то переворачиваем сигнал светодиода
   {
    ledEnabled = !ledEnabled;
    digitalWrite(10, ledEnabled); 
    }
  }
  
  buttonWasUp=buttonIsUp; //запоминаем состояние кнопки для новой итерации 
}
