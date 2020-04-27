int licznik = 1;

void setup()
{
    pinMode(3, OUTPUT); //Ustawienie wyjscia
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);                         //Ustawienie stanu na wyjsciu
    attachInterrupt(0, GdyPrzyciskStart, RISING); // D e f i n i c j a przerwania
}

void loop()
{
    delay(250);
    digitalWrite(3, HIGH); //Wlaczenie diody
    delay(250);
    digitalWrite(3, LOW); //Wylaczenie diody
    if(licznik < 10)
        licznik++;
    else digitalWrite(4, HIGH); //Wylaczenie diody po 10 mignieciach
}

void GdyPrzyciskStart()
{
    licznik = 1;
    digitalWrite(4, LOW);
}