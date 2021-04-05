using MyPharmacy.DAL.Factories.Impl;
using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Abstract;
using System;
using System.Reflection;
using System.Windows.Forms;

namespace WindowsFormsAdmin
{
    public partial class AppForm : Form
    {
        readonly IMedicineRepository medRepos;
        readonly ICosmeticRepository cosRepos;
        public AppForm()
        {
            FactoryProvider prov = new FactoryProvider();
            medRepos = prov.GetFactory().GetMedicineRepository();
            cosRepos = prov.GetFactory().GetCosmeticRepository();
            InitializeComponent();
        }
        private void Clear_Table(DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            dataGridView.Rows.Clear();
            dataGridView.Columns.Clear();
        }
        private void Load_Med_Table(DataGridView dataGridView)
        {
            dataGridView.Columns.Add("", "Id");
            dataGridView.Columns.Add("", "Name");
            dataGridView.Columns.Add("", "Expir. Date");
            dataGridView.Columns.Add("", "Amount");
            dataGridView.Columns.Add("", "Temperature");
            foreach (var it in medRepos.GetAll())
            {
                dataGridView.Rows.Add(it.Id, it.name, it.expirationDate, it.amount, it.storageTemperature);
            }
        }
        private void Load_Cos_Table(DataGridView dataGridView)
        {
            dataGridView.Columns.Add("", "Id");
            dataGridView.Columns.Add("", "Name");
            dataGridView.Columns.Add("", "Expir. Date");
            dataGridView.Columns.Add("", "Amount");
            dataGridView.Columns.Add("", "Capacity");
            dataGridView.Columns.Add("", "Temperature");
            foreach (var it in cosRepos.GetAll())
            {
                dataGridView.Rows.Add(it.Id, it.name, it.expirationDate, it.amount, it.capacity, it.storageTemperature);
            }
        }
        private void Form_Load(object sender, EventArgs e)
        {
            Clear_Table(this.dataGridView1);
            Load_Med_Table(this.dataGridView1);
            ////////////////
            Clear_Table(this.dataGridView2);
            Load_Cos_Table(this.dataGridView2);
        }

        private void Med_Create_Click(object sender, EventArgs e)
        {
            try
            {
                medRepos.Create(new Medicine()
                {
                    Id = int.Parse(med_Id.Text),
                    name = med_name.Text ?? "",
                    expirationDate = med_expirationDate.Text,
                    amount = int.Parse(med_amount.Text),
                    storageTemperature = int.Parse(med_storageTemperature.Text)
                });
                MessageBox.Show("Created successfully!", "success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                Clear_Table(this.dataGridView1);
                Load_Med_Table(this.dataGridView1);
                //var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
                //m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
            }
            catch (Exception ex)
            {
                MessageBox.Show("exception!", ex.Message, MessageBoxButtons.OK);
            }
        }

        private void Med_Delete_Product_Click(object sender, EventArgs e)
        {
            medRepos.Delete((int)dataGridView1.CurrentCell.Value);
            Clear_Table(this.dataGridView1);
            Load_Med_Table(this.dataGridView1);
            //var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            //m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
        }

        private void Med_Product_Details_Click(object sender, EventArgs e)
        {
            MedicineProductForm secondForm = new MedicineProductForm(medRepos.GetById((int)dataGridView1.CurrentCell.Value));
            secondForm.Show();
        }

        private void Med_Refresh_Click(object sender, EventArgs e)
        {
            Clear_Table(this.dataGridView1);
            Load_Med_Table(this.dataGridView1);
            //dataGridView1.DataSource = medRepos.GetAll();
            //var m = dataGridView1.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            //m.Invoke(dataGridView1, new object[] { EventArgs.Empty });
        }

        private void Cos_Create_Click(object sender, EventArgs e)
        {
            try
            {
                cosRepos.Create(new Cosmetic()
                {
                    Id = int.Parse(cos_Id.Text),
                    name = cos_name.Text ?? "",
                    expirationDate = cos_expirationDate.Text,
                    amount = int.Parse(cos_amount.Text),
                    capacity = int.Parse(cos_capacity.Text),
                    storageTemperature = int.Parse(cos_storageTemperature.Text)
                });
                MessageBox.Show("Created successfully!", "success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                //dataGridView1.Refresh();
                Clear_Table(this.dataGridView2);
                Load_Cos_Table(this.dataGridView2);
                //var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
                //m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
            }
            catch (Exception ex)
            {
                MessageBox.Show("exception!", ex.Message, MessageBoxButtons.OK);
            }
        }

        private void Cos_Delete_Product_Click(object sender, EventArgs e)
        {
            cosRepos.Delete((int)dataGridView2.CurrentCell.Value);
            Clear_Table(this.dataGridView2);
            Load_Cos_Table(this.dataGridView2);
            //var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            //m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
        }

        private void Cos_Product_Details_Click(object sender, EventArgs e)
        {
            CosmeticProductFrom secondForm = new CosmeticProductFrom(cosRepos.GetById((int)dataGridView2.CurrentCell.Value));
            secondForm.Show();
        }

        private void Cos_Refresh_Click(object sender, EventArgs e)
        {
            Clear_Table(this.dataGridView2);
            Load_Cos_Table(this.dataGridView2);
            //dataGridView2.DataSource = cosRepos.GetAll();
            //var m = dataGridView2.GetType().GetMethod("OnDataSourceChanged", BindingFlags.NonPublic | BindingFlags.Instance);
            //m.Invoke(dataGridView2, new object[] { EventArgs.Empty });
        }
    }
}
