#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Validar preenchimento da informacao de entrada
validarEntrada(char input[], int lenInput)
{
    // Valida se o usuario preencheu o campo com o tamanho esperado
    int lenNumber = strlen(input);
    if (lenInput != lenNumber)
    {
        return false;
    }

    // Valida se o usuario informou zero no valor
    int valInput = strtol(input, NULL, 10);
    if (valInput == 0)
    {
        return false;
    }

    // Verifica se existe caracter com espaco ou nullo na string
    for(int i=0; i < lenNumber; i++)
    {
        if (input[i] == ' ' || input[i] == NULL)
        {
            return false;
        }
    }

    return true;
};


int main(void)
{
    int seqVoto;
    bool entValidada, votGov, votPres;
    char inscricao[12];
    char zona[3];
    char secao[3];
    char turno[1];
    char indVot[1];

    printf("\n +==================================================+ \n");
    printf("\n   * Preparar urna para votacao\n");
    printf("\n       Informe os dados do Titulo de Eleitor:");

    entValidada = false;
    while(!entValidada)
    {
        printf("\n         Inscricao (12 digitos): ");
        scanf("%s",&inscricao);
        entValidada = validarEntrada(inscricao,12);
    }

    entValidada = false;
    while(!entValidada)
    {
        printf("              Zona ( 3 digitos): ");
        scanf("%s",&zona);
        entValidada = validarEntrada(zona,3);
    }
    entValidada = false;
    while(!entValidada)
    {
        printf("             Secao ( 3 digitos): ");
        scanf("%s",&secao);
        entValidada = validarEntrada(secao,3);
    }
    entValidada = false;
    while(!entValidada)
    {
        printf("\n       Infrome: \n         1 - Primeiro turno \n         2 - Segundo turno \n");
        printf("\n       turno: ");
        scanf("%s",&turno);
        entValidada = validarEntrada(turno,1);
    }

    if (turno[0] == '2')
    {
        printf("\n       Informe: \n         S - Sim ou N - Nao \n");
        votGov = false;
        printf("         Havera eleicoes para governador? ");
        scanf("%s",&*indVot);
        *indVot = tolower(*indVot);
        if (*indVot == 's')
        {
            votGov = true;
        }

        *indVot = ' ';
        votPres = false;
        printf("         Havera eleicoes para presidente? ");
        scanf("%s",&*indVot);
        *indVot = tolower(*indVot);
        if (*indVot == 's')
        {
            votPres = true;
        }
    }

    printf("\n +==================================================+ \n");
    printf("\n     Iniciando a votacao\n");

    char confirmacao[1];
    bool numCandidatoOK, votoValido, votoConfirmado;
    int voto;

    seqVoto = 0;
    votoValido = false;

    while (seqVoto < 5 )
    {
        switch(seqVoto)
        {
            case 0:
                if (turno[0] == '1')
                {
                    char numCandidato[4];
                    votoValido = false;
                    while(!votoValido)
                    {
                        printf("\n     Deputado Federal (%i digitos): ",4);
                        scanf("%s",&*numCandidato);
                        voto = strtol(numCandidato, NULL, 10);
                        if (voto > 999 && voto < 10000)
                        {
                            printf("\n         ATENCAO!\n         Seu voto e no candidato: %i \n",voto);
                        }
                        else
                        {
                            if (voto > 0)
                            {
                                printf("\n         ATENCAO!\n         Seu voto e NULO \n");
                            }
                            else
                            {
                                printf("\n         ATENCAO!\n         Seu voto e BRANCO \n");
                            }
                        }
                        votoConfirmado = false;
                        while(!votoConfirmado)
                        {
                            printf("\n         Confirma seu voto? \n           S - Sim ou N - Nao \n");
                            printf("\n         Confirma? ");
                            scanf("%s",&confirmacao);
                            *confirmacao = tolower(*confirmacao);

                            // Valida confirmacao do voto
                            if (*confirmacao == 's' || *confirmacao == 'n')
                            {
                                votoConfirmado = true;
                            }
                        }
                        if (votoConfirmado && confirmacao[0] == 's')
                        {
                            printf("\n confirmado!!! \n");
                            votoValido = true;
                        }
                    }
                printf("\n      Seu voto foi confirmado com sucesso!\n");
                printf("\n +==================================================+ \n");
                }
                break;
            case 1:
                if (turno[0] == '1')
                {
                    char numCandidato[5];
                    votoValido = false;
                    while(!votoValido)
                    {
                        printf("\n     Deputado Estadual (%i digitos): ",5);
                        scanf("%s",&*numCandidato);
                        voto = strtol(numCandidato, NULL, 10);
                        if (voto > 9999 && voto < 100000)
                        {
                            printf("\n         ATENCAO!\n         Seu voto e no candidato: %i \n",voto);
                        }
                        else
                        {
                            if (voto > 0)
                            {
                                printf("\n         ATENCAO!\n         Seu voto e NULO \n");
                            }
                            else
                            {
                                printf("\n         ATENCAO!\n         Seu voto e BRANCO \n");
                            }
                        }
                        votoConfirmado = false;
                        while(!votoConfirmado)
                        {
                            printf("\n         Confirma seu voto? \n           S - Sim ou N - Nao \n");
                            printf("\n         Confirma? ");
                            scanf("%s",&*confirmacao);
                            *confirmacao = tolower(*confirmacao);

                            // Valida confirmacao do voto
                            if (confirmacao[0] == 's' || confirmacao[0] == 'n')
                            {
                                votoConfirmado = true;
                            }
                        }

                        votoValido = false;
                        if (votoConfirmado && confirmacao[0] == 's')
                        {
                            votoValido = true;
                        }
                    }
                printf("\n      Seu voto foi confirmado com sucesso!\n");
                printf("\n +==================================================+ \n");
                }
                break;
            case 2:
                if (turno[0] == '1')
                {
                    char numCandidato[3];
                    votoValido = false;
                    while(!votoValido)
                    {
                        printf("\n               Senador (%i digitos): ",3);
                        scanf("%s",&*numCandidato);
                        voto = strtol(numCandidato, NULL, 10);
                        if (voto > 99 && voto < 1000)
                        {
                            printf("\n         ATENCAO!\n         Seu voto e no candidato: %i \n",voto);
                        }
                        else
                        {
                            if (voto > 0)
                            {
                                printf("\n         ATENCAO!\n         Seu voto e NULO \n");
                            }
                            else
                            {
                                printf("\n         ATENCAO!\n         Seu voto e BRANCO \n");
                            }
                        }
                        votoConfirmado = false;
                        while(!votoConfirmado)
                        {
                            printf("\n         Confirma seu voto? \n           S - Sim ou N - Nao \n");
                            printf("\n         Confirma? ");
                            scanf("%s",&*confirmacao);
                            *confirmacao = tolower(*confirmacao);

                            // Valida confirmacao do voto
                            if (confirmacao[0] == 's' || confirmacao[0] == 'n')
                            {
                                votoConfirmado = true;
                            }
                        }

                        votoValido = false;
                        if (votoConfirmado && confirmacao[0] == 's')
                        {
                            votoValido = true;
                        }
                    }
                printf("\n      Seu voto foi confirmado com sucesso!\n");
                printf("\n +==================================================+ \n");
                }
                break;
            case 3:
                if (turno[0] == '1' || votGov)
                {
                    char numCandidato[2];
                    votoValido = false;
                    while(!votoValido)
                    {
                        printf("\n            Governador (%i digitos): ",2);
                        scanf("%s",&*numCandidato);
                        voto = strtol(numCandidato, NULL, 10);
                        if (voto > 9 && voto < 100)
                        {
                            printf("\n         ATENCAO!\n         Seu voto e no candidato: %i \n",voto);
                        }
                        else
                        {
                            if (voto > 0)
                            {
                                printf("\n         ATENCAO!\n         Seu voto e NULO \n");
                            }
                            else
                            {
                                printf("\n         ATENCAO!\n         Seu voto e BRANCO \n");
                            }
                        }
                        votoConfirmado = false;
                        while(!votoConfirmado)
                        {
                            printf("\n         Confirma seu voto? \n           S - Sim ou N - Nao \n");
                            printf("\n         Confirma? ");
                            scanf("%s",&*confirmacao);
                            *confirmacao = tolower(*confirmacao);

                            // Valida confirmacao do voto
                            if (confirmacao[0] == 's' || confirmacao[0] == 'n')
                            {
                                votoConfirmado = true;
                            }
                        }

                        votoValido = false;
                        if (votoConfirmado && confirmacao[0] == 's')
                        {
                            votoValido = true;
                        }
                    }
                printf("\n      Seu voto foi confirmado com sucesso!\n");
                printf("\n +==================================================+ \n");
                }
                break;
            case 4:
                if (turno[0] == '1' || votPres)
                {
                    char numCandidato[2];
                    votoValido = false;
                    while(!votoValido)
                    {
                        printf("\n            Presidente (%i digitos): ",2);
                        scanf("%s",&*numCandidato);
                        voto = strtol(numCandidato, NULL, 10);
                        if (voto > 9 && voto < 100)
                        {
                            printf("\n         ATENCAO!\n         Seu voto e no candidato: %i \n",voto);
                        }
                        else
                        {
                            if (voto > 0)
                            {
                                printf("\n         ATENCAO!\n         Seu voto e NULO \n");
                            }
                            else
                            {
                                printf("\n         ATENCAO!\n         Seu voto e BRANCO \n");
                            }
                        }
                        votoConfirmado = false;
                        while(!votoConfirmado)
                        {
                            printf("\n         Confirma seu voto? \n           S - Sim ou N - Nao \n");
                            printf("\n         Confirma? ");
                            scanf("%s",&*confirmacao);
                            *confirmacao = tolower(*confirmacao);

                            // Valida confirmacao do voto
                            if (confirmacao[0] == 's' || confirmacao[0] == 'n')
                            {
                                votoConfirmado = true;
                            }
                        }

                        votoValido = false;
                        if (votoConfirmado && confirmacao[0] == 's')
                        {
                            votoValido = true;
                        }
                    }
                printf("\n      Seu voto foi confirmado com sucesso!\n");
                printf("\n +==================================================+ \n");
                }
                break;
        }
        seqVoto += 1;
    }
    printf("\n +==================================================+");
    printf("\n      O Brasil agradece por exercer a cidadania!");
    printf("\n +==================================================+\n\n");
    return 0;
}

