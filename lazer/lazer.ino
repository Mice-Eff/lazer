int buz = 9; // пин пассивного зумера
#define foto 0 // аналоговый вход фоторезистора
#define rele 8 // пин реле
int button=5; // пин кнопки
int a = 0;
int b=0;
void setup(){
  pinMode(rele, OUTPUT);
  digitalWrite(rele, 0); // 1 для реле ,  0 для мосфета
  pinMode(buz, OUTPUT);
  pinMode(button, INPUT);
}

void loop(){
if(digitalRead(button) == HIGH && a==0 ){
    a=1;
}
       if(analogRead(foto) < 930 && a==1 ){ //  930 пороговое значение срабатывания ( диапозон от 0-1000, где 1000 засвет, 0 полная темнота)                                                 
      
        b=1;
        while(b==1&&a==1){
        digitalWrite(rele, HIGH); 
        delay(1000);
        tone(buz,2200,1000); 
        
        
          if( digitalRead(button) == HIGH ){      //  чтобы отключить сигнализация надо  нажать на кнопку                                        
             a=2;         
             digitalWrite(rele,LOW);         
             delay(5000);
           
         }
        }
       }
                   if(digitalRead(button) == HIGH && a==2 ){
                      a=0;
} 
     
     
 
}

// CREATED by MICE EFF 

  



              


            

 
   
       
      
                          
    
      
