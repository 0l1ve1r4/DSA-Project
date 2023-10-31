# Sistema de Biblioteca - AEDS 2 - UFOP

Bem-vindo ao nosso Sistema de Gerenciamento de Biblioteca, uma aplicação que oferece um conjunto abrangente de recursos para a administração de bibliotecas. Com este sistema, você pode gerenciar livros, usuários, editoras e realizar várias operações relacionadas à biblioteca de forma eficiente.

## Requisitos

Para executar este projeto, você precisa ter as seguintes tecnologias e ferramentas instaladas:

- **Linguagem de Programação:** [C] - A aplicação é desenvolvida em C puro.

- **Banco de Dados:** [Banco de dados personalizado] - Utilizamos um banco de dados personalizado que armazena informações em arquivos binários na pasta 'bin'.

- **Outras Dependências:** [---] - Atualmente, não há outras dependências.

- **Idiomas:** [PT-BR/EN] - Atualmente, a maioria das funções está em inglês, no entanto, as mensagens exibidas no terminal são predominantemente em português do Brasil.

## Funcionalidades

O Sistema de Gerenciamento de Biblioteca oferece as seguintes funcionalidades:

1. **Criação de Bases de Dados**
   - A função `bases_buscas_sequenciais` lida com a criação de bases de dados e a realização de buscas sequenciais em registros de funcionários.
   - Ela permite a abertura de arquivos binários de funcionários, livros e logs para operações subsequentes.

2. **Busca Sequencial de Funcionários**
   - A função `buscarFuncionario_sequencialmente` é responsável por buscar funcionários de forma sequencial em um arquivo de registro.
   - Ela mede o número de iterações necessárias para encontrar um funcionário com um código específico.
   - Registra o tempo gasto na busca e exibe detalhes do funcionário encontrado.
   - Salva informações sobre a busca sequencial em um arquivo de log.

3. **Salvamento de Log**
   - A função `salvar_log_file` é usada para salvar informações detalhadas sobre a busca sequencial em um arquivo de log.
   - Ela registra o número de iterações e o tempo gasto na busca para análise posterior.

4. **Outras funcionalidades**
   - Além das funcionalidades mencionadas, o sistema provavelmente inclui operações de adição, edição, exclusão e consulta de registros de funcionários, bem como operações relacionadas à gestão de livros, editoras e usuários.

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

## Contribuição

Estamos abertos a contribuições e melhorias neste projeto. Se você deseja contribuir ou sugerir aprimoramentos, sinta-se à vontade para abrir problemas, enviar solicitações de pull e colaborar no desenvolvimento.
