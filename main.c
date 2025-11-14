#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Configuraçőes da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Quadrado Animado 2D"

// Estrutura para o quadrado
typedef struct {
    float x, y;           
    float size;           
    float original_size;  
    float dx, dy;         
    float r, g, b;        
} Square;

Square square;

// Funçăo para gerar cor aleatória entre 0.0 e 1.0
void randomColor() {
    square.r = (float)rand() / RAND_MAX;
    square.g = (float)rand() / RAND_MAX;
    square.b = (float)rand() / RAND_MAX;
}

// Funçăo de inicializaçăo
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    
    // Inicializa o quadrado
    square.original_size = 30.0f;
    square.size = square.original_size;
    square.x = WINDOW_WIDTH / 2.0f;
    square.y = WINDOW_HEIGHT / 2.0f;
    square.dx = 3.0f;  // Velocidade em X
    square.dy = 2.0f;  // Velocidade em Y
    
    // Cor inicial aleatória
    srand((unsigned int)time(NULL));
    randomColor();
}

// Funçăo para desenhar o quadrado
void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(square.r, square.g, square.b);
    glVertex2f(square.x - square.size, square.y - square.size);
    glVertex2f(square.x + square.size, square.y - square.size);
    glVertex2f(square.x + square.size, square.y + square.size);
    glVertex2f(square.x - square.size, square.y + square.size);
    glEnd();
}

// Funçăo de display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    drawSquare();
    
    glutSwapBuffers();
}

// Funçăo de redimensionamento
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

// Funçăo para atualizar a animaçăo
void update(int value) {
    // Atualiza posiçăo
    square.x += square.dx;
    square.y += square.dy;
    
    // Verifica colisăo com bordas horizontais
    if (square.x - square.size <= 0 || square.x + square.size >= WINDOW_WIDTH) {
        square.dx = -square.dx; // Inverte direçăo X
        randomColor(); // Muda cor
        
        // Aumenta tamanho (máximo 20% do original)
        if (square.size < square.original_size * 1.2f) {
            square.size *= 1.01f;
        }
    }
    
    // Verifica colisăo com bordas verticais
    if (square.y - square.size <= 0 || square.y + square.size >= WINDOW_HEIGHT) {
        square.dy = -square.dy; // Inverte direçăo Y
        randomColor(); // Muda cor
        
        // Aumenta tamanho (máximo 20% do original)
        if (square.size < square.original_size * 1.2f) {
            square.size *= 1.01f;
        }
    }
    
    // Garante que o quadrado năo saia da tela
    if (square.x - square.size < 0) square.x = square.size;
    if (square.x + square.size > WINDOW_WIDTH) square.x = WINDOW_WIDTH - square.size;
    if (square.y - square.size < 0) square.y = square.size;
    if (square.y + square.size > WINDOW_HEIGHT) square.y = WINDOW_HEIGHT - square.size;
    
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Funçăo principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(WINDOW_TITLE);
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    
    glutMainLoop();
    
    return 0;
}


