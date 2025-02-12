## 🔥 Projeto: Controle de Servomotor por PWM com Raspberry Pi Pico W

## 📌 Descrição do Projeto

Este projeto demonstra como controlar um servomotor utilizando o módulo PWM do microcontrolador Raspberry Pi Pico W. O código foi desenvolvido utilizando a ferramenta Pico SDK e simulado no ambiente Wokwi, um simulador de eletrônica online. O objetivo é ajustar o ângulo do servomotor para diferentes posições (0°, 90° e 180°) e, em seguida, criar uma rotina para movimentar o braço do servomotor suavemente entre 0° e 180°.

## 🛠️ Componentes Utilizados

1. **Microcontrolador**: Raspberry Pi Pico W
2. **Servomotor**: Motor micro servo padrão (simulado no Wokwi)
3. **LED RGB**: Conectado ao GPIO 12 (opcional, para observação de comportamento)

## 📋 Requisitos do Projeto

1. **Configuração do PWM**:
   - GPIO 22 configurada para frequência de 50Hz (período de 20ms).
   - Ciclo ativo (Duty Cycle) ajustado para:
     - 2.400µs (0,12%) para posição de 180°.
     - 1.470µs (0,0735%) para posição de 90°.
     - 500µs (0,025%) para posição de 0°.

2. **Tempo de Espera**:
   - Aguardar 5 segundos em cada posição (0°, 90°, 180°).

3. **Movimentação Periódica**:
   - Criar uma rotina para mover o braço do servomotor suavemente entre 0° e 180°.
   - Incremento de ciclo ativo de ±5µs com atraso de 10ms entre ajustes.

4. **Experimento com LED RGB**:
   - Utilizar o GPIO 12 para controlar um LED RGB e observar seu comportamento durante a execução do código.

## 🛠️ Configurando o Projeto no VS Code

1. **Clonar o Repositório**:
```
git clone https://github.com/deciofrancis/EmbarcatechServomotor.git
cd EmbarcatechServomotor
```

2. **Pra o primeiro projeto - Abra o VS Code** e **importe o projeto**:
   - Vá até a **Extensão Raspberry Pi Pico**.
   - Selecione **Import Project**.
   - Escolha a pasta do repositório clonado.
   - Clique em **Import**.

3. **Compilar o código**:
   - Utilize a opção de **Build** da extensão.

4. **Rodar no BitDogLab**:
   - Na extensão do VSCode Raspberry PI PICO Project.
   - Clique em **Run Project(USB)** para enviar o arquivo para a BitDogLab.

## Desenvolvedor

[Décio Francis](https://www.linkedin.com/in/deciofrancis/)

## Vídeo de Demonstração

[Assista ao vídeo de demonstração aqui](https://youtu.be/7dlulfWD-6Q)