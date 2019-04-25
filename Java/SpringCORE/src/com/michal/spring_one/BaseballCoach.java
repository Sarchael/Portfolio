package com.michal.spring_one;

public class BaseballCoach implements Coach {
	
	private FortuneService fortuneService;
	
	public BaseballCoach(FortuneService theFortuneService){
		fortuneService = theFortuneService;
	}
	
	@Override
	public String getDailyWorkout() {
		return "Do 30 baseball push-ups!";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}
	
	private void callMeAtTheBeginnig() {
		System.out.println("Object is starting");
	}

	private void callMeAtTheEnd() {
		System.out.println("Object is stoping");
	}
}
