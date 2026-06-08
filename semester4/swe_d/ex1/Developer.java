import java.util.ArrayList;

public class Developer {

    private int age;
    private String name;
    private ArrayList<String> languages = new ArrayList<>();
    private String cv;
    private int gender;

    public void setAge(int age) {

        if (age < 18) {
            System.out.printf("Developer of age %d is not old enough.\n", age);
            return;
        }

        this.age = age;
    }

    public void setCv(String cv) {
        this.cv = cv;
    }
    
    public void setGender(int gender) {
        this.gender = gender;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void add_language(String lang) {
        this.languages.add(lang);
    }

    public void remove_language(String lang) {
        if (!this.languages.remove(lang)) {
            System.out.printf("Warning: Language \"%s\" could not be found inside the Delevopers languages!", lang);
        }
    }

    public int getAge() {
        return age;
    }
    public String getCv() {
        return cv;
    }
    public int getGender() {
        return gender;
    }
    public ArrayList<String> getLanguages() {
        return languages;
    }
    public String getName() {
        return name;
    }
    


}