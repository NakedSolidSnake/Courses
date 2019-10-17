
interface Figura{
	void desenha();
}

public class Exemplo01 {
	public static void main(String[] args) {
		Figura figura = new Figura() {
			
			@Override
			public void desenha() {
				System.out.println("Desenha Figura 1");
				
			}
		};
		
		figura.desenha();
		
		Figura figura2 = () -> System.out.println("Desenha Figura 2");
		figura2.desenha();
	}
}
