int licznik = 0;
int wartosc = 0;
int zmiana = 1;

void setup()
{
    for (int i = 3; i < 13; i++)
        pinMode(i, OUTPUT);
    attachInterrupt(0, GdyPrzyciskStart, RISING);
    pinMode(A0, INPUT);
}

void loop()
{
    wartosc = map(analogRead(A0), 0, 1023, 0, 1000);

    digitalWrite(12, HIGH);

    cyfra(wartosc % 10);
    digitalWrite(10, LOW);
    delay(10);
    digitalWrite(10, HIGH);

    cyfra(wartosc % 100 / 10);
    digitalWrite(11, LOW);
    delay(10);
    digitalWrite(11, HIGH);

    cyfra(wartosc / 100);
    digitalWrite(12, LOW);
    delay(10);
}

void GdyPrzyciskStart()
{
    zmiana *= -1;
}

//Przerwanie resetujace wylaczenie diody
void cyfra(int liczba)
{
    switch (liczba)
    {
    case 0:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        break;
    case 1:
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        break;
    case 2:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        break;
    case 3:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        break;
    case 4:
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        break;
    case 5:
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        break;
    case 6:
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        break;
        break;
    case 7:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        break;
    case 8:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        break;
    case 9:
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        break;
    }
}
