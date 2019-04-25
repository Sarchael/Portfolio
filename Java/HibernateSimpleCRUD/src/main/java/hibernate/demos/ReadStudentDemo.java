package hibernate.demos;

import hibernate.entities.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entities.Student;

public class ReadStudentDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Student.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {
			//Saving Student in data base
			System.out.println("Creating new student object...");
			Student tempStudent = new Student("Gigi", "Buffon", "gianluigi@gmail.com");
			System.out.println(tempStudent);
			
			session.beginTransaction();
			
			System.out.println("Saving the student...");
			session.save(tempStudent);
			
			session.getTransaction().commit();			
			System.out.println("Student saved! Generated ID is: " + tempStudent.getId());
			
			
			//Retrieving Student from data base
			session=factory.getCurrentSession();
			session.beginTransaction();
			
			System.out.println("Getting student from database witch ID is: " + tempStudent.getId());
			Student myStudent = session.get(Student.class, tempStudent.getId());
			System.out.println("I finished! The student: " + myStudent);
			
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
