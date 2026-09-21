#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //=======Declaração das variaveis=======//
    int qtd_participantes, qtd_jogadores_por_time, qtd_computadores_disponiveis;
    float potencia, duracao, preco_kwh, preco_kit, outros_custos, orcamento, quantidade_de_times,
        Consumo_de_energia, Custo_da_energia, Custo_da_alimentacao, Custo_total, Custo_por_participante, Saldo_do_orcamento;

    // ========Entrada e armazenamento de dados========//
    printf("Quantidade total de participantes: ");
    scanf("%d", &qtd_participantes);
    printf("Quantidade de jogadores em cada time: ");
    scanf("%d", &qtd_jogadores_por_time);
    printf("Quantidade de computadores disponiveis: ");
    scanf("%d", &qtd_computadores_disponiveis);
    printf("Potencia media de cada computador, em watts: ");
    scanf("%f", &potencia);
    printf("Duracao do evento em horas: ");
    scanf("%f", &duracao);
    printf("Preco de 1 kWh de energia: ");
    scanf("%f", &preco_kwh);
    printf("Preco de um kit de alimentacao por participante: ");
    scanf("%f", &preco_kit);
    printf("Custos do evento: ");
    scanf("%f", &outros_custos);
    printf("Orcamento maximo disponivel para o evento : ");
    scanf("%f", &orcamento);

    // ======Tratamento de dados======//
    quantidade_de_times = ceil((float)qtd_participantes / qtd_jogadores_por_time);
    Consumo_de_energia = (qtd_computadores_disponiveis * potencia * duracao) / 1000;
    Custo_da_energia = (Consumo_de_energia * preco_kwh);
    Custo_da_alimentacao = (qtd_participantes * preco_kit);
    Custo_total = (Custo_da_energia + Custo_da_alimentacao + outros_custos);
    Custo_por_participante = (Custo_total / qtd_participantes);
    Saldo_do_orcamento = (orcamento - Custo_total);

    //=======Exibição dos resultados=======//
    printf("\n===== RESULTADOS =====\n");
    printf("Quantidade de times: %.0f\n", quantidade_de_times);
    printf("Consumo de energia: %.2f kWh\n", Consumo_de_energia);
    printf("Custo da energia: R$ %.2f\n", Custo_da_energia);
    printf("Custo da alimentacao: R$ %.2f\n", Custo_da_alimentacao);
    printf("Custo total: R$ %.2f\n", Custo_total);
    printf("Custo por participante: R$ %.2f\n", Custo_por_participante);
    printf("Saldo do orcamento: R$ %.2f\n", Saldo_do_orcamento);

    //=======Tomada de decisões=======//

    //===Verificar a infraestrutura===//
    if (qtd_computadores_disponiveis >= qtd_participantes)
    {
        printf("Infraestrutura: suficiente \n");
    }
    else
    {
        printf("Infraestrutura: insuficiente \n");
    }

    //===Classificacao do consumo de energia===//
    if (Consumo_de_energia <= 20)
    {
        printf("Consumo: Baixo \n");
    }
    else if (Consumo_de_energia <= 40)
    {
        printf("Consumo: Moderado \n");
    }
    else
    {
        printf("Consumo: Alto \n");
    }

    //===Verificar orçamentos===//
    if (Custo_total > orcamento)
    {
        printf("Acima do orcamento \n");
    }
    else if (Saldo_do_orcamento <= (orcamento * 0.05))
    {
        printf("No limite do orcamento\n");
    }
    else
    {
        printf("Dentro do orcamento \n");
    }

    //====Decisão final sobre o evento====//
    if (qtd_computadores_disponiveis < qtd_participantes || Custo_total > orcamento)
    {
        printf("Decisao final: NAO RECOMENDADO\n");
    }

    else if (Consumo_de_energia > 40)
    {
        printf("Decisao final: APROVADO COM RESSALVAS\n");
    }
    else
    {
        printf("Decisao final: APROVADO\n");
    }

    return 0;
}

