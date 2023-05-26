<?php

try{
//connection a la bdd 
$db = new PDO('mysql:host=localhost;dbname=kundt;charset=latin1','Directeur','Directeur123');
}
catch(Exception $e)
{
    die ('Erreur:'.$e->getMessage());
}
//$sqlQuery= "SELECT `absorbtion` FROM `enregistrement` WHERE `id_materiau`=1"
$coefliege = $db->prepare("SELECT `absorbtion` FROM `enregistrement` WHERE `id_materiau`=1");
$coefliege->execute();
$liege= $coefliege->fetchall();

?>
<p><?php echo $liege[0];?></p>

