<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulaire de modification</title>
    <style>
        body{
            background-color: black;
            font-size:1.5rem;
        }
        .formulaire{
            background-color:rgb(241, 90, 115);
            width:500px;
            height:600px;
            margin:auto;
            margin-top:75px;
            padding-left: 50px;
            border-radius: 25px 25px 25px 25px;
        }
        input{
            width:325px;
            height:75px;
            margin-left:20px;
            margin-top:50px;
        }
        .multiplication{
            margin-left:20px;
            width:150px;
            height:50px;
            border-radius: 10px 10px 10px 10px;

        }
        input{
            font-size: 20px;
        }
        .multiplication:hover{
            background-color: rgb(31, 30, 30);
            color:white;
        }
        p{
            padding-top:20px;
            margin:auto;
            font-size:1.25rem;
            line-height:40px;
        }
    </style>
</head>
<body>
    <?php
        $A = $_GET["a"];
        $B = $_GET["b"];
        $ligne = $_GET["ligne"];
    ?>
    <div class="formulaire">
        <form action="http://www.zarasoa.com/php/multiplication/modification.php" method="get">
            
            <p>Avant a=<?php echo $A; ?>  et b=<?php echo $B; ?>
            <br>Modifier en:</p>

            <!-- Ajoutez des champs cachés pour les valeurs de A et B -->
            <input type="hidden" name="a" value="<?php echo $A; ?>" >
            <input type="hidden" name="b" value="<?php echo $B; ?>" >
            <input type="hidden" name="ligne" value="<?php echo $ligne; ?>">

            a: <input type="number" name="nouveau_a" required>
            <br><br><br>

            b: <input type="number" name="nouveau_b" required>
            <br><br><br>

            <input type="submit" name="envoyer" value="Modifier" class="multiplication" required>
        
        </form>
    </div>
</body>
</head>
</html>