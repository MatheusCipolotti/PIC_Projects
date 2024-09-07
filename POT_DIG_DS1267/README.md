# [PIC] Controle para potenciômetro digital DS1267 via SPI
## Objetivo
Desenvolver a estrutura de código para o controle do potenciômetro digital DS1267 utilizando o microcontrolador PIC16F877A.
## Diagrama de tempo DS1267
<p align="center" width="100%">
<img width="100%" src="https://github.com/MatheusCipolotti/-PIC-POT_DIG_DS1267/assets/102692462/5182ed6c-35cd-4732-8365-de2a58970a79">
</p>
<p align="center" width="100%">
  Figura 1 - Diagrama de tempo DS1267 
</p>

## Circuito para os testes
<p align="center" width="100%">
<img width="100%" src="https://github.com/MatheusCipolotti/-PIC-POT_DIG_DS1267/assets/102692462/5f800bd2-838d-4b23-b693-ced4608f583b">
</p>
<p align="center" width="100%">
  Figura 2 - Microcontrolador PIC16F877A
</p>

<p align="center" width="100%">
<img width="100%" src="https://github.com/MatheusCipolotti/-PIC-POT_DIG_DS1267/assets/102692462/4e06905e-6cb6-4cc2-a04d-82a58050f7b0">
</p>
<p align="center" width="100%">
  Figura 3 - Circuito do Master Clear e cristal de oscilação
</p>

<p align="center" width="100%">
<img width="100%" src="https://github.com/MatheusCipolotti/-PIC-POT_DIG_DS1267/assets/102692462/46efca41-6d0c-4662-9de8-13a389c4f663">
</p>
<p align="center" width="100%">
  Figura 4 - DS1267 + Amplificador
</p>

## Resultados obtidos
No código, além da configuração da comunicação SPI foi configurado para o teste o incremento do valor dos potenciômetros para verificar a resistência desde 0x00 a 0xFF, a imagem abaixo mostra o comportamento visto no teste
<p align="center" width="100%">
<img width="100%" src="https://github.com/MatheusCipolotti/-PIC-POT_DIG_DS1267/assets/102692462/d5a058f9-aaba-455f-b45b-cea9ab2bf392)">
</p>
