# [PIC] Controle para potenciômetro digital DS1267 via SPI
## Objetivo
Desenvolver a estrutura de código para o controle do potenciômetro digital DS1267 utilizando o microcontrolador PIC16F877A.
## Diagrama de tempo DS1267
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/f6aa927a-51e8-4273-87b8-97cf1eaf5056">
</p>
<p align="center" width="100%">
  Figura 1 - Diagrama de tempo DS1267 
</p>

## Circuito para os testes
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/de1ebef2-110e-45f1-b65d-376034fb4436">
</p>
<p align="center" width="100%">
  Figura 2 - Microcontrolador PIC16F877A
</p>

<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/d0e74fa8-cfc2-4022-a03b-5948063de217">
</p>
<p align="center" width="100%">
  Figura 3 - Circuito do Master Clear e cristal de oscilação
</p>

<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/c324d954-3d60-499b-9ac6-a845884f03f2">
</p>
<p align="center" width="100%">
  Figura 4 - DS1267 + Amplificador
</p>

## Resultados obtidos
No código, além da configuração da comunicação SPI foi configurado para o teste o incremento do valor dos potenciômetros para verificar a resistência desde 0x00 a 0xFF, a imagem abaixo mostra o comportamento visto no teste
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/02706809-3ca8-459c-bc4f-70d16e280444">
</p>
