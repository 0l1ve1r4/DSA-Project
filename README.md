# Sistema de Biblioteca - AEDS 2 - UFOP

Bem-vindo ao nosso Sistema de Gerenciamento de Biblioteca, uma aplicação que oferece um conjunto abrangente de recursos para a administração de bibliotecas. Com este sistema, você pode gerenciar livros, usuários, editoras e realizar várias operações relacionadas à biblioteca de forma eficiente.

## Requisitos

Para executar este projeto, você precisa ter as seguintes tecnologias e ferramentas instaladas:

- **Linguagem de Programação:** [C] - A aplicação é desenvolvida em C puro.

- **Banco de Dados:** [Banco de dados personalizado] - Utilizamos um banco de dados personalizado que armazena informações em arquivos binários na pasta 'bin'.

- **Outras Dependências:** [---] - Atualmente, não há outras dependências.

- **Idiomas:** [PT-BR/EN] - Atualmente, a maioria das funções está em inglês, no entanto, as mensagens exibidas no terminal são predominantemente em português do Brasil.

## Uso

Para começar a usar o Sistema de Gerenciamento de Biblioteca, siga estas etapas:

1. Compile o código-fonte, se necessário.

```shell windows or linux
gcc -o app ./*.c

```
2. Execute o programa principal usando o seguinte comando:
````windows shell
./nome_do_programa
````

## TODO

1. **Entidades e Campos de Dados**
   ~~- Definir a estrutura das entidades principais, como Livros, Usuários e Editoras.~~
  ~~- Especificar os campos de dados para cada entidade, como título, autor, categoria, nome do usuário, etc.~~

2. **Operações de Gerenciamento**
   - Implementar as seguintes operações de gerenciamento:
     ~~- Buscar Livro: Permitir que os usuários pesquisem livros por título, autor, categoria, etc. (de forma sequencial)~~
     - Buscar Livro: Permitir que os usuários pesquisem livros por título, autor, categoria, etc. (de forma binária)
     - Realizar Empréstimos: Capacidade de registrar empréstimos de livros com data de início e prazo de devolução.
     - Devolver Livros: Funcionalidade para que os usuários possam devolver livros emprestados, atualizando o status.
     - Registrar Usuários: Possibilitar que funcionários registrem novos membros na biblioteca.
     - Relatórios: Implementar a geração de relatórios, incluindo empréstimos atrasados, livros populares, membros mais ativos, etc.
     - Renovar Empréstimos: Permitir que os usuários estendam o prazo de empréstimo, se disponível.
     - Gerenciar Funcionários: Adicionar e atualizar informações sobre os funcionários da biblioteca.

3. **Melhorias Gerais**
   - Aprimorar a interface do usuário e as mensagens do sistema.
   - Refinar o mecanismo de busca e classificação de livros.
   - Implementar medidas de segurança para proteger os dados sensíveis.

4. **Documentação**
   - Documentar o código-fonte com comentários detalhados para facilitar a compreensão e manutenção futura.


## Contribuição

Estamos abertos a contribuições e melhorias neste projeto. Se você deseja contribuir ou sugerir aprimoramentos, sinta-se à vontade para abrir problemas, enviar solicitações de pull e colaborar no desenvolvimento.
