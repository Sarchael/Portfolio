package hibernate.demos;

import java.util.List;

import hibernate.entities.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entities.Student;

public class QueryStudentDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Student.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {			
			session.beginTransaction();
			
			List<Student> studentsList = session.createQuery("from Student").getResultList();
			displayStudents(studentsList);
			studentsList = session.createQuery("from Student s where s.lastName='Pochec'").getResultList();
			displayStudents(studentsList);
			studentsList = session.createQuery("from Student s where s.email like '%.pl'").getResultList();
			displayStudents(studentsList);
			
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

	private static void displayStudents(List<Student> studentsList) {
		for(Student tempStudent : studentsList) {
			System.out.println(tempStudent);
		}
	}

}
