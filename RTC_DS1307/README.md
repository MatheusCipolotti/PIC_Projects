# Controle para o RTC DS1307 via I2C
## Objetivo
Desenvolver a estrutura de código para o controle do RTC DS1307 utilizando o microcontrolador PIC16F877A.
## Registradores e Funções do DS1307
As informações de tempo e calendário no DS1307 são obtidas lendo os bytes dos registros apropriados. Esses registros estão em formato BCD. O dia da semana é incrementado à meia-noite e é definido pelo usuário, devendo ser sequencial (por exemplo, 1 para domingo, 2 para segunda-feira, etc.). Valores incorretos de data e hora causam operação indefinida. O bit 7 do registro 0 é o bit de parada do relógio (CH). Quando definido como 1, o oscilador é desativado; quando 0, é ativado. Inicialmente, os registros de data e hora são resetados para 01/01/00 01 00:00:00. O DS1307 pode operar em modos de 12 ou 24 horas, controlado pelo bit 6 do registro de horas. O modo de 12 horas usa o bit 5 para indicar AM/PM, enquanto no modo de 24 horas, o bit 5 indica horas de 20 a 23. Os registros de tempo e data utilizam buffers secundários para evitar erros durante leituras ou atualizações, e ao escrever no registro de segundos, o divisor é resetado.
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/4b067b1a-9fe3-402d-8e2d-7cfb27d2ee8d">
</p>
<p align="center" width="100%">
  Figura 1 - Registradores do DS1307 
</p>
O registrador de controle do DS1307 é usado para controlar a operação do pino SQW/OUT.
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/92a249dc-f4c6-4f6e-813d-b77bfd634259">
</p>
<p align="center" width="100%">
  Figura 2 - Registrador de controle 
</p>

Bit 7: Output Control (OUT) - Este bit controla o nível de saída do pino SQW/OUT, se SQWE = 0, o nível lógico no pino SQW/OUT é 1 se OUT = 1 e é 0 se OUT = 0.

Bit 4: Square-Wave Enable (SQWE) - Este bit, quando definido como lógico 1, habilita a saída do oscilador, a frequência da saída depende do valor dos bits RS0 e RS1.

Bits 1 and 0: Rate Select (RS[1:0]) - Esses bits controlam a frequência de oscilação no pino 7 SQW/OUT, conforme a imagem abaixo:
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/3b563aee-c933-485c-8f5d-caf89f36c3d5">
</p>

## Circuito de Testes
O circuito utilizado para os testes possui o PIC16F877A com o cristal oscilador de 20MHz com o PDF disponibilizado no link abaixo:

- [Circuito](Circuito/Circuito.pdf)

## Resultados
