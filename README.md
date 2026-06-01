# Dicionário com Tabela Hash em C

Projeto foi desenvolvido para a atividade 3 de Estrutura de Dados, administrado pelos professores Gabriel e João Goku, com objetivo acadamico para apredemos sobre a tabela Hash na linguagem em c.

##  Objetivo

Implementar um sistema de dicionário utilizando Tabela Hash em linguagem C, aplicando conceitos fundamentais de:

- Estruturas de Dados
- Ponteiros
- Alocação Dinâmica de Memória
- Listas Encadeadas
- Tratamento de Colisões

##  Funcionalidades

O sistema permite:

✅ Inserir palavras e definições

✅ Buscar palavras cadastradas

✅ Remover palavras

✅ Exibir a tabela hash completa

✅ Exibir estatísticas da tabela

✅ Tratar colisões utilizando listas encadeadas

##  Estrutura Utilizada

Cada registro do dicionário armazena:

```c
Palavra
Definição
Ponteiro para o próximo nó
```

As colisões são resolvidas através de listas encadeadas em cada posição da tabela hash.

##  Função Hash

A função hash utilizada realiza a soma dos valores ASCII dos caracteres da palavra e aplica o operador módulo (%) pelo tamanho da tabela.

Exemplo:

```txt
Hash

H = 72
a = 97
s = 115
h = 104

Total = 388

388 % 10 = 8
```

## Estatísticas Disponíveis

O sistema calcula:

- Número total de elementos
- Número de colisões
- Fator de carga
- Maior lista encadeada

## Conceitos Aplicados

- Tabela Hash
- Listas Encadeadas
- Alocação Dinâmica (`malloc`)
- Liberação de Memória (`free`)
- Manipulação de Strings
- Busca e Remoção de Dados

##  Como Executar

Compile o programa:

```bash
gcc Tabela_Hash.c -o dicionario
```

Execute:

```bash
./dicionario
```

## 📂 Estrutura do Projeto

```txt
📁 Projeto
 ├── Tabela_Hash.c
 └── README.md
```

##  Professor

João ("Goku")

##  Integrantes

- Adryan
- Bruna
- Davi
- Julio
- Natália
- Pedro Woruby
