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

![image](https://github.com/user-attachments/assets/2062d63c-b3e5-4ac3-b404-0020841d29f1)

## Išvados

Tyrimas parodė, kad naudojant didesnius failus, `vector` buvo efektyviausias, o `deque` buvo mažiausiai efektyvus.


atminties naudojimas

strategija 1, vector, 10 000 000 stud
![vector1](https://github.com/user-attachments/assets/9d95c054-c330-4eb4-af5b-57cee43a5af7)

strategija 1, deque, 10 000 000 stud
![deque1](https://github.com/user-attachments/assets/5645f382-3494-499a-a26c-9f06a9a6c3b0)

strategija 2, list, 10 000 000 stud
![list2](https://github.com/user-attachments/assets/a30e6158-e6e6-4c48-8ba8-59ec6ac81981)

