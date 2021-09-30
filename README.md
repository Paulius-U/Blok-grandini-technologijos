# Blok-grandiniu-technologijos

# Uzduotis

Sukurti hash funkcija 

1. Nuskaitomas failas gali buti bet kokio dydzio
2. gaunamas hash turi buti 256 bitu arba 64 simboliu 
3. naudojant ta pati faila gaunamas visada tas pats hash
4. taciau jei failo duomenys pasikecia bet vienu simboliu musu hash pasikeicia labai daug

# Programos veikimo principas:
pasileidus programą iveskite skaiciu nuo 1 iki 5 koki darba norite atlikti
![image](https://user-images.githubusercontent.com/75576100/135520165-cd5c9a52-1cdd-4167-a301-d26aa0f6d192.png)

veliau iveskite nuskaityti failo varda
![image](https://user-images.githubusercontent.com/75576100/135520396-b8065ca3-01af-4bdd-9c81-71d76d23e08b.png)

Pasirinkus faila a.txt kuriame yra tik vienas simbolis gauname rezultata 
![image](https://user-images.githubusercontent.com/75576100/135521162-dc6e7703-4765-43cb-bc1a-6447e36aee6f.png)

Taciau pasirinke b.txt gauname visiškai kitoki atsakyma
![image](https://user-images.githubusercontent.com/75576100/135521288-80fffb5b-d7fe-4d1f-a8ed-69755643580f.png)

Toliau mes galime patikrinti ar panašus efektas bus kai paimsime du failus kurie yra visiskai vienodi taciau viename yra įrašytas vienas atsitiktinai pasirinktas simbolis
![image](https://user-images.githubusercontent.com/75576100/135521571-c7a348aa-bddf-403e-b6ab-43ec8597ab31.png)
![image](https://user-images.githubusercontent.com/75576100/135521645-aa14ca18-b53e-419c-849a-711afaddfedf.png)

Žinome mes galime patikrinti ar hash bus pana6us kai du failus kurie visiškai skiresi viena nuo kito suhašuosime
Dokumentas apie Lord of the Rings informaciją iš wiki 
![image](https://user-images.githubusercontent.com/75576100/135522017-c79c4e72-689e-434b-b0f4-6cac819d0674.png)

Kitas dokumentas turintis informaciją apie juokelius
![image](https://user-images.githubusercontent.com/75576100/135522175-4d330675-2eff-450e-acf0-ee50ed228425.png)

Tarp pasirinkimu taip pat galima susikurti 100 000 eilučiu atsitiktinai sugeneruotų simbolių dokumentą
Šitas dokumentas yra sudarytas iš 25 000 eilučių kuriose yra 10 simbolių, 25 000 eilučių sudarytų iš 100 simbolių, 25 000 euilučių sudarytų iš 500 simbolių ir 25 000 eilučių sudarytų iš 1000 simbolių.

Taip pat tarp pasirinkimų galima ir nusiskaityti failą po eilutę tik žinomas tas užtruks ilgiau, bet jums bus sugeneruota daugiau hash kodų žinoma skaitant po eilutę jums ir apskaičiuos laiką kurį sugaišo programa hashuojant


Jeigu jau nusiskaitėte bent vieną failą po eilute galite tuomet lyginti ar nesusidarė tokie pat hashšai tarp eilučių ir taip įsitikinsite kodo stiprumu 
Mano kodo dabartinė versija nesugeba padaryti tiek hash kad jie nesikartotų, o pati skaičiuoklė veikia tokiu principu jog jeigu antroje eilutėje buvo rastas toks pat hash kaip ir ketvirtoje ir devintoje tada skaičiuojant jų kiekį bus 3 kadangi antra eilutė randa ketvirtą ir devintą ir tada ketvirtoji eilutė randa dar devintą.
![image](https://user-images.githubusercontent.com/75576100/135526893-3430aa7f-dd34-4e8f-ac8c-41bf19850e05.png)

Taip pat kai jau suhashuojate kokį nors dokumentą po eilutę galite pasitiktinti kiek simbolių atitinka vienas hex kitą. Tarkime pirmas hex simbolis kito hex pirmą simbolį ir tuomet gauname kiek jų buvo daugiausia, mažiausia ir vidutiniškai. Tas pats daroma ir su Bitais.
![image](https://user-images.githubusercontent.com/75576100/135524342-9375da47-8ba8-4fa9-a48c-bdb86caaa0a1.png)
