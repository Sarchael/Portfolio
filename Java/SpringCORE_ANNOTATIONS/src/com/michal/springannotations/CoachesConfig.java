package com.michal.springannotations;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@ComponentScan("com.michal.springannotations") //mo�na zakomentowa� je�li wszystkie beany s� 
												//zdefiniowane ni�ej (ale nie s� xd)
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
