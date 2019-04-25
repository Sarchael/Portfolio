package hibernate.demos;

import hibernate.entities.Instructor;
import hibernate.entities.InstructorDetail;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


public class GetInstructorDetailDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Instructor.class)
								.addAnnotatedClass(InstructorDetail.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {

			session.beginTransaction();

			InstructorDetail temp = session.get(InstructorDetail.class, 1);
			System.out.println("Instructor detail: " + temp.toString());
			System.out.println("Instructor: " + temp.getInstructor().toString());

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
