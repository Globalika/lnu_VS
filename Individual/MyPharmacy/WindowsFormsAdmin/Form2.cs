using MyPharmacy.DAL.Modules.Impl;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsAdmin
{
    public partial class Form2 : Form
    {
        Medicine medProduct;
        Cosmetic cosProduct;
        public Form2(Medicine product)
        {
            medProduct = product;
            InitializeComponent();
        }
        public Form2(Cosmetic product)
        {
            cosProduct = product;
            InitializeComponent();
        }

        private void Product_Load_Form(object sender, EventArgs e)
        {
            List<object> list = new List<object>();
            list.Add(medProduct.Id);
            list.Add(medProduct.name);
            list.Add(medProduct.expirationDate);
            list.Add(medProduct.amount);
            list.Add(medProduct.storageTemperature);
            dataGridView1.DataSource = list/*new List<int>() { 1, 2, 4 }*/;
        }

    }
}
