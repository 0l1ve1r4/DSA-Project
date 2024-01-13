// Dados dos gráficos
const quicksortData = {
    labels: ['1000', '10000', '50000'], // Rótulos para o eixo X (Tamanho do Conjunto de Dados)
    datasets: [{
        label: 'Funcionários', // Rótulo do primeiro conjunto de dados
        data: [0.007, 0.501, 36.723], // Valores do primeiro conjunto de dados (tempos em segundos)
        backgroundColor: 'rgba(255, 99, 132, 0.2)', // Cor de fundo para o gráfico de barras
        borderColor: 'rgba(255, 99, 132, 1)', // Cor da borda das barras
        borderWidth: 1 // Largura da borda das barras
    }, {
        label: 'Livros', // Rótulo do segundo conjunto de dados
        data: [0.010, 0.387, 85.984], // Valores do segundo conjunto de dados (tempos em segundos)
        backgroundColor: 'rgba(54, 162, 235, 0.2)', // Cor de fundo para o gráfico de barras
        borderColor: 'rgba(54, 162, 235, 1)', // Cor da borda das barras
        borderWidth: 1 // Largura da borda das barras
    }]
};

const naturalSelectionData = {
    labels: ['1000', '10000', '50000'],
    datasets: [{
        label: 'Classificação',
        data: [0.203, 2.418, 5.677],
        backgroundColor: 'rgba(255, 206, 86, 0.2)',
        borderColor: 'rgba(255, 206, 86, 1)',
        borderWidth: 1
    }, {
        label: 'Intercalação',
        data: [0.232, 1.009, 2.146],
        backgroundColor: 'rgba(75, 192, 192, 0.2)',
        borderColor: 'rgba(75, 192, 192, 1)',
        borderWidth: 1
    }]
};

// Opções comuns para os gráficos
const commonOptions = {
    scales: {
        y: {
            beginAtZero: true, // Começar o eixo Y a partir de zero
            title: {
                display: true,
                text: 'Tempo (segundos)' // Rótulo do eixo Y
            },
            ticks: {
                beginAtZero: true,
                callback: function(value) {
                    // Formatar valores pequenos com precisão de 4 casas decimais
                    return value.toFixed(4);
                }
            }
        },
        x: {
            title: {
                display: true,
                text: 'Tamanho do Conjunto de Dados' // Rótulo do eixo X
            }
        }
    },
    plugins: {
        datalabels: {
            display: true,
            color: '#444',
            align: 'top',
            formatter: function(value, context) {
                return value.toFixed(3); // Formatar números com precisão de 3 casas decimais
            }
        }
    },
    responsive: true,
    maintainAspectRatio: false,
    tooltips: {
        enabled: true,
        mode: 'index',
        intersect: false,
        callbacks: {
            label: function(tooltipItem, data) {
                let label = data.datasets[tooltipItem.datasetIndex].label || '';
                if (label) {
                    label += ': ';
                }
                // Aumentar a precisão para 4 casas decimais para tempos pequenos
                label += Number(tooltipItem.yLabel).toFixed(4) + ' s';
                return label;
            }
        }
    }
};

// Criação dos gráficos
const quicksortGraph = new Chart(document.getElementById('quicksortGraph'), {
    type: 'bar',
    data: quicksortData,
    options: commonOptions
});

const naturalSelectionGraph = new Chart(document.getElementById('naturalSelectionGraph'), {
    type: 'bar',
    data: naturalSelectionData,
    options: commonOptions
});

// Função para atualizar o tipo de gráfico
function updateChartType(chart, newType) {
    chart.config.type = newType;
    chart.update();
}

// Função para filtrar dados
function filterData(chart, size) {
    const filteredData = chart.data.datasets.map(dataset => {
        return {
            ...dataset,
            data: dataset.data.filter((_, index) => chart.data.labels[index] === size)
        };
    });

    chart.data.datasets = filteredData;
    chart.update();
}

// Armazena os dados originais
const originalQuicksortData = JSON.parse(JSON.stringify(quicksortData));
const originalNaturalSelectionData = JSON.parse(JSON.stringify(naturalSelectionData));

// Função para filtrar dados
function filterData(chart, originalData, size) {
    const filteredData = originalData.datasets.map(dataset => {
        return {
            ...dataset,
            data: dataset.data.filter((_, index) => originalData.labels[index] === size)
        };
    });

    chart.data.datasets = filteredData;
    chart.update();
}

// Função para resetar os dados do gráfico para o original
function resetData(chart, originalData) {
    chart.data = JSON.parse(JSON.stringify(originalData));
    chart.update();
}

// Combinando dados da Seleção Natural com Intercalação Ótima
const combinedNaturalSelectionData = naturalSelectionData.datasets[0].data.map((value, index) => {
    return value + naturalSelectionData.datasets[1].data[index];
});

const combinedQuicksortData = quicksortData.datasets[0].data.map((value, index) => {
    return value + quicksortData.datasets[1].data[index];
});

// Dados de comparação
const comparisonData = {
    labels: ['1000', '10000', '50000'],
    datasets: [
        {
            label: 'Quicksort - Combinado',
            data: combinedQuicksortData,
            backgroundColor: 'rgba(255, 159, 64, 0.2)',
            borderColor: 'rgba(255, 159, 64, 1)',
            borderWidth: 1
        },
        {
            label: 'Seleção Natural com Intercalação Ótima',
            data: combinedNaturalSelectionData,
            backgroundColor: 'rgba(75, 192, 192, 0.2)',
            borderColor: 'rgba(75, 192, 192, 1)',
            borderWidth: 1
        }
    ]
};

// Criar gráfico de comparação
const comparisonGraph = new Chart(document.getElementById('comparisonGraph'), {
    type: 'bar',
    data: comparisonData,
    options: commonOptions
});

// Função para alternar entre visualização de gráfico e tabela
function toggleView(chartId) {
    let graph = document.getElementById(chartId + 'Graph');
    let table = document.getElementById(chartId + 'Table');
    let button = document.querySelector(`#${chartId} button`);

    if (graph.style.display !== 'none') {
        graph.style.display = 'none';
        table.style.display = 'table';
        button.textContent = 'Alternar para Gráfico';
        fillTable(chartId);
    } else {
        graph.style.display = 'block';
        table.style.display = 'none';
        button.textContent = 'Alternar para Tabela';
    }
}

// Função para preencher a tabela com dados
function fillTable(chartId) {
    let table = document.getElementById(chartId + 'Table');
    let data;
    switch (chartId) {
        case 'quicksort':
            data = quicksortData;
            break;
        case 'naturalSelection':
            data = naturalSelectionData;
            break;
        case 'comparison':
            data = comparisonData;
            break;
    }

    let html = `<tr><th>Tamanho</th><th>${chartId === 'comparison' ? 'Quicksort' : 'Funcionários'}</th><th>${chartId === 'comparison' ? 'Intercalação com Seleção' : 'Livros'}</th></tr>`;
    data.labels.forEach((label, index) => {
        html += `<tr>
                    <td>${label}</td>
                    <td>${data.datasets[0].data[index].toFixed(3)} segundos</td>
                    <td>${data.datasets[1].data[index].toFixed(3)} segundos</td>
                </tr>`;
    });

    table.innerHTML = html;
}
