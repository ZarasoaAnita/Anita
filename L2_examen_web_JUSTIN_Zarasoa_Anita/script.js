document.addEventListener('DOMContentLoaded',function(){
    // Variable pour suivre la page actuelle
    let currentPage = 1;
    // Nombre d'articles par page
    const itemsPerPage = 6;
    // Variable pour stocker les produits
    let products = [];

    
    let addBookButton = document.getElementById("add-book-btn");
     // Ajouter un événement de clic pour rediriger vers la formulaire d'ajout de livres
    addBookButton.addEventListener('click', () => {
        window.location.href = `ajout.html`;
    });

    // Chargement des produits depuis le fichier JSON et affichage initial
    fetch("json/livre.json")
        .then(result => result.json())
        .then(data => {
            products = data;
            console.log(products);
            const totalPages = Math.ceil(products.length / itemsPerPage);
            displayProducts(products, currentPage, itemsPerPage);
            setupPagination(totalPages);
        }); 


        // Fonction pour afficher les produits d'une page spécifique
        function displayProducts(products, page, itemsPerPage) {
            const productContainer = document.getElementById('product-container');
            // Effacer le contenu précédent du conteneur des produits
            productContainer.innerHTML = '';

            // Calculer les indices de début et de fin pour la pagination
            const startIndex = (page - 1) * itemsPerPage;
            const endIndex = Math.min(startIndex + itemsPerPage, products.length);
            // Sélectionner les produits pour la page actuelle
            const paginatedProducts = products.slice(startIndex, endIndex);

            // Afficher chaque produit
            // paginatedProducts.forEach(product => {
            //     const productDiv = document.createElement('div');
            //     // Structure HTML pour chaque produit
            //     productDiv.innerHTML = `
            //         <img src="${product.image}" alt="Couverture du livre">
            //         <h3>${product.titre}</h3>
            //         <p>${product.auteurs}</p>
            //         <button class="detail-btn" data-id="${product.id}">Détails</button>
            //     `;

            //     // Ajouter le produit au conteneur
            //     productContainer.appendChild(productDiv);
            // });
            paginatedProducts.forEach(product => {
                const productDiv = document.createElement('div');
                productDiv.classList.add('product'); // Ajoute la classe CSS "product"
            
                // Structure HTML pour chaque produit
                productDiv.innerHTML = `
                    <img src="${product.image}" alt="Couverture du livre">
                    <h3>${product.titre}</h3>
                    <p>${product.auteurs}</p>
                    <button class="detail-btn" data-id="${product.id}">Détails</button>
                `;
            
                // Ajouter un écouteur d'événement pour le bouton "Détails"
                const detailButton = productDiv.querySelector('.detail-btn');
                detailButton.addEventListener('click', () => {
                    window.location.href = `detail.html?id=${product.id}`;
                });
            
                // Ajouter le produit stylisé au conteneur principal
                productContainer.appendChild(productDiv);
            });
            

            // Ajouter un écouteur d'événement à chaque bouton "Détails" après avoir généré tous les produits
            const detailButtons = document.querySelectorAll('.detail-btn');
            detailButtons.forEach(button => {
                button.addEventListener('click', () => {
                    // Récupérer l'ID du produit à partir de l'attribut data-id du bouton
                    const productId = button.getAttribute('data-id');
                    // Rediriger vers la page de détails avec l'ID dans l'URL
                    window.location.href = `detail.html?id=${productId}`;
                });
            });
        }


    // Événement pour la recherche en temps réel
    const searchInput = document.getElementById('search-input');
    const searchSelect = document.getElementById('search-select');

    searchInput.addEventListener('input', function() {
        const searchTerm = searchInput.value.toLowerCase();
        const searchCriteria = searchSelect.value;

        const filteredProducts = products.filter(product => {
            const fieldValue = product[searchCriteria].toString().toLowerCase();
            return fieldValue.includes(searchTerm);
        });

        currentPage = 1;
        displayProducts(filteredProducts, currentPage, itemsPerPage);
        setupPagination(Math.ceil(filteredProducts.length / itemsPerPage), filteredProducts);
    });

    // // Fonction pour configurer la pagination
    function setupPagination(totalPages, currentProducts) {
        const paginationContainer = document.getElementById('pagination');
        // Effacer le contenu précédent du conteneur de pagination
        paginationContainer.innerHTML = '';
    
        // Créer des liens pour chaque page
        for (let i = 1; i <= totalPages; i++) {
            const pageLink = document.createElement('a');
            pageLink.href = "#";
            pageLink.innerText = i;
    
            // Ajouter la classe "active" à la page courante
            if (i === currentPage) {
                pageLink.classList.add('active');
            }
    
            // Ajouter un événement de clic pour chaque lien de page
            pageLink.addEventListener('click', function(event) {
                event.preventDefault();
                currentPage = i;
                if (currentProducts) {
                    displayProducts(currentProducts, currentPage, itemsPerPage);
                } else {
                    displayProducts(products, currentPage, itemsPerPage);
                }
    
                // Mettre à jour la classe "active" pour tous les liens de pagination
                const paginationLinks = paginationContainer.querySelectorAll('a');
                paginationLinks.forEach(link => {
                    link.classList.remove('active');
                });
                pageLink.classList.add('active');
            });
    
            // Ajouter le lien au conteneur de pagination
            paginationContainer.appendChild(pageLink);
        }
    }
    
});