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

![image](https://github.com/user-attachments/assets/2485c3f4-bee4-47f8-b481-e34660de263f)

## Išvados

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `list` buvo mažiausiai efektyvus.
