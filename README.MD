# Torre de Hanói 🗼 — Estrutura de Dados em C

Este repositório contém a implementação completa da clássica **Torre de Hanói**, desenvolvida em linguagem **C** como projeto final da disciplina de **Estrutura de Dados**. O programa simula, no terminal, o deslocamento dos discos entre torres utilizando **estruturas de pilhas**, **listas encadeadas** para o histórico de jogadas e **arquivos de texto** para persistência dos dados. Todo o desenvolvimento segue boas práticas de **versionamento com Git**.

---

## 🔍 Visão Geral

O projeto tem como foco aplicar, na prática, os conceitos aprendidos ao longo da disciplina. A proposta foi simular o desafio lógico das torres com o uso de ponteiros, estruturas dinâmicas e organização modular do código em C.

### Funcionalidades:

- Inicialização de torres com número de discos definido pelo usuário.
- Movimentação automática dos discos via algoritmo recursivo.
- Registro de cada movimento em uma **lista encadeada**.
- Salvamento do histórico completo em um arquivo `movimentos.txt`.
- Exibição passo a passo no **terminal**, com visualização clara dos movimentos.
- Estrutura organizada em múltiplos arquivos `.c` e `.h`, com uso de Git para controle de versões.

---

## 🛠️ Tecnologias e Estruturas

- **Linguagem**: C (padrão ANSI)
- **Estruturas usadas**:
  - `Pilha` (para as torres A, B e C)
  - `Lista encadeada` (para armazenar os movimentos)
  - `Arquivo de texto` (registro final dos movimentos)
- **Ferramentas**:
  - Terminal (para entrada/saída)
  - GCC (compilador)
  - Git (versionamento)
  - Makefile (opcional, se estiver usando)

---

## 🚀 Como Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/seuusuario/torre-de-hanoi.git
   cd torre-de-hanoi
Compile com gcc:

bash
Copiar
Editar
gcc main.c pilha.c lista.c -o hanoi
Execute no terminal:

bash
Copiar
Editar
./hanoi
Após a execução, verifique o arquivo movimentos.txt para o histórico.

📁 Estrutura do Repositório
bash
Copiar
Editar
torre-de-hanoi/
├── main.c              # Arquivo principal (controle da execução)
├── pilha.c / pilha.h   # Implementação das pilhas (torres)
├── lista.c / lista.h   # Implementação da lista encadeada (histórico)
├── movimentos.txt      # Saída final dos movimentos realizados
├── .git/               # Pasta de versionamento Git
├── README.md           # Este arquivo
└── (opcional) Makefile
📜 Exemplo de Saída
css
Copiar
Editar
Movendo disco 1 de A para C
Movendo disco 2 de A para B
Movendo disco 1 de C para B
...
Total de movimentos: 7
Histórico salvo em 'movimentos.txt'
📌 Observações
O projeto foi versionado desde sua estrutura inicial.

Commits foram organizados por etapas: estrutura de dados, lógica de jogo, interface terminal, integração de histórico e salvamento em arquivo.

Ideal para estudantes de ciência da computação, engenharia ou cursos técnicos que queiram aprender algoritmos recursivos e manipulação de ponteiros em C.

👨‍💻 Autor
Desenvolvido por [Seu Nome]
Disciplina de Estrutura de Dados — [Nome da Instituição ou Professor]
Ano: 2025

📝 Licença
Distribuído sob a licença MIT. Veja o arquivo LICENSE para mais informações.
