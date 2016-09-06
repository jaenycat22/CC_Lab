var paragraph_showing = false;

document.getElementById("cold").addEventListener("click", displayCold);
document.getElementById("cold_pop_up").addEventListener("click", displayCold);
document.getElementById("hot").addEventListener("click", displayHot);
document.getElementById("hot_pop_up").addEventListener("click", displayHot);

function displayCold(){

	if(paragraph_showing == true){
	document.getElementById("cold_pop_up").style.display="none"; 
	paragraph_showing = false;
}  else{
	document.getElementById("cold_pop_up").style.display="inherit"; 
	paragraph_showing = true;
}
}


function displayHot(){

	if(paragraph_showing == true){
	document.getElementById("hot_pop_up").style.display="none"; 
	paragraph_showing = false;
}  else{
	document.getElementById("hot_pop_up").style.display="inherit"; 
	paragraph_showing = true;
}
}