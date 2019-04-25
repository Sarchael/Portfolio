<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>

<!DOCTYPE html>

<html>

<head>
	<title>Student Registration Form</title>
</head>

<body>

	<form:form action="processForm" modelAttribute="student">
	
		First name: <form:input path="firstName" />
		
		<br><br>
		
		Last name: <form:input path="lastName" />
		
		<br><br>
		
		Country:
		
		<form:select path="country">
			<form:options items="${ student.countryOptions }" />
		</form:select>
		
		<br><br>
		
		Favourite language: 
		
		<form:radiobutton path="favouriteLanguage" value="PHP" /> PHP  
		<form:radiobutton path="favouriteLanguage" value="Java" /> Java  
		<form:radiobutton path="favouriteLanguage" value="C#" /> C#  
		<form:radiobutton path="favouriteLanguage" value="Kotlin" /> Kotlin  
		<form:radiobutton path="favouriteLanguage" value="Swift" /> Swift
		
		<br><br>
		
		Known operating systems:
		
		<form:checkbox path="operatingSystems" value="Windows" /> Windows
		<form:checkbox path="operatingSystems" value="MacOS" /> MacOS
		<form:checkbox path="operatingSystems" value="Linux" /> Linux
		
		<br><br>
		
		<input type="submit" value="Submit" />
	
	</form:form>

</body>

</html>