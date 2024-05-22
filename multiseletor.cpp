#include <stdio.h> //incluindo as bibliotecas (barras duplas(//) servem para comentar o c�digo e n�o � executado;
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void side() //um bloco para deixar o menu; poupa tempo da execu��o do c�digo principal;
{
	printf("\tBem vindo!"); //printf("") � o comando para escrever na tela - print function (fun��o de imprimir);
	printf("\nPor favor, selecione alguma das alternativas"); // \n e \t, respectivamente pulam uma linha e d�o um tab de espa�o - por padrão definido 4 espaços;
	printf("\n1........................Sorte do dia"); //sempre finalizar com ";" ;
	printf("\n2........................Soma Simples");
	printf("\n3........................Cor aleatoria");
	printf("\n0........................Sair\n");
}

int main() // bloco principal, onde tudo � executado; 
{
	setlocale(LC_ALL, "Portuguese"); //fun��o para definir simbolos do alfabeto portugues- UTF-8;
	inicio: //inicio: ->� um label, isto �, um ponto de retorno para o "goto" (v� para, em tradu��oo livre);
	int esc=0, esc2=0, n1=0, n2=0, r=0, random; //definimos as vari�veis como 0, menos random, pois random ser� dada um n�mero aleat�rio;
	system("cls"); // -> comando para limpar a tela - system � da biblioteca <stdlib> - CLS � o comando padr�o cara Clear Screen (Limpar Tela);
	srand(time(NULL)); //definindo uma seed aleat�ria baseada no tempo. NULL -> um tempo nulo definido pelo rel�gio do sistema(nunca um n�mero negativo);
	side(); //executando o bloco side - o menu;
	scanf("%i", &esc); // pegando a escolha do menu;
	
	switch(esc)  //switch -> interruptor, estamos dando v�rias op��eses para "esc", isto �, caso "esc" seja 1 -> *c�digo especifico*;
	{
		case 1 : //primeiro caso. Sorte do dia, isto �, pegar um n�mero aleat�rio pelo tempo e definir se a sorte � "Azar", "Sorte", ou "Normal";
			random = rand() % 10; // pegamos e definimos random por rand() -> o um n�mero baseado naquela seed mais cedo e colocamos "%10" para definir o limite;
			random++;  //definimos "random++" (++ sifnifica +1) para que o n�mero seja de 1 � 10, n�o de 0 � 9;
			
			system("cls");
			printf("O numero da sua sorte �: %i", random);
			if(random >= 9) //if -> uma fun��o para "se"; ou seja, ir� comparar duas express�es e far� aquela que for verdadeira.
			{				// Isto �, se random for >= 9 for real, ele iniciar� um novo c�digo;
				printf("\nEsta sortudo hoje!"); //mensagem da "sorte";
			}
			else if(random >= 5) //else if -> funciona como um if, no entanto est� declarado para caso o de cima seja falso.
			{					 //Isto �, se n�o for >= 9, ir� conferir se � maior que 5; sen�o, ignora;
				printf("\nNormal, nada de diferente.");
			}
			else if(random >= 1)
			{
				printf("\nQue azar, amigo.");
			}
			printf("\ngostaria de reiniciar?"); //mensagem para reiniciar;
			printf("\n[1 -> Sim ; 0 -> Nao] ");
			scanf("%i", &esc2); //escolha para reiniciar ou n�o;
			if(esc2 == 1)
			{
				goto inicio; //goto inicio: -> estamos definindo que deste ponto ele ir� para o label "inicio";
			}
			else // n�o h� necessidade de declarar um else if, pois h� apenas duas op��es, seguir ou n�o;
			{
				printf("\n\tObrigado!");
				break; //break � um comando para quebrar o switch e seguir o c�digo ap�s. Ser� executado o "default" se n�o for declarado "break";
			}
		case 2 :
			system("cls");
			printf("\n--Soma Simples--");
			printf("\n\nSelecione o primeiro numero: ");
			scanf("%i", &n1);
			printf("\nSelecione o segundo numero: ");
			scanf("%i", &n2);
			
			r = n1 + n2;
			
			printf("\nO resultado de %i mais %i � igual � %i", n1, n2, r);
			printf("\n\nGostaria de reiniciar?");
			printf("\n[1 -> Sim ; 0 -> Nao] ");
			scanf("%i", &esc2);
			if(esc2 == 1)
			{
				goto inicio;
			}
			else
			{
				printf("\n\n\tObrigado!");
				break;
			}
		case 3 :
			random = rand() % 10; //caso parecido da fun��o de sorte;
			random++;
			
			system("cls");
			printf("sua sorte � %i \n", random); //printf para checar se a sorte da cor est� dando o esperado;
			if(random >= 10) //come�aar sempre pela maior vari�vel; Isto �, sempre come�aar da maior compara��o;
			{
				printf("Sua cor hoje � Azul!");
			}
			else if(random >= 9)
			{
				printf("A cor agora � Verde!");
			}
			else if(random >= 8)
			{
				printf("A cor agora � Amarela!");
			}
			else if(random >= 7)
			{
				printf("Voce parece Cinza.");
			}
			else if(random >= 6)
			{
				printf("Sua cor � branca.");
			}
			else if(random >= 5)
			{
				printf("Sua cor agora � laranja.");
			}
			else if(random >= 4)
			{
				printf("Voce esta vermelho!");
			}
			else if(random < 4) //Admito que neste ponto fiquei com pregui�a de continuar com as cores;
			{
				printf("Resultado indefinido!");
			}
			printf("\n\nGostaria de reiniciar?");
			printf("\n[1 -> Sim ; 0 -> Nao] ");
			scanf("%i", &esc2);
			if(esc2 == 1)
			{
				goto inicio;
			}
			else
			{
				printf("\n\n\tObrigado!");
				break;
			}
		case 0 : //caso apenas para se selecionar sair, isto �, querer sair do menu e fechar;
			printf("\n\nObrigado por usar!");
			break;
		default: //default � o que vai ser executado caso n�o haja break e nenhum caso seja especifico. Isto �, se a escolha estiver fora do 0 - 3;
			printf("\nPor favor selecione algo válido.");
			system("pause");
			goto inicio;
	}
} //fim do c�digo!
