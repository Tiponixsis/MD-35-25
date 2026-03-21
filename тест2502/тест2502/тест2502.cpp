    #include <iostream>
    #include <string>

    class Supplier
    {
    public:
        Supplier(std::string name, std::string phone)
        {
            _name = name;
            _phone = phone;
        };
        std::string getPhone() const
        {
            return _phone;
        };
        std::string getName() const
        {
            return _name;
        };

    private:
        std::string _name;
        std::string _phone;
    };


    class ItemBase
    {
    public:
        virtual void show() = 0;
        virtual ~ItemBase() = default;
    };


    class Product : public ItemBase
    {
    public:
        void show() override {
            std::cout << "Title: " << _title << "\n";
            std::cout << "Price: " << _price << "\n";
            std::cout << "Supplier name: " << _supplier.getName() << "\n";
            std::cout << "Supplier phone: " << _supplier.getPhone() << "\n";
        };
        Product(std::string title, unsigned price, const Supplier& supplier)
          : _title(title),
           _price(price),
            _supplier(supplier)
        {
            std::cout << "Product created\n";
        };

//        Product(std::string title, unsigned price, const Supplier& supplier) {
//            _title = title;
//            _price = price;
//            _supplier = supplier;
//        };

        void setPrice(unsigned price)
        {
            _price = price;
        };
        int getPrice() const
        {
            return _price;
        };
        void setTitle(std::string title)
        {
            _title = title;
        };
        std::string getTitle() const
        {
            return _title;
        };
    private:
        std::string _title;
        unsigned _price;
        Supplier _supplier;
    };


    int main() {
        Supplier FoodCo("FoodCo.", "+12334243242");
        Supplier CoolerFoodCo("CoolerFoodCo.", "+43562623563");
        Product Apple("Apple", 14, FoodCo);
        Product Pizza("Pizza", 23, FoodCo);
        Apple.show();
        Pizza.show();

        ItemBase* item = new Product("Cool Item 11", 11, CoolerFoodCo);
        item->show();
        delete item;
    }