Formas 2D Compostas em OpenGL
- Projeto simples em C++ com OpenGL e GLUT
- Exibe uma figura geométrica composta (triângulos e retângulo) girando continuamente no eixo Z.

== O que ele faz? ==
- Renderiza uma estrutura composta por 4 formas primitivas com cores RGB (vermelho, verde e azul).
- Aplica rotação 2D/3D automática contínua em torno do próprio eixo (~60 FPS).
- Configura câmera em perspectiva 3D, viewport responsiva e teste de profundidade.

Como rodar

Compilar
g++ main.cpp -o formas_2d -lGL -lGLU -lglut

Executar
./formas_2d
