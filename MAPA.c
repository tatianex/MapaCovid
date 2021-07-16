#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h> // necess�rio para usar o setlocale
#include <ctype.h> // biblioteca p/ as fun��es isalpha isdigit toupper tolower

struct fichaPaciente
{
    char nome[50];
    char CPF[14];
    char sexo[1];
    int idade;
    int pontuacao;
    char temFebre[1];
    char temDordeCabeca[1];
    char temSecrecaoNasalOuEspirros[1];
    char temDorOuIrritacaoNaGarganta[1];
    char temTosseSeca[1];
    char temDificuldadeRespiratoria[1];
    char temDoresNoCorpo[1];
    char temDiarreia[1];
    char esteveEmContatoContaminado14dias[1];
    char esteveAglomerado[1];
};

int main()
{
	setlocale(LC_ALL, "portuguese"); // Permite usar acentua��o
    struct fichaPaciente paciente[1]; // Cria a primeira ficha de paciente
    paciente[0].pontuacao = 0; // Inicia a pontua��o do usu�rio em 0, sen�o os c�lculos n�o funcionam
    
    FILE * arq;
    arq = fopen("arquivo.txt", "w");
    
    printf("FACA SEU CADASTRO: \n");
    
    printf("Digite seu CPF: \n");
    scanf("%s", &paciente[0].CPF);
    fflush(stdin);
    fprintf(arq, " CPF: ");
    fprintf(arq, "%s", &paciente[0].CPF);
    
    printf("Digite seu Nome: \n");
    scanf("%s", &paciente[0].nome);
    fflush(stdin);
    fprintf(arq, "\n Nome: ");
    fprintf(arq, "%s", &paciente[0].nome);
    
    printf("Digite seu Sexo: F - Feminino OU M - Masculino \n");
    scanf("%s", &paciente[0].sexo);   
    fflush(stdin);
    fprintf(arq, "\n Sexo: ");
    fprintf(arq, "%s", &paciente[0].sexo);
    
    printf("Digite sua Idade: \n");
    scanf("%i", &paciente[0].idade);
    fflush(stdin);
    fprintf(arq, "\n Idade: ");
    fprintf(arq, "%i", paciente[0].idade);
    
    char temFebre;
    while ((temFebre != 'S') && (temFebre != 'N'))
    {
        printf("Voc� tem Febre? S - SIM OU N - N�O\n");
        scanf("%s", &temFebre);
        temFebre = toupper(temFebre);
        fflush(stdin);
    }
    strcpy(paciente[0].temFebre, &temFebre);
    
    if (temFebre == 'S')  paciente[0].pontuacao += 5;
    
    char temDordeCabeca;
    while ((temDordeCabeca != 'S') && (temDordeCabeca != 'N'))
    {
        printf("Voc� tem Dor de cabe�a? S - SIM OU N - N�O\n");
        scanf("%s", &temDordeCabeca);
        temDordeCabeca = toupper(temDordeCabeca);
        fflush(stdin);
    }
    strcpy(paciente[0].temDordeCabeca, &temDordeCabeca);
    
    if (temDordeCabeca == 'S') paciente[0].pontuacao += 1 ;
    
    char temSecrecaoNasalOuEspirros;
    while ((temSecrecaoNasalOuEspirros != 'S') && (temSecrecaoNasalOuEspirros != 'N'))
    {
        printf("Voc� tem Secre��o Nasal ou Espirros? S - SIM OU N - N�O\n");
        scanf("%s", &temSecrecaoNasalOuEspirros);
        temSecrecaoNasalOuEspirros = toupper(temSecrecaoNasalOuEspirros);
        fflush(stdin);
    }
    strcpy(paciente[0].temSecrecaoNasalOuEspirros, &temSecrecaoNasalOuEspirros);
    
    if (temSecrecaoNasalOuEspirros == 'S') paciente[0].pontuacao += 1;
    
    char temDorOuIrritacaoNaGarganta;
    while ((temDorOuIrritacaoNaGarganta != 'S') && (temDorOuIrritacaoNaGarganta != 'N'))
    {
        printf("Voc� tem Dor ou Irrita��o na Garganta? S - SIM OU N - N�O\n");
        scanf("%s", &temDorOuIrritacaoNaGarganta);
        temDorOuIrritacaoNaGarganta = toupper(temDorOuIrritacaoNaGarganta);
        fflush(stdin);
    }
    strcpy(paciente[0].temDorOuIrritacaoNaGarganta, &temDorOuIrritacaoNaGarganta);
    
    if (temDorOuIrritacaoNaGarganta == 'S') paciente[0].pontuacao += 1;
    
    char temTosseSeca;
    while ((temTosseSeca != 'S') && (temTosseSeca != 'N'))
    {
        printf("Voc� tem Tosse Seca? S - SIM OU N - N�O\n");
        scanf("%s", &temTosseSeca);
        temTosseSeca = toupper(temTosseSeca);
        fflush(stdin);
    }
    strcpy(paciente[0].temTosseSeca, &temTosseSeca);
    
    if (temTosseSeca == 'S') paciente[0].pontuacao += 3;
    
    char temDificuldadeRespiratoria;
    while ((temDificuldadeRespiratoria != 'S') && (temDificuldadeRespiratoria != 'N'))
    {
        printf("Voc� tem Dificuldade Respirat�ria? S - SIM OU N - N�O\n");
        scanf("%s", &temDificuldadeRespiratoria);
        temDificuldadeRespiratoria = toupper(temDificuldadeRespiratoria);
        fflush(stdin);
    }
    strcpy(paciente[0].temDificuldadeRespiratoria, &temDificuldadeRespiratoria);
    
    if (temDificuldadeRespiratoria == 'S') paciente[0].pontuacao += 10;
    
    char temDoresNoCorpo;
    while ((temDoresNoCorpo != 'S') && (temDoresNoCorpo != 'N'))
    {
        printf("Voc� tem Dores no Corpo? S - SIM OU N - N�O\n");
        scanf("%s", &temDoresNoCorpo);
        temDoresNoCorpo = toupper(temDoresNoCorpo);
        fflush(stdin);
    }
    strcpy(paciente[0].temDoresNoCorpo, &temDoresNoCorpo);
    
    if (temDoresNoCorpo == 'S') paciente[0].pontuacao += 1;
    
    char temDiarreia;
    while ((temDiarreia != 'S') && (temDiarreia != 'N'))
    {
        printf("Voc� tem Diarr�ia? S - SIM OU N - N�O\n");
        scanf("%s", &temDiarreia);
        temDiarreia = toupper(temDiarreia);
        fflush(stdin);
    }
    strcpy(paciente[0].temDiarreia, &temDiarreia);
    
    if (temDiarreia == 'S') paciente[0].pontuacao += 1;
    
    char esteveEmContatoContaminado14dias;
    while ((esteveEmContatoContaminado14dias != 'S') && (esteveEmContatoContaminado14dias != 'N'))
    {
        printf("Voc� esteve em contato com contaminado por Covid nos �ltimos 14 dias? S - SIM OU N - N�O\n");
        scanf("%s", &esteveEmContatoContaminado14dias);
        esteveEmContatoContaminado14dias = toupper(esteveEmContatoContaminado14dias);
        fflush(stdin);
    }
    strcpy(paciente[0].esteveEmContatoContaminado14dias, &esteveEmContatoContaminado14dias);
    
    if (esteveEmContatoContaminado14dias == 'S') paciente[0].pontuacao += 10;
    
    char esteveAglomerado;
    while ((esteveAglomerado != 'S') && (esteveAglomerado != 'N'))
    {
        printf("Voc� esteve em alguma aglomera��o? S - SIM OU N - N�O\n");
        scanf("%s", &esteveAglomerado);
        esteveAglomerado = toupper(esteveAglomerado);
        fflush(stdin);
    }
    strcpy(paciente[0].esteveAglomerado, &esteveAglomerado);
    
    if (esteveAglomerado == 'S') paciente[0].pontuacao += 3;
    
    printf("SUA PONTUACAO: ");
    printf("%i", paciente[0].pontuacao);
    printf(" PONTOS");
    printf("\n");
    fflush(stdin);
    fprintf(arq, "\n Total de Pontua��o: ");
    fprintf(arq, "%d", paciente[0].pontuacao);
    
    if (paciente[0].pontuacao <= 9) 
    {
        printf("Seu risco para Covid � baixo, dirija-se ao setor: risco baixo. Obrigado!");
        fflush(stdin);
    }
    else 
    {
        if (paciente[0].pontuacao <= 19) 
        {
            printf("Seu risco para Covid � m�dio, dirija-se ao setor: Risco Medio. Obrigado!");
            fflush(stdin);            
        }
        else
        {
            printf("Seu risco para Covid � ALTO, dirija-se ao setor: RISCO ALTO!. Obrigado!");
            fflush(stdin);
        }
    }
    
    fclose(arq);
    return 0;
}