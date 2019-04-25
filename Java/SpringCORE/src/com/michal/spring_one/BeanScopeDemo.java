package com.michal.spring_one;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class BeanScopeDemo {

	public static void main(String[] args) {
		
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContextScope.xml");
		
		Coach theCoach = context.getBean("myCoach", Coach.class);
		Coach theSecondCoach = context.getBean("myCoach", Coach.class);
		
		Boolean result = (theCoach == theSecondCoach);
		
		System.out.println("Those two references points for the same object: " + result);
		System.out.println("Memory location for theCoach: " + theCoach);
		System.out.println("Memory location for theSecondCoach: " + theSecondCoach);
		
		context.close();
	}

}
