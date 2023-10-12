Willkommen bei Petsi's DigiKlo!

Den Blogartikel zum Projekt "Mikrocontrollergestütztes experimentelles Kacken" findest du hier: https://derpetsi.de/2023-10-09-die-prozessorgesteuerte-trenntoilette.html

Die hier abgelegten Programme steuern jeweils die Relais, die die Getriebemotoren am Feststoffbehälter (->Kokosfasern und Kaka) meiner Trenntoilette mit 12V Spannung versorgen. Ich benutzte einen D1 mini ESP8266, der ist günstig, hat WLAN und mehr Anschlüsse als nötig - naja, je nach Ausbaustufe... ;-)

DigiKlo_1.5-arduino.ino wird über das Arduino Programm angepasst und auf den ESP übertragen. Es beinhaltet mehrere Rührprogramme, die durch die Länge des Tastendrucks ausgewählt werden, sowie die Ansteuerung einer Spülpumpe für das Urinal. Mehr nicht. Die Ersteinrichtung der Arduino Software fand ich nervig (u.A. wg. D1 mini), daher -und wegen Home Assistant im Wohnmobil- benutze ich jetzt hauptsächlich ESPHome. 

DigiKlo_2.0_ESPHome.yaml wird über ESPHome (sogar online!) auf den ESP geflasht. BME280 für Temperatur, Luftfeuchtigkeit und Luftdruck.
DigiKlo_2.1.yaml bezieht von Home Assistant die Uhrzeit und rührt alle 2 Stunden zur vollen Stunde automatisch. Ich überlege derzeit, ob rückwärts rühren im Automatikmodus nicht sinnvoller wäre. Die Praxis wird es zeigen. 



Viel Spaß mit dem DigiKlo und allezeit eine gesunde Verdauung!
Der Petsi
