<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>


<!DOCTYPE html> 
<html>

<head>
	<title>Student Confirmation</title>
</head>

<body>
	The student confirmed: ${ student.firstName } ${ student.lastName } from ${ student.country }
	that likes ${ student.favouriteLanguage }.
	<br>
	Student know such operating systems as:
	<ul>		
		<c:forEach var="temp" items="${ student.operatingSystems }">
			<li> ${ temp } </li>
		</c:forEach>
	</ul>
	
</body>

</html>