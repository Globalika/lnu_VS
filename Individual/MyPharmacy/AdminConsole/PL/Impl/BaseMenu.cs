using System;
using System.Collections.Generic;
using System.Text;

namespace AdminConsole.PL.Impl
{
    public class BaseMenu<TableType, ProductType>
	{
		public enum TableMenuCommands
		{
			TableMenuBack,
			Up,
			Down,
			SelectCurrentProduct,
			SortTableById,
			OrderCurrentProduct,
			TableOpenCard,
			TableMenuWaiting,
		};
		public enum ProductMenuCommands
		{
			ProductMenuBack,
			ProductFieldUp,
			ProductFieldDown,
			ChangeCurrentField,
			ProductMenuWaiting,
		};
		public int currentId;
		public List<ProductType> products;
		public TableMenuCommands tState;
		public ProductMenuCommands pState;
		public int currentProductFieldId = 1;

		public virtual void ShowTableMenu() { }
		public virtual void PrintTable() { }
		public virtual void PrintTableForm() { }
		public virtual void PrintSortTable() { }
		public virtual void UpdateDataForTableMenu() { }
		public void MoveCursorByProductId(int n)
		{
            //if (n == 1)
            //{
            //    if (currentId == products[products.Count - 1].id)
            //    {
            //        return;
            //    }
            //}
            //else
            //{
            //    if (currentId == products->at(0)->id)
            //    {
            //        return;
            //    }
            //}
            //int i = 0;
            //while (products->at(i)->id != currentId)
            //{
            //    i++;
            //}
            //currentId = products->at(i + n)->id;
        }
		public virtual void CreateNewProductForm() { }
		//public virtual ~BaseMenu() { }
		public void SetState(TableMenuCommands state)
		{
			this.tState = state;
		}
		public void ShowProductMenu(int Id) { }
		public virtual void PrintProduct() { }
		public virtual void PrintProductForm() { }
		public void CheckProductString(string str)
		{
			foreach (var i in str)
			{
				if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
				{
					throw new Exception();
				}
			}
		}
		public void CheckProductDate(string str) 
		{
			if (!(str[2] == 46 && str[5] == 46 && str.Length == 10))
            {
				throw new Exception();
			}
            for (int i = 0; i < str.Length; i++)
            {
                if (i == 2 || i == 5)
                {
                    continue;
                }
                else if (!(str[i] >= 48 && str[i] <= 58))
                {
					throw new Exception();
				}
            }
            if ((str[0] - 48) * 10 + (str[1] - 48) < 1 || ((str[0] - 48) * 10 + (str[1] - 48)) > 31)
            {
				throw new Exception();
			}
            if ((str[3] - 48) * 10 + (str[4] - 48) < 1 || ((str[3] - 48) * 10 + (str[4] - 48)) > 12)
            {
				throw new Exception();
			}
            if (((str[6] - 48) * 1000 + (str[7] - 48) * 100 + (str[8] - 48) * 10 + (str[9] - 48)) < 2020 || ((str[6] - 48) * 1000 + (str[7] - 48) * 100 + (str[8] - 48) * 10 + (str[9] - 48)) > 2300)
            {
				throw new Exception();
			}
        }
		public void CheckProductInt(string str) 
		{
			foreach (var i in str)
			{
                if (!(i >= 48 && i <= 58))
                {
					throw new Exception();
				}
            }
        }
		public string CreateNewDate()
		{
			string str = "";
			bool isTrue = true;
			while (isTrue)
			{
				try
				{
					isTrue = false;
					Console.WriteLine("New Date : ");
					str = Console.ReadLine();
					CheckProductDate(str);
				}
				catch (Exception err)
				{
					PrintProductForm();
					Console.WriteLine("Wrong form! Please, type date like this example: dd.mm.yyyy");
					isTrue = true;
				}
			}
			return str;
		}
		public string CreateNewString() 
		{
			string str = "";
            bool isTrue = true;
            while (isTrue)
            {
                try
                {
                    isTrue = false;
					Console.WriteLine("New Line : ");
					str = Console.ReadLine();
					CheckProductString(str);
                }
                catch (Exception err)
				{
                    PrintProductForm();
					Console.WriteLine("Wrong! Please, try again.");
					isTrue = true;
                }
            }
            return str;
        }
		public string CreateNewInt() 
		{
			string str = "";
            bool isTrue = true;
            while (isTrue)
            {
                try
                {
                    isTrue = false;
					Console.WriteLine("New Line : ");
					str = Console.ReadLine();
					CheckProductInt(str);
                }
                catch (Exception err)
					{
                    PrintProductForm();
					Console.WriteLine("Wrong format! Please, use only numbers.");
					isTrue = true;
                }
            }
            return str;
        }
		//public ProductType ChangeCurrentFieldById(int Id) { }
		public void SetState(ProductMenuCommands state)
		{
			this.pState = state;
		}
		//public TablesRepository repository;
		//public FlyweightFactory factory;
	}
}





//void BaseMenu<TableType, ProductType>::MoveCursorByProductId(int n)
//{
//	if (n == 1)
//	{
//		if (currentId == products->at(products->size() - 1)->id)
//		{
//			return;
//		}
//	}
//	else
//	{
//		if (currentId == products->at(0)->id)
//		{
//			return;
//		}
//	}
//	int i = 0;
//	while (products->at(i)->id != currentId)
//	{
//		i++;
//	}
//	currentId = products->at(i + n)->id;
//}
