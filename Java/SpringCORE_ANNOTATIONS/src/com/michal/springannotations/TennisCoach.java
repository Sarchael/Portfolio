package com.michal.springannotations;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class TennisCoach implements Coach {

	//WERSJA Z ANOTACJA NAD POLEM (NAJPROSTSZE)
	
	@Autowired
	@Qualifier("randomFortuneService")
	private FortuneService fortuneService;
	
	@Value("${email}")
	private String email;
	
	@Value("${phone_number}")
	private String phone;
	
	//WERSJA Z KONSTRUKTOREM
	
	/*@Autowired
	public TennisCoach(FortuneService theFortuneService){
		fortuneService = theFortuneService;
	}*/
	
	//WERSJA Z SETTEREM
	
	/*@Autowired
	public void randomNameSetter(FortuneService theFortuneService) {
		fortuneService = theFortuneService;
	}*/
	
	@Override
	public String getDailyWorkout() {
		return "Practice your backhand volley!";
	}
	
	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}
	
	@Override
	public String getCoachPersonals() {
		return "email: " + email + "\nphone number: " + phone;
	}

}
