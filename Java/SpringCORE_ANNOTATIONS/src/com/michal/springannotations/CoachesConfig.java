package com.michal.springannotations;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@ComponentScan("com.michal.springannotations") //mo¿na zakomentowaæ jeœli wszystkie beany s¹ 
												//zdefiniowane ni¿ej (ale nie s¹ xd)
@PropertySource("classpath:personal_data.prop")
public class CoachesConfig {

	@Bean
	public FortuneService sadFortuneService() {
		return new SadFortuneService();
	}
	
	@Bean
	public SwimCoach swimCoach() {
		return new SwimCoach(sadFortuneService());
	}
}
