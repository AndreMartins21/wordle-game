# WORDLE GAME:

### Algoritmo:
- 1°: Você deverá inicialmente ler um arquivo chamado "palavras.txt" que contém um conjunto de palavras. A primeira linha contém um inteiro n com o número de palavras do arquivo, seguidas pelas n palavras, uma por linha. Cada palavra possui 5 letras (para simplificar, você pode considerar que a palavra é fornecida em letras maiúsculas e não há caracteres repetidos);

- 2°: O próximo passo é ler da entrada padrão um número de 1 a n que vai escolher a palavra a ser adivinhada. Vamos chamar essa palavra de chave.

- 3°: A partir daí começa o jogo propriamente dito... Você deverá fornecer como entrada uma palavra de 5 letras. (da mesma forma,  você pode considerar que a palavra é fornecida em letras maiúsculas e não há caracteres repetidos).

- 4°: O seu programa deverá analisar a palavra fornecida como entrada em comparação com a chave e, para cada uma das letras, fornecer uma string de saída da seguinte forma (veja um exemplo em seguida):
- imprimir a letra em maiúscula caso ela esteja presente na chave e esteja na posição correta.
- imprimir a letra em minúscula caso ela esteja presente na chave mas na posição incorreta.
- imprimir um * caso a letra não esteja presente. Além disso, as letras que não estão presentes são impressas depois da palavra entre parênteses.
(devem ser impressas as letras não presentes de todas as tentativas, sem repetição. coloque um espaço depois da palavra).  

- 5°: Caso a palavra seja igual a chave, você deve imprimir "GANHOU!" e terminar o programa. Senão, deve ler uma nova entrada;

- 6°: Depois de 5 tentativas, caso você não tenha acertado a palavra, você deve imprimir: "PERDEU!", seguido da palavra correta, separada por um espaço.