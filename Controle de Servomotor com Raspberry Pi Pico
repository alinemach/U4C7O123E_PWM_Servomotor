Este projeto demonstra o controle de um servomotor utilizando o módulo PWM (Pulse Width Modulation) do microcontrolador RP2040, presente na placa Raspberry Pi Pico. O objetivo é simular o controle do ângulo de um servomotor padrão, utilizando a ferramenta Pico SDK e o simulador de eletrônica online Wokwi.

#### 📝Descrição do Projeto

O projeto implementa um sistema que controla o ângulo de um servomotor através de sinais PWM. O servomotor é movido para três posições específicas (0°, 90° e 180°), com pausas de 5 segundos em cada posição. Após isso, o servomotor é movido suavemente entre 0° e 180° com incrementos de 5μs, simulando uma movimentação contínua e suave. Além disso, um LED RGB conectado ao GPIO 12 é utilizado para indicar visualmente o estado do sistema.

#### 📌 Requisitos

    Frequência do PWM:
        Configurar o PWM no GPIO 22 para uma frequência de aproximadamente 50Hz (período de 20ms).

    Ciclo Ativo do PWM:
        Definir o ciclo ativo para 2.400μs (0,12%) para posicionar o servomotor em 180°.
        Definir o ciclo ativo para 1.470μs (0,0735%) para posicionar o servomotor em 90°.
        Definir o ciclo ativo para 500μs (0,025%) para posicionar o servomotor em 0°.

    Movimentação Suave:
        Criar uma rotina para movimentar o servomotor suavemente entre 0° e 180°, com incrementos de ±5μs e um atraso de 10ms entre cada ajuste.

    LED RGB:
        Utilizar o LED RGB conectado ao GPIO 12 para indicar visualmente o estado do sistema.

#### 🔧 Diagrama do Circuito

O circuito foi simulado no Wokwi e consiste nos seguintes componentes:

    Raspberry Pi Pico (RP2040):
        GPIO 22: Conectado ao pino PWM do servomotor.
        GPIO 12: Conectado ao LED RGB.
        3V3 e GND: Conectados ao servomotor e ao LED.

    Servomotor:
        Conectado ao GPIO 22 para controle de ângulo.

    LED RGB:
        Conectado ao GPIO 12 para feedback visual.

    Resistor:
        Um resistor de 1kΩ é utilizado para limitar a corrente do LED.

O diagrama do circuito pode ser visualizado no arquivo diagram.json fornecido.
#### Como Executar o Projeto
#### 📋 Pré-requisitos

    Ferramentas:
        Wokwi Simulator para simulação do circuito.
        Pico SDK para desenvolvimento do código.

    Dependências:
        Biblioteca pico/stdlib.h para funções básicas do Pico.
        Biblioteca hardware/pwm.h para controle do módulo PWM.

#### 🚀 Simulação

    Copiar o Código:
        O código-fonte está disponível no arquivo main.c. Copie e cole o código no ambiente Wokwi.

    Configurar o Circuito:
        Utilize o diagrama fornecido no arquivo diagram.json para configurar o circuito no Wokwi.

    Compilar e Executar:
        No Wokwi, compile e execute o código. O servomotor começará a se mover conforme descrito no projeto.

    Observar o Comportamento:
        O servomotor se moverá para as posições de 0°, 90° e 180°, com pausas de 5 segundos em cada posição.
        Após isso, o servomotor se moverá suavemente entre 0° e 180°.
        O LED RGB mudará de brilho conforme o servomotor se move.

#### 📂 Estrutura do Código

O código está organizado da seguinte forma:

    Configuração do PWM:
        pwm_setup_servo(): Configura o PWM para o servomotor no GPIO 22.
        pwm_setup_led(): Configura o PWM para o LED RGB no GPIO 12.

    Controle do Servomotor:
        set_servo_angle(): Ajusta o ciclo ativo do PWM para controlar o ângulo do servomotor.

    Loop Principal:

        Move o servomotor para as posições de 0°, 90° e 180°.
        Realiza a movimentação suave entre 0° e 180°.
        Controla o brilho do LED RGB conforme o estado do servomotor.

#### 🎯 Resultados

Servomotor (Wokwi):
- Movimento para 180°, 90° e 0° com pausas de 5 segundos.
- Movimentação suave entre 0° e 180°.

LED RGB (Na placa BitDogLab):
    
O efeito de brilho no LED azul (conectado ao pino GPIO 12) que observei ao testar o firmware na placa BitDogLab é resultado direto do uso do PWM (Pulse Width Modulation) para controlar a intensidade da luz do LED. Acredito que isso acontece, porque o PWM é uma técnica usada para controlar a quantidade de energia entregue a um dispositivo, como um LED, variando a proporção entre o tempo em que o sinal está em nível alto (ON) e o tempo em que está em nível baixo (OFF) dentro de um ciclo. Essa proporção é chamada de Ciclo de Trabalho (Duty Cycle).
- Duty Cycle de 100%: O sinal está sempre em nível alto (ON), e o LED brilha com intensidade máxima.
- Duty Cycle de 50%: O sinal passa metade do tempo em nível alto e metade em nível baixo, resultando em um brilho médio.
- Duty Cycle de 0%: O sinal está sempre em nível baixo (OFF), e o LED permanece apagado.

Com isso, o LED azul, ao receber esse sinal PWM, é ligado e desligado rapidamente. Como a frequência do PWM é alta (geralmente na casa dos kHz), os olhos humanos não conseguem perceber as rápidas mudanças entre ON e OFF. Em vez disso, percebem um efeito de brilho contínuo, onde a intensidade da luz parece variar suavemente.

- Quando o ciclo de trabalho do PWM é alto (por exemplo, 2400μs para o servomotor em 180°), o LED brilha intensamente.
- Quando o ciclo de trabalho é médio (por exemplo, 1470μs para o servomotor em 90°), o LED brilha com intensidade média.
- Quando o ciclo de trabalho é baixo (por exemplo, 500μs para o servomotor em 0°), o LED fica apagado ou com brilho mínimo.

Além disso, durante a movimentação suave do servomotor, o ciclo de trabalho do PWM é ajustado gradualmente, o que faz com que o brilho do LED também varie suavemente.

#### 🎥 Vídeo de demonstração
[Clique Aqui](https://youtu.be/c9VTGgHgeQE)

#### 🤝 Contribuição

Este projeto foi desenvolvido como parte de uma atividade prática. Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests com melhorias ou correções.

Este projeto está licenciado sob a MIT License.

Para dúvidas ou sugestões, entre em contato.

Nota: Este projeto foi desenvolvido para fins educacionais e pode ser utilizado como base para outros projetos envolvendo controle de servomotores com PWM no Raspberry Pi Pico.
