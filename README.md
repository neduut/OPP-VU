# Naudojimo instrukcijos

Yra 3 skirtingos programos versijos: vector, deque ir list, jas galima rasti atitinkamuose aplankuose. Kiekviena versija naudoja atskirą šaltinio failų rinkinį ir CMake konfigūraciją.

**Kad paleisti programą, turite atlikti šiuos veiksmus:**

1. Įeikite į norimos versijos katalogą
2. Paleiskite `run.bat` failą

  `run.bat` failas atliks šiuos veiksmus:
   - Sukurs build katalogą (jei jo dar nėra)
   - Paleis CMake, kad sugeneruotų `Makefile`
   - Sukompiliuos projektą naudodamas make komandą
   - Paleis sukompiliuotą programą terminale

**Reikalavimai**

- Windows 10 x64bit ar naujesnė versija
- Įdiegtas CMake (rekomenduojama naudoti CMake versiją 3.25 ar naujesnę)
- Kompiliatorius: g++ (g++ turi būti įdiegtas jūsų sistemoje, kad veiktų komanda make)

# Spartos tyrimai

Buvo atlikti du programos spartos tyrimai su su trimis skirtingais konteineriais: `vector`, `deque` ir `list`.

Testavimo sistemos parametrai:
- CPU - AMD Ryzen AI 9 HX 370 (12 fizinių ir 24 loginiai branduoliai)
- GPU - AMD Radeon 890M (16 GB)
- RAM - 32.0 GB LPDDR5x 
- SSD - 2 TB
- Kompiliatorius: GCC
- IDE: Visual Studio Code

Visiems testams buvo naudojami tie patys failai, užtikrinant tyrimų patikimumą.
  
# 1. Konteinerių tyrimas

Buvo tiriamos šios operacijos:
1. Duomenų nuskaitymas iš failų 
2. Studentų rūšiavimas didėjimo tvarka konteineryje 
3. Studentų skirstymas į dvi grupes 

Kiekvienas konteineris (`vector`, `deque` ir `list`) buvo testuojamas su penkiais skirtingo dydžio failais, kurių įrašų skaičius buvo: 
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Sukiekvienu failu buvo atlikta po 5 testus. Visų testų rezultatus galima rasti `assets` -> `containerTests` kataloge.

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/209393ed-6b71-455f-b411-85acf06023bf)

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `deque` buvo mažiausiai efektyvus.


# 2. Strategijų tyrimas

Buvo tiriama studentų rūšiavimo į grupes operacija pagal tris skirtingas strategijas.

Kiekvienas konteineris (`vector`, `deque` ir `list`) buvo testuojamas su penkiais skirtingo dydžio failais, kurių įrašų skaičius buvo: 
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Sukiekvienu failu buvo atlikta po 5 testus. Visų testų rezultatus galima rasti `assets` -> `strategies` kataloge.

## 1 strategija

Šioje strategijoje bendras studentų konteineris (`vector`, `deque` ir `list`) yra suskirstomas į du naujus konteinerius pagal studento pažymį. Vienas konteineris talpina "vargšiukus", kitas — "kietiakus". Kiekvienas studentas egzistuoja tiek bendrame konteineryje, tiek viename iš suskirstytų konteinerių. 

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/10b7ad8e-6318-4132-b525-47c0d6fcd5fe)

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `deque` buvo mažiausiai efektyvus.

Žemiau pateikiamas atminties naudojimas su 10 000 000 įrašų failu:

**Vector** 
![vector1](https://github.com/user-attachments/assets/86ef0846-6e8e-43e2-a077-047dd9406407)

**Vector - 3 strategija** (palyginimui) 
![vector3](https://github.com/user-attachments/assets/8a2cd813-2709-46ad-86c0-c9ed2632f1f4)

**Deque** 
![deque1](https://github.com/user-attachments/assets/9985949c-1c03-44d4-a1fc-7aba5dadfd8d)

**List**
![list1](https://github.com/user-attachments/assets/fd4726ee-3d4a-4a5d-a755-8bb14e98a23b)

Tyrimas parodė, kad `deque` naudoja daugiausiai atminties, `vector` pasiekia gerą atminties naudojimo ir vidutinį našumą, o `list` yra efektyviausias atminties požiūriu, tačiau pasiekia lėtesnį našumą.

## 2 strategija

Šioje strategijoje studentų konteineris yra skaidomas į "vargšiukų" konteinerį, tačiau tik vienas naujas konteineris yra sukuriamas. Jei studentas atitinka "vargšiuko" kriterijus, jis perkeliamas į šį naują konteinerį, o iš bendro studentų konteinerio ištrinamas. Po to bendrame konteineryje lieka tik "kietiakai".

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/6f7ba9e1-e022-4bcd-af74-bf926f029893)

Tyrimas parodė, kad naudojant didesnius failus, `list` buvo efektyviausias, o `vector` bei `deque` buvo žymiai mažiau efektyvūs.

## 3 strategija

Šioje strategijoje naudojamas bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant greičiausiai veikianti iš 1 arba 2 strategijos, įtraukiant į jį "efektyvius" darbo su konteineriais metodus. 
Buvo optimizuotas `vector` tipo konteineris, optimizuota 1 strategija.

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/8b77907f-78ab-4319-b2d5-59cae73c90ef)

Tyrimas parodė, kad pritaikius tam `std::partition` metodą, failo su 10 000 000 įrašų atžvilgiu, `vector` tapo efektyvesnis ~0.5 sek. Taip pat sumažėjo ir atminties sąnaudos, kurias galima rasti pirmos strategijos apraše.
