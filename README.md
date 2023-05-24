# TFT
O código fornecido serve como um exemplo básico de como usar um dispositivo ESP32 para se conectar a uma rede Wi-Fi, estabelecer uma conexão MQTT com um broker e exibir mensagens em uma tela TFT. Ele pode ser usado como ponto de partida para projetos que envolvam a comunicação e controle de dispositivos por meio da internet usando o protocolo MQTT.

O código permite que o dispositivo ESP32 se conecte a uma rede Wi-Fi e a um broker MQTT, configurando corretamente as credenciais e endereços de conexão. Ele utiliza a biblioteca Adafruit_ILI9341 para controlar a tela TFT e exibir mensagens nela.

Além disso, o código define uma lógica básica de conexão MQTT, em que o dispositivo se conecta ao broker MQTT e se inscreve no tópico "somar". No entanto, o código fornecido não inclui a implementação da lógica de recebimento e processamento de mensagens MQTT, que seria necessária para executar ações com base nas mensagens recebidas.

Portanto, o código pode ser usado como base para projetos que envolvam a comunicação MQTT e a exibição de informações em uma tela TFT, mas requer a adição de lógica personalizada para atender aos requisitos específicos do projeto.
