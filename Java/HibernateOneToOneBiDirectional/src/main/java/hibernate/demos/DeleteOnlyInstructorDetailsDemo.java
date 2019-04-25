package hibernate.demos;

import hibernate.entities.Instructor;
import hibernate.entities.InstructorDetail;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


public class DeleteOnlyInstructorDetailsDemo {

	public static void main(String[] args) {
		
		SessionFactory factory = new Configuration()
								.configure("hibernate.cfg.xml")
								.addAnnotatedClass(Instructor.class)
								.addAnnotatedClass(InstructorDetail.class)
								.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		try {

			session.beginTransaction();

			int id=6;

			InstructorDetail temp = session.get(InstructorDetail.class, id);


			if(temp != null){
				temp.getInstructor().setInstructorDetail(null);
				session.delete(temp);
			}

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
