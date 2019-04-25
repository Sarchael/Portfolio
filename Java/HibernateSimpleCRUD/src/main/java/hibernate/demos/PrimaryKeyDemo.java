package hibernate.demos;

import hibernate.entities.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entities.Student;

public class PrimaryKeyDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
				.configure("hibernate.cfg.xml")
				.addAnnotatedClass(Student.class)
				.buildSessionFactory();

		Session session = factory.getCurrentSession();
		
		try {
			System.out.println("Creating 3 new student object...");
			Student tempStudent1 = new Student("Michal", "Pochec", "mpochec2012@gmail.com");
			Student tempStudent2 = new Student("Barbara", "Kurdej-Szatan", "bubulinek@o2.pl");
			Student tempStudent3 = new Student("Wojciech", "Pankowski", "fasartian@wp.pl");
			
			session.beginTransaction();
			
			System.out.println("Saving students...");
			session.save(tempStudent1);
			session.save(tempStudent2);
			session.save(tempStudent3);
			
			session.getTransaction().commit();			
			System.out.println("Done!");
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
		finally {
			factory.close();
		}
	}

}
