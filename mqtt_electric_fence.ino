void setup() {
  // put your setup code here, to run once:

  const byte A0 = 32;
  const byte A1 = 33;
  const byte A2 = 34;
  const byte A3 = 35;

  Serial.begin(115200);
  pinMode(34, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int maxv[4];
  maxv[0] = 0;
  maxv[1] = 0;
  maxv[2] = 0;
  maxv[3] = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 4; j++) {
      int v = analogRead(j+32);
      if (v > maxv[j]) maxv[j] = v;
    }
    delay(1);
  }
  //Serial.printf("%d %d %d %d\n",  maxv[0], maxv[1], maxv[2], maxv[3]);
  int sum = maxv[0]+maxv[1]*2+maxv[3]*4+maxv[3]*8;
  Serial.printf("%d\n",sum);

delay(1000);
}
