package com.michal.spring_one;

public class TrackCoach implements Coach {

	private FortuneService fortuneService;
	
	public TrackCoach(FortuneService theFortuneService){
		fortuneService = theFortuneService;
	}
	
	@Override
	public String getDailyWorkout() {
		return "Make a poo `cause you`re just a poor tracker!";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

}
