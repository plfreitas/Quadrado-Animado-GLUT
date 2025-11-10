# Quadrado Animado GLUT

Este projeto é uma implementação em C++ de um protetor de tela (screensaver) simples, utilizando a biblioteca gráfica **GLUT (OpenGL Utility Toolkit)**. O objetivo é simular um quadrado que se move continuamente pela janela, reagindo a colisões com as bordas.

## Funcionalidades Principais

O projeto demonstra conceitos fundamentais de animação 2D, detecção de colisão e manipulação de estado em tempo real.

### 1. Movimento e Colisão
*   **Movimento Contínuo:** O quadrado se move de forma diagonal e constante pela janela.
*   **Detecção de Colisão:** Ao atingir qualquer uma das quatro bordas da tela, o quadrado inverte sua direção (ricochete).

### 2. Feedback Visual
*   **Mudança de Cor:** A cada colisão, a cor do quadrado é alterada para uma nova cor aleatória (RGB), proporcionando um feedback visual imediato.
*   **Crescimento Progressivo:** O tamanho do quadrado é sutilmente aumentado a cada colisão, até atingir um limite máximo pré-definido, adicionando um elemento de progressão à animação.

## Detalhes Técnicos

| Componente | Descrição |
| :--- | :--- |
| **Linguagem** | C++ (código puro) |
| **Biblioteca Gráfica** | GLUT (OpenGL Utility Toolkit) |
| **Animação** | Controlada pela função `glutTimerFunc`, garantindo uma atualização de estado e renderização fluida. O intervalo de tempo (timer) define a velocidade da animação. |
| **Renderização** | Utiliza as funções básicas do OpenGL (`glBegin(GL_QUADS)`, `glColor3f`, `glVertex2f`) para desenhar o quadrado e `gluOrtho2D` para configurar o sistema de coordenadas 2D. |
| **Lógica** | A função `update` gerencia a mudança de direção (`square.dx = -square.dx`), a alteração de cor (`randomColor()`) e o aumento de tamanho. |

## Como Compilar e Executar

Para compilar e executar este projeto, você precisará ter o **GLUT** configurado no seu ambiente de desenvolvimento C++.

1.  **Instalação do GLUT:** Certifique-se de que as bibliotecas `freeglut` (ou `glut`) estejam instaladas e configuradas corretamente no seu compilador (como MinGW ou Visual Studio).
2.  **Compilação:** O projeto deve ser compilado com a inclusão das bibliotecas GLUT e OpenGL.
    *   **Exemplo de flags de compilação (GCC/G++):**
        ```bash
        g++ Quadrado-Animado-GLUT.cpp -o animacao -lglut -lGLU -lGL
        ```
3.  **Execução:**
    ```bash
    ./animacao
    ```

---
*Desenvolvido por plfreitas*
*Este projeto é um excelente ponto de partida para entender os fundamentos da animação 2D e do uso do pipeline de eventos e callbacks da biblioteca GLUT.*
