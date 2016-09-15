// Start animation to left +300px
$( "#go" ).click(function() {
  $( ".block" ).animate({ left: "+=900px" }, 5000 );
});
 
// Stop animation when button is clicked
$( "#stop" ).click(function() {
  $( ".block" ).stop();
});
 
// Start animation to right +300px
$( "#back" ).click(function() {
  $( ".block" ).animate({ left: "-=900px" }, 2000 );
});

// hide the image when button is clicked 
$( "cat" ).click(function() {
  $( "p" ).hide( "slow" );
});

