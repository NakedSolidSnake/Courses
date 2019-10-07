package employee;

public class Employee {
	private int id;
	private String name;
	private double hourlyRate;
	private boolean partyTime;
	
	public Employee(int id, String name, double hourlyRate, boolean partyTime) {
		super();
		this.id = id;
		this.name = name;
		this.hourlyRate = hourlyRate;
		this.partyTime = partyTime;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getHourlyRate() {
		return hourlyRate;
	}

	public void setHourlyRate(double hourlyRate) {
		this.hourlyRate = hourlyRate;
	}

	public boolean isPartyTime() {
		return partyTime;
	}

	public void setPartyTime(boolean partyTime) {
		this.partyTime = partyTime;
	}

}
