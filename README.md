# Compilar e Executar a Simulação

O seguinte documento aborda os procedimentos a serem executados para compilar e executar a simulação do robô Edubot no mapa "Maze", dentro da [Edubot IDE](https://github.com/Edubot2020/ide).

## 1 - Requisitos

Para realizar os procedimentos abordados neste documento, é necessário possuir as seguintes ferramentas instaladas na sua máquina. 

- [Edubot IDE](https://github.com/Edubot2020/ide)

- Compilador para linguagem C

A página para download da IDE utilizada já contempla os passos a serem seguidos para sua instalação. No caso do compilador para linguagem C, recomenda-se seguir a documentação do [GCC](https://gcc.gnu.org/install/index.html) para Linux e [MinGW](https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download) para Windows.

Além disso, assume-se que já exista um projeto criado dentro da interface da IDE, com a estrutura principal referenciada em um arquivo sob nome **Main.cpp**.

## 2 - Procedimentos

O primeiro é realizar a compilação do código, que na interface da IDE é realizada através do botão de **Build**, localizado no canto inferior esquerdo da tela de edição do código. O início do processo de será indicado no terminal abaixo do botão, por meio da mensagem **Start building**, e caso não ocorram erros durante o processo retornará a mensagem **Stop building**. 

![botao_build](https://github.com/user-attachments/assets/63910bef-c625-4edd-b203-3a78942256c8)

Figura 1: Botão **Build**.

![botao_run](https://github.com/user-attachments/assets/1919e52a-b410-42b3-8186-40b4bc07e7c8)

Figura 2: Execução do build e surgimento do botão **Run**.


Com o projeto compilado, o botão **Run** surgirá ao lado do botão de **Build**, o qual será utilizado para executar o código na simulação que inciaremos a seguir. 

O próximo passo é abrir a tela de simulação da IDE, que pode ser feito através do menu do canto superior esquerdo, em **Edubot** -> **Simulator**, ou através do atalho **Ctrl + Shift + J**. Uma vez aberto o simulador, faremos o carregamento da pasta de mapas por meio do botão **Load maps folder** e a seleção do mapa "Maze" na visualização da lista de mapas **Map**.

![load_maps_folder](https://github.com/user-attachments/assets/a98e72b6-bc12-4c61-9fc6-72ee0e28aee0)


Figura 3: Botão **Load maps folder** na tela do simulador.

![mapa_maze](https://github.com/user-attachments/assets/a80c3274-3bbf-4b9e-a450-615bc743856d)


Figura 4: Mapa "Maze" selecionado na lista e botão **Start simulation**.


Com isso, iniciamos a simulação através do botão **Start simulation** na tela do simulador. Por fim, podemos executar o código por meio do botão **Run**, presente do lado do botão de **Build** na tela principal da IDE.

