# Programos spartos tyrimas 

Buvo atliktas programos spartos tyrimas su trimis skirtingais konteineriais: `vector`, `deque` ir `list`.

Testavimo sistemos parametrai:
- CPU - AMD Ryzen AI 9 HX 370 (12 fizinių ir 24 loginiai branduoliai)
- GPU - AMD Radeon 890M (16 GB)
- RAM - 32.0 GB LPDDR5x 
- SSD - 2 TB
- Kompiliatorius: GCC
- IDE: Visual Studio Code 

## Testavimo metodika

Kiekvienas konteineris buvo testuojamas su penkiais skirtingo dydžio failais, kurių įrašų skaičius buvo: 
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Testai buvo atliekami po 5 kartus. Buvo tikrinamos šios operacijos:
1. Duomenų nuskaitymas iš failų
2. Studentų rūšiavimas didėjimo tvarka konteineryje
3. Studentų skirstymas į dvi grupes

Visiems testams buvo naudojami tie patys failai, užtikrinant tyrimų patikimumą.

Visų testų rezultatus galima rasti `assets` kataloge.

## Testų rezultatų vidurkiai

Žemiau pateikiami atliktų testų rezultatų vidurkiai (sekundėmis):

![image](https://github.com/user-attachments/assets/999f84f5-b265-45d7-a6b7-9a7908242d95)

![image](https://github.com/user-attachments/assets/3e18511e-df82-44c9-aedb-c29c754cf042)

![image](https://github.com/user-attachments/assets/625c0d73-8c7b-416e-9234-20732307369f)


## Išvados

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `list` buvo mažiausiai efektyvus.
