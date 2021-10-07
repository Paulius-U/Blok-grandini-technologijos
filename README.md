# Blok-grandiniu-technologijos

# Uzduotis

Sukurti hash funkcija 

1. Nuskaitomas failas gali buti bet kokio dydzio
2. gaunamas hash turi buti 256 bitu arba 64 simboliu 
3. naudojant ta pati faila gaunamas visada tas pats hash
4. taciau jei failo duomenys pasikecia bet vienu simboliu musu hash pasikeicia labai daug
5. Atsparumas kolizijai.

# Programos veikimo principas:
pasileidus programą iveskite skaiciu nuo 1 iki 5 koki darba norite atlikti

![image](https://user-images.githubusercontent.com/75576100/135527123-13e96112-e4a6-49db-8be3-02fa1b4de055.png)

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

![image](https://user-images.githubusercontent.com/75576100/136427672-29e92964-63ba-427e-bbb6-5e5ef23f2aca.png)

Jeigu jau nusiskaitėte bent vieną failą po eilute galite tuomet lyginti ar nesusidarė tokie pat hashšai tarp eilučių ir taip įsitikinsite kodo stiprumu 
Pati skaičiuoklė veikia tokiu principu jog jeigu antroje eilutėje buvo rastas toks pat hash kaip ir ketvirtoje ir devintoje tada skaičiuojant jų kiekį bus 3 kadangi antra eilutė randa ketvirtą ir devintą ir tada ketvirtoji eilutė randa dar devintą.
Jei viskas gerai ir hash nepasikarotjo gauname: 

![image](https://user-images.githubusercontent.com/75576100/136422111-63cc9e45-d02f-4333-b0e2-566cfb50fdf6.png)

Jei pasikartojo išvardinama kur pasikartojo ir kiek iš viso tai buvo kartų: 

![image](https://user-images.githubusercontent.com/75576100/136426535-5dce1781-f656-402b-aee4-fbea09985f22.png)

Taip pat kai jau suhashuojate kokį nors dokumentą po eilutę galite pasitiktinti kiek simbolių atitinka vienas hex kitą. Tarkime pirmas hex simbolis kito hex pirmą simbolį ir tuomet gauname kiek jų buvo daugiausia, mažiausia ir vidutiniškai. Tas pats daroma ir su Bitais.

![image](https://user-images.githubusercontent.com/75576100/136421487-1d59abf4-7aab-4db6-a35c-960bac5fac4b.png)

# išvados 

1. Programa su failais ir jų pasikeitimu susitvarko tvarkingai jokios koalizijos nėra kol tikrinami pilni failai nors ir jie skirtūsi tik vienu simboliu 
2. Toks pat dokumentas visada turės tą patį hash.
3. Nors su failais visaks tvarkoje tačiau skaitant failus po eilutę buvo sulaukta koalizijos. Todėl galima suprasti kad programa neveikia 100Į taip kaip turėtų veikti
