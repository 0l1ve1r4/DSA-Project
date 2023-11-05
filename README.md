# Data Structures & Algorithms II

Este repositório foi construído para o estudo dos alunos de Algoritmos e Estruturas de Dados II, mostrando de forma prática como funciona a manipulação de arquivos em memória secundária em linguagem C. Como exemplo, foi montada uma aplicação que disponibiliza um conjunto de recursos para a administração de uma biblioteca. Com o auxílio deste sistema, é possível supervisionar o controle de exemplares literários, gestão de usuários, registros de editoras e funcionários, etc...

## Requisitos Essenciais

Para a implementação bem-sucedida deste projeto, é indispensável que você disponha das seguintes tecnologias e ferramentas devidamente configuradas:

- **Linguagem de Programação:** [C] - A aplicação foi concebida mediante o uso exclusivo da linguagem de programação C.

- **Banco de Dados:** [Banco de dados personalizado] - O sistema emprega um banco de dados personalizado que armazena informações em arquivos binários localizados na pasta 'bin'.

- **Compilador:** [Minimalist GNU for Windows] - A aplicação foi desenvolvida utilizando o MinGW como compilador. Para garantir o desempenho adequado do programa e evitar potenciais bugs, é altamente recomendado [INSTALAR](https://terminalroot.com.br/2022/12/como-instalar-gcc-gpp-mingw-no-windows.html) o MinGW ou o GCC, pois as correções realizadas no código se baseiam em comandos específicos do compilador.

- **Outras Dependências:** [Windows] - Importante ressaltar que o programa é exclusivamente compatível com o sistema operacional Windows devido à utilização de uma biblioteca gráfica específica, *<windows.h>*.

- **Idiomas:** [PT-BR/EN] - Atualmente, a maioria das funções do programa está em inglês, porém, as mensagens exibidas no terminal são predominantemente apresentadas em português do Brasil.

## Uso

Para começar a usar o Sistema de Gerenciamento de Biblioteca, siga estas etapas:

1. Compile o código-fonte;

```shell windows 
gcc -o window ./src/*.c ./src/buscas/*.c ./windows_main.c

```
2. Isso irá compilar todos os arquivos .c no diretório, após execute o programa principal usando o seguinte comando:
````shell windows
./window.exe
````

## TODO

1. **Entidades e Campos de Dados**
    - ~~Definir a estrutura das entidades principais, como Livros, Usuários e Editoras.~~
    - ~~Especificar os campos de dados para cada entidade, como título, autor, categoria, nome do usuário, etc.~~

2. **Operações de Gerenciamento**
   - Implementar as seguintes operações de gerenciamento:
     - ~~Buscar Livro: Permitir que os usuários pesquisem livros por título, autor, categoria, etc. (de forma sequencial)~~
     - ~~Buscar Livro: Permitir que os usuários pesquisem livros por título, autor, categoria, etc. (de forma binária)~~
     - Realizar Empréstimos: Capacidade de registrar empréstimos de livros com data de início e prazo de devolução.
     - Devolver Livros: Funcionalidade para que os usuários possam devolver livros emprestados, atualizando o status.
     - Registrar Usuários: Possibilitar que funcionários registrem novos membros na biblioteca.
     - Relatórios: Implementar a geração de relatórios, incluindo empréstimos atrasados, livros populares, membros mais ativos, etc.
     - Renovar Empréstimos: Permitir que os usuários estendam o prazo de empréstimo, se disponível.
     - Gerenciar Funcionários: Adicionar e atualizar informações sobre os funcionários da biblioteca.

3. **Melhorias Gerais**
   - ~~Aprimorar a interface do usuário e as mensagens do sistema.~~
   - ~~Refinar o mecanismo de busca e classificação de livros.~~

4. **Documentação**
   - ~~Documentar o código-fonte com comentários detalhados para facilitar a compreensão e manutenção futura.~~


## Contribuição

Estamos abertos a contribuições e melhorias neste projeto. Se você deseja contribuir ou sugerir aprimoramentos, sinta-se à vontade para abrir problemas, enviar solicitações de pull e colaborar no desenvolvimento.
