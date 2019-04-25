package com.michal.spring_one;

public class HappyFortuneService implements FortuneService {
	
	@Override
	public String getFortune() {
		return "Today is your lucky day!";
	}

}
