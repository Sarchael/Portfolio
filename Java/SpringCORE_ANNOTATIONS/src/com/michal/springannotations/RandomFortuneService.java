package com.michal.springannotations;

import java.util.Random;

import org.springframework.stereotype.Component;

@Component
public class RandomFortuneService implements FortuneService {

	private String[] fortunes = {
			"Today you can do everything!",
			"Today nothing special should happen to you!",
			"Today you should stay in bed!"
	};
	
	private Random randomNumberGenerator = new Random();
	
	@Override
	public String getFortune() {	
		return fortunes[randomNumberGenerator.nextInt(fortunes.length)];
	}

}
