//Gabriela La�s Pereira         RA:201025752

//fontes: keys2cognition.com , personality-database.com , personalityatwork.co , dftbar.com

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

char a;
int Sek=0, Sik=0, Nek=0, Nik=0, Tek=0, Tik=0, Fek=0, Fik=0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void moveXY(int x, int y, char t[10]) //cursor
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetColor(int ForgC) //cores
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void boasvindas() //inicio
{
    SetColor(0);
    moveXY(47, 13, "BEM VINDO AO TESTE DE MBTI!");
    moveXY(41,29,"desenvolvido por Gabriela La�s Pereira");

    //desenho quadrado duplo
    int astX,astY;
    //primeiro quadrado
    for (astX=37 ; astX<84 ; astX++)
    {
        moveXY(astX,11,"_");
    }
    for (astX=37 ; astX<84 ; astX++)
    {
        moveXY(astX,16,"_");
    }
    for (astY=12 ; astY<17 ; astY++)
    {
        moveXY(36,astY,"|");
    }
    for (astY=12 ; astY<17 ; astY++)
    {
        moveXY(84,astY,"|");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void instrucoes() //iniciar teste->instrucoes
{
    SetColor(4);
    moveXY(48,10,"INSTRU��ES PARA O TESTE");
    SetColor(0);
    moveXY(30,13,"1.Responda as afirma��es de acordo com o qu�o frequente voc�");
    moveXY(30,14,"faz/sente o que a frase descreve.");
    moveXY(30,16,"2.Caso n�o entenda a frase ou n�o saiba sua resposta, marque");
    moveXY(30,17,"como 'N�O ME IDENTIFICO'.");
    SetColor(12);
    moveXY(31,22,"ATEN��O: esse teste tem 48 etapas e dura de 8 a 10 minutos!");

    SetColor(2);
    moveXY(100,30,"INICIAR TESTE");
    SetColor(4);
    moveXY(100,31,"voltar");

    //desenho quadrado INSTRUCOES
    int astX,astY;
    for (astX=28 ; astX<=93 ; astX++)
    {
        moveXY(astX,11,"_");
    }
    for (astX=28 ; astX<=93 ; astX++)
    {
        moveXY(astX,18,"_");
    }


    //desenho quadrado MENU
    SetColor(0);
    for (astX=98; astX<=114 ; astX++)
    {
        moveXY(astX,29,"_");
    }
    for (astY=30; astY<=31 ; astY++)
    {
        moveXY(97,astY,"|");
    }
    for (astY=30; astY<=31 ; astY++)
    {
        moveXY(115,astY,"|");
    }

    //setas menu instrucoes
    short posX = 98, posY = 30;
    SetColor(0);
    moveXY(98, 30, "->");
    do
    {
        moveXY(posX, posY, "->");
            a = toupper(getch());
            switch(a)
            {
                case 'H':
                    if (posY > 30)
                    {
                        moveXY(98,posY, "  ");
                        posY-=1;
                        moveXY(98,posY, "->");
                        _beep(550, 250);
                    }
                break;

                case 'P':
                    if (posY < 31)
                    {
                        moveXY(98,posY, "  ");
                        posY+=1;
                        moveXY(98,posY, "->");
                        _beep(550, 250);
                    }
                break;

                case 13:  //pressionou enter
                    _beep(900, 250);
                    if (posY == 30) //teste MBTI
                    {
                        system("cls");
                        testeMBTI();
                    }
                    if (posY == 31) //menu inicial
                    {
                        system("cls");
                        resetaseta();
                    }
                    break;
            }
    }while(1);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tchau()
{
    int astX,astY;
    SetColor(2);
    moveXY(56,13, "AT� MAIS!");
    SetColor(0);
    moveXY(1,26,"");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void resetaseta() //iniciar teste->instrucoes->voltar pro menu->resetaseta
{
    short posX = 98, posY = 26;
    moveXY(98, 26, "->");
    do
    {

        SetColor(1);
        menu();
        SetColor(0);
        moveXY(posX, posY, "->");
        a = toupper(getch());

        switch(a)
        {
            case 'H':
                if (posY > 26)
                {
                    moveXY(98,posY, "  ");
                    posY-=1;
                    moveXY(98,posY, "->");
                    _beep(550, 250);
                }
            break;

            case 'P':
                if (posY < 29)
                {
                    moveXY(98,posY, "  ");
                    posY+=1;
                    moveXY(98,posY, "->");
                    _beep(550, 250);
                }
            break;

            case 13:  //pressionou enter
                _beep(900, 250);
                if (posY == 28) //teste MBTI
                {
                    system("cls");
                    instrucoes();
                	testeMBTI();
                }
                if (posY == 26) //info
                {
                	system("cls");
                	info();
                }
                if (posY == 27) //16 tipos
                {
                    system("cls");
                    menuTipos();
                    system("cls");
                }
                if (posY == 29)
                {
                    system("cls");
                    tchau();
                    exit(0);
                }
            break;
        }

    }while(1);

    system("pause");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alternativas() //alternativas de cada questao
{
    SetColor(12);
    moveXY(1,13,"1. N�O ME IDENTIFICO");
    SetColor(4);
    moveXY(1,14,"2. ME IDENTIFICO UM POUCO");
    SetColor(3);
    moveXY(1,15,"3. ME IDENTIFICO PARCIALMENTE");
    SetColor(2);
    moveXY(1,16,"4. ME IDENTIFICO NA MAIOR PARTE");
    SetColor(10);
    moveXY(1,17,"5. ME IDENTIFICO MUITO");
    SetColor(1);
    moveXY(1,19,"DIGITE SUA RESPOSTA (1 a 5):");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testereposta(resposta) //respostas invalidas
{
    if (resposta<1 || resposta>5)
    {
        do{
        //apaga a resposta invalida
        _beep(1000, 250); _beep(1000, 250); _beep(1000, 250);
        moveXY(30,19,"                                                     ");
        SetColor(4);
        moveXY(16,30,"!!!sua resposta deve ser de 1 a 5!!!");
        SetColor(1);
        moveXY(30,19, "");
        scanf("%d",&resposta);
        }while(resposta<1 || resposta>5);
        moveXY(16,30,"                                                     ");
    }
    //apaga mensagem de erro
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void economiza(resposta)
{
    testereposta(resposta);
    _beep(500, 250); _beep(850, 250);
    SetColor(3);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void esteticateste()
{
    int astX;
    SetColor(0);
    for (astX=1 ; astX<119 ; astX++)
    {
        moveXY(astX,8,"_");
        moveXY(astX,9,"_");
    }
    for (astX=1 ; astX<119 ; astX++)
    {
        moveXY(astX,20,"_");
        moveXY(astX,21,"_");
    }
    SetColor(1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testeMBTI() //teste
{
    int resposta;
    SetColor(3);
    moveXY(1,30, "0% completo");
    //1                               FEITO!!!!!!!!!!!!!!!!!!!
    esteticateste();
    moveXY(1,11,"Etapa 1: Sigo meus instintos e impulsos f�sicos livremente.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    moveXY(1,30, "2% completo");
    //2                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "2% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 2: Proponho-me v�rias ideias diferentes, valorizando o potencial de cada uma.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    moveXY(1,30, "4% completo");
    //3                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "4% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 3: Sucesso � medido objetivamente, como tempo levado de uma atividade.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    moveXY(1,30, "6% completo");
    //4                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "6% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 4: Sinto-me inclinado a ser respons�vel e a cuidar dos sentimentos de outros.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    moveXY(1,30, "8% completo");
    //5                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "8% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 5: Tenho facilidade em prever o futuro.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    moveXY(1,30, "10% completo");
    //6                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "10% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 6: Noto se os detalhes ao meu redor s�o diferentes dos quais estou acostumado.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    moveXY(1,30, "12% completo");
    //7                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "12% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 7: Guio-me por dedu��o l�gica, raz�o.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    moveXY(1,30, "14% completo");
    //8                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "14% completo");
    esteticateste();
    SetColor(1);
    moveXY(1,11,"Etapa 8: Tenho opini�es fortes sobre o que � bom e o que � mau.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    moveXY(1,30, "16% completo");
    //9                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "16% completo");
    esteticateste();
    moveXY(1,11,"Etapa 9: Tomo necessidades dos outros como minhas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    moveXY(1,30, "18% completo");
    //10
    system("cls");
    moveXY(1,30, "18% completo");
    esteticateste();
    moveXY(1,11,"Etapa 10: Em argumentos, tento convencer o outro mostrando evid�ncias emp�ricas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    moveXY(1,30, "20% completo");
    //11
    system("cls");
    moveXY(1,30, "20% completo");
    esteticateste();
    moveXY(1,11,"Etapa 11: Tenho fortes vis�es internas de mudan�a.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    moveXY(1,30, "22% completo");
    //12                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "22% completo");
    esteticateste();
    moveXY(1,11,"Etapa 12: Comparo novas experi�ncias com aquelas mais familiares, buscando o que � mais confi�vel.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    moveXY(1,30, "25% completo");
    //13                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "25% completo");
    esteticateste();
    moveXY(1,11,"Etapa 13: Mantenho-me em contato com aquilo que quero para mim, o que me motiva e o que me faz bem.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    moveXY(1,30, "27% completo");
    //14
    system("cls");
    moveXY(1,30, "27% completo");
    esteticateste();
    moveXY(1,11,"Etapa 14: Gosto de resolver problemas de uma maneira mais impessoal poss�vel.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    moveXY(1,30, "29% completo");
    //15                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "29% completo");
    esteticateste();
    moveXY(1,11,"Etapa 15: Aprecio a adrenalina de experi�ncias f�sicas moment�neas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    moveXY(1,30, "31% completo");
    //16                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "31% completo");
    esteticateste();
    moveXY(1,11,"Etapa 16: Gosto de notar interconex�es aleat�rias e padr�es na vida.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    moveXY(1,30, "33% completo");
    //17                               FEITO!!!!!!!!!!!!!!!!!!!
    system("cls");
    moveXY(1,30, "33% completo");
    esteticateste();
    moveXY(1,11,"Etapa 17: Reconheco e normalmente sigo valores e normas sociais para me enturmar.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    Si(resposta);
    moveXY(1,30, "35% completo");
    //18
    system("cls");
    moveXY(1,30, "35% completo");
    esteticateste();
    moveXY(1,11,"Etapa 18: Fa�o planos para maximizar o progresso em dire��o � metas diferentes de uma vez s�.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    Ni(resposta);
    moveXY(1,30, "37% completo");
    //19
    system("cls");
    moveXY(1,30, "37% completo");
    esteticateste();
    moveXY(1,11,"Etapa 19: Aprecio livremente fazer o que gosto apenas para a minha pr�pria felicidade.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    Se(resposta);
    moveXY(1,30, "39% completo");
    //20
    system("cls");
    moveXY(1,30, "39% completo");
    esteticateste();
    moveXY(1,11,"Etapa 20: Ao resolver um problema, consigo pensar em v�rios fatores diferentes de uma vez s�.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    Ne(resposta);
    moveXY(1,30, "41% completo");
    //21
    system("cls");
    moveXY(1,30, "41% completo");
    esteticateste();
    moveXY(1,11,"Etapa 21: Fico profundamente realizado ao soltar minhas emo��es.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    Fe(resposta);
    moveXY(1,30, "43% completo");
    //22
    system("cls");
    moveXY(1,30, "43% completo");
    esteticateste();
    moveXY(1,11,"Etapa 22: Sigo passos para assegurar que tarefas sejam previs�veis e completadas corretamente.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    Te(resposta);
    moveXY(1,30, "45% completo");
    //23
    system("cls");
    moveXY(1,30, "45% completo");
    esteticateste();
    moveXY(1,11,"Etapa 23: Deixo-me levar por momentos 'm�gicos' da vida.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    Fi(resposta);
    moveXY(1,30, "47% completo");
    //24
    system("cls");
    moveXY(1,30, "47% completo");
    esteticateste();
    moveXY(1,11,"Etapa 24: Fa�o decis�es r�pidas para me aproveitar de op��es imediatas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    Ti(resposta);
    moveXY(1,30, "50% completo");
    //25
    system("cls");
    moveXY(1,30, "50% completo");
    esteticateste();
    moveXY(1,11,"Etapa 25: Sempre sou verdadeiro quanto ao que eu quero e o que quero para outros.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    moveXY(1,30, "52% completo");
    //26
    system("cls");
    moveXY(1,30, "52% completo");
    esteticateste();
    moveXY(1,11,"Etapa 26: Analiso e critico o que � ideal de acordo com princ�pios bem definidos.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    moveXY(1,30, "54% completo");
    //27
    system("cls");
    moveXY(1,30, "54% completo");
    esteticateste();
    moveXY(1,11,"Etapa 27: Reviso informa��es para notar o que � frequente e regular.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    moveXY(1,30, "56% completo");
    //28
    system("cls");
    moveXY(1,30, "56% completo");
    esteticateste();
    moveXY(1,11,"Etapa 28: Atraio-me pelo simb�lico, misterioso.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    moveXY(1,30, "58% completo");
    //29
    system("cls");
    moveXY(1,30, "58% completo");
    esteticateste();
    moveXY(1,11,"Etapa 29: Instant�neamente consigo avistar elementos f�sicos.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    moveXY(1,30, "60% completo");
    //30
    system("cls");
    moveXY(1,30, "60% completo");
    esteticateste();
    moveXY(1,11,"Etapa 30: Tenho v�rias ideias tangenciais e n�o me limito a apenas uma.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    moveXY(1,30, "62% completo");
    //31
    system("cls");
    moveXY(1,30, "62% completo");
    esteticateste();
    moveXY(1,11,"Etapa 31: Sigo uma �nica linha de racioc�nio.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    moveXY(1,30, "64% completo");
    //32
    system("cls");
    moveXY(1,30, "64% completo");
    esteticateste();
    moveXY(1,11,"Etapa 32: Tento ajudar os outros a ficarem confort�veis em situa��es sociais.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    moveXY(1,30, "66% completo");
    //33
    system("cls");
    moveXY(1,30, "66% completo");
    esteticateste();
    moveXY(1,11,"Etapa 33: Fa�o m�todos para outros completarem tarefas de maneira eficiente.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    moveXY(1,30, "68% completo");
    //34
    system("cls");
    moveXY(1,30, "68% completo");
    esteticateste();
    moveXY(1,11,"Etapa 34: Me comunico com todos os membros de um grupo para promover uni�o.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    moveXY(1,30, "70% completo");
    //35
    system("cls");
    moveXY(1,30, "70% completo");
    esteticateste();
    moveXY(1,11,"Etapa 35: Utilizo de defini��es e conceitos para sustentar teorias e perspectivas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    moveXY(1,30, "72% completo");
    //36
    system("cls");
    moveXY(1,30, "72% completo");
    esteticateste();
    moveXY(1,11,"Etapa 36: Avalio o que vale a pena acreditar e o que � mais importante para quem realmente sou.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    moveXY(1,30, "75% completo");
    //37
    system("cls");
    moveXY(1,30, "75% completo");
    esteticateste();
    moveXY(1,11,"Etapa 37: Insiro em situa��es contextos aleat�rios n�o relacionados com o momento.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    moveXY(1,30, "77% completo");
    //38
    system("cls");
    moveXY(1,30, "77% completo");
    esteticateste();
    moveXY(1,11,"Etapa 38: Consigo resultados ao apenas 'mostrar presen�a'.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    moveXY(1,30, "79% completo");
    //39
    system("cls");
    moveXY(1,30, "79% completo");
    esteticateste();
    moveXY(1,11,"Etapa 39: Transformo-me ao, internamente, prever um jeito que futuramente terei de ser.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    moveXY(1,30, "81% completo");
    //40
    system("cls");
    moveXY(1,30, "81% completo");
    esteticateste();
    moveXY(1,11,"Etapa 40: Tenho uma rotina que performo confortavelmente.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    moveXY(1,30, "83% completo");
    //41
    system("cls");
    moveXY(1,30, "83% completo");
    esteticateste();
    moveXY(1,11,"Etapa 41: Sinto-me conectado e �ntimo � outras pessoas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fe(resposta);
    Ni(resposta);
    moveXY(1,30, "85% completo");
    //42
    system("cls");
    moveXY(1,30, "85% completo");
    esteticateste();
    moveXY(1,11,"Etapa 42: Fa�o decis�es baseadas em medidas impessoais.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Te(resposta);
    Si(resposta);
    moveXY(1,30, "87% completo");
    //43
    system("cls");
    moveXY(1,30, "87% completo");
    esteticateste();
    moveXY(1,11,"Etapa 43: Constantemente examino se minhas escolhas s�o compat�veis com o que acredito.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Fi(resposta);
    Ne(resposta);
    moveXY(1,30, "89% completo");
    //44
    system("cls");
    moveXY(1,30, "89% completo");
    esteticateste();
    moveXY(1,11,"Etapa 44: Examino sob quais princ�pios certas coisas funcionam.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ti(resposta);
    Se(resposta);
    moveXY(1,30, "91% completo");
    //45
    system("cls");
    moveXY(1,30, "91% completo");
    esteticateste();
    moveXY(1,11,"Etapa 45: For�o meus limites mentais para atingir conquistas.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ni(resposta);
    Te(resposta);
    moveXY(1,30, "93% completo");
    //46
    system("cls");
    moveXY(1,30, "93% completo");
    esteticateste();
    moveXY(1,11,"Etapa 46: Aponto discrep�ncias sobre como as coisas sempre eram e o que se tornaram.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Si(resposta);
    Fe(resposta);
    moveXY(1,30, "95% completo");
    //47
    system("cls");
    moveXY(1,30, "95% completo");
    esteticateste();
    moveXY(1,11,"Etapa 47: Confio nas conclsu�es que chego no 'brainstorming'.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Ne(resposta);
    Ti(resposta);
    moveXY(1,30, "97% completo");
    //48
    system("cls");
    moveXY(1,30, "97% completo");
    esteticateste();
    moveXY(1,11,"Etapa 48: Facilmente encontro sincronia f�sica com aquilo e aqueles ao meu redor.");
    alternativas();
    moveXY(30,19, "");
    scanf("%d",&resposta);
    economiza(resposta);
    Se(resposta);
    Fi(resposta);
    moveXY(1,30, "100% completo");

    //tela de 100%
    finalteste();
}

void carregamento() //barra
{
    int astX,astY,aXi,aXf,freq;
    SetColor(2);
    for (aXi=55, aXf=66,freq=700 ; aXi>=37 && aXf<=84; aXi-=3, aXf+=3, freq+=50)
    {
        for (astX=aXi ; astX<aXf ; astX++)
        {
            moveXY(astX,14,"_");
        }
        for (astX=aXi ; astX<aXf ; astX++)
        {
            moveXY(astX,15,"_");
        }
            moveXY(aXi-1,15,"|");
            moveXY(aXf,15,"|");
            _beep(freq, 250);
    }
}

void finalteste()
{
    system("cls");
    SetColor(0);
    moveXY(55,13,"calculando...");
    carregamento();
    SetColor(0);
    moveXY(53,13, "                                                  ");
    moveXY(54,13, "100% COMPLETO");
    SetColor(1);
    moveXY(37,17, "PRESSIONE QUALQUER TECLA PARA VER SEU RESULTADO");
    getch();
    system("cls");
    resultado();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Se(resposta)
{
    //int Se=0;
    if (resposta==1)
    {
        Sek+=0;
    }
    if (resposta==2)
    {
        Sek+=1;
    }
    if (resposta==3)
    {
        Sek+=2;
    }
    if (resposta==4)
    {
        Sek+=3;
    }
    if (resposta==5)
    {
        Sek+=4;
    }
    return Sek;
}

int Si(resposta)
{
    //int Si=0;
    if (resposta==1)
    {
        Sik+=0;
    }
    if (resposta==2)
    {
        Sik+=1;
    }
    if (resposta==3)
    {
        Sik+=2;
    }
    if (resposta==4)
    {
        Sik+=3;
    }
    if (resposta==5)
    {
        Sik+=4;
    }
    return Sik;
}

int Ne(resposta)
{
    //int Ne=0;
    if (resposta==1)
    {
        Nek+=0;
    }
    if (resposta==2)
    {
        Nek+=1;
    }
    if (resposta==3)
    {
        Nek+=2;
    }
    if (resposta==4)
    {
        Nek+=3;
    }
    if (resposta==5)
    {
        Nek+=4;
    }
    return Nek;
}

int Ni(resposta)
{
    //int Ni=0;
    if (resposta==1)
    {
        Nik+=0;
    }
    if (resposta==2)
    {
        Nik+=1;
    }
    if (resposta==3)
    {
        Nik+=2;
    }
    if (resposta==4)
    {
        Nik+=3;
    }
    if (resposta==5)
    {
        Nik+=4;
    }
    return Nik;
}

int Te(resposta)
{
    //int Te=0;
    if (resposta==1)
    {
        Tek+=0;
    }
    if (resposta==2)
    {
        Tek+=1;
    }
    if (resposta==3)
    {
        Tek+=2;
    }
    if (resposta==4)
    {
        Tek+=3;
    }
    if (resposta==5)
    {
        Tek+=4;
    }
    return Tek;
}

int Ti(resposta)
{
    //int Ti=0;
    if (resposta==1)
    {
        Tik+=0;
    }
    if (resposta==2)
    {
        Tik+=1;
    }
    if (resposta==3)
    {
        Tik+=2;
    }
    if (resposta==4)
    {
        Tik+=3;
    }
    if (resposta==5)
    {
        Tik+=4;
    }
    return Tik;
}

int Fe(resposta)
{
    //int Fe=0;
    if (resposta==1)
    {
        Fek+=0;
    }
    if (resposta==2)
    {
        Fek+=1;
    }
    if (resposta==3)
    {
        Fek+=2;
    }
    if (resposta==4)
    {
        Fek+=3;
    }
    if (resposta==5)
    {
        Fek+=4;
    }
    return Fek;
}

int Fi(resposta)
{
    //int Fi=0;
    if (resposta==1)
    {
        Fik+=0;
    }
    if (resposta==2)
    {
        Fik+=1;
    }
    if (resposta==3)
    {
        Fik+=2;
    }
    if (resposta==4)
    {
        Fik+=3;
    }
    if (resposta==5)
    {
        Fik+=4;
    }
    return Fik;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int calcularesultado()
{
    int SeF=Se(),SiF=Si(),NeF=Ne(),NiF=Ni(),TeF=Te(),TiF=Ti(),FeF=Fe(),FiF=Fi();
    int vetI[4]={SeF,NeF,TeF,FeF};
    int vetE[4]={SiF,NiF,TiF,FiF};
    int i,tipo;
    int maiorI=0 , maiorE=0;
    int maior1=0,maior2=0;

    for (i=0 ; i<4 ; i++)
    {
        if (vetI[i]>maiorI)
        {
            maiorI=vetI[i];
        }
    }
    for (i=0 ; i<4 ; i++)
    {
        if (vetE[i]>maiorE)
        {
            maiorE=vetE[i];
        }
    }
    if (maiorI>=maiorE)
    {
        maior1=maiorI;
        maior2=maiorE;
    }
    else
    {
        maior1=maiorE;
        maior2=maiorI;
    }

    if (maior1==FiF && maior2==SeF)
    {
        tipo=1; //ISFP
    }
    else
    if (maior1==TiF && maior2==NeF)
    {
        tipo=2; //INTP
    }
    else
    if (maior1==FiF && maior2==NeF)
    {
        tipo=3; //INFP
    }
    else
    if (maior1==TiF && maior2==SeF)
    {
        tipo=4; //ISTP
    }
    else
    if (maior1==NiF && maior2==FeF)
    {
        tipo=5; //INFJ
    }
    else
    if (maior1==NiF && maior2==TeF)
    {
        tipo=6; //INTJ
    }
    else
    if (maior1==SiF && maior2==FeF)
    {
        tipo=7; //ISFJ
    }
    else
    if (maior1==SiF && maior2==TeF)
    {
        tipo=8; //ISTJ
    }
    else
    if (maior1==FeF && maior2==NiF)
    {
        tipo=9; //ENFJ
    }
    else
    if (maior1==FeF && maior2==SiF)
    {
        tipo=10; //ESFJ
    }
    else
    if (maior1==TeF && maior2==NiF)
    {
        tipo=11; //ENTJ
    }
    else
    if (maior1==TeF && maior2==SiF)
    {
        tipo=12; //ESTJ
    }
    else
    if (maior1==NeF && maior2==FiF)
    {
        tipo=13; //ENFP
    }
    else
    if (maior1==NeF && maior2==TiF)
    {
        tipo=14; //ENTP
    }
    else
    if (maior1==SeF && maior2==FiF)
    {
        tipo=15; //ESFP
    }
    else
    if (maior1==SeF && maior2==TiF)
    {
        tipo=16; //ESTP
    }
    return tipo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modeloTelaResposta()
{
    SetColor(0);
    int astX,astY;
    moveXY(2,2,"seu tipo: ");
    moveXY(2,5,"Voc�:");

    for (astX=1 ; astX<118 ; astX++)
    {
        moveXY(astX,3,"_");
    }
    for (astX=1 ; astX<118 ; astX++)
    {
        moveXY(astX,26,"_");
    }
    SetColor(1);
}

void FiPrimario()
{
    SetColor(3);
    moveXY(2,7,"- usa sentimentos privados e necessidades emocionais como meios de decis�o leg�timos.");
    moveXY(2,9,"- desfruta de atividades que ofere�am oportunidades para autoexpress�o criativa.");
    moveXY(2,11,"- sofre de autoestima flutuante ou sentimentos e desejos inst�veis quando incapaz de realizar metas/tarefa.");
    moveXY(2,13,"- tende a projetar seus pr�prios valores, desejos e preconceitos nos outros sem perceber.");
    moveXY(2,15,"- tende a usar sua habilidade de entender a profundidade da experi�ncia humana para ajudar os outros.");
}

void ISFP()
{
    SetColor(3);
    moveXY(12,2,"ISFP - 'Aventureiro'");
    moveXY(2,17,"- gosta de viver no momento e � espont�neo.");
    moveXY(2,19,"- prefere o real e s�lido do que o hipot�tico.");
    moveXY(2,21,"- procura padr�es nas informa��es que recebe.");
    moveXY(2,24,"ISFPs famosos: Frida Kahlo, Michael Jackson, Britney Spears, Lula Molusco, Jon Snow, Harry Potter.");
    SetColor(1);
}

void INFP()
{
    SetColor(3);
    moveXY(12,2,"INFP - 'Mediador'");
    moveXY(2,17,"- prefere focar no futuro.");
    moveXY(2,19,"- explora valores e ideias de todos os lados.");
    moveXY(2,21,"- pensa e analisa informa��es excessivamente.");
    moveXY(2,24,"INFPs famosos: Kurt Cobain, Keanu Reeves, Vincent Van Gogh, Luke Skywalker, Coraline, Frodo Baggins.");
    SetColor(1);
}

void TiPrimario()
{
    SetColor(3);
    moveXY(2,7,"- procura descobrir regras ou f�rmulas diretas baseadas em fatos.");
    moveXY(2,9,"- tende a ser muito anal�tico, preferindo adotar posi��es/julgamentos que s�o livres de vi�zes.");
    moveXY(2,11,"- � muitas vezes admirado por sua abordagem calma e competente ao destrinchar problemas.");
    moveXY(2,13,"- pode ser emocionalmente desconectado das situa��es e excessivamente redutor das mesmas.");
    moveXY(2,15,"- gosta de ter muito tempo privado para perseguir seus pr�prios interesses ou habilidades.");
}

void INTP()
{
    SetColor(3);
    moveXY(12,2,"INTP - 'L�gico'");
    moveXY(2,17,"- � privado, dif�cil de se conhecer e extremamente independente.");
    moveXY(2,19,"- luta contra emo��es e � �timo em ler situa��es, mas p�ssimo em entender pessoas.");
    moveXY(2,21,"- prefere argumentos racionais, l�gicos e intelectuais.");
    moveXY(2,24,"INTPs famosos: Albert Einsten, Charles Darwin, Stephen King, Patrick Estrela, Yoda, Bruce Banner.");
    SetColor(1);
}

void ISTP()
{
    SetColor(3);
    moveXY(12,2,"ISTP - 'Virtuoso'");
    moveXY(2,17,"- fica imediatamente com t�dio ap�s resolver um problema.");
    moveXY(2,19,"- � �timo em crises e adora a adrenalina dos problemas e dificuldades.");
    moveXY(2,21,"- � independente e gosta da liberdade de trabalhar em pequenos picos de energia, ao inv�s de uma rotina.");
    moveXY(2,24,"ISTPs famosos: Clint Eastwood, Tom Cruise, Michael Jordan, Mulan, Shrek, James Bond.");
    SetColor(1);
}

void NiPrimario()
{
    SetColor(3);
    moveXY(2,7,"- busca padr�es subjacentes que possam ajudar a prever como eventos evoluir�o ao longo do tempo.");
    moveXY(2,9,"- tende a ser perceptivo e capazes de �ver atrav�s� de situa��es encontrando a �ess�ncia� real das coisas.");
    moveXY(2,11,"- tende a estar bastante seguro sobre como quer que sua vida se desdobre, sendo focado e determinado em suas metas.");
    moveXY(2,13,"- pode ser desconectado do presente, pois � muito focado no futuro.");
    moveXY(2,15,"- costuma achar dif�cil decidir o que fazer se n�o conseguir ver nenhum prop�sito ou significado mais profundo.");
}

void INFJ()
{
    SetColor(3);
    moveXY(12,2,"INFJ - 'Advogado'");
    moveXY(2,17,"- valoriza muito seus valores e sua integridade.");
    moveXY(2,19,"- trabalha para manter a harmonia em situa��es sociais, mas �, simultaneamente, independente.");
    moveXY(2,21,"- tem opini�es fortes e prioriza a causa ao inv�s do ego.");
    moveXY(2,24,"INFJs famosos: Adolf Hitler, Jesus Cristo, Gandhi, Elsa, Albus Dumbledore, Lisa Simpson.");
    SetColor(1);
}

void INTJ()
{
    SetColor(3);
    moveXY(12,2,"INTJ - 'Arquiteto'");
    moveXY(2,17,"- � fascinado pelo abstrato, complexo, novo e n�o explorado, ao contr�rio de fatos concretos.");
    moveXY(2,19,"- tende a preferir o trabalho individual, mas, quando em grupo, gosta de cercar-se por pessoas semelhantes.");
    moveXY(2,21,"- mira na perfei��o, adorando desenvolver solu��es �nicas para problemas complexos e interessantes.");
    moveXY(2,24,"INTJs famosos: Stephen Hawking, Friedrich Nietzsche, Mark Zuckerberg, Doutor Estranho, Walter White, Gandalf.");
    SetColor(1);
}

void SiPrimario()
{
    SetColor(3);
    moveXY(2,7,"- valoriza uma abordagem cuidadosa, met�dica e consistente de tudo, e pode parecer inflex�vel para os outros.");
    moveXY(2,9,"- busca familiaridade, estabilidade, consist�ncia, seguran�a, rituais.");
    moveXY(2,11,"- toma decis�es com base em prioridades pessoais, paix�es, compromissos.");
    moveXY(2,13,"- fica facilmente envergonhado caso tenha feito algo errado, e � muito preocupado em aparecer �apropriado�.");
    moveXY(2,15,"- tem dificuldade em aproveitar o momento devido ao medo do futuro.");
}

void ISFJ()
{
    SetColor(3);
    moveXY(12,2,"ISFJ - 'Defensor'");
    moveXY(2,17,"- � consciente, leal, respons�vel e dedicado a pessoas, organiza��es, e, principalmente, a causas.");
    moveXY(2,19,"- traz a ordem, claridade, organiza��o e planejamento, mesmo n�o sendo muitas vezes o membro mais vocal do grupo.");
    moveXY(2,21,"- tende a se preocupar com coisas pequenas e � relutante quanto a �deixar pra l�.");
    moveXY(2,24,"ISFJs famosos: Beyonc�, Emma Watson, Ed Sheeran, Capit�o Am�rica, Mulher El�stica, Super-Homem.");
    SetColor(1);
}

void ISTJ()
{
    SetColor(3);
    moveXY(12,2,"ISTJ - 'Log�stico'");
    moveXY(2,17,"- prefere evitar conflitos emocionais, mas tem um forte senso bin�rio do que � certo e errado.");
    moveXY(2,19,"- � dif�cil de se conhecer, por parecer frio e desconectado.");
    moveXY(2,21,"- � soci�vel, por�m n�o gosta da espontaneidade de grandes multid�es.");
    moveXY(2,24,"ISTJs famosos: Sigmund Freud, Greta Thunberg, Jeff Bezos, Sheldon Cooper, Darth Vader, Ross Geller.");
    SetColor(1);
}

void FePrimario()
{
    SetColor(5);
    moveXY(2,7,"- deseja garantir que todos se entendam, e sente que mede naturalmente a �temperatura� emocional de uma sala.");
    moveXY(2,9,"- gosta de estabelecer um senso de comunidade ou de pertencer a grupos.");
    moveXY(2,11,"- tem um senso natural de quais fun��es sociais as pessoas ocupam e espera que todos honrem seus pap�is.");
    moveXY(2,13,"- deseja suavizar conflitos, e �s vezes tenta corrigir comportamentos de outros para serem mais �harmoniosos�.");
    moveXY(2,15,"- tem dificuldade em lidar com cr�ticas, porque seu primeiro pensamento � que voc� n�o � aceito/apreciado.");
}

void ENFJ()
{
    SetColor(5);
    moveXY(12,2,"ENFJ - 'Protagonista'");
    moveXY(2,17,"- � para quem seus amigos pedem ajuda, gra�as a sua personalidade caridosa, organizada, aut�ntica.");
    moveXY(2,19,"- assume cargos de lideran�a por querer assegurar que todos sejam felizes, alimentando sua paix�o por a��o e pessoas.");
    moveXY(2,21,"- � confiante, persuasivo e persistente.");
    moveXY(2,24,"ENFJs famosos: Martin Luther King, Oprah Winfrey, Cleopatra, Daenerys Targaryen, Moana, Mufasa.");
    SetColor(1);
}

void ESFJ()
{
    SetColor(5);
    moveXY(12,2,"ESFJ - 'C�nsul'");
    moveXY(2,17,"- prefere solu��es pr�ticas para problemas interpessoais, e � um �timo e organizado planejador.");
    moveXY(2,19,"- sente que obriga��es e responsabilidades vem antes de seus pr�prios interesses e desejos.");
    moveXY(2,21,"- se torna como uma figura �parental� sob press�o, gra�as ao seu desejo de controlar e criar harmonia.");
    moveXY(2,24,"ESFJs famosos: Taylor Swift, LeBron James, Jennifer Aniston, Bob Esponja, Katara, Monica Geller.");
    SetColor(1);
}

void TePrimario()
{
    SetColor(5);
    moveXY(2,7,"- � naturalmente motivado a fazer planos para situa��es e a torn�-la mais apropriadas e efetivas.");
    moveXY(2,9,"- deseja instintivamente definir um objetivo claro e tenta alcan��-lo rapidamente com a menor confus�o poss�vel.");
    moveXY(2,11,"- odeia a sensa��o de deixar um problema �bvio sem solu��o mesmo quando esse n�o te envolve.");
    moveXY(2,13,"- se sente muito mais � vontade quando o meio � ordenado e tudo est� em seu leg�timo lugar.");
    moveXY(2,15,"- sente desconforto quando v� incompet�ncia, sentindo forte vontade de corrigir as pessoas quando cometem erros.");
}

void ENTJ()
{
    SetColor(5);
    moveXY(12,2,"ENTJ - 'Comandante'");
    moveXY(2,17,"- ama o novo e o desafiador, � confiante e autorit�rio, assumindo cargos de lideran�a sem hesitar.");
    moveXY(2,19,"- gosta de conflitos, j� que s�o oportunidades para discuss�es e debates para que objetivos sejam cumpridos.");
    moveXY(2,21,"- � energ�tico, assertivo, falante, e pode acabar chateando pessoas com seu jeito �direto ao ponto�.");
    moveXY(2,24,"ENTJs famosos: Gordon Ramsey, Joseph Stalin, Napole�o Bonaparte, Voldemort, Plankton, Rachel Berry.");
    SetColor(1);
}

void ESTJ()
{
    SetColor(5);
    moveXY(12,2,"ESTJ - 'Executivo'");
    moveXY(2,17,"- toma lideran�a, trazendo ordem e foco para situa��es, priorizando a tarefa e n�o problemas interpessoais.");
    moveXY(2,19,"- precisa traduzir sentimentos para uma linguagem pr�tica e racional para lidar com esses e demonstrar empatia.");
    moveXY(2,21,"- foi constru�do para resolver problemas, tomar conta de situa��es e assegurar que planos s�o seguidos.");
    moveXY(2,24,"ESTJs famosos: Hillary Clinton, Kim Jong-Un, Michelle Obama, Hermione Granger, Leia Organa, Regina George.");
    SetColor(1);
}

void NePrimario()
{
    SetColor(5);
    moveXY(2,7,"- se sente energizado por ideias interessantes, te excitando a experimentar novos caminho de desenvolvimento.");
    moveXY(2,9,"- acha que sua mente � muitas vezes cheia de ideias ou vis�es muito diversificadas/dispersas.");
    moveXY(2,11,"- acha dif�cil de seguir com seus planos por causa de ser facilmente distra�do por outras ideias emocionantes.");
    moveXY(2,13,"- come�a a se sentir mal/entediado quando falta inspira��o por um longo per�odo de tempo.");
    moveXY(2,15,"- deseja melhorar as coisas e se sente frustrado quando outros n�o se importam em fazer mudan�as.");
}

void ENFP()
{
    SetColor(5);
    moveXY(12,2,"ENFP - 'Ativista'");
    moveXY(2,17,"- � criativo, impulsivo, adora pessoas, espont�neo e abra�a todas as oportunidades com energia e entusiasmo.");
    moveXY(2,19,"- consegue entender muito bem e tem interesse genu�no nos outros.");
    moveXY(2,21,"- � otimista e se d� bem com todos, mas tem uma alma sens�vel, leva cr�ticas � s�rio e precisa de valida��o externa.");
    moveXY(2,24,"ENFPs famosos: John Lennon, Kanye West, Jim Carrey, Homem-Aranha, Rapunzel, Olaf.");
    SetColor(1);
}

void ENTP()
{
    SetColor(5);
    moveXY(12,2,"ENTP - 'Inovador'");
    moveXY(2,17,"- est� sempre atento aos arredores procurando por novas oportunidades que alimentam seu desejo por coisas novas.");
    moveXY(2,19,"- � charmoso, persuasivo e utiliza de informa��es emp�ricas, evid�ncias e l�gica para fazer decis�es.");
    moveXY(2,21,"- tem �timas habilidades sociais e � extremamente divertido, mas n�o � muito emocional.");
    moveXY(2,24,"ENTPs famosos: Barack Obama, Leonardo da Vinci, S�crates, Homem de Ferro, Jack Sparrow, Chandler Bing.");
    SetColor(1);
}

void SePrimario()
{
    SetColor(5);
    moveXY(2,7,"- fica facilmente impaciente quando as situa��es/pessoas parecem muito repetitivas, excessivas ou convencionais.");
    moveXY(2,9,"- costuma sentir o desejo de �se juntar� e fazer parte de algo interessante que est� acontecendo.");
    moveXY(2,11,"- adora experimentar coisas novas e divertidas, ser interativo e obter experi�ncia em primeira m�o.");
    moveXY(2,13,"- � capaz de lidar com confian�a e suavidade atividades ou situa��es interessantes/desafiadoras.");
    moveXY(2,15,"- se sente facilmente mal quando n�o consegue aprender algo rapidamente ou resolver um problema imediatamente.");
}

void ESFP()
{
    SetColor(5);
    moveXY(12,2,"ESFP - 'Animador'");
    moveXY(2,17,"- � interessado por pessoas e experi�ncias, odiando regras e rotinas.");
    moveXY(2,19,"- � sens�vel a cr�ticas e evita conflitos, vendo a promo��o da paz e harmonia como seu papel.");
    moveXY(2,21,"- � excelente para amenizar momentos de tens�o em situa��es dif�ceis.");
    moveXY(2,24,"ESFPs famosos: Quentin Tarantino, Freddie Mercury, Adele, Jesse Pinkman, Goku, Rachel Green.");
    SetColor(1);
}

void ESTP()
{
    SetColor(5);
    moveXY(12,2,"ESTP - 'Empres�rio'");
    moveXY(2,17,"- adora a a��o e abra�a qualquer oportunidade t�o rapidamente quanto as abandona, odiando compromissos e agendas.");
    moveXY(2,19,"- prefere aplica��es pr�ticas e m�todos imediatos para resolver problemas.");
    moveXY(2,21,"- � direto e economiza palavras, e, por isso, aqueles que s�o mais reflexivos podem te achar bruto.");
    moveXY(2,24,"ESTPs famosos: Donald Trump, Madonna, Dwayne 'The Rock' Johnson, Gato de Botas, Buzz Lightyear, Johnny Bravo.");
    SetColor(1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void finaliza()
{
    SetColor(2);
    moveXY(38,28, "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
    getch();
    system("cls");
}

void resultado() //tela de resultado
{
    int tipoF = calcularesultado();
    system("cls");

    if (tipoF==1)
    {
        modeloTelaResposta();
        FiPrimario();
        ISFP();
    }
    if (tipoF==2)
    {
        modeloTelaResposta();
        TiPrimario();
        INTP();
    }
    if (tipoF==3)
    {
        modeloTelaResposta();
        FiPrimario();
        INFP();
    }
    if (tipoF==4)
    {
        modeloTelaResposta();
        TiPrimario();
        ISTP();
    }
    if (tipoF==5)
    {
        modeloTelaResposta();
        NiPrimario();
        INFJ();
    }
    if (tipoF==6)
    {
        modeloTelaResposta();
        NiPrimario();
        INTJ();
    }
    if (tipoF==7)
    {
        modeloTelaResposta();
        SiPrimario();
        ISFJ();
    }
    if (tipoF==8)
    {
        modeloTelaResposta();
        SiPrimario();
        ISTJ();
    }
    if (tipoF==9)
    {
        modeloTelaResposta();
        FePrimario();
        ENFJ();
    }
    if (tipoF==10)
    {
        modeloTelaResposta();
        FePrimario();
        ESFJ();
    }
    if (tipoF==11)
    {
        modeloTelaResposta();
        TePrimario();
        ENTJ();
    }
    if (tipoF==12)
    {
        modeloTelaResposta();
        TePrimario();
        ESTJ();
    }
    if (tipoF==13)
    {
        modeloTelaResposta();
        NePrimario();
        ENFP();
    }
    if (tipoF==14)
    {
        modeloTelaResposta();
        NePrimario();
        ENTP();
    }
    if (tipoF==15)
    {
        modeloTelaResposta();
        SePrimario();
        ESFP();
    }
    if (tipoF==16)
    {
        modeloTelaResposta();
        SePrimario();
        ESTP();
    }
    finaliza();
    Sek=0, Sik=0, Nek=0, Nik=0, Tek=0, Tik=0, Fek=0, Fik=0;
	resetaseta();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void info() //o que � MBTI
{
    system("cls");
    SetColor(4);
    moveXY(52,5,"O QUE � 'MBTI'?");
    SetColor(0);
    moveXY(30,8,"O prop�sito do Indicador de Tipo Myers-Briggs (MBTI) � tornar");
    moveXY(30,9,"a teoria de tipos psicol�gicos descritos por C. G. Jung �til");
    moveXY(30,10,"e acess�vel � todos. A ess�ncia da teoria se apoia na consis-");
    moveXY(30,11,"t�ncia de varia��o de comportamento em cada indiv�duo, classi-");
    moveXY(30,12,"ficando a popula��o mundial em 16 diferentes tipos.");
    moveXY(30,14,"Nesse teste, seu tipo � avaliado a partir de 8 fun��es cogniti-");
    moveXY(30,15,"vas, que envolvem Pensamento, Sentimento, Sensa��o e Intui��o,");
    moveXY(30,16,"todas essas podendo ser extrovertidas ou introvertidas. Essas,");
    moveXY(30,17,"combinadas em 4, resultam em um dos 16 tipos �nicos.");
    moveXY(30,19,"MBTI � um teste muito popular e � usado em ambientes profissio-");
    moveXY(30,20,"nais para auxiliar funcion�rios a potencializar suas habilida-");
    moveXY(30,21,"des, ou at� mesmo para ajudar qualquer um a se entender melhor.");

    //desenho quadrado
    int astX,astY;
    for (astX=28 ; astX<=93 ; astX++)
    {
        moveXY(astX,6,"_");
    }
    for (astX=28 ; astX<=93 ; astX++)
    {
        moveXY(astX,22,"_");
    }

    //voltar pro menu
    SetColor(2);
    moveXY(37,24, "PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU");
    getch();
    system("cls");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu()
{
    SetColor(0);
	moveXY(101,24, "TESTE MBTI");
	SetColor(1);
    moveXY(100,26,"o que � MBTI?");
    moveXY(100,27,"os 16 tipos");
    SetColor(2);
    moveXY(100,28,"INICIAR TESTE");
    SetColor(4);
    moveXY(100,29,"sair");
    SetColor(0);

    //desenho quadrado
    int astY;
    for (astY=23; astY<=29 ; astY++)
    {
        moveXY(97,astY,"|");
    }
    for (astY=23; astY<=29 ; astY++)
    {
        moveXY(115,astY,"|");
    }
    int astX;
    for (astX=98; astX<=114 ; astX++)
    {
        moveXY(astX,25,"_");
    }
    for (astX=98; astX<=114 ; astX++)
    {
        moveXY(astX,22,"_");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void efeito()
{
    int astX,astY;
    //primeiro quadrado
    for (astX=37 ; astX<84 ; astX++)
    {
        moveXY(astX,11,"_");
    }
    for (astX=37 ; astX<84 ; astX++)
    {
        moveXY(astX,16,"_");
    }
    for (astY=12 ; astY<17 ; astY++)
    {
        moveXY(36,astY,"|");
    }
    for (astY=12 ; astY<17 ; astY++)
    {
        moveXY(84,astY,"|");
    }
    _beep(600, 250);
    //segundo quadrado
    SetColor(9);
    for (astX=35 ; astX<86 ; astX++)
    {
        moveXY(astX,10,"_");
    }
    for (astX=35 ; astX<86 ; astX++)
    {
        moveXY(astX,17,"_");
    }
    for (astY=11 ; astY<18 ; astY++)
    {
        moveXY(34,astY,"|");
    }
    for (astY=11 ; astY<18 ; astY++)
    {
        moveXY(86,astY,"|");
    }
    _beep(650, 250);
    //terceiro quadrado
    SetColor(10);
    for (astX=33 ; astX<88 ; astX++)
    {
        moveXY(astX,9,"_");
    }
    for (astX=33 ; astX<88 ; astX++)
    {
        moveXY(astX,18,"_");
    }
    for (astY=10 ; astY<19 ; astY++)
    {
        moveXY(32,astY,"|");
    }
    for (astY=10 ; astY<19 ; astY++)
    {
        moveXY(88,astY,"|");
    }
    _beep(700, 250);
    //quarto quadrado
    SetColor(14);
    for (astX=31 ; astX<90 ; astX++)
    {
        moveXY(astX,8,"_");
    }
    for (astX=31 ; astX<90 ; astX++)
    {
        moveXY(astX,19,"_");
    }
    for (astY=9 ; astY<20 ; astY++)
    {
        moveXY(30,astY,"|");
    }
    for (astY=9 ; astY<20 ; astY++)
    {
        moveXY(90,astY,"|");
    }
    _beep(750, 250);
    //quinto quadrado
    SetColor(12);
    for (astX=29 ; astX<92 ; astX++)
    {
        moveXY(astX,7,"_");
    }
    for (astX=29 ; astX<92 ; astX++)
    {
        moveXY(astX,20,"_");
    }
    for (astY=8 ; astY<21 ; astY++)
    {
        moveXY(28,astY,"|");
    }
    for (astY=8 ; astY<21 ; astY++)
    {
        moveXY(92,astY,"|");
    }
    _beep(800, 250);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navegtipos()
{
    short posX = 94, posY = 13;
    moveXY(94, 13, "->");
    do
    {

        SetColor(0);
        moveXY(posX, posY, "->");
        a = toupper(getch());

        switch(a)
        {
            case 'H':
                if (posY > 13)
                {
                    moveXY(94,posY, "  ");
                    posY-=1;
                    moveXY(94,posY, "->");
                    _beep(550, 250);
                }
            break;

            case 'P':
                if (posY < 29)
                {
                    moveXY(94,posY, "  ");
                    posY+=1;
                    moveXY(94,posY, "->");
                    _beep(550, 250);
                }
            break;

            case 13:  //pressionou enter
                _beep(900, 250);
                if (posY == 13) //ESFP
                {
                    system("cls");
                    modeloTelaResposta();
                    SePrimario();
                    ESFP();
                    finaliza();
                    menuTipos();
                    navegtipos();
                }
                if (posY == 14) // ISFP
                {
                    system("cls");
                    modeloTelaResposta();
                    FiPrimario();
                    ISFP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 15) // ENTJ
                {
                    system("cls");
                    modeloTelaResposta();
                    TePrimario();
                    ENTJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 16) // INTJ
                {
                    system("cls");
                    modeloTelaResposta();
                    NiPrimario();
                    INTJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 17) // ESTP
                {
                    system("cls");
                    modeloTelaResposta();
                    SePrimario();
                    ESTP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 18) // ISTP
                {
                    system("cls");
                    modeloTelaResposta();
                    TiPrimario();
                    ISTP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 19) // ENFJ
                {
                    system("cls");
                    modeloTelaResposta();
                    FePrimario();
                    ENFJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 20) // INFJ
                {
                    system("cls");
                    modeloTelaResposta();
                    NiPrimario();
                    INFJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 21) // ENFP
                {
                    system("cls");
                    modeloTelaResposta();
                    NePrimario();
                    ENFP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 22) // INFP
                {
                    system("cls");
                    modeloTelaResposta();
                    FiPrimario();
                    INFP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 23) // ESTJ
                {
                    system("cls");
                    modeloTelaResposta();
                    TePrimario();
                    ESTJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 24) // ISTJ
                {
                    system("cls");
                    modeloTelaResposta();
                    SiPrimario();
                    ISTJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 25) // ENTP
                {
                    system("cls");
                    modeloTelaResposta();
                    NePrimario();
                    ENTP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 26) // INTP
                {
                    system("cls");
                    modeloTelaResposta();
                    TiPrimario();
                    INTP();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 27) // ESFJ
                {
                    system("cls");
                    modeloTelaResposta();
                    FePrimario();
                    ESFJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 28) // ISFJ
                {
                    system("cls");
                    modeloTelaResposta();
                    SiPrimario();
                    ISFJ();
                	finaliza();
                	menuTipos();
                    navegtipos();
                }
                if (posY == 29) //voltar
                {
                    system("cls");
                    resetaseta();
                }
            break;
        }

    }while(1);
}

void esteticatipos()
{
    int astX,astY,num,y;
    SetColor(0);
    for (astX=93 ; astX<119 ; astX++)
    {
        moveXY(astX,12,"_");
    }
    for (astX=93 ; astX<119 ; astX++)
    {
        moveXY(astX,9,"_");
    }
    for (astY=10 ; astY<30 ; astY++)
    {
        moveXY(93,astY,"|");
    }
    for (num=1, y=13; num<=16 ; num++,y++)
    {
        moveXY(96,y,"");
        printf("%d.",num);
    }
}

void menuTipos()
{
    esteticatipos();
    moveXY(101,11,"OS 16 TIPOS");
    SetColor(5);
    moveXY(98,13,"ESFP - 'Animador'");
    SetColor(3);
    moveXY(98,14,"ISFP - 'Aventureiro'");
    SetColor(5);
    moveXY(98,15,"ENTJ - 'Comandante'");
    SetColor(3);
    moveXY(98,16,"INTJ - 'Arquiteto'");
    SetColor(5);
    moveXY(98,17,"ESTP - 'Empres�rio'");
    SetColor(3);
    moveXY(98,18,"ISTP - 'Virtuoso'");
    SetColor(5);
    moveXY(98,19,"ENFJ - 'Protagonista'");
    SetColor(3);
    moveXY(98,20,"INFJ - 'Advogado'");
    SetColor(5);
    moveXY(98,21,"ENFP - 'Ativista'");
    SetColor(3);
    moveXY(99,22,"INFP - 'Mediador'");
    SetColor(5);
    moveXY(99,23,"ESTJ - 'Executivo'");
    SetColor(3);
    moveXY(99,24,"ISTJ - 'Log�stico'");
    SetColor(5);
    moveXY(99,25,"ENTP - 'Inovador'");
    SetColor(3);
    moveXY(99,26,"INTP - 'L�gico'");
    SetColor(5);
    moveXY(99,27,"ESFJ - 'C�nsul'");
    SetColor(3);
    moveXY(99,28,"ISFJ - 'Defensor'");
    SetColor(4);
    moveXY(96,29,"voltar");
    navegtipos();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "Portuguese");
    system("color F1");
    boasvindas();
    SetColor(2);
    moveXY(42,15, "PRESSIONE QUALQUER TECLA PARA INICIAR");
    getch();
    system("cls");
    SetColor(0);
    moveXY(55,14, "INICIANDO...");
    efeito();
    system("cls");
	resetaseta();
    system("pause");
    return 0;
}
