#define PRETO 40

#define sensor_direita SENSOR_2
#define sensor_esquerda SENSOR_1

void movToRight(){
	Off(OUT_A+OUT_C);
	OnRev(OUT_A);
	OnFwd(OUT_C);
}

void movToLeft(){
	Off(OUT_A+OUT_C);
	OnFwd(OUT_A);
	OnRev(OUT_C);

}

void walkingFront(){
	Off(OUT_A+OUT_C);
	OnFwd(OUT_A+OUT_C);
}

void walkingBack(){
	Off(OUT_A+OUT_C);
	OnRev(OUT_A+OUT_C);
}

task main(){

     SetSensor(SENSOR_1, SENSOR_LIGHT);
     SetSensor(SENSOR_2, SENSOR_LIGHT);

	while(true){
		// Saindo um pouco para direita
		if(sensor_direita > PRETO && sensor_esquerda < PRETO){
			movToLeft();
			Wait(10);
		}

		//saindo um pouco para a esquerda
		if(sensor_direita < PRETO && sensor_esquerda > PRETO){
			movToRight();
			Wait(10);
		}
		if(sensor_direita > PRETO && sensor_esquerda > PRETO){
			walkingFront();
			Wait(10);
		}

		if(sensor_direita < PRETO && sensor_esquerda < PRETO){
			walkingBack();
			Wait(10);
		}

	}
}