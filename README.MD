# Torre de Hanói 🗼 — Projeto em C (GitHub)

Este repositório apresenta sua implementação da **Torre de Hanói**, feita em **C**, com execução via terminal. O código utiliza **pilhas** e **listas encadeadas** para controle de torres e registro de movimentos, respectivamente. Está estruturado de forma modular, com versionamento via **Git**.

---

## 📦 Estrutura do repositório

```text
torre-de-hanoi/
├── main.c              # Função principal e interface de execução
├── pilha.c / pilha.h   # Estrutura de dados: pilhas para torres
├── lista.c / lista.h   # Registro de histórico via lista encadeada
├── movimentos.txt      # Gerado ao final da execução (registro dos movimentos)
├── .git/               # Histórico de commits e versionamento
└── README.md           # Documentação atualizada
🛠️ Tecnologias & Conceitos
Linguagem: ANSI C

Estruturas:

Pilha → representação das torres A, B e C

Lista encadeada → armazena sequência de movimentos

Arquivo texto → registra os movimentos realizados

Ferramentas:

Compiler: GCC

Git: controle de versão

Execução via terminal

⚙️ Como compilar e rodar
Faça clone do repositório:

bash

git clone https://github.com/DanielpinheiroH/torre-de-hanoi.git
cd torre-de-hanoi
Compile:

bash

gcc main.c pilha.c lista.c -o hanoi
Execute:

bash

./hanoi
Ao término, veja movimentos.txt:

bash

cat movimentos.txt
🔍 Funcionalidades
Recebe via terminal o número de discos (ex: 3, 4, 5…).

Executa algoritmo recursivo para mover discos.

Grava cada jogada na lista encadeada, exibindo-a ao final.

Gera movimentos.txt com todas as instruções.

Demonstra boas práticas de modularização e versionamento.

🗂️ Histórico de versões (Git)
Este projeto evoluiu com commits estruturados, por exemplo:

Início: criação das estruturas de dados (pilhas, lista).

Lógica do Jogo: implementação do algoritmo recursivo e terminal.

Histórico: gravação em lista e arquivo texto.

Refatoração: modularização, comentários e limpeza de código.

📜 Exemplo de saída
text

Entre com o número de discos: 3
Movendo disco 1 de A para C
Movendo disco 2 de A para B
Movendo disco 1 de C para B
Movendo disco 3 de A para C
Movendo disco 1 de B para A
Movendo disco 2 de B para C
Movendo disco 1 de A para C

Histórico de movimentos:
1: A -> C
2: A -> B
...

Movimentos salvos em 'movimentos.txt'
✅ Próximas melhorias (opcional)
Adicionar Makefile para automatizar compilação (make build, make clean).

Permitir entrada de arquivo com múltiplos testes.

Implementar interface web ou gráfica.

Incluir testes unitários para verificar integridade das estruturas.

📝 Licença
Projeto sob licença MIT. Veja LICENSE para detalhes.

👨‍💻 Contato
Daniel Pinheiro — criador e responsável pelo projeto.
Disciplina: Estrutura de Dados • 2025

