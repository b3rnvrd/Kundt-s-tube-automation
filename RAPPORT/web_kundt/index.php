<?php

try{
//connection a la bdd 
$db = new PDO('mysql:host=localhost;dbname=kundt;charset=latin1','root','');
}
catch(Exception $e)
{
    die ('Erreur:'.$e->getMessage());
}
?>





<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Mesures Kundt</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="css/styles.css">
  </head>

  <body>
    <section id="title">
      <div class="container-fluid">
    
        <!-- Title -->
    
    
        <div class="row">
    
          <div class="col-lg-6">
            <h1>Équipez vous de l'insonorisant le plus adéquat.</h1>
          </div>
    
          <div class="col-lg-6">
            <img class="title-image" src="images/isolation-acoustique-1.jpg">
          </div>
    
        </div>
    
    </div>
    </section>
    <!-- Materiaux-->

    <h2>Nos Materiaux</h2>
    <p>Verifiez et choisissez le plus adapté a vos besoins</p>
    <div class="row g-4">

      <div class="col col-lg-4 col-md-6 col-sm-12 pricing-column">
        <!-- Implantation des 3 Cards -->
        <div class="card">
          <div class="card-header">
            <!--card liege-->
            <h3>Le Liège</h3>
          </div>
          <div class="card-body">
            <img src="images/liege.jpg">
            <div class="d-grid gap-2 mx-auto">
                           <!--Bouton modale-->
    <button class="d-block mt-5 btn btn-primary mx-auto" data-bs-toggle="modal" data-bs-target="#modal1">Voir les caractéristiques</button>
    <!--Modal-->
    <div class="modal fade" id="modal1">
      <div class="modal-dialog modal-dialog-scrollable modal-dialog-centered">
        <div class="modal-content">
          <div class="modal-header">
           <h5 class="modal-title" aria-labelledby="modal-title">
             Les Caractéristiques Du Liège
            </h5>
            <button class="btn-close" data-bs-dismiss="modal" aria-labelledby="Close"></button>
          </div>
          <div class="modal-body" aria-describedby="content">
            <!--Tableau des caractéristiques-->
            <table>
              <tr>
                <td>Fréquence</td>
                <td >Coefficient d'absorbtion</td>
              </tr>
              <?php
            $tabfreq = $db->prepare("SELECT `frequence` FROM `enregistrement` WHERE `id_materiau`=1");
            $tabfreq->execute();
            
            $coefliege = $db->prepare("SELECT `absorption` FROM `enregistrement` WHERE `id_materiau`=1");
            $coefliege->execute();

            for ($i=0; $i<13; $i++)
            {

            
            $frequences= $tabfreq->fetch();
            $lieges= $coefliege->fetch();

              ?>
              <tr>
              <td><?php echo $frequences['frequence'];?></td>
              <td><?php echo($lieges['absorption']);?></td>
              </tr>
            <?php
            }
            ?>
            </table>
          </div>
          <div class="modal-footer">
            <button class="btn btn-secondary" data-bs-dismiss="modal">Fermer</button>
          </div>
        </div>
      </div>
    </div>
<!--fin modal-->
            </div>
            
          </div>
        </div>
      </div>

      <div class="col col-lg-4 col-md-6 col-sm-12 pricing-column">
        <!--card polystyrene-->
        <div class="card">
          <div class="card-header">
            <h3>Le Polystyrène</h3>
          </div>
          <div class="card-body">
            <img src="images/polystyrene.jpg">
            <div class="d-grid gap-2 mx-auto">
                         <!--Bouton modale-->
    <button class="d-block mt-5 btn btn-primary mx-auto" data-bs-toggle="modal" data-bs-target="#modal2">Voir les caractéristiques</button>
    <!--Modal-->
    <div class="modal fade" id="modal2">
      <div class="modal-dialog modal-dialog-scrollable modal-dialog-centered">
        <div class="modal-content">
          <div class="modal-header">
           <h5 class="modal-title" aria-labelledby="modal-title">
            Les Caractéristiques Du Polystyrène
            </h5>
            <button class="btn-close" data-bs-dismiss="modal" aria-labelledby="Close"></button>
          </div>
          <div class="modal-body" aria-describedby="content">
            <!--Tableau des caractéristiques-->
            <table>
              <tr>
                <td>Fréquence</td>
                <td >Coefficient d'absorbtion</td>
              </tr>
              <?php
            $tabfreq = $db->prepare("SELECT `frequence` FROM `enregistrement` WHERE `id_materiau`=3");
            $tabfreq->execute();
            
            $coefliege = $db->prepare("SELECT `absorption` FROM `enregistrement` WHERE `id_materiau`=3");
            $coefliege->execute();

            for ($i=0; $i<13; $i++)
            {

            
            $frequences= $tabfreq->fetch();
            $lieges= $coefliege->fetch();

              ?>
              <tr>
              <td><?php echo $frequences['frequence'];?></td>
              <td><?php echo($lieges['absorption']);?></td>
              </tr>
            <?php
            }
            ?>
            </table>
          </div>
          <div class="modal-footer">
            <button class="btn btn-secondary" data-bs-dismiss="modal">Fermer</button>
          </div>
        </div>
      </div>
    </div>
<!--fin modal-->
            </div>
            
          </div>
        </div> 
      </div>

      <div class="col col-lg-4 col-sm-12 pricing-column">
        <!--card bois-->
        <div class="card">
          <div class="card-header">
            <h3>Le Bois</h3>
          </div>
          <div class="card-body">
            <img src="images/bois.jpg">
            <div class="d-grid gap-2 mx-auto">
                          <!--Bouton modale-->
    <button class="d-block mt-5 btn btn-primary mx-auto" data-bs-toggle="modal" data-bs-target="#modal3">Voir les caractéristiques</button>
    <!--Modal-->
    <div class="modal fade" id="modal3">
      <div class="modal-dialog modal-dialog-scrollable modal-dialog-centered">
        <div class="modal-content">
          <div class="modal-header">
           <h5 class="modal-title" aria-labelledby="modal-title">
              Les Caractéristiques Du Bois
            </h5>
            <button class="btn-close" data-bs-dismiss="modal" aria-labelledby="Close"></button>
          </div>
          <div class="modal-body" aria-describedby="content">
            <!--Tableau des caractéristiques-->
            <table>
              <tr>
                <td>Fréquence</td>
                <td >Coefficient d'absorbtion</td>
              </tr>
              <?php
            $tabfreq = $db->prepare("SELECT `frequence` FROM `enregistrement` WHERE `id_materiau`=2");
            $tabfreq->execute();
            
            $coefliege = $db->prepare("SELECT `absorption` FROM `enregistrement` WHERE `id_materiau` = 2");
            $coefliege->execute();

            for ( $i=0 ; $i < 13 ; $i ++)
            {

            
            $frequences = $tabfreq->fetch();
            $lieges = $coefliege->fetch();

              ?>
              <tr>
              <td><?php echo $frequences['frequence'];?></td>
              <td><?php echo($lieges['absorption']);?></td>
              </tr>
            <?php
            }
            ?>
            </table>
          </div>
          <div class="modal-footer">
            <button class="btn btn-secondary" data-bs-dismiss="modal">Fermer</button>
          </div>
        </div>
      </div>
    </div>
<!--fin modal-->
            </div>
            
          </div>
        </div>
      </div>

    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
  </body>
</html>