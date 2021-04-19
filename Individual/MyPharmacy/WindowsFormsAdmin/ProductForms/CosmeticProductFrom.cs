﻿using MyPharmacy.DAL.Modules.Impl;
using System;
using System.Windows.Forms;

namespace WindowsFormsAdmin
{
    public partial class CosmeticProductFrom : Form
    {
        Cosmetic cosProduct;
        public CosmeticProductFrom(Cosmetic product)
        {
            cosProduct = product;
            InitializeComponent();
        }
        public Cosmetic GetProductBack()
        {
            return this.cosProduct;
        }
        private void CosmeticProductFrom_Load(object sender, EventArgs e)
        {
            textBox1.Text = cosProduct.Id.ToString();
            textBox2.Text = cosProduct.name;
            textBox3.Text = cosProduct.expirationDate;
            textBox4.Text = cosProduct.amount.ToString();
            textBox6.Text = cosProduct.capacity.ToString();
            textBox5.Text = cosProduct.storageTemperature.ToString();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            cosProduct.name = textBox2.Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            cosProduct.expirationDate = textBox3.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            cosProduct.amount = int.Parse(textBox4.Text);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            cosProduct.storageTemperature = int.Parse(textBox5.Text);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            cosProduct.amount = int.Parse(textBox6.Text);
        }


    }
}
