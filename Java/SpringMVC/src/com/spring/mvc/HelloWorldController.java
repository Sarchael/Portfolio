package com.spring.mvc;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloWorldController {
	
	@RequestMapping("/showForm")
	public String showForm() {
		return "helloworld-form";
	}	
	
	@RequestMapping("/processForm")
	public String processForm() {
		return "helloworld";
	}
	
	@RequestMapping("/processFormV2")
	public String letShoutDude(HttpServletRequest request, Model model) {
		
		String name = request.getParameter("studentName");
		
		name = name.toUpperCase();
		String message = "Yo! " + name;
		
		model.addAttribute("message", message);
		
		return "helloworld";
	}
	
	@RequestMapping("/processFormV3")
	public String letShoutDude3(@RequestParam("studentName") String theName, Model model) {
		
		String message = "Yo! " + theName.toUpperCase();
		
		model.addAttribute("message", message);
		
		return "helloworld";
	}
}
