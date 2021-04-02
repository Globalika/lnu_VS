using MyPharmacy.DAL.Factories.Impl;
using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Abstract;
using System;
using System.Reflection;
using System.Windows.Forms;

namespace WindowsFormsAdmin
{
    public partial class Form1 : Form
    {
        readonly IMedicineRepository medRepos;
        readonly ICosmeticRepository cosRepos;
        public Form1()
        {
            FactoryProvider prov = new FactoryProvider();
            medRepos = prov.GetFactory().GetMedicineRepository();
            cosRepos = prov.GetFactory().GetCosmeticRepository();
            InitializeComponent();
        }
        private void Form_Load(object sender, EventArgs e)
        {
            dataGridView1.DataSource = medRepos.GetAll();
            dataGridView2.DataSource = cosRepos.GetAll();
        }

        private void Med_Create_Click(object sender, EventArgs e)
        {
            try
            {
                var _Id = int.Parse(med_Id.Text);
                var _name = med_name.Text ?? "";
                var _expirationDate = med_expirationDate.Text;
                var _amount = int.Parse(med_amount.Text);
                var _storageTemperature = int.Parse(med_storageTemperature.Text);
                medRepos.Create(new Medicine()
                {
                    Id = _Id,
                    name = _name,
                    amount = _amount,
                    expirationDate = _expirationDate,
                    storageTemperature = _storageTemperature
                });
                MessageBox.Show("Created successfully!","success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                //dataGridView1.Refresh();
                var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
                m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
            }
            catch(Exception ex)
            {
                MessageBox.Show("exception!", ex.Message, MessageBoxButtons.OK);
            }
        }

        private void Med_Sort_Table_Click(object sender, EventArgs e)
        {
            if (medRepos.GetAll()[0].Id > medRepos.GetAll()[1].Id)
            {
                medRepos.GetAll().Sort((x, y) => x.Id.CompareTo(y.Id));
            }
            else
            {
                medRepos.GetAll().Sort((y, x) => x.Id.CompareTo(y.Id));
            }

            var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
        }

        private void Med_Delete_Product_Click(object sender, EventArgs e)
        {
            medRepos.Delete((int)dataGridView1.CurrentCell.Value);
            var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
        }

        private void Med_Product_Details_Click(object sender, EventArgs e)
        {
            Form2 secondForm = new Form2(medRepos.GetById((int)dataGridView1.CurrentCell.Value));
            secondForm.Show();
        }

        private void Med_Refresh_Click(object sender, EventArgs e)
        {
            dataGridView1.DataSource = medRepos.GetAll();
            var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
        }

        private void Cos_Create_Click(object sender, EventArgs e)
        {
            try
            {
                var _Id = int.Parse(cos_Id.Text);
                var _name = cos_name.Text ?? "";
                var _expirationDate = cos_expirationDate.Text;
                var _amount = int.Parse(cos_amount.Text);
                var _capacity = int.Parse(cos_capacity.Text);
                var _storageTemperature = int.Parse(cos_storageTemperature.Text);
                cosRepos.Create(new Cosmetic()
                {
                    Id = _Id,
                    name = _name,
                    amount = _amount,
                    capacity = _capacity,
                    expirationDate = _expirationDate,
                    storageTemperature = _storageTemperature
                });
                MessageBox.Show("Created successfully!", "success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                //dataGridView1.Refresh();
                var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
                m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
            }
            catch (Exception ex)
            {
                MessageBox.Show("exception!", ex.Message, MessageBoxButtons.OK);
            }
        }

        private void Cos_Sort_Table_Click(object sender, EventArgs e)
        {
            if (cosRepos.GetAll()[0].Id > cosRepos.GetAll()[1].Id)
            {
                cosRepos.GetAll().Sort((x, y) => x.Id.CompareTo(y.Id));
            }
            else
            {
                cosRepos.GetAll().Sort((y, x) => x.Id.CompareTo(y.Id));
            }

            var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
        }

        private void Cos_Delete_Product_Click(object sender, EventArgs e)
        {
            cosRepos.Delete((int)dataGridView2.CurrentCell.Value);
            var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
        }

        private void Cos_Product_Details_Click(object sender, EventArgs e)
        {
            Form2 secondForm = new Form2(cosRepos.GetById((int)dataGridView2.CurrentCell.Value));
            secondForm.Show();
        }

        private void Cos_Refresh_Click(object sender, EventArgs e)
        {
            dataGridView2.DataSource = cosRepos.GetAll();
            var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
        }

        //private void Form_Cos_Load(object sender, EventArgs e)
        //{
        //    dataGridView1.DataSource = cosRepos.GetAll();
        //}
        //private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        //{
        //}

    }
}
