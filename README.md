# Merilnik-svetilnosti-LUX-meter
V tem projektu je predstavljen merilnik svetilnosti oziroma LUX meter, ki temelji na uporabi foto upora (LDR – Light Dependent Resistor) in mikrokrmilnika Arduino. Merilnik svetilnosti je naprava, ki omogoča merjenje intenzitete svetlobe v okolici ter prikaz izmerjenih vrednosti v uporabniku razumljivi obliki.

Za merjenje svetlobe je foto upor povezan v napetostni delilnik, ki spremembe njegove upornosti pretvarja v spremembe napetosti. Nastala analogna napetost se dovede na analogni vhod mikrokrmilnika Arduino, ki jo s pomočjo analogno-digitalnega pretvornika pretvori v digitalno vrednost. Program nato te podatke obdela in jih pretvori v približno vrednost svetilnosti, ki jo lahko prikažemo na serijskem monitorju, LCD-zaslonu ali drugi prikazovalni napravi.


Glavni cilj naloge je izdelati delujoč merilnik svetilnosti, raziskati delovanje foto upora ter prikazati postopek pretvorbe analognih signalov v uporabne podatke za nadaljnjo obdelavo. Ob tem želiva pridobiti praktične izkušnje pri povezovanju elektronskih komponent, programiranju mikrokrmilnika Arduino in interpretaciji merilnih rezultatov. Projekt predstavlja preprost, vendar učinkovit primer uporabe senzorjev za zaznavanje fizikalnih veličin v realnem okolju.

# KOSOVNICA
<img width="841" height="242" alt="image" src="https://github.com/user-attachments/assets/d30de1ad-809b-4d5b-b25b-066432567bc1" />






# SKICA VEZAVE V EASYEDA
<img width="1039" height="650" alt="Posnetek zaslona 2026-05-11 114841" src="https://github.com/user-attachments/assets/9f7e4abe-0380-40be-ac14-8c93c3550ec4" />

# SLIKA NAČRTA OHIŠJA
Skici vezave si lahko ogldate v repezitorju načrt_ohišja.png [klikni za ogled](načrt_ohišja.png) in načrt_pokrova.png [klikni za ogled](načrt_pokorva.png)

# KODA
Koda se nahaja v repezitorju koda.ino [klikni za ogled](koda.ino)

# POSNETEK DELOVANJA
posnetek se nahaja v repezitorju video.DELOVANJA.md [klikni za ogled](video.delovanja.md)

# A-TEST
A-test se nahaja v repezitorju a-test.pdf [klikni za ogled](a-test.pdf)

# KOMENTAR DELOVANJA
Projekt merilnika svetilnosti je bil uspešno izveden, saj sva izdelala napravo, ki s pomočjo foto upora zaznava spremembe svetlobe v okolici. Izmerjene vrednosti se obdelajo z mikrokrmilnikom Arduino in prikažejo na LCD zaslonu, LED diode pa uporabniku omogočajo hitro vizualno oceno osvetlitve prostora. Med izdelavo projekta sva pridobila praktično znanje s področja elektronike, uporabe senzorjev in programiranja mikrokrmilnikov. Ugotovila sva, da je mogoče z enostavnimi in cenovno dostopnimi komponentami izdelati učinkovit sistem za merjenje svetilnosti.

# MOŽNE IZBOLJŠAVE
* Samodejna kalibracija
* shranjevanje podatkov na pomnilniško kartico ali brezžični prenos podatkov na računalnik oziroma mobilno napravo
*  zaščitno ohišje, ki bi komponente zaščitilo pred poškodbami
*  uporaba drugih barv diod, ki bi bolj spominjale stanja svetlobe v oklici

# POSTOPEK KALIBRACIJE
Senzor sva kalibrerala s pomočjo referenčnega merilnika DT - 1309. Za zagotovitev čim bolj natančnih meritev svetilnosti sva kalibrirala foto upor. Najprej sva pri različnih stopnjah osvetlitve izmerila vrednosti ADC, ki jih je zaznal Arduino, nato pa sva iste svetlobne pogoje izmerila še z referenčnim lux metrom. Na podlagi pridobljenih podatkov sva določila štiri kalibracijske točke, ki povezujejo ADC vrednosti z dejanskimi vrednostmi svetilnosti v luksih (lx).




