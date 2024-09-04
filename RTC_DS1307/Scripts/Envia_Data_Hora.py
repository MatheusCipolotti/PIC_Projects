import serial
import time
from datetime import datetime

# Configura a porta serial (ajuste a porta e a taxa de transmissão conforme necessário)
ser = serial.Serial('COM6', 9600, timeout=1) 
time.sleep(2)  # Aguarda a inicialização da conexão serial

# Mapeamento dos dias da semana
dias_semana = {
    0: "2",  # Segunda-feira
    1: "3",  # Terça-feira
    2: "4",  # Quarta-feira
    3: "5",  # Quinta-feira
    4: "6",  # Sexta-feira
    5: "7",  # Sábado
    6: "1",  # Domingo
}

def enviar_data_hora():
    # Obtém a data e hora atuais
    agora = datetime.now()

    # Formata a data e hora
    dia = agora.strftime("%d")
    mes = agora.strftime("%m")
    ano = agora.strftime("%y")
    dia_semana = dias_semana[agora.weekday()]
    hora = agora.strftime("%H")
    minuto = agora.strftime("%M")
    segundo = agora.strftime("%S")

    # Constrói a string a ser enviada
    data_hora_str = f"{dia}/{mes}/{ano}{dia_semana}{hora}:{minuto}:{segundo}"
    
    # Envia a string via serial
    ser.write(data_hora_str.encode())

    # Imprime no terminal para verificação
    print(f"Enviado: {data_hora_str}")

# Chama a função para enviar a data e hora
enviar_data_hora()

# Fecha a conexão serial ao final
ser.close()
