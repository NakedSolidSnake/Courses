package students;

public class Subject {
	private String id;
	private String name;
	
	public Subject(String id, String name) throws Exception {
		
		if(!subjectOk(id, name))
			throw new Exception("The subject must have both an ID and a name");
		this.id = id;
		this.name = name;
	}
	
	public String getId() {
		return id;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) throws Exception{
		if(!subjectOk(id, name))
			throw new Exception("The subject must have a name");
		this.name = name;
	}
	
	public String toString() {
		return name;
	}
	
	public static boolean subjectOk(String id, String name) {
		return id != null && id.length() > 0 && name != null && name.length() > 0;
	}
}
