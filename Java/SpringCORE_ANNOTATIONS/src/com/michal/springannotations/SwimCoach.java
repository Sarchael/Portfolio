package com.michal.springannotations;

public class SwimCoach implements Coach {

	private FortuneService fortuneService;
	
	public SwimCoach (FortuneService theFortuneService) {
		fortuneService = theFortuneService;
	}
	
	@Override
	public String getDailyWorkout() {
		return "Let`s swim 3km in the pool!";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

	@Override
	public String getCoachPersonals() {
		return "Don`t have any personals :(";
	}

}
