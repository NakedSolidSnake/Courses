package br.com.solid;

public class Demo {

	public static void main(String[] args) {
		String [] val = {"RECTANGLE", "SQUARE"};
		AbstractFactory abFactory = FactoryProducer.getFactory(false);
		for(int i = 0; i < val.length; i++) {
			Shape s = abFactory.getShape(val[i]);
			s.draw();
		}
		
		
		abFactory = FactoryProducer.getFactory(true);
		for(int i = 0; i < val.length; i++) {
			Shape s = abFactory.getShape(val[i]);
			s.draw();
		}
	}
}
