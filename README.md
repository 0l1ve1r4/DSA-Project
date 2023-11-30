# Data Structures & Algorithms II

Este repositório é destinado ao estudo dos alunos de **Algoritmos e Estruturas de Dados II**, oferecendo uma abordagem prática sobre a manipulação de arquivos em memória secundária utilizando a linguagem C. Como exemplo, desenvolvemos uma aplicação para administração de uma biblioteca.

#### Última Atualização da documentação: `30/11/2023`

## Sumário

1. [Requisitos](#requisitos)
2. [Como Usar/Instalar](#uso)
3. [Detalhes do Projeto - Parte Lógica](#source)
4. [Contribuição](#contribuição)

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

1. Compile o código-fonte diretamente pelo bat (dentro do diretório do repositório):

```shell windows 
.\compile.bat
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

4. (Voce também pode alterar o compile.bat para facilitar o processo repetitivo)

**Observação** Se houver bugs na compilação, você pode apagar todos os arquivos e pastas de manipulação de janelas, sendo eles:
- `./windows_main.c`
- `./src/window_functions`

## Source

Nesta seção, abordaremos como os códigos funcionam

Fique tranquilo, na pasta `./src`, você encontrará tudo documentado nos headers, boa leitura!


<img src="assets/readme/f1.png" alt="Comentários">

#### Observações Gerais:

- Cada script é independente e contém suas próprias janelas e funcionalidades específicas.
- O cuidado com a manipulação de arquivos e a validação de entrada do usuário são considerações importantes em todos os scripts. e suas implementações estão em `/src/estruturas.c`
- Os scripts podem ser compilados separadamente, e suas funcionalidades podem ser integradas conforme necessário.


## Contribuição

Estamos abertos a contribuições e melhorias neste projeto. Se você deseja contribuir ou sugerir aprimoramentos, sinta-se à vontade para abrir problemas, enviar solicitações de pull e colaborar no desenvolvimento.
