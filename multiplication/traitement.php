<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Table de multiplication</title>
    <style>
        body{
            padding:0px;
            margin:0px;
        }
        table{
            /* width:1000px; */
            text-align:center;
        }
        table,tr,td,thead,th{
            border:solid 2px black;
            border-collapse:collapse;
            margin:auto;
            font-size:1.20rem;
        }
        td{
            height:50px;
            font-weight:600;
        }
        th{
            height:65px;
            font-size:1.5rem;
        }
        .variable{
            width:150px;  
        }
        .reponse{
            width:200px;
        }
        .action{
            width:400px;
        }
        h1{
            text-align:center;
            padding-top:20px;
            color:rgb(63, 62, 62);
        }
        .modification{
            color:rgb(104, 35, 95);
            text-transform:uppercase;
            text-decoration:none;
            margin-right:10px;
            
        }
        .suppression{
            color:rgb(151, 23, 33);
            text-transform:uppercase;
            text-decoration:none;
            margin-left:10px;
        }

    </style>
</head>
<body>
    <table>
        <thead>
            <th class="variable">A</th>
            <th class="variable">B</th>
            <th class="reponse">A * B</th>
            <th  class="action">Action à effectuer</th>
        </thead>
       
        <?php
            $A = $_GET["a"];
            $B = $_GET["b"];
            $result = array();
            $a = array();
            $b = array();
           
            // Ouvrir ou créer un fichier CSV en écriture
            $nomFichierCSV = 'donnees.csv';
            $handleCSV = fopen($nomFichierCSV, 'w');

            // En-tête du fichier CSV
            //   $header = array('A', 'B', 'A * B', 'Action à effectuer');
            //  fputcsv($handleCSV, $header);
            echo "<h1>Table de multiplication de $A</h1>";

            for($i=0 ; $i<=$B ; $i++){
                $a[$i] = $A;
                $b[$i] = $i;
                $result[$i] = $a[$i] * $b[$i];

                // Écrire chaque ligne du tableau dans le fichier CSV
            
                $ligneCSV = array($a[$i], $b[$i], $result[$i], '');  // L'action à effectuer n'est pas ajoutée ici
                fputcsv($handleCSV, $ligneCSV);


                if ($i % 2 == 0) {
                    $color = "#7FDD4C";
                }
                else $color = "#3585CD" ;

              
                echo "<tr style=\"background-color:$color;\"> <td>$a[$i]</td>
                        <td>$b[$i]</td>  
                        <td>$result[$i]</td>
                        
                        <td>
                                <a class=\"modification\" href=\"http://www.zarasoa.com/php/multiplication/modification_form.php?action='modification'&a=$a[$i]&b=$b[$i]&ligne=$i\">Modifier</a>
                                |
                                <a class=\"suppression\" href=\"http://www.zarasoa.com/php/multiplication/suppression.php?ligne=$i\">Supprimer</a>
                        
                        </td>
                        
                        
                    </tr>";     
            }

            // Fermer le fichier CSV
            fclose($handleCSV);
         ?> 
  
    </table>
</body>
</html>