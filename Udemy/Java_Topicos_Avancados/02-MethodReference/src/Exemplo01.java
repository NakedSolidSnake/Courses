interface Figura2D{
	void desenha(Double largura, Double altura);
}

class Retangulo{
	public void desenhaRetangulo(Double largura, Double altura) {
		System.out.println("Desenha retangulo de largura: " + largura + " e altura: " + altura);
	}
}


public class Exemplo01 {
	
	public static void main(String[] args) {
		Figura2D fig1 = (l, a) -> System.out.println("Desenha retangulo de largura: " + l + " e altura: " + a);
		fig1.desenha(8.0, 1.5);
		
		Retangulo ret = new Retangulo();
		//Metodo Reference
		Figura2D fig2 = ret::desenhaRetangulo;
		
		fig2.desenha(10.5, 7.0);
		
	}

}
