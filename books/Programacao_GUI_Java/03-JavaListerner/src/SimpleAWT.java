import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Choice;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class SimpleAWT extends java.applet.Applet implements ActionListener, ItemListener{
	private Button button = new Button("Push Me");
	private Checkbox checkbox = new Checkbox("Check Me");
	
	private Choice choice = new Choice() ;
	private Label label = new Label("Pick something");
	
	public SimpleAWT() {
		init();
	}
	
	public void init() {
		button.addActionListener(this);
		checkbox.addItemListener(this);
		choice.addItemListener(this);
		
		setLayout(new BorderLayout());
		
		choice.addItem("Red");
		choice.addItem("Green");
		choice.addItem("Blue");
		
		Panel panel = new Panel();
		panel.add(button);
		panel.add(checkbox);
		panel.add(choice);
		
		add(label, "Center");
		add(panel, "South");
	}	
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == button) {
			label.setText("The button was pushed.");
		}
	}
	
	public void itemStateChanged(ItemEvent e) {
		if(e.getSource() == checkbox) {
			label.setText("The Checkbox is now " + checkbox.getState() + ".");
		}else if(e.getSource() == choice) {
			label.setText(choice.getSelectedItem() + " was selected");
		}
	}
	
	public static void main(String[] args) {
		SimpleAWT awt = new SimpleAWT();
		awt.setVisible(true);
	}
}
