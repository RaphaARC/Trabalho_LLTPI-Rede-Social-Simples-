## 📌 EchoFeed – Simulação de Feed Social em C++
Simulação de um backend de rede social em C++, executado via terminal, com foco em ponteiros e gerenciamento manual de memória.

## 📚 Contexto e aprendizados
Projeto acadêmico focado em fundamentos de C++, com ênfase em controle de memória e estruturas de dados de baixo nível. 
Nesse pequeno projeto nos preocupamos com:

- Gerenciamento manual de memória
- Consistência entre múltiplas estruturas de dados
- Modelagem de sistemas sem abstrações modernas

## 🧠 Descrição
O EchoFeed implementa um sistema de feed social com usuários, posts e interações (curtidas), modelando relações 
entre dados e garantindo consistência.

## ⚙️ Funcionalidades
- Cadastro de usuários e posts
- Listagem de feed completo e filtrado (público)
- Suspensão e reativação de usuários
- Controle de visibilidade de posts
- Registro de curtidas com validação (sem duplicidade)
- Matriz usuário × post para controle de interações
- Busca por ID

## 🚀 Compilação
</> Terminal

$ g++ core/main/main.cpp core/src/*.cpp assets/icon.res -o EchoFeed.exe -static -static-libgcc -static-libstdc++

## 🧩 Conceitos aplicados
- Ponteiros e aritmética de ponteiros
- Alocação dinâmica (new / delete)
- Matrizes dinâmicas (int**)
- Validação de dados e regras de negócio
- Organização modular em múltiplos arquivos

## 👥 Autores

- RAPHAEL AUGUSTO ROCHA COSTA — Arquitetura geral, interface de menu, integração geral e revisão de código (...)
- LUIZ FELIPE BRAZ OLIVEIRA — Implementação de usuários e posts, busca de usuário por ID e sistema de curtidas (...)
- GABRIEL LOPES DE SOUZA NEVES BRASIL — Busca de posts por ID, contagem de posts (por ID e usuário), ocultação e publicação de posts (...)
- ARTHUR ALVES SANTOS — Sistema de administração dos usuários (usuário suspenso ou não), (...)
