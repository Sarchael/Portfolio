package com.spring.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/student")
public class StudentController {

	@RequestMapping("/showForm")
	public String showForm(Model theModel) {
		
		theModel.addAttribute("student", new Student());
		
		return "student-form";
	}
	
	@RequestMapping("/processForm")
	public String processForm(@ModelAttribute("student") Student theStudent) {
		
		System.out.println("Name: " + theStudent.getFirstName() + " Surname: " + theStudent.getLastName());
		System.out.println("Country: " + theStudent.getCountry());
		System.out.println("Favourite language: " + theStudent.getFavouriteLanguage());
		
		return "student-confirmation";
	}
}
