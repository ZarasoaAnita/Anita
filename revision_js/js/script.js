document.addEventListener('DOMContentLoaded',function(){
    let listProductHTML = document.querySelector('.listProduct');

    let listProducts = [];

    const addDataToHTML = () =>{
        listProductHTML.innerHTML = ``;
        if(listProducts.length>0){
            listProducts.forEach(product =>{
                let newProduct = document.createElement('div');
                newProduct.classList.add('item');
                newProduct.innerHTML = `
                    <img src="${product.image_src} " alt="">
                    <h2>${product.name}</h2>
                    <div class="price">$${product.price}</div>
                    <button class="addCart">
                        Add To cart
                    </button>
                    <button class="details" data-id="${product.id}">Details</button>
      
                `;

                listProductHTML.appendChild(newProduct);
            });

             // Ajouter des gestionnaires d'événements pour les boutons "Details"
             const detailButtons = document.querySelectorAll('.details');
             detailButtons.forEach(button => {
                 button.addEventListener('click', function() {
                     const productId = this.getAttribute('data-id');
                     window.location.href = `details.html?id=${productId}`;
                 });
             });
        }
    }

    const initApp = () =>{
        fetch('../json/products.json')
        .then(result => result.json())
        .then(products=>{
            listProducts = products;
            // console.log(listProducts);
            addDataToHTML();
        })
        .catch(error =>{
            console.log("Error fetchind data");
        })
    };

    initApp();
});