# Naudojimo instrukcijos

....................parasyt 

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

Kiekvienas konteineris (`vector`, `deque` ir `list`) buvo testuojamas su penkiais skirtingo dydžio failais, kurių įrašų skaičius buvo: 
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Testai buvo atliekami po 5 kartus. Buvo tikrinamos šios operacijos:
1. Duomenų nuskaitymas iš failų
2. Studentų rūšiavimas didėjimo tvarka konteineryje
3. Studentų skirstymas į dvi grupes

Visų testų rezultatus galima rasti `assets` -> `containerTests` kataloge.

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/92bbf9f4-8de0-4af2-a358-2c49a70b7703)

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `deque` buvo mažiausiai efektyvus.


# 2. Strategijų tyrimas

Buvo tiriama studentų rūšiavimo į grupes operacija (`groupStudents`) pagal tris skirtingas strategijas.

Visų testų rezultatus galima rasti `assets` -> `containerTests` kataloge.

## 1 strategija

Šioje strategijoje bendras studentų konteineris (`vector`, `deque` ir `list`) yra suskirstomas į du naujus konteinerius pagal studento pažymį. Vienas konteineris talpina "vargšiukus", kitas — "kietiakus". Kiekvienas studentas egzistuoja tiek bendrame konteineryje, tiek viename iš suskirstytų konteinerių. 

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/7a38dd7d-092c-4f5b-9c5c-da0dc9928bcf)

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

![image](https://github.com/user-attachments/assets/ff01718c-fbca-4ac1-974d-1ff87bf4b812)

Tyrimas parodė, kad naudojant didesnius failus, `list` buvo efektyviausias, o `vector` bei `deque` buvo žymiai mažiau efektyvūs.

## 3 strategija

Šioje strategijoje naudojamas bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant greičiausiai veikianti iš 1 arba 2 strategijos, įtraukiant į jį "efektyvius" darbo su konteineriais metodus. 
Buvo optimizuotas `vector` tipo konteineris, optimizuota 1 strategija.

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/6502b221-abfe-4e5e-a595-388fe918b94b)

Tyrimas parodė, kad pritaikius tam tikrus metodus, failo su 10 000 000 įrašų atžvilgiu, `vector` tapo efektyvesnis ~0.5 sek. Taip pat sumažėjo ir atminties sąnaudos, kurias galima rasti pirmos strategijos apraše.
