using System;
using System.Collections.Generic;
using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Impl;
using System.Linq;
using MyPharmacy.DAL.Repositories;

namespace MyPharmacy.PL.UserMenu.Impl
{
    public class CosmeticMenu : BaseMenu<CosmeticRepository, Cosmetic>
    {
        public CosmeticMenu() /*: base()*/
        {
            cart = new CartRepository();
            cosRepos = new CosmeticRepository();
            factory = new FlyweightFactory();
        }
        CartRepository cart;
        CosmeticRepository cosRepos;
        FlyweightFactory factory;
        public override void ShowTableMenu()
        {
            products = cosRepos.GetAll() ?? new List<Cosmetic>();
            if (products.Count() != 0)
            {
                this.currentId = products[0].id;
            }
            PrintTableForm();
            TableMenuCommands catcher;
            do
            {
                catcher = (TableMenuCommands)((int)(Console.ReadKey(true).KeyChar) - 48);
                switch (catcher)
                {
                    case TableMenuCommands.Up:
                        {
                            MoveCursorByProductId(-1);
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.Down:
                        {
                            MoveCursorByProductId(1);
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.SelectCurrentProduct:
                        {
                            ShowProductMenu(this.currentId);
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.SortTableById:
                        {
                            SortTable();
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.OrderCurrentProduct:
                    {
                        OrderProduct();
                        PrintTableForm();
                        break;
                    }
                    case TableMenuCommands.TableOpenCard:
                    {
                        OpenCard();
                        PrintTableForm();
                        break;
                    }
                    default:
                    {
                        continue;
                    }
                }
            } while (catcher != TableMenuCommands.TableMenuBack);
        }
		public override void PrintTable()
        {
            Console.WriteLine("\n\n");
            Console.WriteLine("ID | expirationDate | Name | storageFormType | Capacity | Amount");
            Console.WriteLine("\n\n");
            foreach (var it in products)
            {
                Cosmetic p = it;
                if (p.id == this.currentId)
                {
                    Console.Write(" ->  ");
                }
                Console.WriteLine($"{ p.id} | {p.expirationDate} | {p.name}" +
                    $" | {p.storageTemperature} | {p.capacity} | {p.amount}");
            }
            Console.WriteLine("\n\n");
        }
        public override void PrintTableForm()
        {
            Console.Clear();
            Console.WriteLine("\t\t\t Cosmetic Table \t\t\t \n\n");
            Console.WriteLine(
                $" {(int)TableMenuCommands.TableMenuBack} : Back |" +
                $" {(int)TableMenuCommands.Up}" + $" : Up |" +
                $" {(int)TableMenuCommands.Down} : Down |\n" +
                $" {(int)TableMenuCommands.SelectCurrentProduct} : Select Current Product |" +
                $" {(int)TableMenuCommands.SortTableById}: Sort Table By Id | " +
                $" {(int)TableMenuCommands.OrderCurrentProduct}  : Order current product | " +
                $" {(int)TableMenuCommands.TableOpenCard} : Table open card | "
                
                );
            SetState(TableMenuCommands.TableMenuWaiting);
            PrintTable();
        }
        public override void SortTable()
        {
            Console.Clear();

            if (products[0].id > products[1].id)
            {
                products.Sort((x, y) => x.id.CompareTo(y.id));
            }
            else
            {
                products.Sort((y, x) => x.id.CompareTo(y.id));
            }
        }
        public override void MoveCursorByProductId(int n)
        {
            if (n == 1)
            {
                if (currentId == products[products.Count - 1].id)
                {
                    return;
                }
            }
            else
            {
                if (currentId == products[0].id)
                {
                    return;
                }
            }
            int i = 0;
            while (products[i].id != currentId)
            {
                i++;
            }
            currentId = products[i+n].id;
        }

        public void ShowProductMenu(int Id)
        {
            this.currentId = Id;
            PrintProductForm();
            ProductMenuCommands command;
            do
            {
                command = (ProductMenuCommands)((int)(Console.ReadKey(true).KeyChar) - 48);
                switch (command)
                {
                    case ProductMenuCommands.ProductFieldUp:
                    {
                        if (currentProductFieldId != 1) { currentProductFieldId--; }
                        PrintProductForm();
                        break;
                    }
                    case ProductMenuCommands.ProductFieldDown:
                    {
                        if (currentProductFieldId != 5) { currentProductFieldId++; }
                        PrintProductForm();
                        break;
                    }
                    case ProductMenuCommands.ChangeCurrentField:
                    {
                        //
                        Console.WriteLine("Change this field ? | 0 : No | 1 : Yes");
                        if (Console.ReadKey().KeyChar == '1')
                        {
                            ChangeCurrentFieldById(currentProductFieldId);
                            products = cosRepos.GetAll();
                        }
                        //
                        currentProductFieldId = 1;
                        PrintProductForm();
                        break;
                    }
                    default:
                    {
                        continue;
                    }
                }
            } while (command != ProductMenuCommands.ProductMenuBack);
        }
        public void PrintProduct()
        {
            products = cosRepos.GetAll();
            Cosmetic product = new Cosmetic();
            foreach (var it in products)
            {
                if (it.id == currentId)
                {
                    product = it;
                }
            }
            Console.WriteLine("\n\n");
            Console.WriteLine($"Id : { product.id} \n\n");

            if (currentProductFieldId == 1) { Console.Write(" ->  "); }
            Console.WriteLine($"Expiration Date : {product.expirationDate}");

            if (currentProductFieldId == 2) { Console.Write(" ->  "); }
            Console.WriteLine($"Name :  {product.name}");

            if (currentProductFieldId == 3) { Console.Write(" ->  "); }
            Console.WriteLine($"Storage Form Type : {product.storageTemperature}");

            if (currentProductFieldId == 4) { Console.Write(" ->  "); }
            Console.WriteLine($"Capacity : {product.capacity}");

            if (currentProductFieldId == 5) { Console.Write(" ->  "); }
            Console.WriteLine($"Amount : {product.amount}");
            Console.WriteLine();
            Console.WriteLine();
        }
        public void PrintProductForm()
        {
            Console.Clear();
            Console.WriteLine("\t\t\t Cosmetic Product \t\t\t \n\n");
            Console.WriteLine
                (
                $"{(int)ProductMenuCommands.ProductMenuBack} : Back | " +
                $"{(int)ProductMenuCommands.ProductFieldUp} : Move Up | " +
                $"{(int)ProductMenuCommands.ProductFieldDown} : Move Down | " +
                $"{(int)ProductMenuCommands.ChangeCurrentField}  : ChangeCurrentField "
                );
            SetState(ProductMenuCommands.ProductMenuWaiting);
            PrintProduct();
        }
        public void CreateNewProductForm()
        {
            Cosmetic product = new Cosmetic();
            string str; int k;

            Console.WriteLine("Id (Example : 9999) : ");
            k = int.Parse(Console.ReadLine());
            product.id = k;
            Console.WriteLine();

            Console.WriteLine("Expiration Date (Example : 12.12.2012) : ");
            str = Console.ReadLine();
            product.expirationDate = str;
            Console.WriteLine();

            Console.WriteLine("Name (Example : Kfehjvre) : ");
            str = Console.ReadLine();
            product.name = str;
            Console.WriteLine();

            Console.WriteLine("Storage Temperature (Example : 23) : ");
            k = int.Parse(Console.ReadLine());
            product.storageTemperature = k;
            Console.WriteLine();

            Console.WriteLine("Capacity (Example : 44) ");
            k = int.Parse(Console.ReadLine());
            product.capacity = k;
            Console.WriteLine();

            Console.WriteLine("Amount (Example : 44) : ");
            k = int.Parse(Console.ReadLine());
            product.amount = k;
            Console.WriteLine();

            cosRepos.Create(product);
            products = cosRepos.GetAll();
        }
        public Cosmetic ChangeCurrentFieldById(int Id)
        {
            Cosmetic product = cosRepos.GetById(currentId);
            switch (Id)
            {
                case 1:
                {
                    product.expirationDate = CreateNewDate();
                    break;
                }
                case 2:
                {
                    product.name = CreateNewString();
                    break;
                }
                case 3:
                {
                    product.storageTemperature = Convert.ToInt32(CreateNewInt());
                    break;
                }
                case 4:
                {
                    product.capacity = Convert.ToInt32(CreateNewInt());
                    break;
                }
                case 5:
                {
                    product.amount = Convert.ToInt32(CreateNewInt());
                    break;
                }
                default:
                {
                    break;
                }
            }
            return product;
        }

        public void OrderProduct() 
        {
            Console.WriteLine("\n\n choose amount: ");
            int amount = int.Parse(Console.ReadLine());
            CartEntity cartProduct = TakeAmountFromCurrentProduct(amount);

            if (cart.IsProductExist(factory.GetCartFlyweight(cartProduct, amount)))///////////////////////////////////
            {
                factory.GetCartFlyweight(cartProduct, amount).amount += amount;/////
            }
            else if ((factory.GetCartFlyweight(cartProduct, amount)).amount == 0)
            {
                factory.GetCartFlyweight(cartProduct, amount).amount += amount;
                cart.Create(factory.GetCartFlyweight(cartProduct, amount));
            }
            else
            {
                cart.Create(factory.GetCartFlyweight(cartProduct, amount));
            }

            Console.WriteLine("\n product successfully added to cart");
            Console.WriteLine("1 : back to table | 2 : open cart");

            bool w = true;
            while (w)
            {
                int k = ((int)Console.ReadKey().KeyChar)-48;
                if (k == 1)
                {
                    w = false;
                }
                else if (k == 2)
                {
                    PrintTableForm();
                    OpenCard();
                    w = false;
                }
            }

        }

        public void OpenCard()
        {
            bool w = true;
            while (w)
            {
                PrintTableForm();
                Console.WriteLine("\t\t\t My Cart");
                Console.WriteLine("Product Id || Name || Amount \n\n");
                if (cart.GetAll() == null)
                {
                    Console.WriteLine("||  Cart is Emply");
                    Console.WriteLine("\n\n || 1 : Back ");
                }
                else
                {
                    bool empty = false;
                    foreach (var it in cart.entities)
                    {
                        if (it.amount != 0)
                        {
                            empty = true;
                            Console.WriteLine(it.ToString());
                        }
                    }
                    if(empty)
                    {
                        Console.WriteLine("\n\n || 1 : Back | 2 : Clear Cart");
                    }
                    else
                    {
                        Console.WriteLine("||  Cart is Emply");
                        Console.WriteLine("\n\n || 1 : Back ");
                    }
                }
                int g = ((int)(Console.ReadKey().KeyChar))-48;
                if (g == 1)
                {
                    w = false;
                }
                else if (g == 2)
                {
                    foreach (var it in cart.entities)
                    {
                        ReturnProductAmount(it.id, it.name, it.amount);
                        //
                        CartEntity c = new CartEntity();
                        c.id = it.id;
                        c.name = it.name;
                        factory.GetCartFlyweight(c, 0).amount = 0;
                        //
                    }
                    PrintTableForm();
                    w = false;
                }
            }
        }

        public CartEntity TakeAmountFromCurrentProduct(int amount)
        {
            CartEntity p = new CartEntity();
            products = cosRepos.GetAll();
            foreach (var it in products)
            {
                if (it.id == currentId)
                {
                    p.id = it.id;
                    p.name = it.name;
                    it.amount = it.amount - amount;
                }
            }
            return p;
        }

        public void ReturnProductAmount(int id, string name, int amount)
        {
            products = cosRepos.GetAll();
            foreach(var it in products)
            {
                if (it.id == id)
                {
                    it.amount += amount;
                }
            }
        }

    }
}

