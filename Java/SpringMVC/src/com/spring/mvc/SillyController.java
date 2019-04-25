package com.spring.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/silcon")
public class SillyController {

	@RequestMapping("/showForm")
	public String showForm() {
		return "silly";
	}
}
