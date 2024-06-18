document.addEventListener('DOMContentLoaded', function() {
    const urlParams = new URLSearchParams(window.location.search);
    const productId = urlParams.get('id');

    // Charge les produits depuis le fichier JSON
    fetch("json/livre.json")
        .then(result => result.json())
        .then(products => {
            console.log(products);
            // Trouve le produit correspondant à l'ID récupéré
            const product = products.find(p => p.id === parseInt(productId)); // Convertir en entier si nécessaire
            if (product) {
                // Affiche les détails du produit
                displayProductDetails(product);
               
            }
        })
        .catch(error => {
            console.error('Erreur lors du chargement du fichier JSON :', error);
        });

    // Fonction pour afficher les détails d'un produit
    function displayProductDetails(product) {
        const productDetailsContainer = document.getElementById('product-details');

        // Créer les éléments HTML pour afficher les détails du produit
        const productDiv = document.createElement('div');
        productDiv.classList.add('product-details');

        productDiv.innerHTML = `
            <div class="product-image">
                <img src="${product.image}" alt="Couverture du livre">
            </div>
            <div class="product-info">
                <h2>${product.titre}</h2>
                <p>Auteur(s): ${product.auteurs}</p>
                <p>ISBN: ${product.isbn}</p>
                <p>Éditeur: ${product.editeur}</p>
                <p>Date de Publication: ${product.datePublication}</p>
                <p>Genre: ${product.genre}</p>
                <p>Langue: ${product.langue}</p>
                <p>Nombre de Pages: ${product.nombrePages}</p>
                <p>Disponibilité: ${product.disponibilite ? 'Disponible' : 'Non disponible'}</p>
                <p>État: ${product.etat}</p>
                <p>Emplacement: ${product.emplacement}</p>
                <p class="resume">Résumé: ${product.resume}</p>
            </div>
        `;

        // Ajouter les détails du produit au conteneur principal
        productDetailsContainer.appendChild(productDiv);
    }

    let returnButton = document.getElementById("return-btn");
    returnButton.addEventListener('click', () => {
       window.location.href = `index.html`;
   });

});
