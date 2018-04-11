public class BubbleSort {
	public static void main(String[] args){
		int vetor[] = new int[10];
		int i, pass, swap;
		
		for(i=0;i<10;i++){
			vetor[i] = 10-i;
		}
		System.out.printf("Vetor Original\n");
		for(i=0;i<10;i++) {
			System.out.printf("Vetor[%d] = %d\n", i, vetor[i]);
		}
		
		/*Ordenação*/
		for(pass=0;pass<9;pass++) {
			for(i=0;i<9;i++){
				if(vetor[i] > vetor[i+1]){
					swap = vetor[i];
					vetor[i] = vetor[i+1];
					vetor[i+1] = swap;
				}
			}
		}
		System.out.printf("Vetor Ordenado\n");
		/*Imprimindo Vetores*/
		for(i=0;i<10;i++) {
			System.out.printf("Vetor[%d] = %d ", i, vetor[i]);

		}
		
		System.out.printf("\n");

	}
}
