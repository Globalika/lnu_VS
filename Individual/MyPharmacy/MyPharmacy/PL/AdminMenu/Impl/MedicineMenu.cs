using System;
using System.Collections.Generic;
using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Impl;
using System.Linq;

namespace MyPharmacy.PL.AdminMenu.Impl
{
    public class MedicineMenu : BaseMenu<MedicineRepository, Medicine>
    {
        public MedicineMenu() /*: base()*/
        {
            medRepos = new MedicineRepository()
            { };
        }
        MedicineRepository medRepos;
        public override void ShowTableMenu()
        {
            products = medRepos.GetAll() ?? new List<Medicine>();
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
                    case TableMenuCommands.CreateNewProduct:
                        {
                            CreateNewProduct();
                            PrintTableForm();
                            break;
                        }
                    case TableMenuCommands.DeleteCurrentProduct:
                        {
                            DeleteCurrentProduct();
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
                Medicine p = it;
                if (p.id == this.currentId)
                {
                    Console.Write(" ->  ");
                }
                Console.WriteLine($"{ p.id} | {p.expirationDate} | {p.name}" +
                    $" | {p.storageTemperature} | {p.amount}");
            }
            Console.WriteLine("\n\n");
        }
        public override void PrintTableForm()
        {
            Console.Clear();
            Console.WriteLine("\t\t\t Medicine Table \t\t\t \n\n");
            Console.WriteLine(
                $" {(int)TableMenuCommands.TableMenuBack} : Back |" +
                $" {(int)TableMenuCommands.Up}" + $" : Up |" +
                $" {(int)TableMenuCommands.Down} : Down |\n" +
                $" {(int)TableMenuCommands.SelectCurrentProduct} : Select Current Product |" +
                $" {(int)TableMenuCommands.SortTableById}: Sort Table By Id | " +
                $" {(int)TableMenuCommands.CreateNewProduct} : Create new product | " +
                $" {(int)TableMenuCommands.DeleteCurrentProduct}  : Delete current product | "
                
                );
            SetState(TableMenuCommands.TableMenuWaiting);
            PrintTable();
        }
        public void CreateNewProduct()
        {
            Console.WriteLine("Create new product? | 0 : No | 1 : Yes");
            if (Console.ReadKey().KeyChar == '1')
            {

                CreateNewProductForm();
                currentId = products[0].id;
            }
        }
        public void DeleteCurrentProduct()
        {
            Console.WriteLine("Delete current product? | 0 : No | 1 : Yes");
            if (Console.ReadKey().KeyChar == '1')
            {
                medRepos.Delete(currentId);
                products = medRepos.GetAll();
                currentId = products[0].id;
            }
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
            currentId = products[i + n].id;
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
                            if (currentProductFieldId != 4) { currentProductFieldId++; }
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
                                products = medRepos.GetAll();
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
            products = medRepos.GetAll();
            Medicine product = new Medicine();
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
            Console.WriteLine($"Amount : {product.amount}");
            Console.WriteLine();
            Console.WriteLine();
        }
        public void PrintProductForm()
        {
            Console.Clear();
            Console.WriteLine("\t\t\t Medicine Product \t\t\t \n\n");
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
            Medicine product = new Medicine();
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

            Console.WriteLine("Amount (Example : 44) : ");
            k = int.Parse(Console.ReadLine());
            product.amount = k;
            Console.WriteLine();

            medRepos.Create(product);
            products = medRepos.GetAll();
        }
        public Medicine ChangeCurrentFieldById(int Id)
        {
            Medicine product = medRepos.GetById(currentId);
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
    }
}

