class Product:
    # Membuat kelas Product untuk merepresentasikan setiap produk
    def __init__(self, id, name, price, quantity):
        # Fungsi __init__ digunakan untuk menginisialisasi objek Product
        # self merujuk pada objek yang sedang dibuat
        # id, name, price, quantity adalah atribut dari objek Product
        self.id = id
        self.name = name
        self.price = price
        self.quantity = quantity

class ProductManager:
    # Membuat kelas ProductManager untuk mengelola kumpulan produk
    def __init__(self):
        # Fungsi __init__ untuk menginisialisasi objek ProductManager
        self.products = {} # Membuat kamus kosong untuk menyimpan objek Product

    def insert_product(self):
        # Fungsi untuk menambahkan produk baru ke dalam kamus products
        id = int(input("Enter product ID: "))
        if id in self.products:
            print("Error: Product ID", id, "already exists. Insertion aborted.")
            return
        name = input("Enter product name: ")
        price = float(input("Enter product price: "))
        quantity = int(input("Enter product quantity: "))
        product = Product(id, name, price, quantity)
        self.products[id] = product
        print("Product inserted successfully.")

    def search_product(self):
        # Fungsi untuk mencari produk berdasarkan ID
        id = int(input("Enter product ID to search: "))
        if id in self.products:
            product = self.products[id]
            print("Product found - ID:", product.id, ", Name:", product.name, ", Price:", product.price, ", Quantity:", product.quantity)
        else:
            print("Product not found")

    def delete_product(self):
        # Fungsi untuk menghapus produk berdasarkan ID
        id = int(input("Enter product ID to delete: "))
        if id in self.products:
            del self.products[id]
            print("Product deleted successfully.")
        else:
            print("Product not found")

    def display_products(self):
        # Fungsi untuk menampilkan semua produk yang ada
        print("Displaying all products:")
        for product in self.products.values():
            print("ID:", product.id, ", Name:", product.name, ", Price:", product.price, ", Quantity:", product.quantity)

# Fungsi utama program
def main():
    # Membuat objek ProductManager
    product_manager = ProductManager()

    # Looping menu
    while True:
        # Menampilkan menu pilihan
        print("\nMenu:")
        print("1. Insert product")
        print("2. Search product")
        print("3. Delete product")
        print("4. Display products")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            product_manager.insert_product()
        elif choice == 2:
            product_manager.search_product()
        elif choice == 3:
            product_manager.delete_product()
        elif choice == 4:
            product_manager.display_products()
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice")

# Memanggil fungsi main jika program dijalankan secara langsung
if __name__ == "__main__":
    main()
