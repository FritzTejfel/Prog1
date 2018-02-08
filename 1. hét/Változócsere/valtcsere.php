<!DOCTYPE html>
<html>
<head>
    <title>Page Title</title>

</head>
<body>
<?php 
    $a = 25;
    $b = 12;

    echo 'a: ' . $a . '</br>';
    echo 'b: ' . $b . '</br>';

    $a = $b - $a;
	$b -= $a;
    $a += $b; 
    
    echo 'a: ' . $a . '</br>';
    echo 'b: ' . $b . '</br>';

    $a = $b - $a;
	$b -= $a;
    $a += $b; 
    
    echo 'a: ' . $a . '</br>';
    echo 'b: ' . $b . '</br>';

?>
    
</body>
</html>