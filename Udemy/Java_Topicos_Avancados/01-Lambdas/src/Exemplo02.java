import java.util.ArrayList;
import java.util.List;

class Produto{
	String nome;
	Double preco;
	
	public Produto(String nome, Double preco) {
		this.nome = nome;
		this.preco = preco;
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Double getPreco() {
		return preco;
	}
	public void setPreco(Double preco) {
		this.preco = preco;
	}
	
}

public class Exemplo02 {
	
	public static void main(String[] args) {
		List<Produto> lista = new ArrayList<Produto>();
		
		lista.add(new Produto("TV 42", 2000.0));
		lista.add(new Produto("Geladeira", 3200.0));
		lista.add(new Produto("Sofa", 1000.0));
		lista.add(new Produto("Notebook", 4200.0));
		
//		lista.forEach((p) -> System.out.println(p.getNome() + " = " + p.getPreco()));
		
		lista.sort((p1, p2) -> p1.getPreco().compareTo(p2.getPreco()));
		
		lista.forEach((p) -> System.out.println(p.getNome() + " = " + p.getPreco()));
	}
	
}
