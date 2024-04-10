<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Accueil</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #eaaac9;
            margin: 0;
            padding: 0;
            height: 100vh; /* Utilise toute la hauteur de la vue (écran) */
            display: flex; /* Utilise le modèle de boîte flexible pour le centrage vertical */
            justify-content: center; /* Centre le contenu horizontalement */
            
        }

        h1 {
            text-align: center;
            margin-top: 75px;
            margin-bottom:50px;
            font-size: 2.2rem;
        }

        ul {
            list-style-type: none;
            padding: 0;
            text-align: center;
            margin-top: 30px;
            
        }

        li {
            display: inline-block;
            margin: 0 20px;

        }

        a {
            text-decoration: none;
            color: #333;
            background-color: #fff;
            padding: 10px 20px;
            border: 2px solid #333;
            border-radius: 5px;
            transition: all 0.3s ease;
        }

        a:hover {
            background-color: #333;
            color: #e24a6d;
        }
        .contenu-au-milieu{
        	
        }
    </style>
</head>
<body>
	<div class="contenu-au-milieu">
	    <h1>Bienvenue sur votre application de gestion des tâches !</h1>
	    <ul>
	        <li><a href="ServletList">Lister les tâches</a></li>
	        <li><a href="ajout.html">Ajouter une tâche à la liste</a></li>
	    </ul>
    </div>
</body>
</html>
