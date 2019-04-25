package com.michal.springannotations;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class AnnotationDemoJavaCoding {

	public static void main(String[] args) {
		
		AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(CoachesConfig.class);
		
		//Wersja z adnotacjami dzia³a jak nale¿y
		Coach theCoach = context.getBean("tennisCoach", Coach.class);
		
		System.out.println(theCoach.getDailyWorkout());
		System.out.println(theCoach.getDailyFortune());
		System.out.println(theCoach.getCoachPersonals());
		
		//Ale mo¿e byæ te¿ bez adnotacji tylko z @Bean w klasie konfiguracyjnej
		Coach secondCoach = context.getBean("swimCoach", Coach.class);
		
		System.out.println(secondCoach.getDailyWorkout());
		System.out.println(secondCoach.getDailyFortune());
		System.out.println(secondCoach.getCoachPersonals());
		
		context.close();
	}

}
