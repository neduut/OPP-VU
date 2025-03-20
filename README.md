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


Atminties naudojimas su 10 000 000 įrašų failu

vector - 1 strategija 
![vector1](https://github.com/user-attachments/assets/4772f4e3-25cb-4945-9bdf-fdd021ae4348)

vector - 3 strategija
![vector3](https://github.com/user-attachments/assets/540e93fa-07ae-43f4-bd1f-ac91d8a43b51)

deque - 1 strategija 
![deque1](https://github.com/user-attachments/assets/9985949c-1c03-44d4-a1fc-7aba5dadfd8d)

list - 1 strategija 
![list1](https://github.com/user-attachments/assets/fd4726ee-3d4a-4a5d-a755-8bb14e98a23b)


