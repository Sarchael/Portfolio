package hibernate.demos;

import hibernate.entities.Instructor;
import hibernate.entities.InstructorDetail;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


public class CreateDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Instructor.class)
								.addAnnotatedClass(InstructorDetail.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {

			Instructor instructor = new Instructor("Bartosz", "Szaszlyk", "b.szaszlyk@interia.pl");
			InstructorDetail instructorDetail = new InstructorDetail("youtube.com/szaszlyczek95", "football");
			instructor.setInstructorDetail(instructorDetail);

			session.beginTransaction();

			session.save(instructor);

			session.getTransaction().commit();

			System.out.println(instructor);
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
		finally {
			factory.close();
		}
	}

}
