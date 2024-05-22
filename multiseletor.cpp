#include <stdio.h> //incluindo as bibliotecas (barras duplas(//) servem para comentar o código e não é executado;
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void side() //um bloco para deixar o menu; poupa tempo da execução do código principal;
{
	printf("\tBem vindo!"); //printf("") é o comando para escrever na tela - print function (função de imprimir);
	printf("\nPor favor, selecione alguma das alternativas"); // \n e \t, respectivamente pulam uma linha e dão um tab de espaço - por padrÃ£o definido 4 espaÃ§os;
	printf("\n1........................Sorte do dia"); //sempre finalizar com ";" ;
	printf("\n2........................Soma Simples");
	printf("\n3........................Cor aleatoria");
	printf("\n0........................Sair\n");
}

int main() // bloco principal, onde tudo é executado; 
{
	setlocale(LC_ALL, "Portuguese"); //função para definir simbolos do alfabeto portugues- UTF-8;
	inicio: //inicio: ->É um label, isto é, um ponto de retorno para o "goto" (vá para, em traduçãoo livre);
	int esc=0, esc2=0, n1=0, n2=0, r=0, random; //definimos as variáveis como 0, menos random, pois random será dada um número aleatório;
	system("cls"); // -> comando para limpar a tela - system é da biblioteca <stdlib> - CLS é o comando padrão cara Clear Screen (Limpar Tela);
	srand(time(NULL)); //definindo uma seed aleatória baseada no tempo. NULL -> um tempo nulo definido pelo relógio do sistema(nunca um número negativo);
	side(); //executando o bloco side - o menu;
	scanf("%i", &esc); // pegando a escolha do menu;
	
	switch(esc)  //switch -> interruptor, estamos dando várias opçõeses para "esc", isto é, caso "esc" seja 1 -> *código especifico*;
	{
		case 1 : //primeiro caso. Sorte do dia, isto é, pegar um número aleatório pelo tempo e definir se a sorte é "Azar", "Sorte", ou "Normal";
			random = rand() % 10; // pegamos e definimos random por rand() -> o um número baseado naquela seed mais cedo e colocamos "%10" para definir o limite;
			random++;  //definimos "random++" (++ sifnifica +1) para que o número seja de 1 à  10, não de 0 à  9;
			
			system("cls");
			printf("O numero da sua sorte é: %i", random);
			if(random >= 9) //if -> uma função para "se"; ou seja, irá¡ comparar duas expressões e fará aquela que for verdadeira.
			{				// Isto é, se random for >= 9 for real, ele iniciará um novo código;
				printf("\nEsta sortudo hoje!"); //mensagem da "sorte";
			}
			else if(random >= 5) //else if -> funciona como um if, no entanto está declarado para caso o de cima seja falso.
			{					 //Isto é, se não for >= 9, irá conferir se é maior que 5; senão, ignora;
				printf("\nNormal, nada de diferente.");
			}
			else if(random >= 1)
			{
				printf("\nQue azar, amigo.");
			}
			printf("\ngostaria de reiniciar?"); //mensagem para reiniciar;
			printf("\n[1 -> Sim ; 0 -> Nao] ");
			scanf("%i", &esc2); //escolha para reiniciar ou não;
			if(esc2 == 1)
			{
				goto inicio; //goto inicio: -> estamos definindo que deste ponto ele irá para o label "inicio";
			}
			else // não há necessidade de declarar um else if, pois há apenas duas opções, seguir ou não;
			{
				printf("\n\tObrigado!");
				break; //break é um comando para quebrar o switch e seguir o código após. Será executado o "default" se não for declarado "break";
			}
		case 2 :
			system("cls");
			printf("\n--Soma Simples--");
			printf("\n\nSelecione o primeiro numero: ");
			scanf("%i", &n1);
			printf("\nSelecione o segundo numero: ");
			scanf("%i", &n2);
			
			r = n1 + n2;
			
			printf("\nO resultado de %i mais %i é igual à %i", n1, n2, r);
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
			random = rand() % 10; //caso parecido da função de sorte;
			random++;
			
			system("cls");
			printf("sua sorte é %i \n", random); //printf para checar se a sorte da cor está dando o esperado;
			if(random >= 10) //começaar sempre pela maior variável; Isto é, sempre começaar da maior comparação;
			{
				printf("Sua cor hoje é Azul!");
			}
			else if(random >= 9)
			{
				printf("A cor agora é Verde!");
			}
			else if(random >= 8)
			{
				printf("A cor agora é Amarela!");
			}
			else if(random >= 7)
			{
				printf("Voce parece Cinza.");
			}
			else if(random >= 6)
			{
				printf("Sua cor é branca.");
			}
			else if(random >= 5)
			{
				printf("Sua cor agora é laranja.");
			}
			else if(random >= 4)
			{
				printf("Voce esta vermelho!");
			}
			else if(random < 4) //Admito que neste ponto fiquei com preguiça de continuar com as cores;
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
		case 0 : //caso apenas para se selecionar sair, isto é, querer sair do menu e fechar;
			printf("\n\nObrigado por usar!");
			break;
		default: //default é o que vai ser executado caso não haja break e nenhum caso seja especifico. Isto é, se a escolha estiver fora do 0 - 3;
			printf("\nPor favor selecione algo vÃ¡lido.");
			system("pause");
			goto inicio;
	}
} //fim do código!
