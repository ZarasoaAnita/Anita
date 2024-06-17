document.addEventListener('DOMContentLoaded', () => {
    const params = new URLSearchParams(window.location.search);
    const productId = params.get('id');
    if (productId) {
        fetch('../json/products.json')
            .then(response => response.json())
            .then(products => {
                const product = products.find(p => p.id == productId);
                if (product) {
                    displayProductDetails(product);
                } else {
                    document.getElementById('product-details').textContent = 'Produit non trouvé.';
                }
            })
            .catch(error => {
                console.error('Error fetching product details', error);
                document.getElementById('product-details').textContent = 'Erreur lors de la récupération des détails du produit.';
            });
    } else {
        document.getElementById('product-details').textContent = 'Aucun produit spécifié.';
    }
});

function displayProductDetails(product) {
    const productDetails = document.getElementById('product-details');
    productDetails.innerHTML = `
        <img src="${product.image_src}" alt="${product.name}">
        <h2>${product.name}</h2>
        <p>Prix : $${product.price}</p>
        <p>Catégorie : ${product.category}</p>
        <p>Description : ${product.description || 'Aucune description disponible.'}</p>
        <button onclick="addToCart(${product.id})">Ajouter au Panier</button>
    `;
}

function addToCart(productId) {
    let cart = localStorage.getItem('cart');
    cart = cart ? JSON.parse(cart) : [];
    const existingItem = cart.find(item => item.id === productId);
    if (existingItem) {
        existingItem.quantity += 1;
    } else {
        fetch('../json/products.json')
            .then(response => response.json())
            .then(products => {
                const product = products.find(p => p.id == productId);
                if (product) {
                    cart.push({ ...product, quantity: 1 });
                    localStorage.setItem('cart', JSON.stringify(cart));
                    alert('Produit ajouté au panier.');
                }
            })
            .catch(error => {
                console.error('Error adding product to cart', error);
            });
    }
    localStorage.setItem('cart', JSON.stringify(cart));
    alert('Produit ajouté au panier.');
}
