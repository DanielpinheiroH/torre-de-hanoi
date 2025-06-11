# Torre de Hanói 🗼 — Projeto em C (GitHub)

Este repositório apresenta a implementação da **Torre de Hanói**, feita em **C**, com execução via terminal. O código utiliza **pilhas** e **listas encadeadas** para controle das torres e registro de partidas, e está estruturado de forma modular, com versionamento via **Git**.

---

## 📦 Estrutura do Repositório

```text
torre-de-hanoi/
├── src/
│   ├── main.c              # Função principal e menu interativo
│   ├── hanoi.c / hanoi.h   # Lógica principal do jogo
│   ├── pilha.c / pilha.h   # Estrutura de dados: pilhas para torres
│   ├── lista_historico.c / lista_historico.h  # Registro de partidas com nome e data
├── dados/
│   └── historico.txt       # Arquivo gerado com histórico de partidas
├── .git/                   # Histórico de versionamento
├── .gitignore
└── README.md
🛠️ Tecnologias & Conceitos
Linguagem: C (padrão ANSI)

Estruturas utilizadas:

Pilha → representação das torres T1, T2 e T3

Lista encadeada → armazena registros de partidas (jogador, discos, data, movimentos)

Ferramentas:

GCC para compilação

Git para controle de versão

Execução via terminal

⚙️ Como Compilar e Executar
Clone o repositório:

#bash#

git clone https://github.com/DanielpinheiroH/torre-de-hanoi.git
cd torre-de-hanoi/src
Compile o projeto:

#bash#

gcc -o hanoi.exe main.c hanoi.c pilha.c lista_historico.c
Execute no terminal:

#bash#
./hanoi.exe
🔍 Funcionalidades do Projeto
✅ Interface interativa via terminal
✅ Menu com 3 opções:

1 - Jogar: você informa seu nome e o número de discos, e joga a Torre de Hanói com visualização gráfica.

2 - Ver histórico: mostra as partidas registradas no arquivo historico.txt.

3 - Sair

✅ Impressão gráfica das torres com alinhamento central dos discos
✅ Verificação de jogadas válidas e invalidação de movimentos incorretos
✅ Registro do nome do jogador, data/hora, discos e número de movimentos
✅ Histórico salvo automaticamente em dados/historico.txt

📜 Exemplo de Saída (jogo com 3 discos)
text

Digite o número de discos: 3
Digite seu nome: Daniel

=== ESTADO DAS TORRES ===

   *|*           |           |
  **|**          |           |
 ***|***         |           |
=======     =======     =======
   T1           T2           T3

Movimento #1
Digite origem (1, 2 ou 3): 
🗂️ Histórico de Versões (Git)
v1.0: Estruturas de dados (pilhas, lista)

v1.1: Lógica básica do jogo

v2.0: Menu, nome do jogador, histórico com data

v2.1: Visualização gráfica ajustada

v2.2: Refatoração final, git organizado

✅ Próximas Melhorias
 Adicionar Makefile para facilitar compilação

 Adicionar testes unitários

 Adicionar opção de desfazer jogadas

 Interface gráfica ou web

📝 Licença
Projeto sob licença MIT. Veja LICENSE para detalhes.

👨‍💻 Autor
Daniel Pinheiro, José leonardo, 
Curso: Engenharia de softare — 2025
GitHub: DanielpinheiroH
