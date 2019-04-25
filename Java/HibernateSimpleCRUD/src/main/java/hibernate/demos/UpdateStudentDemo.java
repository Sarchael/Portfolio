package hibernate.demos;

import hibernate.entities.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entities.Student;

public class UpdateStudentDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Student.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {
			
			int studentId=1;
			
			session.beginTransaction();
			
			Student myStudent = session.get(Student.class, studentId);
			myStudent.setLastName("Szaranowski");
			
			session.createQuery("update Student s set s.email='gowniany jakis' where s.email like '%wp.pl'").executeUpdate();
			
			session.getTransaction().commit();						
			
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
		finally {
			factory.close();
		}
	}

}
