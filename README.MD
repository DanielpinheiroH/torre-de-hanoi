# Torre de Hanói 🗼

Este projeto é uma simulação do clássico jogo **Torre de Hanói**, desenvolvido como trabalho final da disciplina de **Estrutura de Dados**. O objetivo é demonstrar, de forma didática e interativa, o uso de **pilhas**, **listas encadeadas** e **arquivos de texto**, aplicando os conceitos fundamentais da disciplina em um problema consagrado da computação.

---

## 🔧 Tecnologias Utilizadas

- 💻 Linguagem: `C` (ou substitua pela sua linguagem, como Python/Java/C++)
- 🧠 Estruturas de Dados:
  - **Pilha**: representa as torres do jogo
  - **Lista Encadeada**: armazena o histórico dos movimentos realizados
  - **Arquivo de Texto**: salva o histórico após a finalização da partida
- 🖥️ Interface: Terminal (modo texto)

---

## 🎯 Objetivos do Projeto

- Implementar a simulação da Torre de Hanói com 3 torres (A, B e C) e N discos.
- Utilizar **pilhas** para representar as torres e garantir as regras do jogo.
- Registrar cada movimento em uma **lista encadeada**, que será exibida ao final.
- Salvar o histórico em um **arquivo `.txt`** para análise posterior.
- Reforçar conceitos de **manipulação de ponteiros**, **alocação dinâmica** e **estruturas de dados lineares**.

---

## ▶️ Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seuusuario/torre-de-hanoi.git
   cd torre-de-hanoi
Compile o código (para C):

"bash

gcc main.c -o hanoi
./hanoi
Ou execute diretamente se for Python:"

bash

python3 main.py
📂 Estrutura do Projeto
bash
Copiar
Editar
torre-de-hanoi/
├── main.c               # Arquivo principal do programa
├── pilha.c / pilha.h    # Implementação da estrutura de pilha
├── lista.c / lista.h    # Implementação da lista encadeada
├── utils.c / utils.h    # Funções auxiliares
├── movimentos.txt       # Arquivo gerado com o histórico dos movimentos
└── README.md            # Documentação do projeto
🧠 Lógica do Jogo
Apenas um disco pode ser movido por vez.

Um disco só pode ser colocado sobre outro maior.

O objetivo é mover todos os discos da torre A para a torre C usando a torre B como auxiliar, seguindo as regras.

📜 Exemplo de Saída
python-repl
Copiar
Editar
Movendo disco 1 de A para C
Movendo disco 2 de A para B
Movendo disco 1 de C para B
...
Movimentos salvos em 'movimentos.txt'
📘 Créditos
Projeto desenvolvido por [Seu Nome] como parte do curso de Estrutura de Dados - [Nome da Instituição/Professor].

📄 Licença
Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
