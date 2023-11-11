# Data Structures & Algorithms II

Este repositório é destinado ao estudo dos alunos de **Algoritmos e Estruturas de Dados II**, oferecendo uma abordagem prática sobre a manipulação de arquivos em memória secundária utilizando a linguagem C. Como exemplo, desenvolvemos uma aplicação para administração de uma biblioteca.

#### Última Atualização da documentação: `11/11/2023`

## Sumário

1. [Requisitos](#requisitos)
2. [Como Usar/Instalar](#uso)
3. [Detalhes do Projeto - Parte Lógica](#source)
   - [./src/bin](#arquivos-binários)
   - [./src/buscas](#buscas)
   - [./src/metodos_ordenacao](#ordenacoes)
4. [Detalhes do Projeto - Parte Visual](#windows-source)
   - [`./src/window_functions/`](#window-functions)
5. [Contribuição](#contribuição)

## Requisitos

Para implementar com sucesso este projeto, você precisa das seguintes tecnologias e ferramentas configuradas:

- **Linguagem de Programação:** [C] - O projeto foi desenvolvido exclusivamente em C.

- **Banco de Dados:** [Banco de dados personalizado] - Utiliza um banco de dados personalizado armazenado em arquivos binários na pasta 'bin'.

- **Compilador:** [Minimalist GNU for Windows] - Desenvolvido usando o MinGW como compilador. Recomendamos [instalar](https://terminalroot.com.br/2022/12/como-instalar-gcc-gpp-mingw-no-windows.html) o MinGW ou GCC para garantir desempenho adequado e evitar bugs, pois as correções se baseiam em comandos específicos do compilador.

- **Sistema Operacional:** [Windows] - Exclusivamente compatível com Windows devido à utilização da biblioteca gráfica *<windows.h>*.

- **Idiomas:** [PT-BR/EN] - A maioria das funções está em inglês, mas as mensagens no terminal são predominantemente em português do Brasil.

## Uso

### Uso Comum

Para começar a usar o Sistema de Gerenciamento de Biblioteca, siga estas etapas:

1. Compile o código-fonte (dentro do diretório do repositório):

```shell windows 
gcc -o window ./src/*.c ./src/buscas/*.c ./src/metodos_ordenacao/*.c ./windows_main.c

```
2. Isso irá compilar todos os arquivos .c no diretório, após execute o programa principal usando o seguinte comando:
````shell windows
./window.exe
````
### Uso Próprio/Modificado

Caso você queira fazer modificações no projeto para que funcione apenas via terminal, recomendo que siga essas etapas para evitar bugs:

1. Crie seu arquivo *main* dentro de `unit_tests/main.c` ;

2. Depois de realizar todas as modificações desejadas para seu programa, compile:
```shell windows 
gcc -o main ./src/*.c ./src/buscas/*.c ./src/metodos_ordenacao/*.c ./unit_tests/*.c 

```
3. Isso irá compilar todos os arquivos .c no diretório `unit_tests/main.c`, após execute o programa principal usando o seguinte comando:
````shell windows
./main.exe
````

**Observação** Se houver bugs na compilação, você pode apagar todos os arquivos e pastas de manipulação de janelas, sendo eles:
- `./windows_main.c`
- `./src/window_functions`

## Source

Nesta seção, abordaremos cada um dos scripts do projeto e seu respectivo uso.

Na pasta `./src`, você encontrará as seguintes pastas e arquivos:

- **"funcionario.c":** Este arquivo contém a estrutura e as funções definidas em seu cabeçalho (_.h_), e realiza a implementação lógica de cada função.

- **"livro.c":** Este arquivo contém a estrutura e as funções definidas em seu cabeçalho (_.h_), e realiza a implementação lógica de cada função.

### Arquivos-Binários

Nesta pasta, todos os arquivos binários do projeto são armazenados. Isso inclui aqueles criados ou modificados durante:

- 3.1.1 Salvamento ou remoção de um livro.
- 3.1.2 Salvamento ou remoção de um funcionário.
- 3.1.3 Realização de empréstimos.

### Buscas

Nesta pasta, estão implementados todos os métodos de busca do projeto, como buscas binárias ou sequenciais. Alguns exemplos de utilização incluem:

- 3.2.1 Buscar um livro e retornar sua estrutura por meio de ponteiros.
- 3.2.2 Buscar um funcionário e retornar sua estrutura por meio de ponteiros.

### Ordenacoes

Nesta pasta, você encontrará os métodos de ordenação mais comumente utilizados na manipulação de arquivos, como:

- 3.3.1 Insertion Sort.
- 3.3.2 Classificações internas por partições.

## Windows-Source
**Obserbação**: Recomendo que estude essa parte e faça alterações se e somente se for por estudo, já que na maioria dos trabalhos dessa disciplina, não é obrigatório parte visual.

A função `WindowProc_Main` dentro do arquivo: `./windows_main.c` é o procedimento de janela para a janela principal da aplicação. Ela lida com várias mensagens, como criação de janela, cliques em botões e destruição. Aqui estão alguns pontos-chave:

- Define o ícone da janela e remove o botão de expansão.

- Cria botões para várias operações relacionadas a livros, funcionários, relatórios e gerenciamento de banco de dados.

- Manipula cliques em botões usando a mensagem `WM_COMMAND`.

- Invoca funções específicas com base no botão clicado, como inserir um livro, buscar um livro, inserir um funcionário e mais.

- Garante uma saída adequada quando a janela é destruída.

A função `main` configura a janela da aplicação, registra a classe da janela e entra no loop de mensagens. Pontos-chave incluem:

- Registra a classe da janela com o nome "MyWindowClass".

- Cria a janela principal com o título "Sistema Biblioteca" e dimensões especificadas.

- Entra no loop de mensagens, manipulando mensagens até que a aplicação seja fechada.

**Observação:** O código utiliza a API do Windows para funcionalidade GUI. Certas operações relacionadas à gestão de livros e funcionários, geração de relatórios e manipulação de banco de dados são acionadas por cliques em botões na janela principal.

## Window-Functions

### Alguns pontos de destaque dos scripts dessas pastas:

- Script cria uma janela para realizar buscas sequenciais em bases de dados desordenadas.

- Interface gráfica para definir o tamanho da base de dados.

- Realiza buscas sequenciais em arquivos binários de funcionários, livros e logs.

- Converte e valida entradas do usuário.

- Manipula arquivos binários de funcionários, livros e logs.

- Realiza buscas binárias em arquivos binários de funcionários, livros e logs.

- Utiliza a Windows API para criar elementos de interface.

- Converte e valida entradas do usuário.

- Remove o botão de maximizar da barra de título da janela.

- Define um ícone para a janela.

#### Observações Gerais:

- Cada script é independente e contém suas próprias janelas e funcionalidades específicas.
- O cuidado com a manipulação de arquivos e a validação de entrada do usuário são considerações importantes em todos os scripts.
- Os scripts podem ser compilados separadamente, e suas funcionalidades podem ser integradas conforme necessário.


## Contribuição

Estamos abertos a contribuições e melhorias neste projeto. Se você deseja contribuir ou sugerir aprimoramentos, sinta-se à vontade para abrir problemas, enviar solicitações de pull e colaborar no desenvolvimento.
