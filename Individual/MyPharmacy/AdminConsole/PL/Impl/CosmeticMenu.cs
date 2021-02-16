using System;
using System.Collections.Generic;
using System.Text;
using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Impl;
using System.Linq;

namespace AdminConsole.PL.Impl
{
    public class CosmeticMenu : BaseMenu<CosmeticRepository, Cosmetic>
    {
        //public CosmeticsMenu()
        //{
        //	this.repository = new TablesRepository;
        //}
        CosmeticRepository cosRepos = new CosmeticRepository();
        public void ShowTableMenu()
		{
            products = cosRepos.GetAll() ?? new List<Cosmetic>();
            if (products.Count() != 0)
            {
                this.currentId = products[0].id;
            }
            PrintTableForm();
            //int catcher;
            TableMenuCommands catcher = (TableMenuCommands)Console.Read();
            do
            {
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
                            //UpdateDataForTableMenu();
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.SortTableById:
                        {
                            PrintSortTable();
                            break;
                        }
                    //case TableMenuCommands.OrderCurrentProduct:
                    //    {
                    //        OrderProduct();
                    //        PrintTableForm();
                    //        break;
                    //    }
                    //case TableMenuCommands.TableOpenCard:
                    //    {
                    //        OpenCard();
                    //        PrintTableForm();
                    //        break;
                    //    }
                    default:
                        {
                            continue;
                        }
                }
            } while (catcher != TableMenuCommands.TableMenuBack);
        }
		public void PrintTable()
        {
            Console.WriteLine("\n\n");
            Console.WriteLine("ID | expirationDate | Name | storageFormType | Capacity | Amount");
            Console.WriteLine("\n\n");
            foreach (var it in products)
            {
                Cosmetic p = it;
                if (p.id == this.currentId)
                {
                    Console.WriteLine(" ->  ");
                }
                Console.WriteLine($"{ p.id} | {p.expirationDate} | {p.name}" +
                    $" | {p.storageTemperature} | {p.capacity} | {p.amount}");
            }
            Console.WriteLine("\n\n");
        }
        public void PrintTableForm()
        {
            Console.Clear();
            Console.WriteLine("\t\t\t Cosmetics Table \t\t\t \n\n");
            Console.WriteLine(
                $" {(int)TableMenuCommands.TableMenuBack} : Back |" +
                $" {(int)TableMenuCommands.Up}" + $" : Up |" +
                $" {(int)TableMenuCommands.Down} : Down |" +
                $" {(int)TableMenuCommands.SelectCurrentProduct} : Select Current Product\n" +
                $" {(int)TableMenuCommands.SortTableById}: Sort Table By Id | " +
                $" {(int)TableMenuCommands.OrderCurrentProduct} : Order Product | " +
                $" {(int)TableMenuCommands.TableOpenCard}  : Open Card | "
                );
            SetState(TableMenuCommands.TableMenuWaiting);
            PrintTable();
        }
        public void PrintSortTable()
        {
            Console.Clear();
            /*this.products = *///products.OrderBy(o => o.id).ToList();

            if (products[0].id > products[1].id)
            {
                //products.OrderBy(o => o.id).ToList();
                products.Sort((x, y) => x.id.CompareTo(y.id));
            }
            else
            {
                //products.OrderBy(o => o.id).ToList();
                products.Sort((y, x) => x.id.CompareTo(y.id));
            }
            PrintTableForm();
        }
        //////////////////////
        //public void OrderProduct();

            //public void OpenCard();

            //public CartProduct& TakeAmountFromCurrentProduct(int amount);

            //public void ReturnProductAmount(int id, std::string name, int amount);
            /////////////////////


