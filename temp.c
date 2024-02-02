
/*
int main() {
    // Crie a tabela hash
    HashTable *ht = (HashTable*) malloc(sizeof(HashTable));

    // Inicialize a tabela hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }

    // Crie alguns dados para inserir na tabela hash
    TFunc func1 = {1, "Nome Func1", "CPF Func1", "Data Nasc Func1", 1000.0};
    TCliente cliente1 = {"Nome Cliente1", "CPF Cliente1"};
    TLivro livro1 = {1, "Nome Livro1", 100, "Autor Livro1", "Editora Livro1", "Data Emprestimo Livro1", 50.0, &func1, &cliente1};

    // Insira os dados na tabela hash
    insert(ht, livro1.cod, &livro1);

    // Carregue a tabela hash de um arquivo

    saveHashTable(ht);

    HashTable *loadedHt = loadHashTable();

    // Busque os dados na tabela hash
    TLivro *livroBuscado = (TLivro*) search(loadedHt, livro1.cod);
    if (livroBuscado != NULL) {
        printf("Livro encontrado: %s\n", livroBuscado->nome);
    } else {
        printf("Livro não encontrado.\n");
    }

    


    return 0;
}


*/