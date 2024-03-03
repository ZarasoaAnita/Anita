<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
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
            color:rgb(151, 5, 115);
            text-transform:uppercase;
            text-decoration:none;
            margin-right:10px;
            
        }
        .suppression{
            color:brown;
            text-transform:uppercase;
            text-decoration:none;
            margin-left:10px;
        }
        table{
            margin-top:50px;
        }

    </style>
</head>
<body>
<?php

        $A = $_GET["a"];
        $B = $_GET["b"];
        $ligne = $_GET["ligne"];
        $nouveau_A = $_GET["nouveau_a"];
        $nouveau_B = $_GET["nouveau_b"];
        
        $nomFichierCSV = 'donnees.csv';

        // Lire le contenu du fichier CSV dans un tableau
        $contenuCSV = file($nomFichierCSV, FILE_IGNORE_NEW_LINES);

        // Vérifier si la ligne à modifier existe dans le tableau
        if (isset($contenuCSV[$ligne])) {
            // Modifier la ligne appropriée dans le tableau
            $contenuCSV[$ligne] = "$nouveau_A,$nouveau_B," . ($nouveau_A * $nouveau_B);
            
            // Réécrire le tableau modifié dans le fichier CSV
            file_put_contents($nomFichierCSV, implode("\n", $contenuCSV));
        }

        $a = array();
        $b = array();
        $result = array();

        foreach ($contenuCSV as $ligne) {
            // Supposons que les champs dans le CSV sont séparés par des virgules
            $champs = explode(',', $ligne);
            
            // Stocker chaque champ dans les tableaux respectifs
            $a[] = $champs[0];
            $b[] = $champs[1];
            $result[] = $champs[2];
        }

        $nombre_total_ligne = count($result);

        if ($nombre_total_ligne != 0) {

            // Afficher la table de multiplication uniquement si le nombre total de lignes est supérieur à zéro
            echo '<table>';
            echo '<thead>';
            echo '<th class="variable">A</th>';
            echo '<th class="variable">B</th>';
            echo '<th class="reponse">A * B</th>';
            echo '<th class="action">Action à effectuer</th>';
            echo '</thead>';

            for ($i = 0; $i < $nombre_total_ligne; $i++) {
                if ($i % 2 == 0) {
                    $color = "#7FDD4C";
                } else {
                    $color = "#3585CD";
                }

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

            echo '</table>';
        } else {
            echo "<p>La table de multiplication est vide</p>";
        }
       

       

    ?>

    
</body>
</html>