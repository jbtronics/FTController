# FTController

Der FTController ist eine Motorsteuerung hauptsächlich entwickelt für Fischertechnik. Mittels zweier Joysticks lassen sich 4 analoge Motorausgänge, plus ein Digitalausgang steuern.

## Funktionen
* 4 (bipolare) Analoge Motorausgänge, verschiedene Übertragungsfunktionen auswählbar (digital, linear, quadratisch, logarithmisch, etc.)
* 1 (unipolarer) Digitaler Leistungsausgang (schaltbar über rechten Joysticktaster)
* 1 Impulszähleingang, für Frequenz oder Umdrehungszahlmessung (mit einstellbarem Multiplikator und Teilungsverhältnis)
* Eingangsspannung und Ausgangsstrommessung
* Virtuelle Einrastfunktion: Wird während der Bedienung der Joysticks der linke Joystick doppelt gedrückt, so wird der aktuelle Wert eingefroren (d.h. der Motorwert wird beibehalten auch wenn der Stick losgelassen wird)
* Ansteuermöglichkeit für Raupenketten (Vor/Rück, Links/Rechts-Bewegung an den Joysticks wird auf Raupenkettenantrieb umgesetzt)
* Möglichkeit zur Funkübertragung vorgesehen, d.h. zukünftig auch drahtlose Steuerung möglich.

## Technische Daten
* Eingangsspannungsbereich: 7 - 15 V; Empfohlen: 8 - 10V
* Strombelastbarkeit (Summe aller Ausgänge): max 1,5A
* Strombelastbarkeit *OUT*-Ausgang: max. 500mA
* ATMega328 als Steuerung, d.h. Firmware-Updates via ISP möglich
* Software Arduino kompatibel

## Lizenzen
Für Details siehe `LICENSE.md` in den entsprechenden Verzeichnissen.
* Software: Die Software steht unter der General Public License 3.0
* Hardware: Die Design-Files für die Hardware stehen unter "Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)"

## Benötigte Bauteile
[Hier](https://hackaday.io/project/20349/components) kann eine Liste benötigter Bauteile gefunden werden. Keine Garantie auf Vollständigkeit, sicherer ist der Schaltplan oder die interaktive Bauteileliste die unter `hardware/bom` gefunden werden kann.

## Galerie:
### PCB:
![PCB1](https://github.com/jbtronics/FTController/raw/master/hardware/export/renderings/PCB/top.png)
![PCB2](https://github.com/jbtronics/FTController/raw/master/hardware/export/renderings/with_parts/1.png)

### Fertiges Gerät:
![finished1](https://github.com/jbtronics/FTController/raw/master/documentation/pictures/pic5.jpg)
![finished2](https://github.com/jbtronics/FTController/raw/master/documentation/pictures/pic2.jpg)