        public void ShowProductMenu(int Id)
        {
            this.currentId = Id;
            PrintProductForm();
            string str;
            ProductMenuCommands command;
            do
            {
                command = (ProductMenuCommands)Console.Read();
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
                        int i = Console.Read();
                        if (i == 1)
                        {
                            //repository->GetCosmeticsTable()->Update(*ChangeCurrentFieldById(currentProductFieldId));
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
            Console.WriteLine("\t\t\t Cosmetics Product \t\t\t \n\n");
            Console.WriteLine
                (
                $"{ProductMenuCommands.ProductMenuBack} : Back | " +
                $"{ProductMenuCommands.ProductFieldUp} : Move Up | " +
                $"{ProductMenuCommands.ProductFieldDown} : Move Down | " +
                $"{ProductMenuCommands.ChangeCurrentField}  : ChangeCurrentField "
                );
            SetState(ProductMenuCommands.ProductMenuWaiting);
            PrintProduct();
        }
        public void CreateNewProductForm()
        {
            Cosmetic product = new Cosmetic();
            string str; int k;

            Console.WriteLine("Id (Example : 9999) : ");
            k = Console.Read();
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
            k = Console.Read();
            product.storageTemperature = k;
            Console.WriteLine();

            Console.WriteLine("Capacity (Example : 44) ");
            k = Console.Read();
            product.storageTemperature = k;
            Console.WriteLine();

            Console.WriteLine("Amount (Example : 44) : ");
            k = Console.Read();
            product.amount = k;
            Console.WriteLine();

            cosRepos.Create(product);
            //repository->GetCosmeticsTable()->Create(*product);
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

        //~CosmeticsMenu() { }
    }
}



//void CosmeticsMenu::OrderProduct()
//{
//	std::cout << "\n\n" << "choose amount: ";
//	int amount;
//	std::cin >> amount;
//	CartProduct cartProduct = TakeAmountFromCurrentProduct(amount);

//	repository->GetCosmeticsTable()->Save();
//	if (repository->GetCartTable()->IsProductExist(*factory.GetCartFlyweight(cartProduct, amount)))///////////////////////////////////
//	{
//		factory.GetCartFlyweight(cartProduct, amount)->amount += amount;/////
//		repository->GetCartTable()->Update(*factory.GetCartFlyweight(cartProduct, amount));
//	}
//	else if ((factory.GetCartFlyweight(cartProduct, amount))->amount == 0)
//	{
//		factory.GetCartFlyweight(cartProduct, amount)->amount += amount;
//		repository->GetCartTable()->Create(*factory.GetCartFlyweight(cartProduct, amount));
//	}
//	else
//	{
//		repository->GetCartTable()->Create(*factory.GetCartFlyweight(cartProduct, amount));
//	}

//	std::cout << "\n" << "product successfully added to cart" << std::endl;

//	std::cout << "1 : back to table | 2 : open cart" << std::endl;
//	bool w = true;
//	while (w)
//	{
//		int k = GETCH;
//		if (k == 1)
//		{
//			w = false;
//		}
//		else if (k == 2)
//		{
//			PrintTableForm();
//			OpenCard();
//			w = false;
//		}
//	}

//}

//void CosmeticsMenu::OpenCard()
//{
//	bool w = true;
//	while (w)
//	{
//		PrintTableForm();
//		std::cout << "\t\t\t" << "My Cart" << std::endl;
//		std::cout << "Product Id || Name || Amount" << "\n\n";
//		if ((*repository->GetCartTable()->GetAll()).size() == 0)
//		{
//			std::cout << "||  " << "Cart is Emply" << std::endl;
//			std::cout << "\n\n" << "|| 1 : Back " << std::endl;
//		}
//		else
//		{
//			for (auto it : *repository->GetCartTable()->GetAll())
//			{
//				std::cout << "||  " << it->id << "|| " << it->name << "|| " << it->amount << std::endl;
//			}
//			std::cout << "\n\n" << "|| 1 : Back | 2 : Clear Cart" << std::endl;
//		}
//		int g = GETCH;
//		if (g == 1)
//		{
//			w = false;
//		}
//		else if (g == 2)
//		{
//			for (auto it : *repository->GetCartTable()->GetAll())
//			{
//				ReturnProductAmount(it->id, it->name, it->amount);

//				//
//				CartProduct c;
//				c.id = it->id;
//				c.name = it->name;
//				factory.GetCartFlyweight(c, 0)->amount = 0;
//				//
//			}
//			repository->GetCartTable()->DeleteAll();
//			PrintTableForm();
//			w = false;
//			(*repository->GetCartTable()->GetAll()).clear();
//		}
//	}
//}

//CartProduct & CosmeticsMenu::TakeAmountFromCurrentProduct(int amount)
//{
//	CartProduct* p = new CartProduct;
//	products = repository->GetCosmeticsTable()->GetAll();
//	for (auto it : *products)
//	{
//		if (it->id == currentId)
//		{
//			p->id = it->id;
//			p->name = it->name;
//			it->amount = it->amount - amount;
//		}
//	}
//	return *p;
//}

//void CosmeticsMenu::ReturnProductAmount(int id, std::string name, int amount)
//{
//	products = repository->GetCosmeticsTable()->GetAll();
//	for (auto it : *products)
//	{
//		if (it->id == id)
//		{
//			it->amount += amount;
//		}
//	}
//	repository->GetCosmeticsTable()->Save();
//}

