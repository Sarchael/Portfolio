package hibernate.demos;

import hibernate.entities.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


public class DeleteStudentDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Student.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {
			
			int studentId=6;
			
			session.beginTransaction();
			
			Student myStudent = session.get(Student.class, studentId);
			//session.delete(myStudent);
			
			session.createQuery("delete from Student s where s.id=7").executeUpdate();
			
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
