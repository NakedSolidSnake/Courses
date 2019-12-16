package factory;

public class FactoryDemo {
	public static void main(String[] args) {
		
		String shapes[] = {
				"RECTANGLE",
				"CIRCLE",
				"SQUARE"
		};
		
		ShapeFactory factory = new ShapeFactory();
		
		for(int i = 0; i < shapes.length; i++) {
			Shape shape = factory.getShape(shapes[i]);
			shape.draw();
		}		
	}
}
