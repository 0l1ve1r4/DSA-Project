document.addEventListener("DOMContentLoaded", function() {
    const insertForm = document.getElementById('insertForm');
    const searchForm = document.getElementById('searchForm');
    const removeForm = document.getElementById('removeForm');
    const hashTableDisplay = document.getElementById('hashTableDisplay');

    let hashTable = {};

    // Função hash aprimorada
    function hash(key) {
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash << 5) - hash + key.charCodeAt(i);
            hash = hash & hash; // Convert to 32bit integer
        }
        return Math.abs(hash) % 5; // Simples mod para limitar índices de 0 a 4
    }

    function insertIntoHashTable(key, value) {
        const hashKey = hash(key);
        if (!hashTable[hashKey]) {
            hashTable[hashKey] = [];
        }
        const item = { key, value };
        // Encontra o índice do elemento, se existir
        const existingIndex = hashTable[hashKey].findIndex(element => element.key === key);
        if (existingIndex > -1) {
            hashTable[hashKey][existingIndex] = item; // Atualiza elemento existente
        } else {
            hashTable[hashKey].push(item); // Insere novo elemento
        }
        displayHashTable();
        alert(`Elemento inserido: ${key} -> ${value}`);
    }

    function searchInHashTable(key) {
        const hashKey = hash(key);
        const element = hashTable[hashKey]?.find(element => element.key === key);
        if (element) {
            alert(`Valor encontrado: ${element.value}`);
        } else {
            alert('Chave não encontrada');
        }
    }

    function removeFromHashTable(key) {
        const hashKey = hash(key);
        const index = hashTable[hashKey]?.findIndex(element => element.key === key);
        if (index > -1) {
            hashTable[hashKey].splice(index, 1);
            if (!hashTable[hashKey].length) delete hashTable[hashKey]; // Remove o índice se estiver vazio
            displayHashTable();
            alert(`Elemento removido: ${key}`);
        } else {
            alert('Chave não encontrada para remoção');
        }
    }

    function displayHashTable() {
        hashTableDisplay.innerHTML = '<h3>Tabela Hash Atual (com Encadeamento Externo):</h3>';
        Object.keys(hashTable).forEach(hashKey => {
            const items = hashTable[hashKey].map(item => `<li>${item.key}: ${item.value}</li>`).join('');
            hashTableDisplay.innerHTML += `<div>Índice ${hashKey}: <ul>${items}</ul></div>`;
        });
    }

    insertForm.addEventListener('submit', function(event) {
        event.preventDefault();
        const key = document.getElementById('insertKey').value.trim();
        const value = document.getElementById('insertValue').value.trim();
        if (key && value) {
            insertIntoHashTable(key, value);
        } else {
            alert('Por favor, preencha ambos os campos chave e valor.');
        }
    });

    searchForm.addEventListener('submit', function(event) {
        event.preventDefault();
        const key = document.getElementById('searchKey').value.trim();
        if (key) {
            searchInHashTable(key);
        } else {
            alert('Por favor, preencha o campo de chave para busca.');
        }
    });

    removeForm.addEventListener('submit', function(event) {
        event.preventDefault();
        const key = document.getElementById('removeKey').value.trim();
        if (key) {
            removeFromHashTable(key);
        } else {
            alert('Por favor, preencha o campo de chave para remoção.');
        }
    });

    displayHashTable();
});

document.querySelectorAll('img').forEach(img => {
    img.onclick = function() {
        const modal = document.getElementById('myModal');
        const modalImg = document.getElementById('img01');
        const captionText = document.getElementById('caption');
        modal.style.display = "block";
        modalImg.src = this.src;
        captionText.innerHTML = this.alt;
    }
});

const span = document.getElementsByClassName("close")[0];
span.onclick = function() {
    const modal = document.getElementById('myModal');
    modal.style.display = "none";
}