using MyPharmacy.DAL.Modules.Impl;
using System;
using System.Windows.Forms;


namespace WindowsFormsAdmin
{
    public partial class MedicineProductForm : Form
    {
        Medicine medProduct;
        public MedicineProductForm(Medicine product)
        {
            medProduct = product;
            InitializeComponent();
        }



        private void ProductForm_Load(object sender, EventArgs e)
        {
            textBox1.Text = medProduct.Id.ToString();
            textBox2.Text = medProduct.name;
            textBox3.Text = medProduct.expirationDate;
            textBox4.Text = medProduct.amount.ToString();
            textBox5.Text = medProduct.storageTemperature.ToString();
            //dataGridView1.Rows.Add("Id", medProduct.Id);
            //dataGridView1.Rows.Add("name", medProduct.name);
            //dataGridView1.Rows.Add("expirationDate", medProduct.expirationDate);
            //dataGridView1.Rows.Add("amount", medProduct.amount);
            //dataGridView1.Rows.Add("storageTemperature", medProduct.storageTemperature);
            //dataGridView1.DataSource = ;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            medProduct.name = textBox2.Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            medProduct.expirationDate = textBox3.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            medProduct.amount = int.Parse(textBox4.Text);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            medProduct.storageTemperature = int.Parse(textBox5.Text);
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }
    }
}